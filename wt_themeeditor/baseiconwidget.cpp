#include "baseiconwidget.h"

BaseIconWidget::BaseIconWidget(const QString iconName)
{
    mIconName = iconName;
    init();
}

void BaseIconWidget::init(){
setAlignment(Qt::AlignCenter);
setFixedSize(120,120);
//setStyleSheet("background: white;border: 1px solid rgb(41, 57, 85);border-radius: 3px;font-weight: bold;");
}
