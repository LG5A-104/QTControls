/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave_As;
    QAction *actionExport;
    QAction *actionPrint;
    QAction *actionExit;
    QAction *actionConnect;
    QAction *actionStop;
    QAction *actionDevice_Set;
    QAction *actionAbout;
    QAction *actionRun;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile_F;
    QMenu *menuMeasure_M;
    QMenu *menuSet_S;
    QMenu *menuHelp_H;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/24px.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/open482.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/save32px.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon2);
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/excel48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport->setIcon(icon3);
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QStringLiteral("actionPrint"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/print48px.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon4);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/connect_creating.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon5);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/stop64.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon6);
        actionDevice_Set = new QAction(MainWindow);
        actionDevice_Set->setObjectName(QStringLiteral("actionDevice_Set"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/setting48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDevice_Set->setIcon(icon7);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/about48px.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon8);
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName(QStringLiteral("actionRun"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/start48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon9);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menuFile_F = new QMenu(menubar);
        menuFile_F->setObjectName(QStringLiteral("menuFile_F"));
        menuMeasure_M = new QMenu(menubar);
        menuMeasure_M->setObjectName(QStringLiteral("menuMeasure_M"));
        menuSet_S = new QMenu(menubar);
        menuSet_S->setObjectName(QStringLiteral("menuSet_S"));
        menuHelp_H = new QMenu(menubar);
        menuHelp_H->setObjectName(QStringLiteral("menuHelp_H"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile_F->menuAction());
        menubar->addAction(menuMeasure_M->menuAction());
        menubar->addAction(menuSet_S->menuAction());
        menubar->addAction(menuHelp_H->menuAction());
        menuFile_F->addAction(actionNew);
        menuFile_F->addAction(actionOpen);
        menuFile_F->addAction(actionSave_As);
        menuFile_F->addAction(actionExport);
        menuFile_F->addSeparator();
        menuFile_F->addAction(actionPrint);
        menuFile_F->addSeparator();
        menuFile_F->addAction(actionExit);
        menuMeasure_M->addAction(actionConnect);
        menuMeasure_M->addAction(actionRun);
        menuMeasure_M->addAction(actionStop);
        menuSet_S->addAction(actionDevice_Set);
        menuHelp_H->addAction(actionAbout);
        toolBar->addAction(actionNew);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave_As);
        toolBar->addAction(actionExport);
        toolBar->addAction(actionPrint);
        toolBar->addSeparator();
        toolBar->addAction(actionConnect);
        toolBar->addAction(actionRun);
        toolBar->addAction(actionStop);
        toolBar->addSeparator();
        toolBar->addAction(actionDevice_Set);
        toolBar->addSeparator();
        toolBar->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionNew->setShortcut(QApplication::translate("MainWindow", "Alt+N", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Alt+O", 0));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", 0));
        actionExport->setText(QApplication::translate("MainWindow", "Export Excel", 0));
        actionExport->setShortcut(QApplication::translate("MainWindow", "Alt+E", 0));
        actionPrint->setText(QApplication::translate("MainWindow", "Print", 0));
        actionPrint->setShortcut(QApplication::translate("MainWindow", "Alt+P", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionConnect->setText(QApplication::translate("MainWindow", "Connect", 0));
        actionStop->setText(QApplication::translate("MainWindow", "Stop", 0));
        actionDevice_Set->setText(QApplication::translate("MainWindow", "Device Set", 0));
        actionDevice_Set->setShortcut(QApplication::translate("MainWindow", "Alt+S", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionAbout->setShortcut(QApplication::translate("MainWindow", "Alt+A", 0));
        actionRun->setText(QApplication::translate("MainWindow", "Run", 0));
        actionRun->setShortcut(QApplication::translate("MainWindow", "Alt+R", 0));
        menuFile_F->setTitle(QApplication::translate("MainWindow", "File(&F)", 0));
        menuMeasure_M->setTitle(QApplication::translate("MainWindow", "Measure(&M)", 0));
        menuSet_S->setTitle(QApplication::translate("MainWindow", "Set(&S)", 0));
        menuHelp_H->setTitle(QApplication::translate("MainWindow", "Help(&H)", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
