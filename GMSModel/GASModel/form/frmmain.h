#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QDialog>
#include <QSystemTrayIcon>

class QToolButton;

namespace Ui {
class frmMain;
}

class frmMain : public QDialog
{
    Q_OBJECT

public:
    explicit frmMain(QWidget *parent = 0);
    ~frmMain();

protected:
    bool eventFilter(QObject *obj, QEvent *event);

private:
    Ui::frmMain *ui;
    bool max;
    QRect location;
    QSystemTrayIcon *trayIcon;

private slots:
    void initStyle();
    void initForm();
    void buttonClick();
    void buttonCheck(QToolButton *btn);

private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void iconIsActived(QSystemTrayIcon::ActivationReason reason);
};

#endif // FRMMAIN_H
