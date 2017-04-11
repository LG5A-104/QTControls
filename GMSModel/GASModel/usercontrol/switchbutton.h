#ifndef SWITCHBUTTON_H
#define SWITCHBUTTON_H

#include <QPushButton>

class SwitchButton : public QPushButton
{
	Q_OBJECT
public:
	explicit SwitchButton(QWidget *parent = 0);

	//获取当前选中状态
	bool getCheck() const
	{
		return isCheck;
	}

	//设置当前选中状态
	void setCheck(bool isCheck);

private:
	bool isCheck;
	QString styleOn;
	QString styleOff;

signals:

private slots:
	void changeOnOff();

};

#endif //SWITCHBUTTON_H
