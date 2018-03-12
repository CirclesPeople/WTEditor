#include "utilfunctrace.h"

#include <QDateTime>
#include <QDebug>

UtilFuncTrace::UtilFuncTrace(QString file, int line, QString func)
    :fileName(file)
    ,fileLine(line)
    ,funcName(func)
{
  QString result = "";
  QString beginTime = QDateTime::currentDateTime().toString("[yyyy-dd-MM hh:mm:ss.zzz] ");
  result += beginTime + "Enter:{" + fileName + ":" + QString::number(fileLine) + "---" + funcName + "}";
  qDebug() << result.toStdString().c_str();
}
UtilFuncTrace::~UtilFuncTrace()
{
  QString result = "";
  QString beginTime = QDateTime::currentDateTime().toString("[yyyy-dd-MM hh:mm:ss.zzz] ");
  result += beginTime + "Leave:{" + fileName + ":" + QString::number(fileLine) + "---" + funcName + "}";
  qDebug() << result.toStdString().c_str();
}
