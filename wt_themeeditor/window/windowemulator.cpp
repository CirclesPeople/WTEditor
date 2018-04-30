#include "windowemulator.h"


double WindowEmulator::mScale = 1;

void WindowEmulator::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu *menuBaseIcon = new QMenu(this);
    QAction *applyAction = menuBaseIcon->addAction(tr("Refresh"));
    connect(applyAction,&QAction::triggered,[=](){
        qDebug() << "Refresh";
        emit signalRefresh();
    });

    menuBaseIcon->move(cursor().pos()); //让菜单显示的位置在鼠标的坐标上
    menuBaseIcon->show();
}

bool isFileExist(const QString path)
{
    QFile file(path);
    if(file.exists())
    {
        return true;
    }
    return false;
}

void WindowEmulator::updateScreencap(const QString path){
    if(isFileExist(path)){
        QPixmap pix(path);
        emulatorLabel->setPixmap(pix);
    }
}

/* initialise emulator window */
void WindowEmulator::init(){
    setFixedSize(300,400);
    emulatorBLayout = new QVBoxLayout();
    emulatorLabel = new QLabel();
    emulatorBLayout->addWidget(emulatorLabel);
    emulatorLabel->setScaledContents(true);
    setLayout(emulatorBLayout);

}

WindowEmulator::WindowEmulator(QWidget *parent):QWidget(parent)
{
    init();
}
