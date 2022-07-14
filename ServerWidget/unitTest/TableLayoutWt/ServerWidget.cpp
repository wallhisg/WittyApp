#include "ServerWidget.h"

ServerWidget::ServerWidget(WVBoxLayout *parent)
	: mainLayout_(parent)
{
	header_ = new TableLayout();
	content_ = new TableLayout();
	footer_ = new TableLayout();

	mainLayout_->addLayout(header_->vLayout());
	mainLayout_->addLayout(content_->vLayout());
	mainLayout_->addLayout(footer_->vLayout());
}

void ServerWidget::createUi()
{
	renderHeader();
	renderContent();
	renderFooter();

}

void ServerWidget::renderHeader()
{

}

void ServerWidget::renderContent()
{


}

void ServerWidget::renderFooter()
{

}