#ifndef WINDOWICON_H
#define WINDOWICON_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>

#include "baseiconwidget.h"

class WindowIcon:public QLabel
{
public:
    WindowIcon();

private:
    QGridLayout *mGridLayout;
    BaseIconWidget *defaultIcon;
    BaseIconWidget *defaultIconM;
    BaseIconWidget *defaultIconH;
    BaseIconWidget *nweIcon;
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
