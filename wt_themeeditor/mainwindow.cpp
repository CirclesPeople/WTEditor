#include "mainwindow.h"

#include <QDebug>

void MainWindow::sendSignal(){
    emit adbDeviceSig();
}

void MainWindow::init(){
    qDebug("MainWindow::init()");
    utilADB = new UtilADB();

    setFixedSize(800,600);
    QPalette mPalette = this->palette();
    mPalette.setBrush(QPalette::Background, Qt::white);
    setPalette(mPalette);

    /* create centralwidget */
    mWindowWidget = new QWidget(this);

    /* create horizontal layout */
    mLayout = new QHBoxLayout();

    //mLayout->addStretch();  /* add stretch */

    /* add pags module */
    pageStackedWidget = new PageModule();
    pageStackedWidget->autoFillBackground();
    pageLayout = new QHBoxLayout();
    pageLayout->addWidget(pageStackedWidget);

    /* add tab module */
    tabLayout = new TabModule(pageStackedWidget);

    /* add layout */
    mLayout->addLayout(tabLayout);
    mLayout->addLayout(pageLayout);
    mWindowWidget->setLayout(mLayout);
    setCentralWidget(mWindowWidget);

    /* add menu bar */
    mainMenuBar =new MainMenuBar(utilADB);
    setMenuBar(mainMenuBar);

    /* adb tools bar */
    mainToolsBar = new MainToolsBar();
    addToolBar(mainToolsBar);

    /* add status bar */
    mainStatusBar = new MainStatusBar();
    setStatusBar(mainStatusBar);

}

/* initialise connections. */
void MainWindow::initConnects(){
    connect(this, &MainWindow::adbDeviceSig,utilADB, &UtilADB::adbDevice);
    connect(utilADB,&UtilADB::adbProcInfo,this,&MainWindow::onADBProcInfo);
}

void MainWindow::onADBProcInfo(const QStringList outputList){
    QString deviceStr;
    int deviceCount = 0;
    foreach(QString tmp,outputList){
        if(tmp.endsWith("device",Qt::CaseSensitive)){
            deviceStr = tmp;
            deviceCount++;
        }
    }
    if(deviceCount > 1){
        mainStatusBar->statusLabel->setText("too more connections");
    }else if(deviceCount < 1){
        mainStatusBar->statusLabel->setText("no device is connected");
    }else if(deviceCount == 1){
        mainStatusBar->statusLabel->setText(deviceStr);
    }else{
        mainStatusBar->statusLabel->setText("unknow connection");
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    init();
    initConnects();
}

MainWindow::~MainWindow()
{

}
