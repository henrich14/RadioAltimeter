#ifndef TWOCHANNELALTIMETER_H
#define TWOCHANNELALTIMETER_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <qwt_plot.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_curve.h>
#include <qwt_legend.h>
#include <qwt_plot_grid.h>
#include <muParser.h>

namespace Ui {
class TwoChannelAltimeter;
}

class TwoChannelAltimeter : public QWidget
{
    Q_OBJECT
    
public:
    explicit TwoChannelAltimeter(QWidget *parent = 0);
    ~TwoChannelAltimeter();
    
private:
    Ui::TwoChannelAltimeter *ui;

    QwtPlotCurve *firstChannel;
    QwtPlotCurve *secondChannel;
    QwtPlotCurve *firstChannel_2;
    QwtPlotCurve *secondChannel_2;
    QwtPlotGrid *grid;
    QwtPlotGrid *grid2;
    QwtPlotGrid *grid3;
    QwtLegend *legend;
    QwtLegend *legend2;
    QwtLegend *legend3;


private slots:
    void drawDiffFreq();


};

#endif // TWOCHANNELALTIMETER_H
