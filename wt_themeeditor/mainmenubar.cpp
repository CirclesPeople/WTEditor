#include "mainmenubar.h"

#include <QMenu>

void MainMenuBar::init()
{

    QMenu *fileMenu=addMenu("File");
    fileMenu->addAction("Open");
    fileMenu->addSeparator();
    fileMenu->addAction("New");
    fileMenu->addSeparator();
    fileMenu->addAction("Last");
    fileMenu->addSeparator();
    fileMenu->addAction("Reload");
    fileMenu->addSeparator();
    fileMenu->addAction("Export");
    fileMenu->addSeparator();
    fileMenu->addAction("Tutorial");
    fileMenu->addSeparator();
    fileMenu->addAction("Apply");
    fileMenu->addSeparator();
    fileMenu->addAction("Apply All");
    fileMenu->addSeparator();

    QMenu *toolsMenu=addMenu("Tools");
    toolsMenu->addAction("Mobile Assistant");
    toolsMenu->addSeparator();
    toolsMenu->addAction("Reset");
    toolsMenu->addSeparator();
    toolsMenu->addAction("OTA Update");
    toolsMenu->addSeparator();
    toolsMenu->addAction("Recovery Mode");
    toolsMenu->addSeparator();
    toolsMenu->addAction("Fastboot Mode");
    toolsMenu->addSeparator();
    toolsMenu->addAction("Factory Mode");
    toolsMenu->addSeparator();
    toolsMenu->addAction("Apps Install");
    toolsMenu->addSeparator();
    toolsMenu->addAction("Apps Uninstall");
    toolsMenu->addSeparator();
    toolsMenu->addAction("Log Grab");
    toolsMenu->addSeparator();
    toolsMenu->addAction("ScreenShot");

    QMenu *settingsMenu=addMenu("Settings");
    settingsMenu->addAction("Preference");

    QMenu *helpMenu=addMenu("Help");
    helpMenu->addAction("About");

}

MainMenuBar::MainMenuBar(QWidget *parent):QMenuBar(parent)
{
    init();
}
