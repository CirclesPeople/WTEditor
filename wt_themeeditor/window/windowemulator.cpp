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
    if(isFileExist()){
        QPixmap pix(path);
        emulatorLabel->setPixmap();
    }
}

/* initialise emulator window */
void WindowEmulator::init(){

    emulatorBLayout = new QVBoxLayout();
    emulatorLabel = new QLabel();
    emulatorBLayout->addWidget(QLabel);
    setLayout(emulatorBLayout);

}

WindowEmulator::WindowEmulator(QWidget *parent):QWidget(parent)
{
    init();
}
