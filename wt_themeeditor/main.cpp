#include "mainwindow.h"
#include "qlogging.h"

#include "utils/UtilStyle.cpp"
#include "configs/Config.cpp"
#include "utils/utiladb.h"

#include <QApplication>
#include <QFile>
#include <QtMessageHandler>
#include <QIODevice>
#include <QString>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>
#include <QSplashScreen>
#include <QPixmap>
#include <QDir>

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

/* 创建工作目录、资源目录等目录 */
void mkdirs(){
    qDebug("*** mkdirs ***");
    QSettings settings(CONFIG_PATH,QSettings::IniFormat);
    QDir dir;
    //创建截屏目录
    if(!dir.exists(SCREENCAP_ADDR_PC_DIR))
    {
        dir.mkdir(SCREENCAP_ADDR_PC_DIR);
    }

    //创建资源目录
    QString cur_path=settings.value("/dir/current").toString();//当前工作区
    if(!dir.exists(cur_path))
    {
        dir.mkdir(cur_path);
    }
    QString default_path=settings.value("/dir/default").toString();//默认
    if(!dir.exists(default_path))
    {
        dir.mkdir(default_path);
    }
    QString output_path=settings.value("/dir/output").toString();//输出目录
    if(!dir.exists(output_path))
    {
        dir.mkdir(output_path);
    }

    QString icon_path=settings.value("/dir/current").toString().append("/icon");//壁纸
    if(!dir.exists(icon_path))
    {
        dir.mkdir(icon_path);
    }
    QString icon_path_d=settings.value("/dir/current").toString().append("/icon").append("/default");
    if(!dir.exists(icon_path_d))
    {
        dir.mkdir(icon_path_d);
    }
    QString icon_path_m=settings.value("/dir/current").toString().append("/icon").append("/middle");
    if(!dir.exists(icon_path_m))
    {
        dir.mkdir(icon_path_m);
    }
    QString icon_path_h=settings.value("/dir/current").toString().append("/icon").append("/high");
    if(!dir.exists(icon_path_h))
    {
        dir.mkdir(icon_path_h);
    }

    QString wallpaper_path=settings.value("/dir/current").toString().append("/wallpaper");//壁纸
    if(!dir.exists(wallpaper_path))
    {
        dir.mkdir(wallpaper_path);
    }
    QString theme_path=settings.value("/dir/current").toString().append("/theme");//主题
    if(!dir.exists(theme_path))
    {
        dir.mkdir(theme_path);
    }
    QString fonts_path=settings.value("/dir/current").toString().append("/fonts");//字体
    if(!dir.exists(fonts_path))
    {
        dir.mkdir(fonts_path);
    }
    QString others_path=settings.value("/dir/current").toString().append("/others");//其他资源
    if(!dir.exists(others_path))
    {
        dir.mkdir(others_path);
    }
}

void init(){
    mkdirs();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //注册MessageHandler,输出log到log.txt
    qInstallMessageHandler(outputMessage);
    qDebug("\n\n****** main ******\n\n");

    //初始化
    init();

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

    //显示应用程序启动画面
    QPixmap pixmap(":/qsrc/starting.png");
    QSplashScreen mSplash(pixmap);
    mSplash.showMessage("starting......");
    mSplash.show();
    a.processEvents();//这样可以保证程序一直可以响应鼠标键盘上事件

    QDateTime n=QDateTime::currentDateTime();
    QDateTime now;
    //延时3s
    do{
        now=QDateTime::currentDateTime();
    } while (n.secsTo(now)<=3);//3为需要延时的秒数

    mSplash.finish(&w);//启动画面在窗口w创建完成以后结束


    w.show();

    return a.exec();
}
