#ifndef TABMODULE_H
#define TABMODULE_H

#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QVBoxLayout>

class TabModule : public QVBoxLayout
{
public:
    TabModule();


    QPushButton *greetBtn;
    QPushButton *iconBtn;
    QPushButton *themeBtn;
    QPushButton *othersBtn;

private:
    void init();
};

#endif // TABMODULE_H
