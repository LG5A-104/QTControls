/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Apr 11 23:04:36 2017
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave_As;
    QAction *actionExport_All;
    QAction *actionExport_Spectrum_Excel;
    QAction *actionPrint;
    QAction *actionExit;
    QAction *actionConnect;
    QAction *actionLuminous;
    QAction *actionPrint_Set;
    QAction *actionDevice_Set;
    QAction *actionAbout;
    QWidget *centralWidget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile_F;
    QMenu *menuMeasure_M;
    QMenu *menuSet_S;
    QMenu *menuHelp_H;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 680);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/24px.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/open482.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/save24px.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon2);
        actionExport_All = new QAction(MainWindow);
        actionExport_All->setObjectName(QString::fromUtf8("actionExport_All"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/excel48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport_All->setIcon(icon3);
        actionExport_Spectrum_Excel = new QAction(MainWindow);
        actionExport_Spectrum_Excel->setObjectName(QString::fromUtf8("actionExport_Spectrum_Excel"));
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/print48px.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon4);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/start48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon5);
        actionLuminous = new QAction(MainWindow);
        actionLuminous->setObjectName(QString::fromUtf8("actionLuminous"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/stop64.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLuminous->setIcon(icon6);
        actionPrint_Set = new QAction(MainWindow);
        actionPrint_Set->setObjectName(QString::fromUtf8("actionPrint_Set"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/connect_creating.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint_Set->setIcon(icon7);
        actionDevice_Set = new QAction(MainWindow);
        actionDevice_Set->setObjectName(QString::fromUtf8("actionDevice_Set"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/setting48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDevice_Set->setIcon(icon8);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/about48px.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon9);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        menuFile_F = new QMenu(menuBar);
        menuFile_F->setObjectName(QString::fromUtf8("menuFile_F"));
        menuMeasure_M = new QMenu(menuBar);
        menuMeasure_M->setObjectName(QString::fromUtf8("menuMeasure_M"));
        menuSet_S = new QMenu(menuBar);
        menuSet_S->setObjectName(QString::fromUtf8("menuSet_S"));
        menuHelp_H = new QMenu(menuBar);
        menuHelp_H->setObjectName(QString::fromUtf8("menuHelp_H"));
        MainWindow->setMenuBar(menuBar);

        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave_As);
        mainToolBar->addAction(actionExport_All);
        mainToolBar->addAction(actionPrint);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionDevice_Set);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAbout);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionLuminous);
        mainToolBar->addAction(actionPrint_Set);
        menuBar->addAction(menuFile_F->menuAction());
        menuBar->addAction(menuMeasure_M->menuAction());
        menuBar->addAction(menuSet_S->menuAction());
        menuBar->addAction(menuHelp_H->menuAction());
        menuFile_F->addAction(actionNew);
        menuFile_F->addAction(actionOpen);
        menuFile_F->addAction(actionSave_As);
        menuFile_F->addAction(actionExport_All);
        menuFile_F->addAction(actionExport_Spectrum_Excel);
        menuFile_F->addSeparator();
        menuFile_F->addAction(actionPrint);
        menuFile_F->addSeparator();
        menuFile_F->addAction(actionExit);
        menuMeasure_M->addAction(actionConnect);
        menuMeasure_M->addAction(actionLuminous);
        menuSet_S->addAction(actionPrint_Set);
        menuSet_S->addAction(actionDevice_Set);
        menuHelp_H->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
        actionNew->setShortcut(QApplication::translate("MainWindow", "Alt+N", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Alt+O", 0, QApplication::UnicodeUTF8));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", 0, QApplication::UnicodeUTF8));
        actionSave_As->setShortcut(QApplication::translate("MainWindow", "Alt+S", 0, QApplication::UnicodeUTF8));
        actionExport_All->setText(QApplication::translate("MainWindow", "Export All(Excel)", 0, QApplication::UnicodeUTF8));
        actionExport_All->setShortcut(QApplication::translate("MainWindow", "Alt+E", 0, QApplication::UnicodeUTF8));
        actionExport_Spectrum_Excel->setText(QApplication::translate("MainWindow", "Export Spectrum(Excel)", 0, QApplication::UnicodeUTF8));
        actionPrint->setText(QApplication::translate("MainWindow", "Print", 0, QApplication::UnicodeUTF8));
        actionPrint->setShortcut(QApplication::translate("MainWindow", "Alt+P", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionConnect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        actionConnect->setShortcut(QApplication::translate("MainWindow", "Alt+C", 0, QApplication::UnicodeUTF8));
        actionLuminous->setText(QApplication::translate("MainWindow", "Luminous Curve", 0, QApplication::UnicodeUTF8));
        actionLuminous->setShortcut(QApplication::translate("MainWindow", "Alt+L", 0, QApplication::UnicodeUTF8));
        actionPrint_Set->setText(QApplication::translate("MainWindow", "Print Set", 0, QApplication::UnicodeUTF8));
        actionDevice_Set->setText(QApplication::translate("MainWindow", "Device Set", 0, QApplication::UnicodeUTF8));
        actionDevice_Set->setShortcut(QApplication::translate("MainWindow", "Alt+D", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionAbout->setShortcut(QApplication::translate("MainWindow", "Alt+A", 0, QApplication::UnicodeUTF8));
        menuFile_F->setTitle(QApplication::translate("MainWindow", "File(&F)", 0, QApplication::UnicodeUTF8));
        menuMeasure_M->setTitle(QApplication::translate("MainWindow", "Measure(&M)", 0, QApplication::UnicodeUTF8));
        menuSet_S->setTitle(QApplication::translate("MainWindow", "Set(&S)", 0, QApplication::UnicodeUTF8));
        menuHelp_H->setTitle(QApplication::translate("MainWindow", "Help(&H)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
