#include "windowsettings.h"
#include "configs/Config.cpp"

#include <QSettings>

void WindowSettings::init(){
    QSettings settings(CONFIG_PATH,QSettings::IniFormat);

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
    connect(srcDefaultEdit,&QLineEdit::editingFinished,[=](){
        settings.setValue("/settings/defaultdir","defaultdir");
    });
    srcOutputEdit = new QLineEdit();
    connect(srcOutputEdit,&QLineEdit::editingFinished,[=](){
        settings.setValue("/settings/outputdir","outputdir");
    });
    srcCurEdit = new QLineEdit();
    connect(srcCurEdit,&QLineEdit::editingFinished,[=](){
        settings.setValue("/settings/curdir","curdir");
    });

    srcDefaultLayout->addWidget(srcDefaultLab);
    srcDefaultLayout->addWidget(srcDefaultEdit);
    srcDirDefault->setLayout(srcDefaultLayout);

    srcOutputLayout->addWidget(srcOutputLab);
    srcOutputLayout->addWidget(srcOutputEdit);
    srcDirOutput->setLayout(srcOutputLayout);

    srcCurLayout->addWidget(srcCurLab);
    srcCurLayout->addWidget(srcCurEdit);
    srcDirCur->setLayout(srcCurLayout);
}
