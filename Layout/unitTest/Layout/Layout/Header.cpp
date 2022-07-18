#include "Header.h"

Header::Header()
{

}


void Header::render()
{
	WImage *icon = new Wt::WImage("resources/icons/DongA.png");
	WText *banner = new WText(WString::tr("header.banner"));

	this->addWidget(0, 0, icon);
	this->addWidget(0, 1, banner);
}

