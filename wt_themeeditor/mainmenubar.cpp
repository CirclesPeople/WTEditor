#include "mainmenubar.h"

#include <QMenu>

MainMenuBar::MainMenuBar(QWidget *parent):QMenuBar(parent)
{
    init();
}


void MainMenuBar::init()
{

    QMenu *fileMenu=addMenu("File");
    fileMenu->addAction("Open");
    fileMenu->addAction("New");
    fileMenu->addAction("Last");
    fileMenu->addAction("Reload");
    fileMenu->addAction("Export");
    fileMenu->addAction("Tutorial");

    QMenu *toolsMenu=addMenu("Tools");
    toolsMenu->addAction("ADB Check");
    toolsMenu->addAction("Mobile Assistant");
    toolsMenu->addAction("Reset");
    toolsMenu->addAction("OTA Update");
    toolsMenu->addAction("Recovery Mode");
    toolsMenu->addAction("Fastboot Mode");
    toolsMenu->addAction("Factory Mode");
    toolsMenu->addAction("Apps Install");
    toolsMenu->addAction("Apps Uninstall");
    toolsMenu->addAction("Log Grab");
    fileMenu->addAction("ScreenShot");

    QMenu *settingsMenu=addMenu("Settings");
    settingsMenu->addAction("Preference");

    QMenu *helpMenu=addMenu("Help");
    helpMenu->addAction("About");

}
