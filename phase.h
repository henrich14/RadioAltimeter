#ifndef PHASE_H
#define PHASE_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <qwt_polar.h>
#include <qwt_legend.h>
#include <qwt_symbol.h>
#include <qwt_polar_grid.h>
#include <qwt_polar_curve.h>
#include <qwt_polar_marker.h>
#include <qwt_scale_engine.h>

namespace Ui {
class Phase;
}

class Phase : public QWidget
{
    Q_OBJECT
    
public:
    explicit Phase(QWidget *parent = 0);
    ~Phase();

    double countPhase0(double H, double f0);
    double countPhaseM(double H, double f0, double df0);
    
private:
    Ui::Phase *ui;

    QwtPolarCurve *a_curve;
    QwtPolarCurve *d_curve;
    QwtPolarCurve *c_curve;
    QwtPolarCurve *e_curve;
    QwtPolarCurve *f_curve;
    QwtPolarCurve *g_curve;
    QwtPolarGrid *d_grid;

private slots:
    void drawPhase();
};

#endif // PHASE_H
