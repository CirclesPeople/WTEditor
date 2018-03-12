#ifndef PAGEMODULE_H
#define PAGEMODULE_H

#include <QStackedWidget>
#include <QWidget>

class PageModule:public QStackedWidget
{
public:
    explicit PageModule(QWidget *parent = 0);
    ~PageModule();

    void init();
};

#endif // PAGEMODULE_H
