#include "utiladb.h"

#include <QDebug>

#define ADB "adb"


UtilADB::UtilADB()
{

}

void UtilADB::init(){

}

void UtilADB::adbDevice(){
    adbProcess.start(ADB);
    if(!adbProcess.waitForFinished(-1))
    {
        return;
    }
    else
    {
        QString output =QString::fromLocal8Bit(adbProcess.readAllStandardOutput());
        QStringList OUT = output.split("\n");
        qDebug()<<OUT;

    }
}

void UtilADB::getADBProcessInfo(){

}

void adbPush(){

}
void adbPull(){

}

void adbInstall(){

}
void adbShell(){

}
void getADBProcessInfo(){

}

void enterRecoveryMode(){}

void enterFastbootMode(){}
void enterFactoryMode(){}
void screenShot(){}
