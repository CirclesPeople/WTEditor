#ifndef PAGEMODULE_H
#define PAGEMODULE_H

#include <QStackedWidget>
#include <QWidget>

#include "pages/pagegreet.h"
#include "pages/pageicon.h"
#include "pages/pagewallpapers.h"
#include "pages/pageothers.h"
#include "utils/utiladb.h"

class PageModule:public QStackedWidget
{
public:
    explicit PageModule(UtilADB *utilADB);
    ~PageModule();

    void init();

    UtilADB *mUtilADB;

    PageGreet *pageGreet;
    PageIcon *pageIcon;
    PageWallPapers *pageWallPapers;
    PageOthers *pageOthers;

    void setGreetPage();
    void setIconPage();
    void setThemePage();
    void setOthersPage();

private:
    void initConnects();
};

#endif // PAGEMODULE_H
