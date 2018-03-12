#include "pagegreet.h"

void PageGreet::init(){

    mTitleLab = new QLabel(QObject::tr("Welcome use WTEditor"));
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
