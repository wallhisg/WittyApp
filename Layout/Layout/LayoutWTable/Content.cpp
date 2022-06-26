#include "Content.h"

void ContentLayout::addWidget(const unsigned short row, const unsigned short col, 
								WWidget *widget)
{
	this->elementAt(row, col)->addWidget(widget);
}

void ContentLayout::setLength(const unsigned short col, const unsigned char  per)
{
	this->columnAt(col)->setWidth(WLength(per, WLength::Percentage));
}

void ContentLayout::setAlignment(const unsigned short row, const unsigned short col, 
									Wt::AlignmentFlag alignment)
{
	this->elementAt(row, col)->setContentAlignment(alignment);
}

void ContentLayout::setPadding(const unsigned short row, const unsigned short col,
								const unsigned short pad)
{
	this->elementAt(row, col)->setPadding(pad);
}
