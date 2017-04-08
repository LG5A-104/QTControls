#-------------------------------------------------
#
# Project created by QtCreator 2014-08-15T14:34:50
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InputTool
TEMPLATE = app


SOURCES += main.cpp\
        frmmain.cpp \
    frminput.cpp \
    frmnum.cpp \
    dialog.cpp

HEADERS  += frmmain.h \
    frminput.h \
    frmnum.h \
    dialog.h

FORMS    += frmmain.ui \
    frminput.ui \
    frmnum.ui \
    dialog.ui

MOC_DIR         = temp/moc
RCC_DIR         = temp/rcc
UI_DIR          = temp/ui
OBJECTS_DIR     = temp/obj
DESTDIR         = bin

RESOURCES += \
    resource.qrc
