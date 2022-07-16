#include "ServerWidget.h"

ServerWidget::ServerWidget(WVBoxLayout *parent)
	: mainLayout_(parent)
{

}

void ServerWidget::createUi()
{
	renderHeader();
	renderContent();
	renderFooter();
}

void ServerWidget::renderHeader()
{
	header_ = new Header();
	mainLayout_->addLayout(header_->vLayout());
}

void ServerWidget::renderContent()
{
	content_ = new Content();
	mainLayout_->addLayout(content_->vLayout());
}

void ServerWidget::renderFooter()
{
	footer_ = new Footer();
	mainLayout_->addLayout(footer_->vLayout());
}