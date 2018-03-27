#include "tabmodule.h"
#include "pagemodule.h"
#include "pagegreet.h"

#include <QVBoxLayout>

TabModule::TabModule(PageModule *pageModule):QVBoxLayout(){

    mPageModule=pageModule;
    //init view/data
    init();
}

void TabModule::init(){
    qDebug("TabModule::init()");

    greetBtn = new QPushButton(QIcon(":/qsrc/image/greet.ico"), QObject::tr("Welcome"));
    connect(greetBtn,&QPushButton::released,mPageModule,&PageModule::setGreetPage);
    iconBtn= new QPushButton(QIcon(":/qsrc/image/icon.ico"), QObject::tr("Icon"));
    connect(iconBtn,&QPushButton::released,mPageModule,&PageModule::setIconPage);
    themeBtn= new QPushButton(QIcon(":/qsrc/image/theme.ico"), QObject::tr("Theme"));
    connect(themeBtn,&QPushButton::released,mPageModule,&PageModule::setThemePage);
    othersBtn= new QPushButton(QIcon(":/qsrc/image/others.ico"), QObject::tr("Others"));
    connect(othersBtn,&QPushButton::released,mPageModule,&PageModule::setOthersPage);

    addWidget(greetBtn);
    addWidget(iconBtn);
    addWidget(themeBtn);
    addWidget(othersBtn);    
}
