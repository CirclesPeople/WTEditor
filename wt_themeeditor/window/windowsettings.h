#ifndef WINDOWSETTINGS_H
#define WINDOWSETTINGS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>

class WindowSettings:public QWidget{
    Q_OBJECT
public:
    WindowSettings(QWidget *parent = 0);

    void init();

    QVBoxLayout *mLayoutSettings;

    QWidget *srcDirDefault;
    QWidget *srcDirOutput;
    QWidget *srcDirCur;

    QHBoxLayout *srcDefaultLayout;
    QHBoxLayout *srcOutputLayout;
    QHBoxLayout *srcCurLayout;

    QLabel *srcDefaultLab;
    QLabel *srcOutputLab;
    QLabel *srcCurLab;

    QLineEdit *srcDefaultEdit;
    QLineEdit *srcOutputEdit;
    QLineEdit *srcCurEdit;



}
#endif // WINDOWSETTINGS_H
