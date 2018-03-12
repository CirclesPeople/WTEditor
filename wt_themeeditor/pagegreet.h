#ifndef PAGEGREET_H
#define PAGEGREET_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

class PageGreet:public QWidget
{
public:
    PageGreet(QWidget *parent = 0);
    ~PageGreet();

    QPushButton *mOpenBtn;
    QPushButton *mNewBtn;

    QLabel *mTitleLab;

    QVBoxLayout *mLayout;
    QHBoxLayout *layoutLab;
    QHBoxLayout *layoutBtn;

private:
    void init();
};

#endif // PAGEGREET_H
