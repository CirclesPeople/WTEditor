#include "baseiconwidget.h"
#include <QDebug>
#include <QEvent>
#include <QMenu>
#include <QAction>

void BaseIconWidget::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu *menuBaseIcon = new QMenu(this);
    QAction *applyAction = menuBaseIcon->addAction(tr("Apply"));
    connect(applyAction,&QAction::triggered,[=](){
        qDebug() << "Apply";
        emit signalApply(this);
    });

    menuBaseIcon->addSeparator();
    QAction *saveAction = menuBaseIcon->addAction(tr("Save"));
    connect(applyAction,&QAction::triggered,[=](){
        qDebug() << "Save";
        emit signalSave(this);
    });

    menuBaseIcon->addSeparator();
    QAction *delAction = menuBaseIcon->addAction(tr("Delete"));
    connect(applyAction,&QAction::triggered,[=](){
        qDebug() << "Save";
        emit signalDel(this);
    });

    menuBaseIcon->move(cursor().pos()); //让菜单显示的位置在鼠标的坐标上
    if(isShow==1){
        menuBaseIcon->show();
    }
}

void BaseIconWidget::mouseReleaseEvent(QMouseEvent *event){
    qDebug() << "left";
    emit onClicked();
}

void BaseIconWidget::init(){
    setAlignment(Qt::AlignCenter);
    setFixedSize(ICON_SIZE,ICON_SIZE);
    mIconFlag=0;
    mTypeFlag=0;
}

BaseIconWidget::BaseIconWidget(const QString iconName, const int showflag, const int iconflag)
{
    init();
    isShow = showflag;
    mIconName = iconName;
    mIconFlag = iconflag;

}

BaseIconWidget::BaseIconWidget(const QString iconName, const int showflag, const int iconflag, const int typeflag)
{
    init();
    isShow = showflag;
    mIconName = iconName;
    mIconFlag = iconflag;
    mTypeFlag = typeflag;

}
