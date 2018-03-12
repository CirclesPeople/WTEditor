#ifndef UTILLOGGER_H
#define UTILLOGGER_H
#include "qlogging.h"
class UtilLogger
{
public:
    UtilLogger();

    void outputMessage(QtMsgType type, const char *msg);
};

#endif // UTILLOGGER_H
