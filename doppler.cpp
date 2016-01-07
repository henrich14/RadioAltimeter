#include "doppler.h"
#include "ui_doppler.h"

const double pi = 3.14159265358979;
const int numPoints = 2;
const double c = 3e8;

Doppler::Doppler(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Doppler)
{
    ui->setupUi(this);

    ui->HdoubleSpinBox->setDecimals(6);
    ui->HdoubleSpinBox->setValue(5.1);
    ui->HdoubleSpinBox->setSingleStep(0.1);
    ui->VlineEdit->setText(QString::number(10));

    ui->f0LineEdit->setText(QString::number(4.4e9));
    ui->fmLineEdit->setText(QString::number(150));
    ui->df0LineEdit->setText(QString::number(50e6));

    ui->qwtPlot->setCanvasBackground(Qt::white);
    ui->qwtPlot_2->setCanvasBackground(Qt::white);
    ui->qwtPlot_3->setCanvasBackground(Qt::white);
    ui->qwtPlot_4->setCanvasBackground(Qt::white);

    execute_clicked();

    connect(ui->HdoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(execute_clicked()));
    connect(ui->execute, SIGNAL(clicked()), this, SLOT(execute_clicked()));
}

Doppler::~Doppler()
{
    delete ui;
}

void Doppler::execute_clicked()
{
    ui->qwtPlot->detachItems(QwtPlotItem::Rtti_PlotItem, false);
    ui->qwtPlot_2->detachItems(QwtPlotItem::Rtti_PlotItem, false);
    ui->qwtPlot_3->detachItems(QwtPlotItem::Rtti_PlotItem, false);
    ui->qwtPlot_4->detachItems(QwtPlotItem::Rtti_PlotItem, false);

    double f0 = ui->f0LineEdit->text().toDouble();
    double fm = ui->fmLineEdit->text().toDouble();
    double df0 = ui->df0LineEdit->text().toDouble();
    double H = ui->HdoubleSpinBox->value();
    double v = ui->VlineEdit->text().toDouble();

    double df0PD = df0 + (f0*2*v)/c;
    double df0MD = df0 - (f0*2*v)/c;
    qDebug() << "df0PD = " << df0PD << "df0MD = " << df0MD;

    QPen impulsPen(Qt::black);
    impulsPen.setWidth(2);

    //double Fr = (8*df0*fm*H)/c;
    //double FrDP = Fr + (f0*2*v)/c;
    //double FrDM = Fr - (f0*2*v)/c;
    double TM = (1/fm);

    double step = 0.000001;
    double min = 0;
    double max = TM/2;
    int range = (max-min)/step;

    int NumOfImuls1 = 0;
    int NumOfImuls2 = 0;
    int NumOfImuls3 = 0;
    int NumOfImuls4 = 0;

    double lambda0 = c/f0;
    double dzeta = df0/f0;

    double dzetaPD = (df0PD)/f0;
    double dzetaMD = (df0MD)/f0;

    double omegaM = 2*pi*fm;
    double omegaMDP = 2*pi*(fm + (f0*2*v)/c);
    double omegaMDM = 2*pi*(fm - (f0*2*v)/c);

    double tau = (2*H)/c;
    double fi0 = (4*pi*H)/lambda0;
    double fim = (4*pi*H*dzeta)/lambda0;

    double fimPD = (4*pi*H*dzetaPD)/lambda0;
    double fimMD = (4*pi*H*dzetaMD)/lambda0;

    int range1 = range*2;

    double t[range];
    double t11[range1];
    double u1[range1];
    double t1[range1];

    for(int i=0; i<(range1); i++)
    {
        t11[i] = min + i*step;
        t1[i] = t11[i] - tau/2;
        u1[i] = cos(fi0+(fim*(cos(omegaM*t1[i]))));

        //t[i] = min + i*step;
        //u1[i] = -1 * sin(2*pi*Fr*t[i]);

        if(u1[i]>0 && u1[i-1]<0)
        {
            NumOfImuls1++;
            double tt[10];
            double yy[10];
            for(int j=0; j<10; j++)
                tt[j] = t11[i-1];
            for(int j=0; j<10; j++)
                yy[j] = 0 + j*(0.5/10);
            QwtPlotCurve *impuls = new QwtPlotCurve("impuls");
            impuls->setSamples(tt,yy,10);
            impuls->setPen(impulsPen);
            impuls->attach(ui->qwtPlot);
        }
    }

    double u2[range];
    double t2[range];

    for(int i=0; i<range; i++)
    {
        t[i] = min + i*step;
        t2[i] = t[i] - tau/2;
        u2[i] = cos(fi0+(fimMD*(cos(omegaM*t2[i]))));

        //t[i] = min + i*step;
        //u2[i] = -1 * sin(2*pi*FrDP*t[i]);

        if(u2[i]>0 && u2[i-1]<0)
        {
            NumOfImuls2++;
            double tt2[10];
            double yy2[10];
            for(int j=0; j<10; j++)
                tt2[j] = t[i-1];
            for(int j=0; j<10; j++)
                yy2[j] = 0 + j*(0.5/10);
            QwtPlotCurve *impuls = new QwtPlotCurve("impuls");
            impuls->setSamples(tt2,yy2,10);
            impuls->setPen(impulsPen);
            impuls->attach(ui->qwtPlot_2);
        }
    }

    double u3[range];
    double t3[range];

    for(int i=0; i<range; i++)
    {
        t[i] = min + i*step;
        t3[i] = t[i] - tau/2;
        u3[i] = cos(fi0+(fimPD*(cos(omegaM*t3[i]))));

        //t[i] = min + i*step;
        //u3[i] = -1 * sin(2*pi*FrDM*t[i]);

        if(u3[i]>0 && u3[i-1]<0)
        {
            NumOfImuls3++;
            double tt3[10];
            double yy3[10];
            for(int j=0; j<10; j++)
                tt3[j] = t[i-1];
            for(int j=0; j<10; j++)
                yy3[j] = 0 + j*(0.5/10);
            QwtPlotCurve *impuls = new QwtPlotCurve("impuls");
            impuls->setSamples(tt3,yy3,10);
            impuls->setPen(impulsPen);
            impuls->attach(ui->qwtPlot_3);
        }
    }

    max = TM;
    int range4 = range*2;

    double u4[range4];
    double t4[range4];


    for(int i=0; i<range; i++)
    {
        t4[i] = min + i*step;
        u4[i] = u2[i];
    }

    for(int i=range; i<range4; i++)
    {
        t4[i] = min + i*step;
        u4[i] = u3[i-range];
    }


    for(int i=0; i<range4; i++)
    {
        if(u4[i]>0 && u4[i-1]<0)
        {
            NumOfImuls4++;
            double tt4[10];
            double yy4[10];
            for(int j=0; j<10; j++)
                tt4[j] = t4[i-1];
            for(int j=0; j<10; j++)
                yy4[j] = 0 + j*(0.5/10);
            QwtPlotCurve *impuls = new QwtPlotCurve("impuls");
            impuls->setSamples(tt4,yy4,10);
            impuls->setPen(impulsPen);
            impuls->attach(ui->qwtPlot_4);
        }
    }

    ui->NoI1_lineEdit->setText(QString::number(NumOfImuls1));
    ui->NoI2_lineEdit->setText(QString::number(NumOfImuls2));
    ui->NoI3_lineEdit->setText(QString::number(NumOfImuls3));
    ui->NoI4_lineEdit->setText(QString::number(NumOfImuls4));

    QPen S1Pen(Qt::red);
    S1Pen.setWidth(2);

    signal = new QwtPlotCurve("signal");
    signal->setPen(S1Pen);
    signal->setSamples(t11,u1,range1);
    signal->attach(ui->qwtPlot);

    dopplerPlus = new QwtPlotCurve("dopplerPlus");
    dopplerPlus->setPen(S1Pen);
    dopplerPlus->setSamples(t,u2,range);
    dopplerPlus->attach(ui->qwtPlot_2);

    dopplerMinus = new QwtPlotCurve("dopplerMinus");
    dopplerMinus->setPen(S1Pen);
    dopplerMinus->setSamples(t,u3,range);
    dopplerMinus->attach(ui->qwtPlot_3);

    doppleractual = new QwtPlotCurve("doppleractual");
    doppleractual->setPen(S1Pen);
    doppleractual->setSamples(t4,u4,range4);
    doppleractual->attach(ui->qwtPlot_4);

    grid = new QwtPlotGrid();
    grid->enableX(true);
    grid->enableY(true);
    grid->enableXMin(true);
    grid->enableYMin(true);
    grid->setMajPen(QPen(Qt::black, 1, Qt::DotLine));
    grid->setMinPen(QPen(Qt::gray, 1, Qt::DotLine));
    grid->attach(ui->qwtPlot);

    grid2 = new QwtPlotGrid();
    grid2->enableX(true);
    grid2->enableY(true);
    grid2->enableXMin(true);
    grid2->enableYMin(true);
    grid2->setMajPen(QPen(Qt::black, 1, Qt::DotLine));
    grid2->setMinPen(QPen(Qt::gray, 1, Qt::DotLine));
    grid2->attach(ui->qwtPlot_2);

    grid3 = new QwtPlotGrid();
    grid3->enableX(true);
    grid3->enableY(true);
    grid3->enableXMin(true);
    grid3->enableYMin(true);
    grid3->setMajPen(QPen(Qt::black, 1, Qt::DotLine));
    grid3->setMinPen(QPen(Qt::gray, 1, Qt::DotLine));
    grid3->attach(ui->qwtPlot_3);

    grid4 = new QwtPlotGrid();
    grid4->enableX(true);
    grid4->enableY(true);
    grid4->enableXMin(true);
    grid4->enableYMin(true);
    grid4->setMajPen(QPen(Qt::black, 1, Qt::DotLine));
    grid4->setMinPen(QPen(Qt::gray, 1, Qt::DotLine));
    grid4->attach(ui->qwtPlot_4);

    ui->qwtPlot->setTitle("Doppler frequency change");

    ui->qwtPlot->setAxisAutoScale(QwtPlot::xBottom,true);
    ui->qwtPlot_2->setAxisAutoScale(QwtPlot::xBottom,true);
    ui->qwtPlot_3->setAxisAutoScale(QwtPlot::xBottom,true);
    ui->qwtPlot_4->setAxisAutoScale(QwtPlot::xBottom,true);

    //ui->qwtPlot->setAxisTitle(QwtPlot::xBottom,"t [s]");
    ui->qwtPlot->setAxisTitle(QwtPlot::yLeft,"U [V]");

    //ui->qwtPlot_2->setAxisTitle(QwtPlot::xBottom,"t [s]");
    ui->qwtPlot_2->setAxisTitle(QwtPlot::yLeft,"U [V]");

    //ui->qwtPlot_3->setAxisTitle(QwtPlot::xBottom,"t [s]");
    ui->qwtPlot_3->setAxisTitle(QwtPlot::yLeft,"U [V]");

    ui->qwtPlot_4->setAxisTitle(QwtPlot::xBottom,"t [s]");
    ui->qwtPlot_4->setAxisTitle(QwtPlot::yLeft,"U [V]");

    ui->qwtPlot->replot();
    ui->qwtPlot_2->replot();
    ui->qwtPlot_3->replot();
    ui->qwtPlot_4->replot();
    ui->qwtPlot_4->replot();

    /*
    double lambda0 = c/f0;
    double dzeta = df0/f0;
    double omegaM = 2*pi*fm;

    double H = ui->HdoubleSpinBox->value();
    double tau1 = (2*H)/c;
    double fi01 = (4*pi*H)/lambda0;
    double fim1 = (4*pi*H*dzeta)/lambda0;

    double TM = (1/fm)/2;

    double step = 0.00001;
    double min = 0;
    double max = TM;
    int range = (max-min)/step;
    double t[range];
    double u1[range];
    double t1[range];

    for(int i=0; i<range; i++)
    {
        t[i] = min + i*step;
        t1[i] = t[i] - tau1/2;
        u1[i] = cos(fi01+(fim1*(cos(omegaM*t1[i]))));
    }

    QPen S1Pen(Qt::red);
    S1Pen.setWidth(2);

    signal = new QwtPlotCurve("signal");
    signal->setPen(S1Pen);
    signal->setSamples(t,u1,range);
    signal->attach(ui->qwtPlot);

    ui->qwtPlot->replot();

    double v = ui->VlineEdit->text().toDouble();

    fm = fm + (f0*2*v)/c;
    omegaM = 2*pi*fm;

    double tau2 = (2*H)/c;
    double fi02 = (4*pi*H)/lambda0;
    double fim2 = (4*pi*H*dzeta)/lambda0;

    double u2[range];
    double t2[range];

    for(int i=0; i<range; i++)
    {
        t[i] = min + i*step;
        t2[i] = t[i] - tau2/2;
        u2[i] = cos(fi02+(fim2*(cos(omegaM*t2[i]))));
    }

    dopplerPlus = new QwtPlotCurve("Plus Doppler frequency");
    dopplerPlus->setPen(S1Pen);
    dopplerPlus->setSamples(t,u2,range);
    dopplerPlus->attach(ui->qwtPlot_2);

    ui->qwtPlot_2->replot();

    */





}
