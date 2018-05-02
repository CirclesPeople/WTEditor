#ifndef TABMODULE_H
#define TABMODULE_H

#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QVBoxLayout>

#include <pagemodule.h>

class TabModule : public QVBoxLayout
{
    Q_OBJECT
public:
    TabModule(PageModule *pageStackedWidget);


    QPushButton *greetBtn;
    QPushButton *iconBtn;
    QPushButton *wallpapersBtn;
    QPushButton *othersBtn;

    PageModule *mPageModule;

private:
    void init();

};

#endif // TABMODULE_H
