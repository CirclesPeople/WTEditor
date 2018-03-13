#ifndef UTILADB_H
#define UTILADB_H

#include <QProcess>

class UtilADB
{
public:
    UtilADB();

    void init();
    void adbCheck();
    int getADBConnStatus();

    QProcess adbProcess;
};

#endif // UTILADB_H
