#ifndef WINDOWSETTINGS_H
#define WINDOWSETTINGS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QWindow>
#include <QFileDialog>
#include <QIODevice>
#include <QMessageBox>

#define FLAG_DEFAULT 0
#define FLAG_OUTPUT 1
#define FLAG_CURRENT 2

#define CONFIG_PATH "config.ini"

#define DEFAULT_PATH "defult"
#define OUTPUT_PATH "output"
#define CURRENT_PATH "current"

class WindowSettings:public QWidget{
    Q_OBJECT
public:
    WindowSettings(QWidget *parent = 0);

    void init();
    void showSettingsWindow();
    void openDirecotry(int flag);
    void showPaths();
    void updatePath(int flag);

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

    QString defaultPath;
    QString outputPath;
    QString curPath;
};
#endif // WINDOWSETTINGS_H
