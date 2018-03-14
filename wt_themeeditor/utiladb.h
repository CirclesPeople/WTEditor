#ifndef UTILADB_H
#define UTILADB_H

#include <QProcess>
#include <QObject>

class UtilADB:public QObject
{
    Q_OBJECT
public:
    UtilADB();

    void init();
    void adbDevice();
    void adbPush();
    void adbPull();
    void adbInstall();
    void adbShell();
    void getADBProcessInfo();
    void enterRecoveryMode();
    void enterFastbootMode();
    void enterFactoryMode();
    void screenShot();
    void readFromProcess();

    QProcess *adbProcess;
};

#endif // UTILADB_H
