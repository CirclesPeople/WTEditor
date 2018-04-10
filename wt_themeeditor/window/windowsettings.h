#ifndef WINDOWSETTINGS_H
#define WINDOWSETTINGS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QWindow>

class WindowSettings:public QWidget{
    Q_OBJECT
public:
    WindowSettings(QWidget *parent = 0);

    void init();
    void showSettingsWindow();

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

    QPushButton *srcDefaultBtn;
    QPushButton *srcOutputBtn;
    QPushButton *srcCurBtn;

};
#endif // WINDOWSETTINGS_H
