#ifndef FRMNUM_H
#define FRMNUM_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QTextBrowser>
#include <QPushButton>
#include <QTimer>

namespace Ui
{
    class frmNum;
}

class frmNum : public QWidget
{
    Q_OBJECT

public:
    explicit frmNum(QWidget *parent = 0);
    ~frmNum();

    //单例模式,保证一个程序只存在一个输入法实例对象
    static frmNum *Instance() {
        if (!_instance) {
            _instance = new frmNum;
        }
        return _instance;
    }

    //初始化面板状态,包括字体大小
    void Init(QString style, int fontSize);

protected:
    //事件过滤器,处理鼠标按下弹出输入法面板
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    //焦点改变事件槽函数处理
    void focusChanged(QWidget *oldWidget, QWidget *nowWidget);
    //输入法面板按键处理
    void btn_clicked();
    //改变输入法面板样式
    void changeStyle(QString topColor, QString bottomColor,
                     QString borderColor, QString textColor);
    //定时器处理退格键
    void reClicked();

private:
    Ui::frmNum *ui;
    static frmNum *_instance;       //实例对象

    bool isPress;                   //是否长按退格键
    QPushButton *btnPress;          //长按按钮
    QTimer *timerPress;             //退格键定时器
    bool checkPress();              //校验当前长按的按钮

    bool isFirst;                   //是否首次加载
    void InitForm();                //初始化窗体数据
    void InitProperty();            //初始化属性
    void ChangeStyle();             //改变样式

    QWidget *currentWidget;         //当前焦点的对象
    QLineEdit *currentLineEdit;     //当前焦点的单行文本框
    QTextEdit *currentTextEdit;     //当前焦点的多行文本框
    QPlainTextEdit *currentPlain;   //当前焦点的富文本框
    QTextBrowser *currentBrowser;   //当前焦点的文本浏览框

    QString currentEditType;        //当前焦点控件的类型
    QString currentStyle;           //当前输入法面板样式
    int currentFontSize;            //当前输入法面板字体大小
    void insertValue(QString value);//插入值到当前焦点控件
    void deleteValue();             //删除当前焦点控件的一个字符

};

#endif // FRMNUM_H
