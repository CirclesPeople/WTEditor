#-------------------------------------------------
#
# Project created by QtCreator 2018-03-08T15:30:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wt_themeeditor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    base/baseiconwidget.cpp \
    configs/config.cpp \
    data/sqlmodule.cpp \
    icon/windowicon.cpp \
    network/networkmodule.cpp \
    pages/pagegreet.cpp \
    pages/pageicon.cpp \
    pages/pageothers.cpp \
    pages/pagetheme.cpp \
    test/testmainwindow.cpp \
    utils/utiladb.cpp \
    main.cpp \
    mainmenubar.cpp \
    mainstatusbar.cpp \
    maintoolsbar.cpp \
    mainwindow.cpp \
    pagemodule.cpp \
    tabmodule.cpp

HEADERS += \
    base/baseiconwidget.h \
    configs/config.h \
    data/sqlmodule.h \
    icon/windowicon.h \
    network/networkmodule.h \
    pages/pagegreet.h \
    pages/pageicon.h \
    pages/pageothers.h \
    pages/pagetheme.h \
    test/testmainwindow.h \
    utils/utiladb.h \
    mainmenubar.h \
    mainstatusbar.h \
    maintoolsbar.h \
    mainwindow.h \
    pagemodule.h \
    tabmodule.h

FORMS += \
    testmainwindow.ui

RESOURCES += \
    qsrc/qss.qrc \
    qsrc/main.qrc \
    qsrc/wt_editor_style.qrc

DISTFILES += \
    qsrc/main.rc

 CONFIG += c++11
