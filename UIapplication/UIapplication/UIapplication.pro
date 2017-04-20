#-------------------------------------------------
#
# Project created by QtCreator 2017-04-15T11:23:18
#
#-------------------------------------------------

QT       += core gui
RC_FILE = myapp.rc
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): DEFINES += QT_MESSAGELOGCONTEXT

TARGET = UIapplication
TEMPLATE = app


SOURCES += main.cpp\
        frmmain.cpp \
    userform/titlebar.cpp \
    userform/mainwindow.cpp \
    userform/iconhelper.cpp \
    generalAPI/app.cpp \
    generalAPI/appinit.cpp \
    generalAPI/log/LogHandler.cpp

HEADERS  += frmmain.h \
    userform/titlebar.h \
    userform/mainwindow.h \
    userform/iconhelper.h \
    generalAPI/app.h \
    generalAPI/appinit.h \
    generalAPI/log/LogHandler.h \
    generalAPI/log/Singleton.h \
    generalAPI/myhelper.h

FORMS    += \
    userform/mainwindow.ui

RESOURCES += \
    source.qrc


OTHER_FILES +=

DESTDIR             = exe
