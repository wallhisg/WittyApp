#include <Wt/WApplication>

#include "Layout.h"


Layout::Layout(WVBoxLayout *parent)
	: mainLayout_(parent)
{

}

void Layout::createUi()
{
	renderHeader();
	renderContent();

	struct device dev = {"1", "BTN", "192.168.1.1", "0"};
	renderDeviceLayout(dev);
}

void Layout::renderHeader()
{
	headerIcon = new Wt::WImage("resources/icons/DongA.png");
	headerIcon->setStyleClass("header-icon");

	banner = new WText(WString::tr("header.banner"));
	banner->setStyleClass("header-banner");

	header = new Header(headerIcon, banner)	;

	mainLayout_->addLayout(header->vLayout());
}

void Layout::renderContent()
{
	contentWt_ = new WTableLayout();

	WText *contLeft = new WText(WString::tr("cont.left"));
	contLeft->setStyleClass("table");
	contentWt_->addWidget(0, 0, contLeft);
	contentWt_->setLength(0, 25);
	contentWt_->setAlignment(0, 0, AlignCenter);

	WText *contCont = new WText(WString::tr("cont.cont"));
	contCont->setStyleClass("table");
	contentWt_->addWidget(0, 1, contCont);
	contentWt_->setAlignment(0, 1, AlignCenter);

	Content *content  = new Content();
	content->addWTableLayout(contentWt_);
	mainLayout_->addLayout(content->vLayout());
}

void Layout::renderDeviceLayout(struct device &device)
{
	DeviceWidget *devWidget = new DeviceWidget(device);
	DeviceLayout *devLayout = new DeviceLayout();
	devLayout->renderWidget(devWidget->widget());
	mainLayout_->addLayout(devLayout);
}