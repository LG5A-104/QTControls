#-------------------------------------------------
#
# Project created by QtCreator 2014-08-15T14:34:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = uimodel
TEMPLATE = app

SOURCES += main.cpp\
        frmmain.cpp \
    api/iconhelper.cpp \
    api/app.cpp \
    api/appinit.cpp \
    usercontrol/frmmessagebox.cpp \
    usercontrol/frminputbox.cpp

HEADERS  += frmmain.h \
    api/iconhelper.h \
    api/myhelper.h \
    api/app.h \
    api/appinit.h \
    usercontrol/frmmessagebox.h \    
    usercontrol/frminputbox.h

FORMS    += frmmain.ui \
    usercontrol/frmmessagebox.ui \
    usercontrol/frminputbox.ui

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/usercontrol


win32:RC_FILE   = other/main.rc

RESOURCES += \
    other/rc.qrc
