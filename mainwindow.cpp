#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showMaximized();

    phaseWidget = new Phase(this);
    //twochannelaltimeterWidget = new TwoChannelAltimeter(this);

    setCentralWidget(phaseWidget);

    phase = new QAction(tr("Phase"), this);
    phase->setToolTip("show phase");
    phase->setStatusTip("show phase");
    phase->setShortcut(tr("Alt+P"));
    connect(phase, SIGNAL(triggered()), this, SLOT(showPhase()));

    twochannel = new QAction(tr("Two channel altimeter"), this);
    twochannel->setToolTip("show tho channel altimeter");
    twochannel->setStatusTip("show two channel altimeter");
    twochannel->setShortcut(tr("Alt+T"));
    connect(twochannel, SIGNAL(triggered()), this, SLOT(showTwoChannelAltimeter()));

    impuls = new QAction(tr("Impulses"), this);
    impuls->setToolTip("Making of impulses");
    impuls->setStatusTip("Making of impulses");
    impuls->setShortcut(tr("Alt+I"));
    connect(impuls, SIGNAL(triggered()), this, SLOT(showImpuls()));

    doppler = new QAction(tr("Doppler"),this);
    doppler->setToolTip("Doppler frequency");
    doppler->setStatusTip("Doppler frequency");
    doppler->setShortcut(tr("Alt+D"));
    connect(doppler, SIGNAL(triggered()), this, SLOT(showDoppler()));

    ui->mainToolBar->addAction(phase);
    ui->mainToolBar->addAction(twochannel);
    ui->mainToolBar->addAction(impuls);
    ui->mainToolBar->addAction(doppler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showPhase()
{
    phaseWidget = new Phase(this);
    setCentralWidget(phaseWidget);
}

void MainWindow::showTwoChannelAltimeter()
{
    twochannelaltimeterWidget = new TwoChannelAltimeter(this);
    setCentralWidget(twochannelaltimeterWidget);
}

void MainWindow::showImpuls()
{
    impulsWidget = new Impuls(this);
    setCentralWidget(impulsWidget);
}

void MainWindow::showDoppler()
{
    dopplerWidget = new Doppler(this);
    setCentralWidget(dopplerWidget);
}
