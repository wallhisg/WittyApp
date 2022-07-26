#include "ServerWidget.h"

ServerWidget::ServerWidget(WVBoxLayout *parent)
	: mainLayout_(parent)
{

}

void ServerWidget::createUi()
{
	dongAUi_ = new DongAUi(mainLayout_);
	dongAUi_->createUi();

}