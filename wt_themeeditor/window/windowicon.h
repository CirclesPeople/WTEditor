#ifndef WINDOWICON_H
#define WINDOWICON_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QEvent>
#include <QSettings>
#include <QDebug>

#include "base/baseiconwidget.h"

#define IS_COVERED true
#define SUCCESSFUL 1
#define NOT_EXIST 0
#define FAILED -1
#define REPEATED -2
#define CONFIG_PATH "config.ini"

class WindowIcon:public QWidget
{
public:
    WindowIcon(BaseIconWidget *baseIconWidget, QWidget *parent = 0);
    void showIconWindow();
    void setIconImg(BaseIconWidget *baseIconWidget, const int iconflag);
    void applyImage(BaseIconWidget *baseIconWidget);
    void saveImage(BaseIconWidget *baseIconWidget);
    void delImage(BaseIconWidget *baseIconWidget);
    int copyFile(QString fromPath ,QString toPath, bool isCover);
    int deleteFile(BaseIconWidget *baseIconWidget);
    int applyFile(QString filePath);

    QString pathD;
    QString pathM;
    QString pathH;
    BaseIconWidget *mBaseIconWidget;
    BaseIconWidget *mBaseIconWidgetEdit;
    int currType;

private:
    QGridLayout *mGridLayout;
    BaseIconWidget *defaultIcon;
    BaseIconWidget *defaultIconM;
    BaseIconWidget *defaultIconH;
    BaseIconWidget *newIcon;
    BaseIconWidget *newIconM;
    BaseIconWidget *newIconH;
    QLabel *arrow;
    QLabel *arrowM;
    QLabel *arrowH;

    QLabel *label;
    QLabel *labelM;
    QLabel *labelH;

    void init();

protected:
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // WINDOWICON_H
