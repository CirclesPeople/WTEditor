#include "utiladb.h"

#include <QDebug>

#define ADB_DEVICES "adb devices"
#define ADB_DEVICES_FLAG 1
#define ADB_SHELL "adb shell"
#define ADB_SHELL_FLAG 2
#define ADB_LOGCAT "adb logcat"
#define ADB_LOGCAT_FLAG 3
#define ADB_PUSH "adb push"
#define ADB_PUSH_FLAG 4
#define ADB_PULL "adb PULL"
#define ADB_PULL_FLAG 5
#define ADB_INSTALL "adb install"
#define ADB_INSTALL_FLAG 6
#define ADB_UNINSTALL "adb uninstall"
#define ADB_UNINSTALL_FLAG 7
#define ADB_REBOOT_RECOVERY "adb reboot recovery"
#define ADB_REBOOT_RECOVERY_FLAG 8
#define ADB_REBOOT_FASTBOOT "adb reboot fastboot"
#define ADB_REBOOT_FASTBOOT_FLAG 9
#define ADB_REBOOT_RESET "adb reboot reset"
#define ADB_REBOOT_RESET_FLAG 10

void UtilADB::init(){
    if(adbProcess != NULL){
        adbProcess = new QProcess();
    }
}

void UtilADB::readFromProcess(const int flag)
{
    QString output = QString::fromUtf8(adbProcess->readAll());
    qDebug() << output;
    outputList = output.split("\r\n");
    qDebug() << "readFromProcess()" << "flag is " << flag << "; outputList's size is " << outputList.size();


    switch (flag) {
    case ADB_DEVICES_FLAG:
        qDebug() <<"readFromProcess" << "+++ADB_DEVICES_FLAG+++";
        emit adbProcInfo(outputList);

        break;
    case ADB_SHELL_FLAG:
        qDebug() << "+++ADB_SHELL_FLAG+++";

        break;
    case ADB_LOGCAT_FLAG:
        qDebug() << "+++ADB_LOGCAT_FLAG+++";

        break;
    case ADB_PUSH_FLAG:
        qDebug() << "+++ADB_PUSH_FLAG+++";

        break;
    case ADB_PULL_FLAG:
        qDebug() << "+++ADB_PULL_FLAG+++";

        break;
    case ADB_INSTALL_FLAG:
        qDebug() << "+++ADB_INSTALL_FLAG+++";

        break;
    case ADB_UNINSTALL_FLAG:
        qDebug() << "+++ADB_UNINSTALL_FLAG+++";

        break;
    case ADB_REBOOT_RECOVERY_FLAG:
        qDebug() << "+++ADB_REBOOT_RECOVERY_FLAG+++";

        break;
    case ADB_REBOOT_FASTBOOT_FLAG:
        qDebug() << "+++ADB_REBOOT_FASTBOOT_FLAG+++";
        break;
    case ADB_REBOOT_RESET_FLAG:
        qDebug() << "+++ADB_REBOOT_RESET_FLAG+++";

        break;
    default:
        break;
    }
}
/* execute adb command "adb devices" */
void UtilADB::adbDevice(){

    adbProcess->setProcessChannelMode(QProcess::MergedChannels);
    adbProcess->start(ADB_DEVICES);

    connect(adbProcess, &QProcess::readyRead, [=](){
        readFromProcess(ADB_DEVICES_FLAG);
    });

}

void UtilADB::getADBProcessInfo(){

}

/* execute adb command "adb push xxx" */
void UtilADB::adbPush(QString *pathFrom,QString *pathTo){
    QString command(ADB_PUSH);
    command = command.append(pathFrom).append(pathTo);

    adbProcess->setProcessChannelMode(QProcess::MergedChannels);
    adbProcess->start(command);

    /*connect(adbProcess, &QProcess::readyRead, [=](){
        //readFromProcess(ADB_DEVICES_FLAG);
    });*/
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
