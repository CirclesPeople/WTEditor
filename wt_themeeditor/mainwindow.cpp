#include "mainwindow.h"

#include <QDebug>

void MainWindow::init(){
    qDebug("MainWindow::init()");

    setFixedSize(800,600);

    /* create centralwidget */
    mWidget = new QWidget(this);

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
    mWidget->setLayout(mLayout);
    setCentralWidget(mWidget);

    /* add menu bar */
    mainMenuBar =new MainMenuBar();
    setMenuBar(mainMenuBar);

    /* adb tools bar */
    mainToolsBar = new MainToolsBar();
    addToolBar(mainToolsBar);

    /* add status bar */
    mainStatusBar = new MainStatusBar();
    setStatusBar(mainStatusBar);

    /* get UtilADB's pointer */
    utilADB = new UtilADB();
    utilADB->adbDevice();


}

/* initialise connections. */
void MainWindow::initConnects(){
    connect(utilADB,&UtilADB::adbProcInfo,this,&MainWindow::onADBProcInfo);
}

void MainWindow::onADBProcInfo(const QStringList outputList){
    foreach(QString tmp,outputList){
        qDebug() << tmp;
    }
    if(outputList.size()==4){
        mainStatusBar->statusLabel->setText(outputList.value(1));
    }else if(outputList.size()<4){
        mainStatusBar->statusLabel->setText("no device is connected");
    }else if(outputList.size()>4){
        mainStatusBar->statusLabel->setText("too more connections");
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
