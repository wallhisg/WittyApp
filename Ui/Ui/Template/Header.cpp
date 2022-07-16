#include "Header.h"

Header::Header()
{
	icon_ = new Wt::WImage("resources/icons/DongA.png");
	banner_ = new WText(WString::tr("header.banner"));

	renderHeader();
}

void Header::renderHeader()
{
	this->addWidget(0, 0, icon_);
	this->setStyleClassCell(0, 0, "header-icon");

	this->addWidget(0, 1, banner_);
	this->setStyleClassCell(0, 0, "header-banner");
}