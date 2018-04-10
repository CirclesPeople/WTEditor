#ifndef MAINMENUBAR_H
#define MAINMENUBAR_H

#include <QMenuBar>

#include "utils/utiladb.h"
#include "window/windowsettings.h"

class MainMenuBar:public QMenuBar
{
    Q_OBJECT
public:
    MainMenuBar(const UtilADB *utilADB, const WindowSettings *winSettings);

private:
    void init();

    const UtilADB *mUtilADB;
    const WindowSettings *mWinSettings;
};

#endif // MAINMENUBAR_H
