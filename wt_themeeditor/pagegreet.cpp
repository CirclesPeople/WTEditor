#include "pagegreet.h"

#include <QFrame>

void PageGreet::init(){
    qDebug("PageGreet::init()");

    mTitleLab = new QLabel(QObject::tr("Welcome use WTEditor"));
    mTitleLab->setFrameShape(QFrame::Box);
    mTitleLab->setStyleSheet("border-width: 1px;border-style: solid;border-color: rgb(255, 170, 0);");
    //居中对齐
    mTitleLab->setAlignment(Qt::AlignCenter);
    mTitleLab->setFixedSize(180,20);

    mOpenBtn = new QPushButton(QObject::tr("Open"));
    mNewBtn = new QPushButton(QObject::tr("New"));

    layoutLab = new QHBoxLayout();

    layoutBtn = new QHBoxLayout();
    mLayout = new QVBoxLayout();

    layoutLab->addWidget(mTitleLab);
    layoutBtn->addWidget(mOpenBtn);
    layoutBtn->addWidget(mNewBtn);

    mLayout->addLayout(layoutLab);
    mLayout->addLayout(layoutBtn);
    setLayout(mLayout);
}

PageGreet::PageGreet(QWidget *parent):QWidget(parent)
{
    PageGreet::init();
}

PageGreet::~PageGreet(){

}
