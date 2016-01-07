#include "phase.h"
#include "ui_phase.h"

const QwtInterval radialInterval( 0.0, 1.0 );
const QwtInterval radial1Interval(0.0, 0.4);
const QwtInterval radial2Interval (0.8, 0.95);
const QwtInterval radial3Interval (0.7, 0.85);
const QwtInterval azimuthInterval( 0.0, 360.0 );
const double pi = 3.14159265358979;
const int numPoints = 2;
const double c = 3e8;


class Data: public QwtSeriesData<QwtPointPolar>
{
public:
    Data( const QwtInterval &radialInterval,
          const QwtInterval &azimuthInterval, size_t size, double ang ):
        d_radialInterval( radialInterval ),
        d_azimuthInterval( azimuthInterval ),
        d_size( size ),
        d_angle( ang )
    {
    }

    virtual size_t size() const
    {
        return d_size;
    }

protected:
    QwtInterval d_radialInterval;
    QwtInterval d_azimuthInterval;
    size_t d_size;
    double d_angle;
};

class PhaseData: public Data
{
public:
    PhaseData( const QwtInterval &radialInterval,
            const QwtInterval &azimuthInterval, size_t size, double ang):
        Data( radialInterval, azimuthInterval, size, ang )
    {
    }

    virtual QwtPointPolar sample( size_t i ) const
    {
        //const double stepA = 4 * d_azimuthInterval.width() / d_size;
        //qDebug() << d_azimuthInterval.minValue();
        //qDebug() << d_size;
        //const double a = d_azimuthInterval.minValue() + i * stepA;
        const double a = d_angle;

        const double stepR = 2*d_radialInterval.width() / d_size;
        const double r = d_radialInterval.minValue() + i * stepR;

        return QwtPointPolar( a, r );
        //return QwtPointPolar();
    }

    virtual QRectF boundingRect() const
    {
        if ( d_boundingRect.width() < 0.0 )
            d_boundingRect = qwtBoundingRect( *this );

        return d_boundingRect;
    }
};

class SpiralData: public Data
{
public:
    SpiralData( const QwtInterval &radialInterval,
            const QwtInterval &azimuthInterval, size_t size, double ang):
        Data( radialInterval, azimuthInterval, size, ang )
    {
    }

    virtual QwtPointPolar sample( size_t i ) const
    {
        const double stepA = d_azimuthInterval.width() / (d_size-1);
        const double a = d_azimuthInterval.minValue() + i * stepA;          //uhol

        const double stepR = d_radialInterval.width() / d_size;             //velkost
        const double r = d_radialInterval.minValue() + i * stepR;

        return QwtPointPolar( a, r );
    }

    virtual QRectF boundingRect() const
    {
        if ( d_boundingRect.width() < 0.0 )
            d_boundingRect = qwtBoundingRect( *this );

        return d_boundingRect;
    }
};

class SpiralData2: public Data
{
public:
    SpiralData2( const QwtInterval &radialInterval,
            const QwtInterval &azimuthInterval, size_t size, double ang):
        Data( radialInterval, azimuthInterval, size, ang )
    {
    }

    virtual QwtPointPolar sample( size_t i ) const
    {
        const double stepA = d_azimuthInterval.width() / (d_size-1);
        const double a = d_azimuthInterval.minValue() + i * stepA;          //uhol

        const double stepR = d_radialInterval.width() / d_size;             //velkost
        const double r = d_radialInterval.minValue() - i * stepR;

        return QwtPointPolar( a, r );
    }

    virtual QRectF boundingRect() const
    {
        if ( d_boundingRect.width() < 0.0 )
            d_boundingRect = qwtBoundingRect( *this );

        return d_boundingRect;
    }
};

Phase::Phase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Phase)
{
    ui->setupUi(this);
    ui->HdoubleSpinBox->setDecimals(6);
    ui->HdoubleSpinBox->setValue(0.2644);

    connect(ui->HdoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(drawPhase()));
    connect(ui->execute, SIGNAL(clicked()), this, SLOT(drawPhase()));

    ui->f0LineEdit->setText(QString::number(4.4e9));
    ui->fmLineEdit->setText(QString::number(150));
    ui->df0LineEdit->setText(QString::number(50e6));

    double f0 = ui->f0LineEdit->text().toDouble();
    double fm = ui->fmLineEdit->text().toDouble();
    double df0 = ui->df0LineEdit->text().toDouble();


    ui->qwtPolarPlot->setPlotBackground( Qt::white );

    // markers
    QwtPolarMarker *marker1 = new QwtPolarMarker();
    marker1->setSymbol( new QwtSymbol( QwtSymbol::Triangle, QBrush( Qt::red ), QPen( Qt::white ), QSize( 8, 8 ) ) );
    marker1->setLabelAlignment( Qt::AlignHCenter | Qt::AlignTop );

    //QwtText text( "Marker" );
    //text.setColor( Qt::black );
    //QColor bg( Qt::white );
    //bg.setAlpha( 200 );
    //text.setBackgroundBrush( QBrush( bg ) );

    //marker->setLabel( text );
    marker1->attach(ui->qwtPolarPlot);

    QwtPolarMarker *marker11= new QwtPolarMarker();
    marker11->setSymbol( new QwtSymbol( QwtSymbol::Ellipse, QBrush( Qt::red ), QPen( Qt::white ), QSize( 7, 7 ) ) );
    marker11->setLabelAlignment( Qt::AlignHCenter | Qt::AlignTop );
    marker11->attach(ui->qwtPolarPlot);

    QwtPolarMarker *marker2= new QwtPolarMarker();
    marker2->setSymbol( new QwtSymbol( QwtSymbol::Triangle, QBrush( Qt::darkGreen ), QPen( Qt::white ), QSize( 8, 8 ) ) );
    marker2->setLabelAlignment( Qt::AlignHCenter | Qt::AlignTop );
    marker2->attach(ui->qwtPolarPlot);

    QwtPolarMarker *marker22= new QwtPolarMarker();
    marker22->setSymbol( new QwtSymbol( QwtSymbol::Ellipse, QBrush( Qt::darkGreen ), QPen( Qt::white ), QSize( 7, 7 ) ) );
    marker22->setLabelAlignment( Qt::AlignHCenter | Qt::AlignTop );
    marker22->attach(ui->qwtPolarPlot);

    QwtPolarMarker *marker3= new QwtPolarMarker();
    marker3->setSymbol( new QwtSymbol( QwtSymbol::Triangle, QBrush( Qt::darkBlue ), QPen( Qt::white ), QSize( 8, 8 ) ) );
    marker3->setLabelAlignment( Qt::AlignHCenter | Qt::AlignTop );
    marker3->attach(ui->qwtPolarPlot);

    QwtPolarMarker *marker33= new QwtPolarMarker();
    marker33->setSymbol( new QwtSymbol( QwtSymbol::Ellipse, QBrush( Qt::darkBlue ), QPen( Qt::white ), QSize( 7, 7 ) ) );
    marker33->setLabelAlignment( Qt::AlignHCenter | Qt::AlignTop );
    marker33->attach(ui->qwtPolarPlot);

    d_curve = new QwtPolarCurve();
    c_curve = new QwtPolarCurve();
    e_curve = new QwtPolarCurve();

    double H = ui->HdoubleSpinBox->value();

    double angleF0 = countPhase0(H,f0);
    d_curve->setData( new PhaseData( radialInterval, azimuthInterval, numPoints, angleF0 ) );
    d_curve->setTitle(QString("fi0 = %1° (%2)").arg(QString::number(angleF0- floor(angleF0/360)*360)).arg(floor(angleF0/360)));

    double angleFm = countPhaseM(H,f0,df0);
    c_curve->setData( new PhaseData( radialInterval, azimuthInterval, numPoints, angleF0 + angleFm ) );
    c_curve->setTitle(QString("+fim = %1° (%2)").arg(QString::number((angleF0- floor(angleF0/360)*360) + angleFm)).arg("fi0+" + QString::number(angleFm) + "°"));

    e_curve->setData( new PhaseData( radialInterval, azimuthInterval, numPoints, angleF0 - angleFm ) );
    e_curve->setTitle(QString("-fim = %1° (%2)").arg(QString::number((angleF0- floor(angleF0/360)*360) - angleFm)).arg("fi0-" + QString::number(angleFm) + "°"));

    const QwtInterval azimuth2Interval(angleF0, angleF0+angleFm);
    const QwtInterval azimuth3Interval(angleF0-angleFm, angleF0);
    double F1 = (angleF0 - floor(angleF0/360)*360)+(qRound(H)*360);
    const QwtInterval azimuth1Interval(0, F1);

    f_curve = new QwtPolarCurve();
    f_curve->setData(new SpiralData( radial2Interval, azimuth2Interval, 400, angleF0 ) );
    f_curve->attach(ui->qwtPolarPlot);

    g_curve = new QwtPolarCurve();
    g_curve->setData(new SpiralData2( radial3Interval, azimuth3Interval, 400, angleF0 ) );
    g_curve->attach(ui->qwtPolarPlot);

    a_curve = new QwtPolarCurve();
    a_curve->setData(new SpiralData( radial1Interval, azimuth1Interval, 800, angleF0 ) );
    a_curve->attach(ui->qwtPolarPlot);

    marker1->setPosition(QwtPointPolar(angleF0+angleFm, radial2Interval.maxValue()));
    marker11->setPosition(QwtPointPolar(angleF0, radial2Interval.minValue()));
    marker2->setPosition(QwtPointPolar(angleF0-angleFm, radial3Interval.maxValue()-0.15));
    marker22->setPosition(QwtPointPolar(angleF0, radial3Interval.minValue()-0.15));
    marker3->setPosition(QwtPointPolar(angleF0, radial1Interval.maxValue()));
    marker33->setPosition(QwtPointPolar(angleF0, radial1Interval.minValue()));

    QPen spiral3Pen(Qt::darkBlue);
    spiral3Pen.setWidth(2);
    a_curve->setPen(spiral3Pen);


    QPen curve1Pen(Qt::darkBlue);
    curve1Pen.setWidth(3);
    d_curve->setPen(curve1Pen);

    QPen curve2Pen(Qt::red);
    curve2Pen.setWidth(3);
    curve2Pen.setStyle(Qt::DashDotLine);
    c_curve->setPen(curve2Pen);

    QPen curve3Pen(Qt::darkGreen);
    curve3Pen.setWidth(3);
    curve3Pen.setStyle(Qt::DashDotLine);

    QPen spiral1Pen(Qt::red);
    spiral1Pen.setWidth(2);
    f_curve->setPen(spiral1Pen);

    QPen spiral2Pen(Qt::darkGreen);
    spiral2Pen.setWidth(2);
    g_curve->setPen(spiral2Pen);

    e_curve->setPen(curve3Pen);

    d_curve->attach(ui->qwtPolarPlot);
    c_curve->attach(ui->qwtPolarPlot);
    e_curve->attach(ui->qwtPolarPlot);

    d_grid = new QwtPolarGrid();
    d_grid->setPen( QPen( Qt::black ) );

    QPen minorPen( Qt::gray );
    minorPen.setStyle( Qt::DotLine );
    d_grid->setMinorGridPen( minorPen );

    d_grid->showGrid(true);
    d_grid->showMinorGrid(true);

    d_grid->setAxisPen( QwtPolar::AxisAzimuth, QPen( Qt::black ) );
    d_grid->showAxis( QwtPolar::AxisAzimuth, true );
    d_grid->showAxis( QwtPolar::AxisLeft, true );
    d_grid->showAxis( QwtPolar::AxisRight, true );
    d_grid->showAxis( QwtPolar::AxisTop, true );
    d_grid->showAxis( QwtPolar::AxisBottom, true );
    d_grid->showGrid( QwtPolar::Azimuth, true );
    d_grid->showGrid( QwtPolar::Radius, true );

    d_grid->attach(ui->qwtPolarPlot);

    QwtLegend *legend = new QwtLegend;
    ui->qwtPolarPlot->insertLegend( legend,  QwtPolarPlot::BottomLegend );
}

Phase::~Phase()
{
    delete ui;
}

double Phase::countPhase0(double H, double f0)
{
    double lambda0 = c / f0;
    double fi0 = (4*pi*H) / lambda0;
    fi0 = (fi0/pi) *180;

    return fi0;
}

double Phase::countPhaseM(double H, double f0, double df0)
{
    double lambda0 = c / f0;
    double dzeta = df0 / f0;
    double fim = (4*pi*H*dzeta) / lambda0;
    fim = (fim/pi) *180;

    return fim;
}

void Phase::drawPhase()
{
    ui->qwtPolarPlot->detachItems(QwtPolarItem::Rtti_PolarItem, false);
    d_grid->attach(ui->qwtPolarPlot);

    double H = ui->HdoubleSpinBox->value();
    double f0 = ui->f0LineEdit->text().toDouble();
    //double fm = ui->fmLineEdit->text().toDouble();
    double df0 = ui->df0LineEdit->text().toDouble();

    double angleF0 = countPhase0(H,f0);
    d_curve->setData( new PhaseData( radialInterval, azimuthInterval, numPoints, angleF0 ) );
    d_curve->setTitle(QString("fi0 = %1° (%2)").arg(QString::number(angleF0- floor(angleF0/360)*360)).arg(floor(angleF0/360)));
    d_curve->attach(ui->qwtPolarPlot);
    qDebug() << "angle F0 = " << angleF0;

    double angleFm = countPhaseM(H,f0,df0);
    c_curve->setData( new PhaseData( radialInterval, azimuthInterval, numPoints, angleF0 + angleFm ) );
    c_curve->setTitle(QString("+fim = %1° (%2)").arg(QString::number((angleF0- floor(angleF0/360)*360) + angleFm)).arg("fi0+" + QString::number(angleFm) + "°"));
    c_curve->attach(ui->qwtPolarPlot);
    qDebug() << "angle Fm = " << angleFm;

    e_curve->setData( new PhaseData( radialInterval, azimuthInterval, numPoints, angleF0 - angleFm) );
    e_curve->setTitle(QString("-fim = %1° (%2)").arg(QString::number((angleF0- floor(angleF0/360)*360) - angleFm)).arg("fi0-" + QString::number(angleFm) + "°"));
    e_curve->attach(ui->qwtPolarPlot);

    const QwtInterval azimuth2Interval(angleF0, angleF0+angleFm);
    const QwtInterval azimuth3Interval(angleF0-angleFm, angleF0);

    double F1 = (angleF0 - floor(angleF0/360)*360)+(qRound(H)*360);
    const QwtInterval azimuth1Interval(0, F1);

    a_curve->setData(new SpiralData( radial1Interval, azimuth1Interval, 10000, angleF0 ));
    a_curve->attach(ui->qwtPolarPlot);

    f_curve->setData(new SpiralData( radial2Interval, azimuth2Interval, 400, angleF0 ));
    f_curve->attach(ui->qwtPolarPlot);
    g_curve->setData(new SpiralData2( radial3Interval, azimuth3Interval, 1000, angleF0 ));
    g_curve->attach(ui->qwtPolarPlot);
    qDebug() << angleF0;

    QwtPolarMarker *marker1 = new QwtPolarMarker();
    marker1->setSymbol( new QwtSymbol( QwtSymbol::Triangle, QBrush( Qt::red ), QPen( Qt::white ), QSize( 8, 8 ) ) );
    marker1->setLabelAlignment( Qt::AlignHCenter | Qt::AlignTop );
    marker1->setPosition(QwtPointPolar(angleF0+angleFm, radial2Interval.maxValue()));
    marker1->attach(ui->qwtPolarPlot);

    QwtPolarMarker *marker11= new QwtPolarMarker();
    marker11->setSymbol( new QwtSymbol( QwtSymbol::Ellipse, QBrush( Qt::red ), QPen( Qt::white ), QSize( 7, 7 ) ) );
    marker11->setLabelAlignment( Qt::AlignHCenter | Qt::AlignTop );
    marker11->setPosition(QwtPointPolar(angleF0, radial2Interval.minValue()));
    marker11->attach(ui->qwtPolarPlot);

    QwtPolarMarker *marker2= new QwtPolarMarker();
    marker2->setSymbol( new QwtSymbol( QwtSymbol::Triangle, QBrush( Qt::darkGreen ), QPen( Qt::white ), QSize( 8, 8 ) ) );
    marker2->setLabelAlignment( Qt::AlignHCenter | Qt::AlignTop );
    marker2->setPosition(QwtPointPolar(angleF0-angleFm, radial3Interval.maxValue()-0.15));
    marker2->attach(ui->qwtPolarPlot);

    QwtPolarMarker *marker22= new QwtPolarMarker();
    marker22->setSymbol( new QwtSymbol( QwtSymbol::Ellipse, QBrush( Qt::darkGreen ), QPen( Qt::white ), QSize( 7, 7 ) ) );
    marker22->setLabelAlignment( Qt::AlignHCenter | Qt::AlignTop );
    marker22->setPosition(QwtPointPolar(angleF0, radial3Interval.minValue()-0.15));
    marker22->attach(ui->qwtPolarPlot);

    QwtPolarMarker *marker3= new QwtPolarMarker();
    marker3->setSymbol( new QwtSymbol( QwtSymbol::Triangle, QBrush( Qt::darkBlue ), QPen( Qt::white ), QSize( 8, 8 ) ) );
    marker3->setLabelAlignment( Qt::AlignHCenter | Qt::AlignTop );
    marker3->setPosition(QwtPointPolar(angleF0, radial1Interval.maxValue()));
    marker3->attach(ui->qwtPolarPlot);

    QwtPolarMarker *marker33= new QwtPolarMarker();
    marker33->setSymbol( new QwtSymbol( QwtSymbol::Ellipse, QBrush( Qt::darkBlue ), QPen( Qt::white ), QSize( 7, 7 ) ) );
    marker33->setLabelAlignment( Qt::AlignHCenter | Qt::AlignTop );
    marker33->setPosition(QwtPointPolar(angleF0, radial1Interval.minValue()));
    marker33->attach(ui->qwtPolarPlot);

    ui->qwtPolarPlot->replot();
}
