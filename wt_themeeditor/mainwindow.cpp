#include "mainwindow.h"

void MainWindow::init(){
    qDebug("MainWindow::init()");

    setFixedSize(800,600);

    //创建centralwidget
    mWidget = new QWidget(this);
    //创建横向布局管理器
    mLayout = new QHBoxLayout();

    //mLayout->addStretch();  // 添加伸缩

    //创建分页模块
    pageStackedWidget = new PageModule();
    pageStackedWidget->autoFillBackground();
    pageLayout = new QHBoxLayout();
    pageLayout->addWidget(pageStackedWidget);

    //创建tab模块
    tabLayout = new TabModule(pageStackedWidget);

    //添加布局
    mLayout->addLayout(tabLayout);
    mLayout->addLayout(pageLayout);
    mWidget->setLayout(mLayout);
    setCentralWidget(mWidget);

    //添加菜单栏
    mainMenuBar =new MainMenuBar();
    setMenuBar(mainMenuBar);


    //添加工具栏
    mainToolsBar = new MainToolsBar();
    addToolBar(mainToolsBar);


    //添加状态栏
    mainStatusBar = new MainStatusBar();
    setStatusBar(mainStatusBar);



}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    MainWindow::init();
}

MainWindow::~MainWindow()
{

}
