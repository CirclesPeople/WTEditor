#include "mainmenubar.h"

#include <QMenu>

MainMenuBar::MainMenuBar(QWidget *parent):QMenuBar(parent)
{
    init();
}


void MainMenuBar::init()
{

    QMenu *fileMenu=addMenu("File");


    QMenu *toolsMenu=addMenu("Tools");


    QMenu *helpMenu=addMenu("Help");

}
