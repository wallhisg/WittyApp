#include "ServerWidget.h"

ServerWidget::ServerWidget(WVBoxLayout *parent)
	: mainLayout_(parent)
{
	header_ = new Header();
	mainLayout_->addItem(header_->layout());

	cout << "count: " << mainLayout_->count() << endl;
}

void ServerWidget::createUi()
{
	renderHeader();
}

void ServerWidget::renderHeader()
{
	header_->render();
}

