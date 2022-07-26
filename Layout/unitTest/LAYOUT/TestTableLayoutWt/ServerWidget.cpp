#include "ServerWidget.h"

ServerWidget::ServerWidget(WVBoxLayout *parent)
	: mainLayout_(parent)
{

}

void ServerWidget::createUi()
{
	renderHeader();
}

void ServerWidget::renderHeader()
{
	WImage *headerIcon_ = new Wt::WImage("resources/icons/DongA.png");
	WText *headerBanner_ = new WText(WString::tr("header.banner"));


	header_ = new TableLayout();
	header_->setStyleClass("table");
	header_->addWidget(0, 0, headerIcon_);
	header_->addWidget(0, 1, headerBanner_);

	content_ = new TableLayout();
	content_->addWidget(new WText("Content Widgets"));
	header_->addLayout(content_);

	mainLayout_->addLayout(header_->vLayout());

	header_->removeLayout(content_);

	// mainLayout_->addLayout(content_->vLayout());
}

