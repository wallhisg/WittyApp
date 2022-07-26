#include "ServerWidget.h"

ServerWidget::ServerWidget(WVBoxLayout *parent)
	: mainLayout_(parent)
{
	device_ = {"123", "BTN", "192.168.1.1", "1"};
	devLayout_ = new DeviceLayout(device_);
	mainLayout_->addItem(devLayout_->layout());
}

void ServerWidget::createUi()
{
	devLayout_->render();
}

