#include "Header.h"

Header::Header()
{
	vLayout_ = new WVBoxLayout();
	vLayout_->addWidget(this->table_);
}

void Header::renderIcon(const unsigned short row, const short col, WImage *icon)
{
	this->addWidget(row, col, icon);
}

void Header::renderBanner(const unsigned short row, const short col, WWidget *banner)
{
	this->addWidget(row, col, banner);
}