#ifndef MAINMENUBAR_H
#define MAINMENUBAR_H

#include <QMenuBar>

#include <utils/utiladb.h>

class MainMenuBar:public QMenuBar
{
    Q_OBJECT
public:
    MainMenuBar(const UtilADB *utilADB);

private:
    void init();
    const UtilADB *mUtilADB;
};

#endif // MAINMENUBAR_H
