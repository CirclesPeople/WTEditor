#ifndef MAINMENUBAR_H
#define MAINMENUBAR_H

#include <QMenuBar>

class MainMenuBar:public QMenuBar
{
    Q_OBJECT
public:
    MainMenuBar(QWidget *parent = nullptr);

private:
    void init();
};

#endif // MAINMENUBAR_H
