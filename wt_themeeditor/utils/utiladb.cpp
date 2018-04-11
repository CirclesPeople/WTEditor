#include "utiladb.h"
#include "mainwindow.h"

#include <QDebug>


void UtilADB::initConnects(){

}

//读取adb进程信息
void UtilADB::readFromProcess(const int flag)
{
    QString output = QString::fromUtf8(adbProcess->readAll()).trimmed();
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
    if(adbProcess != NULL){
        adbProcess = new QProcess();
    }
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

void UtilADB::adbInstall(){}

void UtilADB::adbShell(){}

void UtilADB::adbKill(){
    adbProcess->setProcessChannelMode(QProcess::MergedChannels);
    adbProcess->start(ADB_KILL);

    connect(adbProcess, &QProcess::readyRead, [=](){
        readFromProcess(ADB_KILL_FLAG);
    });

}

void UtilADB::enterRecoveryMode(){}

void UtilADB::enterFastbootMode(){}

void UtilADB::enterFactoryMode(){}

void UtilADB::screenShot(){}

bool isAdbConnect();



UtilADB::UtilADB()
{
}
