#include "utiladb.h"

#include <QDebug>

#define ADB_DEVICES "adb devices"
#define ADB_SHELL "adb shell"
#define ADB_LOGCAT "adb logcat"
#define ADB_PUSH "adb push"
#define ADB_PULL "adb PULL"
#define ADB_INSTALL "adb install"
#define ADB_UNINSTALL "adb uninstall"
#define ADB_REBOOT_RECOVERY "adb reboot recovery"
#define ADB_REBOOT_FASTBOOT "adb reboot fastboot"
#define ADB_REBOOT_RESET "adb reboot reset"


UtilADB::UtilADB()
{
    init();
}

void UtilADB::init(){
    adbProcess = new QProcess();

}

void UtilADB::readFromProcess(){

}

void UtilADB::adbDevice(){

    adbProcess->setProcessChannelMode(QProcess::MergedChannels);
    adbProcess->start(ADB_DEVICES);

    connect(adbProcess, &QProcess::readyRead, this, &UtilADB::readFromProcess);
    if(!adbProcess->waitForFinished(-1))
    {
        return;
    }
    else
    {
        QString output =QString::fromLocal8Bit(adbProcess->readAllStandardOutput());
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
