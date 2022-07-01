#include "Layout.h"
#include <Wt/WApplication>

Layout::Layout(WVBoxLayout *parent)
	: mainLayout_(parent)
{
	hdLayout_ = new WVBoxLayout();
	ctLayout_ = new WVBoxLayout();
	ftLayout_ = new WVBoxLayout();

	mainLayout_->addLayout(hdLayout_);
	mainLayout_->addLayout(ctLayout_);
	mainLayout_->addLayout(ftLayout_);
}

void Layout::createUi()
{
	renderHeader();
	renderContentHead();

	struct device dev = {"1", "BTN", "192.168.1.1", "0"};
	renderDeviceLayout(dev);
}

void Layout::renderHeader()
{
	header_ = new WTableLayout();

	// Header 00
	Wt::WImage* headerIcon;
	headerIcon = new Wt::WImage("resources/icons/DongA.png");
	headerIcon->setStyleClass("header-icon");
	header_->addWidget(0, 0, headerIcon);
	header_->setLength(0, 25);
	header_->setAlignment(0, 0, AlignCenter);

	// // Header 01
	WText *banner = new WText(WString::tr("header.banner"));
	banner->setStyleClass("header-banner");
	header_->addWidget(0, 1, banner);
	header_->setAlignment(0, 1, AlignCenter);
	
	hdLayout_->addWidget(header_);
}

void Layout::renderContentHead()
{
	content_ = new WTableLayout();

	WText *contLeft = new WText(WString::tr("cont.left"));
	contLeft->setStyleClass("table");
	content_->addWidget(0, 0, contLeft);
	content_->setLength(0, 25);
	content_->setAlignment(0, 0, AlignCenter);

	WText *contCont = new WText(WString::tr("cont.cont"));
	contCont->setStyleClass("table");
	content_->addWidget(0, 1, contCont);
	content_->setAlignment(0, 1, AlignCenter);

	ctLayout_->addWidget(content_);
}

void Layout::renderDeviceLayout(struct device &device)
{
	DeviceWidget *devWidget = new DeviceWidget(device);
	DeviceLayout *devLayout = new DeviceLayout();
	devLayout->setDeviceLayout(devWidget->widget());
	ctLayout_->addLayout(devLayout);
}