#ifndef PAGEMODULE_H
#define PAGEMODULE_H

#include <QStackedWidget>
#include <QWidget>

#include "pagegreet.h"
#include "pageicon.h"
#include "pagetheme.h"
#include "pageothers.h"

class PageModule:public QStackedWidget
{
public:
    explicit PageModule(QWidget *parent = 0);
    ~PageModule();

    void init();


    PageGreet *pageGreet;
    PageIcon *pageIcon;
    PageTheme *pageTheme;
    PageOthers *pageOthers;

private:
    void initConnects();
};

#endif // PAGEMODULE_H
