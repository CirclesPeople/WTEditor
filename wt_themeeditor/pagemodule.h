#ifndef PAGEMODULE_H
#define PAGEMODULE_H

#include <QStackedWidget>
#include <QWidget>

class PageModule:public QStackedWidget
{
public:
    PageModule();
    ~PageModule();

    void init();
};

#endif // PAGEMODULE_H
