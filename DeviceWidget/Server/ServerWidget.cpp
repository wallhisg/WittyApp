#include "ServerWidget.h"


void changeName(WString name);

ServerWidget::ServerWidget(WContainerWidget *parent)
	:	WContainerWidget(parent),
        wcDevice_(0),
        loggedIn_(false)
{
	this->addWidget(new Wt::WText("Server Widget"));

    if (loggedIn_)
    {
        wcDevice_ = new WContainerWidget(this);
        wcDevice_->setOverflow(WContainerWidget::OverflowAuto);
    }

    if (!wcDevice_->parent())
    {
        delete wcDevice_;
        wcDevice_ = 0;
    }

}

bool ServerWidget::loggedIn() const
{
    return loggedIn_;
}

void ServerWidget::addDeviceWidget(struct device& device)
{
    DeviceWidget *dev = new DeviceWidget(device);

    devMap_.insertDeviceWidget(dev);

}

void ServerWidget::renderDeviceWidget()
{


}
