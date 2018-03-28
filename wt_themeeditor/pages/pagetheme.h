#ifndef PAGETHEME_H
#define PAGETHEME_H

#include <QObject>
#include <QWidget>

class PageTheme:public QWidget
{
public:
    PageTheme(QWidget *parent = 0);
    ~PageTheme();
};

#endif // PAGETHEME_H
