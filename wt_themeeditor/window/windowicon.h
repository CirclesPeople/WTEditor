#ifndef WINDOWICON_H
#define WINDOWICON_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QEvent>

#include "base/baseiconwidget.h"

class WindowIcon:public QWidget
{
public:
    WindowIcon(BaseIconWidget *baseIconWidget, QWidget *parent = 0);
    void showIconWindow();

    QString pathLittle;
    QString pathMiddle;
    QString pathHigh;
    BaseIconWidget *mBaseIconWidget;

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

protected:
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // WINDOWICON_H
