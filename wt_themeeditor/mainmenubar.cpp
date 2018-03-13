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


    QMenu *toolsMenu=addMenu("Tools");
    toolsMenu->addAction("adb check");


    QMenu *helpMenu=addMenu("Help");
    helpMenu->addAction("About");

}
