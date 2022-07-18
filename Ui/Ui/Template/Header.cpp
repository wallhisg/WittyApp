#include "Header.h"

Header::Header()
{

}

void Header::render()
{
	WImage  *icon_ = new Wt::WImage("resources/icons/DongA.png");
	this->addWidget(0, 0, icon_);
	this->setStyleClassCell(0, 0, "header-icon");

	WText  *banner_ = new WText(WString::tr("header.banner"));
	this->addWidget(0, 1, banner_);
	this->setStyleClassCell(0, 0, "header-banner");
}