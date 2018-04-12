#ifndef WINDOWEMULATOR_H
#define WINDOWEMULATOR_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QFile>

class WindowEmulator:public QWidget
{
public:
    static double mScale;

    WindowEmulator(QWidget *parent = 0);
    void init();
    void updateScreencap(const QString path);

    QVBoxLayout *emulatorBLayout;
    QLabel *emulatorLabel;


};

#endif // WINDOWEMULATOR_H
