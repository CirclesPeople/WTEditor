#include "mainwindow.h"

void MainWindow::init(){
    mLayout = new QHBoxLayout();
    pageStackedWidget = new PageModule();
    pageLayout = new QHBoxLayout();
    pageLayout->addWidget(pageStackedWidget);
    pageStackedWidget->autoFillBackground();
    tabLayout = new TabModule();

    mLayout->addLayout(tabLayout);
    mLayout->addLayout(pageLayout);

    setLayout(mLayout);
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    MainWindow::init();
}

MainWindow::~MainWindow()
{

}
