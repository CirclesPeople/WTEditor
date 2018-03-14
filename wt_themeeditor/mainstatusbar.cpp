#include "mainstatusbar.h"

MainStatusBar::MainStatusBar(QWidget *parent) : QStatusBar(parent)
{
init();
}

void MainStatusBar::init(){
    statusLabel=new QLabel("developed by bill");
    statusLabel->setAlignment(Qt::AlignVCenter|Qt::AlignRight);
    statusLabel->setMargin(5);
    addWidget(statusLabel);


}
