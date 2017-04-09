#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QDialog>
#include<QMap>

namespace Ui
{
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

private slots:
    void on_btnMenu_Max_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_5_clicked();
    void on_cboxStyle_currentIndexChanged(const QString &text);

private:
    Ui::frmMain *ui;

    void initStyle();   //初始化无边框窗体
    void initForm();    //初始化窗体数据

    bool m_max;           //是否处于最大化状态
    QRect locatRect;     //鼠标移动窗体后的坐标位置

    QMap<QString, QString> mapStyle;
};

#endif // FRMMAIN_H
