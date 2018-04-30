#ifndef WINDOWEMULATOR_H
#define WINDOWEMULATOR_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QFile>
#include <QMenu>
#include <QDebug>

class WindowEmulator:public QWidget
{
    Q_OBJECT
public:
    static double mScale;

    WindowEmulator(QWidget *parent = 0);
    void init();
    void updateScreencap(const QString path);

    QVBoxLayout *emulatorBLayout;
    QLabel *emulatorLabel;

signals:
    void signalRefresh();

protected:
    void contextMenuEvent(QContextMenuEvent *event);

};

#endif // WINDOWEMULATOR_H
