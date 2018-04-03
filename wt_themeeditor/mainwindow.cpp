#include "mainwindow.h"

#include <QDebug>

void MainWindow::init(){
    //初始化UtilADB对象
    utilADB = new UtilADB();

    //设置mainwindow样式
    setFixedSize(800,600);
    QPalette mPalette = this->palette();
    mPalette.setBrush(QPalette::Background, Qt::white);
    setPalette(mPalette);

    //创建mainwindow QWidget
    mWindowWidget = new QWidget(this);

    //创建mainwindow 水平布局
    mLayout = new QHBoxLayout();

    //将PageModule添加到一个pagelayout水平布局中
    pageStackedWidget = new PageModule();
    pageStackedWidget->autoFillBackground();
    pageLayout = new QHBoxLayout();
    pageLayout->addWidget(pageStackedWidget);

    //创建TabModule，并将PageModule传递给TabModule
    tabLayout = new TabModule(pageStackedWidget);

    //将TabModule、PageModule同时添加到mainwindow的水平布局当中
    mLayout->addLayout(tabLayout);
    mLayout->addLayout(pageLayout);

    mWindowWidget->setLayout(mLayout);
    //设置MainWindow的widget
    setCentralWidget(mWindowWidget);

    //添加菜单栏
    mainMenuBar =new MainMenuBar(utilADB);
    setMenuBar(mainMenuBar);

    //添加工具栏
    mainToolsBar = new MainToolsBar();
    addToolBar(mainToolsBar);

    //添加状态栏
    mainStatusBar = new MainStatusBar();
    setStatusBar(mainStatusBar);

}

/* initialise connections. */
void MainWindow::initConnects(){
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
