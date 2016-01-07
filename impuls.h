#ifndef IMPULS_H
#define IMPULS_H

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
class Impuls;
}

class Impuls : public QWidget
{
    Q_OBJECT
    
public:
    explicit Impuls(QWidget *parent = 0);
    ~Impuls();

    double impulseUprise(double H, double f0, double df0, double k);
    double impulseDownfall(double H, double f0, double df0, double k);
    double numOfImpulses(double H, double f0, double df0);

    double random();
    
private:
    Ui::Impuls *ui;
    QwtPlotGrid *grid;
    QwtPlotGrid *grid_2;
    double maxImp;

private slots:
    void execute_clicked();
    void plot();
};

#endif // IMPULS_H
