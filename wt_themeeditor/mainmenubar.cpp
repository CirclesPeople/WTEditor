#include "mainmenubar.h"

#include <QMenu>

void MainMenuBar::init()
{

    QMenu *fileMenu=addMenu("File");
    fileMenu->addAction("Open");
    fileMenu->addSeparator();
    fileMenu->addAction("New");
    fileMenu->addSeparator();
    fileMenu->addAction("Export");
    fileMenu->addSeparator();
    fileMenu->addAction("Pack Resources");
    fileMenu->addSeparator();
    fileMenu->addAction("Apply Resources");
    fileMenu->addSeparator();

    QMenu *toolsMenu=addMenu("Tools");
    toolsMenu->addAction("Mobile Assistant");
    toolsMenu->addSeparator();
    toolsMenu->addAction("ADB Check");
    toolsMenu->addSeparator();
    QAction *actADBState = toolsMenu->addAction("ADB State");
    connect(actADBState, &QAction::triggered, mUtilADB, &UtilADB::adbDevice);

    QMenu *helpMenu=addMenu("Help");
    helpMenu->addAction("About");
    helpMenu->addSeparator();
    helpMenu->addAction("Tutorial");
    helpMenu->addSeparator();
    QAction *actPreference = helpMenu->addAction("Preference");
    connect(actPreference, &QAction::triggered,mWinSettings, &WindowSettings::showSettingsWindow);
}

MainMenuBar::MainMenuBar(const UtilADB *utilADB, const WindowSettings *winSettings):QMenuBar()
{
    mUtilADB=utilADB;
    mWinSettings=winSettings;
    init();
}
