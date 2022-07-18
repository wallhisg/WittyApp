#include "ServerWidget.h"

ServerWidget::ServerWidget(WVBoxLayout *parent)
	: mainLayout_(parent)
{

}

void ServerWidget::createUi()
{
	ui_ = new Ui(mainLayout_);
	ui_->renderUi();
}

