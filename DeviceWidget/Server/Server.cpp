#include <Server.h>

ServerWidget::ServerWidget(WContainerWidget *parent)
	:	WContainerWidget(parent)
 
{
	this->addWidget(new Wt::WText("Server Widget"));

	devWidget = new DeviceWidget(this);
}