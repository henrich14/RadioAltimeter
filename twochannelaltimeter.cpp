#include "twochannelaltimeter.h"
#include "ui_twochannelaltimeter.h"

const double pi = 3.14159265358979;
const int numPoints = 2;
const double c = 3e8;

TwoChannelAltimeter::TwoChannelAltimeter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TwoChannelAltimeter)
{
    ui->setupUi(this);

    ui->HdoubleSpinBox->setDecimals(6);
    ui->HdoubleSpinBox->setValue(5.1);
    ui->HdoubleSpinBox->setSingleStep(0.1);

    ui->f0LineEdit->setText(QString::number(4.4e9));
    ui->fmLineEdit->setText(QString::number(150));
    ui->df0LineEdit->setText(QString::number(50e6));

    ui->qwtPlot->setCanvasBackground(Qt::white);
    ui->qwtPlot_2->setCanvasBackground(Qt::white);
    ui->qwtPlot_3->setCanvasBackground(Qt::white);

    drawDiffFreq();

    connect(ui->HdoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(drawDiffFreq()));
    connect(ui->execute, SIGNAL(clicked()), this, SLOT(drawDiffFreq()));
}

TwoChannelAltimeter::~TwoChannelAltimeter()
{
    delete ui;
}

void TwoChannelAltimeter::drawDiffFreq()
{
    ui->qwtPlot->detachItems(QwtPlotItem::Rtti_PlotItem, false);
    ui->qwtPlot_2->detachItems(QwtPlotItem::Rtti_PlotItem, false);
    ui->qwtPlot_3->detachItems(QwtPlotItem::Rtti_PlotItem, false);

    double f0 = ui->f0LineEdit->text().toDouble();
    double fm = ui->fmLineEdit->text().toDouble();
    double df0 = ui->df0LineEdit->text().toDouble();

    double lambda0 = c/f0;
    double dzeta = df0/f0;
    double omegaM = 2*pi*fm;

    double H = ui->HdoubleSpinBox->value();
    double tau1 = (2*H)/c;
    double fi01 = (4*pi*H)/lambda0;
    double fim1 = (4*pi*H*dzeta)/lambda0;

    double step = 0.00001;
    double min = 0;
    double max = 0.01;
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

    QPen impulsPen(Qt::black);
    impulsPen.setWidth(2);

    for(int i=0; i<range; i++)
    {
        t[i] = min + i*step;
        t1[i] = t[i] - tau1/2;
        u1[i] = cos(fi01+(fim1*(cos(omegaM*t1[i]))));

        if(u1[i]>0 && u1[i-1]<0)
        {
            qDebug() << t[i-1];
            double tt[10];
            double yy[10];
            for(int j=0; j<10; j++)
                tt[j] = t[i-1];
            for(int j=0; j<10; j++)
                yy[j] = 0 + j*(0.5/10);
            QwtPlotCurve *impuls = new QwtPlotCurve("impuls");
            impuls->setSamples(tt,yy,10);
            impuls->setPen(impulsPen);
            impuls->attach(ui->qwtPlot);
        }
    }

    double tau2 = (8*H-lambda0)/(4*c);
    double fi02 = (4*pi*H)/lambda0 + pi/2;
    double fim2 = (4*pi*H*dzeta)/lambda0 + pi*dzeta/2;
    double u2[range];
    double t2[range];

    for(int i=0; i<range; i++)
    {
        t[i] = min + i*step;
        t2[i] = t[i] - tau2/2;
        u2[i] = cos(fi02+(fim2*(cos(omegaM*t2[i]))));

        if(u2[i]>0 && u2[i-1]<0)
        {
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

    QPen ch1Pen(Qt::red);
    ch1Pen.setWidth(2);

    QPen ch2Pen(Qt::green);
    ch2Pen.setWidth(2);

    firstChannel = new QwtPlotCurve("1. channel");
    firstChannel->setTitle("1. channel");
    firstChannel->setPen(ch1Pen);
    firstChannel->setSamples(t,u1,range);
    firstChannel->attach(ui->qwtPlot);

    secondChannel = new QwtPlotCurve("2. channel");
    secondChannel->setTitle("2. channel");
    secondChannel->setPen(ch2Pen);
    secondChannel->setSamples(t,u2,range);
    secondChannel->attach(ui->qwtPlot_2);

    firstChannel_2 = new QwtPlotCurve("1. channel");
    firstChannel_2->setTitle("1. channel");
    firstChannel_2->setPen(ch1Pen);
    firstChannel_2->setSamples(t,u1,range);
    firstChannel_2->attach(ui->qwtPlot_3);

    secondChannel_2 = new QwtPlotCurve("2. channel");
    secondChannel_2->setTitle("2. channel");
    secondChannel_2->setPen(ch2Pen);
    secondChannel_2->setSamples(t,u2,range);
    secondChannel_2->attach(ui->qwtPlot_3);

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

    //legend = new QwtLegend();
    //ui->qwtPlot->insertLegend(legend, QwtPlot::BottomLegend);
    //legend2 = new QwtLegend();
    //ui->qwtPlot_2->insertLegend(legend2, QwtPlot::BottomLegend);
    legend3 = new QwtLegend();
    ui->qwtPlot_3->insertLegend(legend3, QwtPlot::BottomLegend);

    ui->qwtPlot->setTitle("Diff frequency of 1. channel and 2. channel");

    ui->qwtPlot->setAxisTitle(QwtPlot::xBottom,"t [s]");
    ui->qwtPlot->setAxisTitle(QwtPlot::yLeft,"U [V]");

    ui->qwtPlot_2->setAxisTitle(QwtPlot::xBottom,"t [s]");
    ui->qwtPlot_2->setAxisTitle(QwtPlot::yLeft,"U [V]");

    ui->qwtPlot_3->setAxisTitle(QwtPlot::xBottom,"t [s]");
    ui->qwtPlot_3->setAxisTitle(QwtPlot::yLeft,"U [V]");


    ui->qwtPlot->replot();
    ui->qwtPlot_2->replot();
    ui->qwtPlot_3->replot();
}
