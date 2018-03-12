#ifndef UTILFUNCTRACE_H
#define UTILFUNCTRACE_H

#include <QString>

#ifdef _DEBUG_PRINT
#define DEBUGPRINT UtilFuncTrace printinfo(__FILE__, __LINE__, __FUNCTION__);
#else
#define DEBUGPRINT
#endif


class UtilFuncTrace
{
public:
    UtilFuncTrace(QString file, int line, QString func);
    ~UtilFuncTrace();
private:
    QString fileName;
    int fileLine;
    QString funcName;
};

#endif // UTILFUNCTRACE_H
