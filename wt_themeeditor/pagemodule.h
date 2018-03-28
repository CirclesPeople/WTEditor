#ifndef PAGEMODULE_H
#define PAGEMODULE_H

#include <QStackedWidget>
#include <QWidget>

#include "pages/pagegreet.h"
#include "pages/pageicon.h"
#include "pages/pagetheme.h"
#include "pages/pageothers.h"

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

    void setGreetPage();
    void setIconPage();
    void setThemePage();
    void setOthersPage();

private:
    void initConnects();
};

#endif // PAGEMODULE_H
