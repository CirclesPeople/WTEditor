#include "windowemulator.h"


double WindowEmulator::mScale = 1;

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
