#include "mainwindow.h"
#include <QApplication>
#include "utilfunctrace.h"

int main(int argc, char *argv[])
{
    DEBUGPRINT
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
