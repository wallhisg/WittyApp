#include "Header.h"

// Header 00
void HeaderLayout::addHeaderWidget_At00(WWidget *widget)
{
	this->elementAt(0, 0)->addWidget(widget);
}

void HeaderLayout::setHeaderLenghtPercentage_At00(const unsigned char  &per)
{
	this->columnAt(0)->setWidth(WLength(per, WLength::Percentage));
}

void HeaderLayout::setContentAlignment_At00(Wt::AlignmentFlag alignment)
{
	this->elementAt(0, 0)->setContentAlignment(alignment);
}

void HeaderLayout::setHeaderPadding_At00(const unsigned short &pad)
{
	this->elementAt(0, 0)->setPadding(pad);
}

// Header 00
void HeaderLayout::addHeaderWidget_At01(WWidget *widget)
{
	this->elementAt(0, 1)->addWidget(widget);
}

void HeaderLayout::setHeaderLenghtPercentage_At01(const unsigned char &per)
{
	this->columnAt(1)->setWidth(WLength(per, WLength::Percentage));
}

void HeaderLayout::setContentAlignment_At01(Wt::AlignmentFlag alignment)
{
	this->elementAt(0, 1)->setContentAlignment(alignment);
}

void HeaderLayout::setHeaderPadding_At01(const unsigned short &pad)
{
	this->elementAt(0, 1)->setPadding(pad);
}