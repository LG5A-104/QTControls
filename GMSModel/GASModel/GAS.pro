#-------------------------------------------------
#
# Project created by QtCreator 2016-09-29T15:15:28
#
#-------------------------------------------------

QT       += core gui network sql xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET              = GAS
TEMPLATE            = app
MOC_DIR             = temp/moc
RCC_DIR             = temp/rcc
UI_DIR              = temp/ui
OBJECTS_DIR         = temp/obj
DESTDIR             = bin
win32:RC_FILE       = other/main.rc
PRECOMPILED_HEADER  = api/myhelper.h

include($$PWD/api/api.pri)
include($$PWD/form/form.pri)
include($$PWD/usercontrol/usercontrol.pri)
ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

SOURCES     += main.cpp
RESOURCES   += other/main.qrc
INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/usercontrol
CONFIG      += qt warn_off release
