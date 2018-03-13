#include "utiladb.h"

#include <QDebug>

#define ADB "adb"


UtilADB::UtilADB()
{

}

void UtilADB::init(){

}

void UtilADB::adbCheck(){
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

int UtilADB::getADBConnStatus(){

    return 0;
}
