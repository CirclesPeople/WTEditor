#ifndef TABMODULE_H
#define TABMODULE_H

#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QVBoxLayout>

#include <pagemodule.h>

class TabModule : public QVBoxLayout
{
public:
    TabModule(PageModule *pageStackedWidget);


    QPushButton *greetBtn;
    QPushButton *iconBtn;
    QPushButton *themeBtn;
    QPushButton *othersBtn;

    PageModule *mPageModule;

private:
    void init();

};

#endif // TABMODULE_H
