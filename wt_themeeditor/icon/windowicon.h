#ifndef WINDOWICON_H
#define WINDOWICON_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>

#include "base/baseiconwidget.h"

class WindowIcon:public QWidget
{
public:
    WindowIcon(QWidget *parent = 0);
    void showIconWindow();

private:
    QGridLayout *mGridLayout;
    BaseIconWidget *defaultIcon;
    BaseIconWidget *defaultIconM;
    BaseIconWidget *defaultIconH;
    BaseIconWidget *newIcon;
    BaseIconWidget *newIconM;
    BaseIconWidget *newIconH;
    QLabel *arrow;
    QLabel *arrowM;
    QLabel *arrowH;

    QLabel *label;
    QLabel *labelM;
    QLabel *labelH;

    void init();
};

#endif // WINDOWICON_H
