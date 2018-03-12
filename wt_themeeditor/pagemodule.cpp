#include "pagemodule.h"

void PageModule::init(){
    pageGreet = new PageGreet();
    pageIcon = new PageIcon();
    pageTheme = new PageTheme();
    pageOthers = new PageOthers();

    addWidget(pageGreet);
    addWidget(pageIcon);
    addWidget(pageTheme);
    addWidget(pageOthers);

}

void PageModule::initConnects(){

}

PageModule::PageModule(QWidget *parent):QStackedWidget(parent){
    PageModule::init();
}

PageModule::~PageModule(){

}
