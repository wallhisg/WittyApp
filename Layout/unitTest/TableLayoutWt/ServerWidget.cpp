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
	// header_->setBlankLeftWidth(25);
	header_->setBlankLeftWidth("table-blank");
	header_->setBlankTopHeight("table-blank-top");

	WImage *headerIcon_ = new Wt::WImage("resources/icons/DongA.png");
	// headerIcon_->setStyleClass("header-icon");

	WText *headerBanner_ = new WText(WString::tr("header.banner"));
	// headerBanner_->setStyleClass("header-banner");




	header_->addWidget(0, 0, headerIcon_);
	// header_->setStyleClassCell(0, 0, "header-icon");
	// header_->setAlignment(AlignCenter | AlignMiddle);

	header_->addWidget(0, 1, headerBanner_);
	// header_->setStyleClassCell(0, 1, "header-banner");

	header_->setBlankBottonHeight("table-blank-botton");
	header_->setBlankRightWidth("table-blank");

	mainLayout_->addLayout(header_->vLayout());
}

void ServerWidget::renderContent()
{
	// content_ = new Content();

	// tbl_tr_devId_ = new WText(WString::tr("tbl.tr.devId"));
	// WText *tbl_tr_devId1_ = new WText(WString::tr("tbl.tr.devId"));
	// WText *tbl_tr_devId2_ = new WText(WString::tr("tbl.tr.devId"));
	// WText *tbl_tr_devId3_ = new WText(WString::tr("tbl.tr.devId"));

	// content_->addWidget(0, 0, tbl_tr_devId_);

	// tableLayout = new TableLayout();
	// tableLayout->addWidget(0, 0, tbl_tr_devId_);
	// tableLayout->addWidget(0, 1, tbl_tr_devId1_);
	// tableLayout->addWidget(0, 2, tbl_tr_devId2_);
	// tableLayout->addWidget(0, 3, tbl_tr_devId3_);
	// tableLayout->setStyleClassCell(0, 0, "table-dev");
	// tableLayout->setStyleClassColumn(2, "table");
	// tableLayout->setLength(0, 15);
	// tableLayout->setLength(1, 25);
	// tableLayout->setLength(2, 25);

	// mainLayout_->addLayout(content_->vLayout());
	// mainLayout_->addLayout(tableLayout->vLayout());

}