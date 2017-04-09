#ifndef FRMINPUTBOX_H
#define FRMINPUTBOX_H

#include <QDialog>

namespace Ui
{
    class frmInputBox;
}

class frmInputBox : public QDialog
{
    Q_OBJECT

public:
    explicit frmInputBox(QWidget *parent = 0);
    ~frmInputBox();

    void setMessage(const QString title);

    QString getValue()const {
        return strValue;
    }

private slots:
    void on_btnOk_clicked();

private:
    Ui::frmInputBox *ui;

    void initStyle();   //初始化无边框窗体

    QString strValue;
};

#endif // FRMINPUTBOX_H
