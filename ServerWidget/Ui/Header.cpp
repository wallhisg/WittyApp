#include "Header.h"

Header::Header(WImage *headerIcon, WText *headerBanner)
	: 	headerIcon_(headerIcon),
		headerBanner_(headerBanner)
{
	vLayout_ = new WVBoxLayout();

	renderHeader();
}

void Header::renderHeader()
{
	// render Icon
	this->addWidget(0, 0, headerIcon_);
	this->setLength(0, 25);
	this->setAlignment(0,0, AlignCenter);

	// // // render banner
	this->addWidget(0, 1, headerBanner_);
	this->setAlignment(0, 1, AlignCenter);

	vLayout_->addWidget(this->table());
}