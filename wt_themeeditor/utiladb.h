#ifndef UTILADB_H
#define UTILADB_H

#include <QProcess>
#include <QObject>

class UtilADB:public QObject
{
    Q_OBJECT
public:
    UtilADB();

    QStringList outputList;

    void init();
    void adbDevice();
    void adbPush(QString *pathFrom,QString *pathTo);
    void adbPull();
    void adbInstall();
    void adbShell();
    void getADBProcessInfo();
    void enterRecoveryMode();
    void enterFastbootMode();
    void enterFactoryMode();
    void screenShot();

private:
    void readFromProcess(const int flag);
    bool isAdbConnect();

    QProcess *adbProcess;
};

#endif // UTILADB_H
