#include <QFile>
#include <QApplication>
#include <QDebug>

class StyleHelper
{
public:
    static void setStyle(const QString &style) {
        QFile qss(style);
        qss.open(QFile::ReadOnly);
        QString str = QLatin1String(qss.readAll());
        //qApp->setStyleSheet(str);
        qss.close();
    }
};
