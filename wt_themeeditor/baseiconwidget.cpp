#include "baseiconwidget.h"
#include <QDebug>

void BaseIconWidget::mouseReleaseEvent(QMouseEvent *event){
    qDebug() << "left";
    emit onClicked();
}

BaseIconWidget::BaseIconWidget(const QString iconName)
{
    mIconName = iconName;
    init();
}

void BaseIconWidget::init(){
    setAlignment(Qt::AlignCenter);
    setFixedSize(120,120);
}
