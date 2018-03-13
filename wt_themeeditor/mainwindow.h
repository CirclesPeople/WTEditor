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

private:
    void init();
    QWidget *mWidget;
    QHBoxLayout *mLayout;
    QHBoxLayout *pageLayout;
};

#endif // MAINWINDOW_H
