#include "pagemodule.h"

//初始化界面
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

//切换到欢迎页面
void PageModule::setGreetPage(){
    setCurrentIndex(0);
}

//切换到欢迎页面
void PageModule::setIconPage(){
    setCurrentIndex(1);
}

//切换到欢迎页面
void PageModule::setThemePage(){
    setCurrentIndex(2);
}

//切换到欢迎页面
void PageModule::setOthersPage(){
    setCurrentIndex(3);
}



void PageModule::initConnects(){

}

PageModule::PageModule(QWidget *parent):QStackedWidget(parent){
    PageModule::init();
}

PageModule::~PageModule(){

}
