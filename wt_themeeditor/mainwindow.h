#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QWidget>

#include <tabmodule.h>
#include <pagemodule.h>
#include <maintoolsbar.h>
#include <mainstatusbar.h>
#include <mainmenubar.h>
#include "utils/utiladb.h"
#include "window/windowsettings.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    TabModule *tabLayout;
    PageModule *pageStackedWidget;
    MainToolsBar *mainToolsBar;
    MainStatusBar *mainStatusBar;
    MainMenuBar *mainMenuBar;

    UtilADB *utilADB;
    WindowSettings *winSettings;

private:
    void init();
    void initConnects();
    void onADBProcInfo(const QStringList outputList);

    QWidget *mWindowWidget;
    QHBoxLayout *mLayout;
    QHBoxLayout *pageLayout;
};

#endif // MAINWINDOW_H
