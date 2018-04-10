#include "windowsettings.h"

#include <QSettings>

void WindowSettings::init(){

    mLayoutSettings=new QVBoxLayout();

    srcDefaultLayout = new QHBoxLayout();
    srcOutputLayout = new QHBoxLayout();
    srcCurLayout = new QHBoxLayout();

    srcDirDefault = new QWidget();
    srcDirOutput = new QWidget();
    srcDirCur = new QWidget();

    srcDefaultLab = new QLabel();
    srcOutputLab = new QLabel();
    srcCurLab = new QLabel();

    srcDefaultEdit = new QLineEdit();
    srcOutputEdit = new QLineEdit();
    srcCurEdit = new QLineEdit();

    srcDefaultBtn = new QPushButton();
    srcOutputBtn = new QPushButton();
    srcCurBtn = new QPushButton();

    srcDefaultLayout->addWidget(srcDefaultLab);
    srcDefaultLayout->addWidget(srcDefaultEdit);
    srcDefaultLayout->addWidget(srcDefaultBtn);
    srcDirDefault->setLayout(srcDefaultLayout);

    srcOutputLayout->addWidget(srcOutputLab);
    srcOutputLayout->addWidget(srcOutputEdit);
    srcOutputLayout->addWidget(srcOutputBtn);
    srcDirOutput->setLayout(srcOutputLayout);

    srcCurLayout->addWidget(srcCurLab);
    srcCurLayout->addWidget(srcCurEdit);
    srcCurLayout->addWidget(srcCurBtn);
    srcDirCur->setLayout(srcCurLayout);

    mLayoutSettings->addWidget(srcDirDefault);
    mLayoutSettings->addWidget(srcDirDefault);
    mLayoutSettings->addWidget(srcDirDefault);

    setLayout(mLayoutSettings);
}
/* 显示窗口 */
void WindowSettings::showSettingsWindow(){
    show();
}
WindowSettings::WindowSettings(QWidget *parent):QWidget(parent)
{
    init();
}

