#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QHBoxLayout>
#include<QVBoxLayout>

#include <tabmodule.h>
#include <pagemodule.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    TabModule *tabLayout;
    PageModule *pageStackedWidget;

private:
    void init();
    QHBoxLayout *mLayout;
    QHBoxLayout *pageLayout;
};

#endif // MAINWINDOW_H
