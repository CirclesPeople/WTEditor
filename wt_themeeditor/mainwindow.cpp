#include "mainwindow.h"

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


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    init();
}

MainWindow::~MainWindow()
{

}
