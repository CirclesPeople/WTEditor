#ifndef UTILADB_H
#define UTILADB_H

#include <QProcess>

class UtilADB
{
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

    QProcess adbProcess;
};

#endif // UTILADB_H
