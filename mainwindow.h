#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <qwt_polar.h>
#include <qwt_legend.h>
#include <qwt_polar_grid.h>
#include <qwt_polar_curve.h>
#include <qwt_polar_marker.h>
#include <qwt_scale_engine.h>
#include "phase.h"
#include "twochannelaltimeter.h"
#include "impuls.h"
#include "doppler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    Phase *phaseWidget;
    TwoChannelAltimeter *twochannelaltimeterWidget;
    Impuls *impulsWidget;
    Doppler *dopplerWidget;

    QAction *phase;
    QAction *twochannel;
    QAction *impuls;
    QAction *doppler;

private slots:
    void showPhase();
    void showTwoChannelAltimeter();
    void showImpuls();
    void showDoppler();

};

#endif // MAINWINDOW_H
