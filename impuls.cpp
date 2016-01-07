#include "impuls.h"
#include "ui_impuls.h"

const double pi = 3.14159265358979;
const double c = 3e8;

Impuls::Impuls(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Impuls)
{
    ui->setupUi(this);

    ui->HdoubleSpinBox->setDecimals(6);
    ui->HdoubleSpinBox->setMinimum(1);
    ui->HdoubleSpinBox->setMaximum(42);
    ui->HdoubleSpinBox->setValue(1);
    ui->HdoubleSpinBox->setSingleStep(0.5);

    ui->f0LineEdit->setText(QString::number(444e6));
    ui->fmLineEdit->setText(QString::number(70));
    ui->df0LineEdit->setText(QString::number(8.5e6));

    double f0 = ui->f0LineEdit->text().toDouble();
    double fm = ui->fmLineEdit->text().toDouble();
    double df0 = ui->df0LineEdit->text().toDouble();

    connect(ui->execute, SIGNAL(clicked()), this, SLOT(execute_clicked()));
    connect(ui->execute, SIGNAL(clicked()), this, SLOT(plot()));
    connect(ui->HdoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(execute_clicked()));
    connect(ui->HdoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(plot()));

    execute_clicked();
    plot();
}

Impuls::~Impuls()
{
    delete ui;
}

double Impuls::impulseUprise(double H, double f0, double df0, double k)
{
    double lambda0 = c / f0;
    double dzeta = df0 / f0;
    double HUprise = (lambda0 / 8) * ((2*k-1) / (1 + dzeta));

    return HUprise;
}

double Impuls::impulseDownfall(double H, double f0, double df0, double k)
{
    double lambda0 = c / f0;
    double dzeta = df0 / f0;
    double HDownfall = (lambda0 / 8) * ((2*k-1) / (1 - dzeta));

    return HDownfall;
}

double Impuls::numOfImpulses(double H, double f0, double df0)
{
    double range = 2;
    double start = H - range/2;
    double stop = H + range/2;

    double HUprise[1000];
    double HDownfall[1000];
    int Ucounter = 0;
    int Dcounter = 0;
    double numOfImp;

    int k = 0;
    HUprise[k] = impulseUprise(H,f0,df0,k);
    HDownfall[k] = impulseDownfall(H, f0, df0, k);

    do{
        k++;
        HUprise[k] = impulseUprise(H,f0,df0,k);
        HDownfall[k] = impulseDownfall(H, f0, df0, k);
    } while(HUprise[k] < stop);

    for(int i=1; i<=k; i++)
    {
        if(HUprise[i] <= H)
        {
            Ucounter++;
        }
        if(HDownfall[i] <= H)
        {
            Dcounter++;
        }
    }

    numOfImp = Ucounter - Dcounter;

    return numOfImp;
}

double Impuls::random()
{
    double randomNumber = (double)rand() / (RAND_MAX + 1);
    return randomNumber;
}

void Impuls::execute_clicked()
{    
    ui->qwtPlot->detachItems(QwtPlotItem::Rtti_PlotItem, false);
    ui->qwtPlot_2->detachItems(QwtPlotItem::Rtti_PlotItem, false);
    double H = ui->HdoubleSpinBox->value();
    double f0 = ui->f0LineEdit->text().toDouble();
    double df0 = ui->df0LineEdit->text().toDouble();

    double range = 2;
    double start = H - range/2;
    double stop = H + range/2;

    double HUp[10];
    double HDo[10];
    double Hx[11];
    double Hy[11];

    double y[10];
    for(int i=0; i<10; i++)
        y[i] = 0+i*0.1;

    double y_2[10];
    for(int i=0; i<10; i++)
        y_2[i] = 0+i*0.1;

    int k = 1;
    double HUprise = impulseUprise(H,f0,df0,0);
    double HDownfall = impulseDownfall(H, f0, df0, 0);
    double numOfImp;
    double hight;

    QPen impulsPen(Qt::red);
    impulsPen.setWidth(2);

    QPen impulsPen2(Qt:: blue);
    impulsPen2.setWidth(2);

    do
    {
        HUprise = impulseUprise(H,f0,df0,k);
        HDownfall = impulseDownfall(H, f0, df0, k);
        //double hight = (k - (k - floor(k/10))) * 0.1 + random();
        hight = 1+ (k - floor(k/10)*10) * 0.1;

        for(int i=0; i<10; i++)
        {
            HUp[i] = HUprise;
            HDo[i] = HDownfall;
            y[i] = 0+i*(hight/10);
            Hy[i] = hight - (hight/10);
            Hx[i] = HUprise + i*(HDownfall - HUprise)/10;
        }

        Hy[10] = hight - (hight/10);
        Hx[10] = HUprise + 10*(HDownfall - HUprise)/10;

        QwtPlotCurve *impuls = new QwtPlotCurve("impuls");
        impuls->setSamples(HUp,y,10);
        impuls->setPen(impulsPen);
        impuls->attach(ui->qwtPlot);

        QwtPlotCurve *impuls2 = new QwtPlotCurve("impuls");
        impuls2->setSamples(HDo,y,10);
        impuls2->setPen(impulsPen2);
        impuls2->attach(ui->qwtPlot);

        QwtPlotCurve *impuls3 = new QwtPlotCurve("impuls");
        impuls3->setSamples(Hx,Hy,11);
        impuls3->setPen(impulsPen);
        impuls3->attach(ui->qwtPlot);

        k++;
    } while(HUprise < stop);

    numOfImp = numOfImpulses(H, f0,df0);
    ui->impulsesForH->setText(QString::number(numOfImp));

    ui->qwtPlot->replot();

    double m = 10000;
    double sampleY[int(m)];
    double sampleX[int(m)];
    double step;
    step = range/m;

    for(int i=0; i<m; i++)
    {
        sampleX[i] = start + i*step;
        sampleY[i] = numOfImpulses(sampleX[i], f0, df0);
    }

    maxImp = sampleY[0];

    for(int i=1; i<m; i++)
    {
        if(sampleY[i] > sampleY[i-1])
            maxImp = sampleY[i];
    }


    qDebug() << maxImp;

    QwtPlotCurve *impuls_2 = new QwtPlotCurve("impuls");
    impuls_2->setSamples(sampleX,sampleY,m);
    impuls_2->setPen(impulsPen);
    impuls_2->attach(ui->qwtPlot_2);

    ui->qwtPlot_2->replot();
}

void Impuls::plot()
{
    double H = ui->HdoubleSpinBox->value();
    double range = 2;

    ui->qwtPlot->setCanvasBackground(Qt::white);
    grid = new QwtPlotGrid();
    grid->enableX(true);
    grid->enableY(true);
    grid->enableXMin(true);
    grid->enableYMin(true);
    grid->setMajPen(QPen(Qt::gray, 1, Qt::DotLine));
    grid->setMinPen(QPen(Qt::lightGray, 1, Qt::DotLine));
    grid->attach(ui->qwtPlot);

    ui->qwtPlot->setAxisScale(QwtPlot::xBottom, H - range/2, H + range/2,range/10);
    ui->qwtPlot->setAxisAutoScale(QwtPlot::yLeft, true);
    ui->qwtPlot->enableAxis(QwtPlot::yLeft,true);
    ui->qwtPlot->setAxisTitle(QwtPlot::yLeft,"Imp");
    ui->qwtPlot->setAxisTitle(QwtPlot::xBottom,"H [m]");

    ui->qwtPlot->replot();

    ui->qwtPlot_2->setCanvasBackground(Qt::white);
    grid_2 = new QwtPlotGrid();
    grid_2->enableX(true);
    grid_2->enableY(true);
    grid_2->enableXMin(true);
    grid_2->enableYMin(true);
    grid_2->setMajPen(QPen(Qt::gray, 1, Qt::DotLine));
    grid_2->setMinPen(QPen(Qt::lightGray, 1, Qt::DotLine));
    grid_2->attach(ui->qwtPlot_2);

    ui->qwtPlot_2->setAxisScale(QwtPlot::xBottom, H - range/2, H + range/2,range/10);
    ui->qwtPlot_2->setAxisScale(QwtPlot::yLeft,0,maxImp,maxImp/4);
    //ui->qwtPlot_2->setAxisTitle(QwtPlot::xBottom,"H [m]");
    ui->qwtPlot_2->setAxisTitle(QwtPlot::yLeft,"N");

    ui->qwtPlot_2->replot();
}
