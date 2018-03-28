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
    void initConnects();

public slots:
    void adbDevice();
    void adbKill();
    void adbPush(QString *pathFrom,QString *pathTo);
    void adbPull();
    void adbInstall();
    void adbShell();
    void getADBProcessInfo();
    void enterRecoveryMode();
    void enterFastbootMode();
    void enterFactoryMode();
    void screenShot();

signals:
    void adbProcInfo(const QStringList outputList);

private:
    void readFromProcess(const int flag);
    bool isAdbConnect();

    QProcess *adbProcess;
};

#endif // UTILADB_H
