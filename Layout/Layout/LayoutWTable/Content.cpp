#include "Content.h"

// Content 00
void ContentLayout::addContentWidget_At00(WWidget *widget)
{
	this->elementAt(0, 0)->addWidget(widget);
}

void ContentLayout::setContentLenghtPercentage_At00(const unsigned char  &per)
{
	this->columnAt(0)->setWidth(WLength(per, WLength::Percentage));
}

void ContentLayout::setContentAlignment_At00(Wt::AlignmentFlag alignment)
{
	this->elementAt(0, 0)->setContentAlignment(alignment);
}

void ContentLayout::setContentPadding_At00(const unsigned short &pad)
{
	this->elementAt(0, 0)->setPadding(pad);
}

// Content 00
void ContentLayout::addContentWidget_At01(WWidget *widget)
{
	this->elementAt(0, 1)->addWidget(widget);
}

void ContentLayout::setContentLenghtPercentage_At01(const unsigned char &per)
{
	this->columnAt(1)->setWidth(WLength(per, WLength::Percentage));
}

void ContentLayout::setContentAlignment_At01(Wt::AlignmentFlag alignment)
{
	this->elementAt(0, 1)->setContentAlignment(alignment);
}

void ContentLayout::setContentPadding_At01(const unsigned short &pad)
{
	this->elementAt(0, 1)->setPadding(pad);
}