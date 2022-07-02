#include "DeviceLayout.h"

DeviceLayout::DeviceLayout()
{
	wtLayout_ = new WTableLayout();
	this->addWidget(wtLayout_);
}

void DeviceLayout::setDeviceLayout(DeviceWidget::Widget *widget)
{
	widget_ = widget;

	renderId(widget_->id);
	renderItems(widget_->name, widget_->ip, widget_->value);
}

void DeviceLayout::renderId(WWidget *id)
{
	wtLayout_->setLength(0, 25);
	wtLayout_->setAlignment(0, 0, AlignCenter);

	wtLayout_->addWidget(0, 0, id);
}

void DeviceLayout::renderItems(WWidget *name, WWidget *ip, WWidget *value)
{
	WHBoxLayout *devItLayout = new WHBoxLayout();

	WContainerWidget *wc = new WContainerWidget();
	wc->setLayout(devItLayout);
	wc->setStyleClass("dev-it");

	devItLayout->addWidget(name);
	devItLayout->addWidget(ip);
	devItLayout->addWidget(value);
	
	int currRow = wtLayout_->rowCount();

	int newRow = currRow;
	int newCol = 1;

	wtLayout_->addWidget(newRow, newCol, wc);
	wtLayout_->setAlignment(newRow, newCol, AlignCenter);
	wtLayout_->setPadding(newRow, newCol, 0);
	wtLayout_->setMargin(newRow, newCol, 0);
}