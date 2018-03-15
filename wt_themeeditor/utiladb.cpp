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

void UtilADB::init(){
    if(adbProcess != NULL){
        adbProcess = new QProcess();
    }
}

void UtilADB::readFromProcess()
{
    QString output = QString::fromUtf8(adbProcess->readAll());
    outputList = output.split(",");
    qDebug() << "readFromProcess()" << "outputList's size is " << outputList.size();
    foreach(QString str, outputList){
        qDebug(str.toLocal8Bit().data());
    }
}
/* execute adb command "adb push xxx" */
QStringList UtilADB::adbDevice(){

    adbProcess->setProcessChannelMode(QProcess::MergedChannels);
    adbProcess->start(ADB_DEVICES);

    connect(adbProcess, &QProcess::readyRead, this, &UtilADB::readFromProcess);

    return outputList;
}

void UtilADB::getADBProcessInfo(){

}

/* execute adb command "adb push xxx" */
void UtilADB::adbPush(QString *pathFrom,QString *pathTo){
    QString command(ADB_PUSH);
    command = command.append(pathFrom).append(pathTo);

    adbProcess->setProcessChannelMode(QProcess::MergedChannels);
    adbProcess->start(command);

    connect(adbProcess, &QProcess::readyRead, this, &UtilADB::readFromProcess);
}
void UtilADB::adbPull(){

}

void UtilADB::adbInstall(){

}
void UtilADB::adbShell(){

}

void UtilADB::enterRecoveryMode(){}

void UtilADB::enterFastbootMode(){}
void UtilADB::enterFactoryMode(){}
void UtilADB::screenShot(){}

bool isAdbConnect();



UtilADB::UtilADB()
{
    init();
}
