#include "switchbutton.h"

SwitchButton::SwitchButton(QWidget *parent): QPushButton(parent)
{
	isCheck = false;
	styleOn = "border-image:url(:/image/btn_check_on.png);";
	styleOff = "border-image:url(:/image/btn_check_off.png);";

	setFocusPolicy(Qt::NoFocus);
	setStyleSheet(styleOff);
	connect(this, SIGNAL(pressed()), this, SLOT(changeOnOff()));
}

void SwitchButton::changeOnOff()
{
	if (isCheck) {
		setStyleSheet(styleOff);
		isCheck = false;
	} else {
		setStyleSheet(styleOn);
		isCheck = true;
	}
}

//设置当前选中状态
void SwitchButton::setCheck(bool isCheck)
{
	if (this->isCheck != isCheck) {
		this->isCheck = !isCheck;
		changeOnOff();
	}
}
