#include "DeviceLayout.h"

DeviceLayout::DeviceLayout(struct device &device)
	: device_(device)
{
	
}

void DeviceLayout::render()
{
	setBlankLeftWidth("dev-table-blank-left");
	setBlankTopHeight("dev-table-blank-top");
	
	WText *id = new WText(device_.id);
	this->renderId(id);

	WText *name = new WText(device_.name);
	this->renderName(name);

	WText *ip = new WText(device_.ip);
	this->renderIp(ip);

	WText *value = new WText(device_.value);
	this->renderValue(value);

	setBlankRightWidth("dev-table-blank-right");
	setBlankBottonHeight("dev-table-blank-botton");
}

void DeviceLayout::renderId(WWidget *widget)
{
	addWidget(0, 0, widget);
	setStyleClassCell(0, 0, "dev-id");
}

void DeviceLayout::renderName(WWidget *widget)
{
	addWidget(1, 1, widget);
	setStyleClassCell(1, 1, "dev-name");
}

void DeviceLayout::renderIp(WWidget *widget)
{
	addWidget(1, 2, widget);
	setStyleClassCell(1, 2, "dev-ip");
}

void DeviceLayout::renderValue(WWidget *widget)
{
	addWidget(1, 3, widget);
	setStyleClassCell(1, 3, "dev-value");
}

void DeviceLayout::renderControl(WWidget *widget)
{
	addWidget(1, 4, widget);
	setStyleClassCell(1, 4, "dev-control");
}