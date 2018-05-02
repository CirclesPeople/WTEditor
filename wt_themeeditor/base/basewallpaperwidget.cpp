#include "basewallpaperwidget.h"

#include "baseiconwidget.h"
#include <QDebug>
#include <QEvent>
#include <QMenu>
#include <QAction>

void BaseWallpaperWidget::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu *menuBaseIcon = new QMenu(this);
    QAction *applyAction = menuBaseIcon->addAction(tr("Apply"));
    connect(applyAction,&QAction::triggered,[=](){
        qDebug() << "Apply";
        emit signalApply(this);
    });

    menuBaseIcon->addSeparator();
    QAction *saveAction = menuBaseIcon->addAction(tr("Save"));
    connect(saveAction,&QAction::triggered,[=](){
        qDebug() << "Save";
        emit signalSave(this);
    });

    menuBaseIcon->addSeparator();
    QAction *delAction = menuBaseIcon->addAction(tr("Delete"));
    connect(delAction,&QAction::triggered,[=](){
        qDebug() << "Delete";
        emit signalDel(this);

        //删除图片
        this->clear();
    });

    menuBaseIcon->move(cursor().pos()); //让菜单显示的位置在鼠标的坐标上
    menuBaseIcon->show();
}

BaseWallpaperWidget::BaseWallpaperWidget()
{
    mTag=new QString("basewallpaperwidget: ");
}

