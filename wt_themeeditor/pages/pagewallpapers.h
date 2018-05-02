#ifndef PAGEWALLPAPERS_H
#define PAGEWALLPAPERS_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QEvent>
#include <QMimeData>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QImage>
#include <QList>
#include <QDebug>
#include <QPixmap>

#include "base/basewallpaperwidget.h"

class PageWallPapers:public QWidget
{
    Q_OBJECT
public:
    PageWallPapers();
    ~PageWallPapers();

    void init();
    QString *mTag;
    QString mImagePath;

    QHBoxLayout *mHLayout;
    BaseWallpaperWidget *mWallpapper;
    BaseWallpaperWidget *mKeyguard;

protected:
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // PAGETHEME_H
