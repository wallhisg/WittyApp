#include "DeviceLayout.h"

void DeviceLayout::render()
{

}

void DeviceLayout::renderId(WWidget *widget)
{
	this->addWidget(0, 0, widget);
}

void DeviceLayout::renderName(WWidget *widget)
{
	this->addWidget(1, 1, widget);
}

void DeviceLayout::renderIp(WWidget *widget)
{
	this->addWidget(1, 2, widget);
}

void DeviceLayout::renderValue(WWidget *widget)
{
	this->addWidget(1, 3, widget);
}

void DeviceLayout::renderControl(WWidget *widget)
{
	this->addWidget(1, 4, widget);
}
