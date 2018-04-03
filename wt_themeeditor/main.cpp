#include "mainwindow.h"
#include "qlogging.h"

#include "utils/UtilStyle.cpp"
#include "configs/Config.cpp"

#include <QApplication>
#include <QFile>
#include <QtMessageHandler>
#include <QIODevice>
#include <QString>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>

void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    static QMutex mutex;
    mutex.lock();

    QString text;
    switch(type)
    {
    case QtDebugMsg:
        text = QString("Debug:");
        break;

    case QtWarningMsg:
        text = QString("Warning:");
        break;

    case QtCriticalMsg:
        text = QString("Critical:");
        break;

    case QtFatalMsg:
        text = QString("Fatal:");
    }

    QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString current_date = QString("(%1)").arg(current_date_time);
    QString message = QString("%1 %2 %3 %4").arg(text).arg(context_info).arg(msg).arg(current_date);

    QFile file("log.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << message << "\r\n";
    file.flush();
    file.close();

    mutex.unlock();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //注册MessageHandler,输出log到log.txt
    qInstallMessageHandler(outputMessage);
    qDebug("\n\n****** main ******\n\n");

    // 初始化QSettings
    Config::initSettings();

    QSettings settings(CONFIG_PATH,QSettings::IniFormat);
    QString author = settings.value("/devinfo/author").toString();
    QString org = settings.value("/devinfo/organization").toString();
    QString orgDomain = settings.value("/devinfo/org_domain").toString();
    QString appName = settings.value("/devinfo/app_name").toString();
    qDebug()<< "\n***devinfo***\n" << author << "\n" << org << "\n" << orgDomain << "\n" << appName << "\n" ;

    // 加载QSS样式
    UtilStyle::setStyle(":/qsrc/qss/psblack.css");

    MainWindow w;
    w.setWindowIcon(QIcon(":/qsrc/main.ico"));
    w.show();

    return a.exec();
}
