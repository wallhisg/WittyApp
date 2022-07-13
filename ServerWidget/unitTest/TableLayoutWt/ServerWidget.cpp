#include "ServerWidget.h"

ServerWidget::ServerWidget(WVBoxLayout *parent)
	: mainLayout_(parent)
{

}

void ServerWidget::createUi()
{
	renderHeader();
	renderContent();

}

void ServerWidget::renderHeader()
{
	headerIcon_ = new Wt::WImage("resources/icons/DongA.png");
	headerIcon_->setStyleClass("header-icon");

	headerBanner_ = new WText(WString::tr("header.banner"));
	headerBanner_->setStyleClass("header-banner");

	header_ = new Header(headerIcon_, headerBanner_);
	mainLayout_->addLayout(header_->vLayout());
}

void ServerWidget::renderContent()
{
	content_ = new Content();

	tbl_tr_devId_ = new WText(WString::tr("tbl.tr.devId"));

	content_->addWidget(0, 0, tbl_tr_devId_);

	mainLayout_->addLayout(content_->vLayout());

}