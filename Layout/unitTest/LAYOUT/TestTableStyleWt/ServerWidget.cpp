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
	header_ = new TableLayout();

	header_->setBlankLeftWidth("table-blank-left");
	header_->setBlankTopHeight("table-blank-top");

	WImage *headerIcon_ = new Wt::WImage("resources/icons/DongA.png");

	WText *headerBanner_ = new WText(WString::tr("header.banner"));

	header_->addWidget(0, 0, headerIcon_);

	header_->addWidget(0, 1, headerBanner_);
	header_->setBlankRightWidth("table-blank-right");
	header_->setBlankBottonHeight("table-blank-botton");


	mainLayout_->addLayout(header_->layout());
}

void ServerWidget::renderContent()
{

}