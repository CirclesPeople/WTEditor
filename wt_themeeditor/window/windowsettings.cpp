#include "windowsettings.h"

#include <QSettings>

void WindowSettings::init(){
    setFixedSize(400,300);

    mLayoutSettings=new QVBoxLayout();

    srcDefaultLayout = new QHBoxLayout();
    srcOutputLayout = new QHBoxLayout();
    srcCurLayout = new QHBoxLayout();

    srcDirDefault = new QWidget();
    srcDirOutput = new QWidget();
    srcDirCur = new QWidget();

    srcDefaultLab = new QLabel(tr("DefPath"));
    srcOutputLab = new QLabel(tr("OutPath"));
    srcCurLab = new QLabel(tr("CurPath"));

    srcDefaultEdit = new QLineEdit();
    srcOutputEdit = new QLineEdit();
    srcCurEdit = new QLineEdit();

    srcDefaultBtn = new QPushButton(tr("Browse"));
    connect(srcDefaultBtn,&QPushButton::clicked,[=](){
        openDirecotry(FLAG_DEFAULT);
    });
    srcOutputBtn = new QPushButton(tr("Browse"));
    connect(srcOutputBtn,&QPushButton::clicked,[=](){
        openDirecotry(FLAG_OUTPUT);
    });
    srcCurBtn = new QPushButton(tr("Browse"));
    connect(srcCurBtn,&QPushButton::clicked,[=](){
        openDirecotry(FLAG_CURRENT);
    });

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
    mLayoutSettings->addWidget(srcDirOutput);
    mLayoutSettings->addWidget(srcDirCur);

    setLayout(mLayoutSettings);
}

void WindowSettings::openDirecotry(int flag)
{
    QString path = QFileDialog::getExistingDirectory(this,
                                                     tr("Open Directory"),
                                                     QDir::currentPath(),
                                                     QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(!path.isEmpty()) {
        switch(flag){
        case FLAG_DEFAULT:
            defaultPath = path;
            updatePath(FLAG_DEFAULT);
            break;
        case FLAG_OUTPUT:
            outputPath = path;
            updatePath(FLAG_OUTPUT);
            break;
        case FLAG_CURRENT:
            curPath = path;
            updatePath(FLAG_CURRENT);
            break;
        }
    } else {
        //QMessageBox::warning(this, tr("Path"),tr("You did not select any directory."));
    }
}

//更新路径到QSettings
void WindowSettings::showPaths(){
    QSettings settings(CONFIG_PATH,QSettings::IniFormat);
    srcDefaultEdit->setText(settings.value("/dir/default").toString());
    srcOutputEdit->setText(settings.value("/dir/output").toString());
    srcCurEdit->setText(settings.value("/dir/current").toString());
}

//更新所有路径到QSettings
void WindowSettings::updatePath(int flag){
    QSettings settings(CONFIG_PATH,QSettings::IniFormat);
    switch(flag){
    case FLAG_DEFAULT:
        srcDefaultEdit->setText(defaultPath);
        settings.setValue("/dir/default", defaultPath);
        break;
    case FLAG_OUTPUT:
        srcOutputEdit->setText(outputPath);
        settings.setValue("/dir/output", outputPath);
        break;
    case FLAG_CURRENT:
        srcCurEdit->setText(curPath);
        settings.setValue("/dir/current", curPath);
        break;
    }
}

/* 显示窗口 */
void WindowSettings::showSettingsWindow(){
    show();
}
WindowSettings::WindowSettings(QWidget *parent):QWidget(parent)
{
    init();
    showPaths();
}

