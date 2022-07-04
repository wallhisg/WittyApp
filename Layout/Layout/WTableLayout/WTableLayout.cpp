#include "WTableLayout.h"

void WTableLayout::addTrWidget(WWidget *widget)
{
	this->elementAt(0, currCol_)->addWidget(widget);
}

void WTableLayout::addTrWidget(const unsigned short col, WWidget *widget)
{
	this->elementAt(0, col)->addWidget(widget);
}

void WTableLayout::addWidget(const unsigned short row, const unsigned short col, 
								WWidget *widget)
{
	this->elementAt(row, col)->addWidget(widget);
}

void WTableLayout::addWidget(WWidget *widget)
{
	this->elementAt(currRow_, currCol_)->addWidget(widget);
}

void WTableLayout::setLength(const unsigned short col, const unsigned char  per)
{
	this->columnAt(col)->setWidth(WLength(per, WLength::Percentage));
}

void WTableLayout::setLength(const unsigned char  per)
{
	this->columnAt(currCol_)->setWidth(WLength(per, WLength::Percentage));
}

void WTableLayout::setAlignment(const unsigned short row, const unsigned short col, 
									Wt::AlignmentFlag alignment)
{
	this->elementAt(row, col)->setContentAlignment(alignment);
}

void WTableLayout::setAlignment(Wt::AlignmentFlag alignment)
{
	this->elementAt(currRow_, currCol_)->setContentAlignment(alignment);
}

void WTableLayout::setPadding(const unsigned short row, const unsigned short col,
								const unsigned short pad)
{
	this->elementAt(row, col)->setPadding(pad);
}

void WTableLayout::setPadding(const unsigned short pad)
{
	this->elementAt(currRow_, currCol_)->setPadding(pad);
}

void WTableLayout::setStyleClass(const WString &style)
{
	this->setStyleClass(style);
}

void WTableLayout::setMargin(const unsigned short row, const unsigned short col,
					const unsigned short margin)
{
	this->elementAt(row, col)->setMargin(margin);
}