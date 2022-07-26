#include <Wt/WApplication>

#include "Layout.h"


Layout::Layout(WVBoxLayout *parent)
	: mainLayout_(parent)
{

}

void Layout::createUi()
{
	renderHeader();
	// renderContent();

	// struct device dev = {"1", "BTN", "192.168.1.1", "0"};
	// renderDeviceLayout(dev);
}

void Layout::renderHeader()
{
	headerIcon = new Wt::WImage("resources/icons/DongA.png");
	headerIcon->setStyleClass("header-icon");

	banner = new WText(WString::tr("header.banner"));
	banner->setStyleClass("header-banner");

	// header = new Header(headerIcon, banner)	;

	// mainLayout_->addLayout(header->vLayout());
}

void Layout::renderContent()
{
	// tbl_tr_devWt_ = new Table();

	// WText *tbl_tr_devId_ = new WText(WString::tr("tbl.tr.devId"));
	// tbl_tr_devId_->setStyleClass("table");
	// tbl_tr_devWt_->addWidget(0, 0, tbl_tr_devId_);
	// tbl_tr_devWt_->setLength(0, 25);
	// tbl_tr_devWt_->setAlignment(0, 0, AlignCenter);

	// WText *tbl_tr_devItem_ = new WText(WString::tr("tbl.tr.devItem"));
	// tbl_tr_devItem_->setStyleClass("table");
	// tbl_tr_devWt_->addWidget(0, 1, tbl_tr_devItem_);
	// tbl_tr_devWt_->setAlignment(0, 1, AlignCenter);

	// Content *content  = new Content();
	// content->addTable(tbl_tr_devWt_);
	// mainLayout_->addLayout(content->vLayout());
}

void Layout::renderDeviceLayout(struct device &device)
{
	// DeviceWidget *devWidget = new DeviceWidget(device);
	// DeviceLayout *devLayout = new DeviceLayout();
	// devLayout->renderWidget(devWidget->widget());
	// mainLayout_->addLayout(devLayout);
}