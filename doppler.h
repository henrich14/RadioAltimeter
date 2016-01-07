#ifndef DOPPLER_H
#define DOPPLER_H

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
class Doppler;
}

class Doppler : public QWidget
{
    Q_OBJECT
    
public:
    explicit Doppler(QWidget *parent = 0);
    ~Doppler();
    
private:
    Ui::Doppler *ui;

    QwtPlotCurve *signal;
    QwtPlotCurve *dopplerPlus;
    QwtPlotCurve *dopplerMinus;
    QwtPlotCurve *doppleractual;
    QwtPlotGrid *grid;
    QwtPlotGrid *grid2;
    QwtPlotGrid *grid3;
    QwtPlotGrid *grid4;
    QwtLegend *legend;
    QwtLegend *legend2;
    QwtLegend *legend3;

private slots:
    void execute_clicked();
};

#endif // DOPPLER_H
