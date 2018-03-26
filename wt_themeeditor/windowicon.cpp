#include "windowicon.h"

void WindowIcon::showIconWindow(){
    show();
}

void WindowIcon::init(){
    setFixedSize(600,400);

    mGridLayout = new QGridLayout();
    defaultIcon = new BaseIconWidget(QObject::tr("default"));
    defaultIconM = new BaseIconWidget(QObject::tr("defaultM"));
    defaultIconH = new BaseIconWidget(QObject::tr("defaultH"));
    nweIcon = new BaseIconWidget(QObject::tr("new"));
    newIconM = new BaseIconWidget(QObject::tr("newM"));
    newIconH = new BaseIconWidget(QObject::tr("newH"));
    arrow =new QLabel("->");
    arrowM =new QLabel("->");
    arrowH =new QLabel("->");
    label = new QLabel("480P");
    labelM = new QLabel("720P");
    labelH = new QLabel("1080P");

    mGridLayout->addWidget(label,0,0,Qt::AlignCenter);
    mGridLayout->addWidget(labelM,1,0,Qt::AlignCenter);
    mGridLayout->addWidget(labelH,2,0,Qt::AlignCenter);

    mGridLayout->addWidget(defaultIcon,0,1,Qt::AlignCenter);
    mGridLayout->addWidget(defaultIconM,1,1,Qt::AlignCenter);
    mGridLayout->addWidget(defaultIconH,2,1,Qt::AlignCenter);

    mGridLayout->addWidget(arrow,0,2,Qt::AlignCenter);
    mGridLayout->addWidget(arrowM,1,2,Qt::AlignCenter);
    mGridLayout->addWidget(arrowH,2,2,Qt::AlignCenter);

    mGridLayout->addWidget(nweIcon,0,3,Qt::AlignCenter);
    mGridLayout->addWidget(newIconM,1,3,Qt::AlignCenter);
    mGridLayout->addWidget(newIconH,2,3,Qt::AlignCenter);

    setLayout(mGridLayout);


}

WindowIcon::WindowIcon(QWidget *parent):QWidget(parent)
{
    init();
}
