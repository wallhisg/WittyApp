#include "TableLayout.h"


void TableLayout::addTrWidget(WWidget *widget)
{
	table_->elementAt(0, currCol_)->addWidget(widget);
}

void TableLayout::addTrWidget(const unsigned short col, WWidget *widget)
{
	table_->elementAt(0, col)->addWidget(widget);
}

void TableLayout::addWidget(const unsigned short row, const unsigned short col, 
							WWidget *widget)
{
	table_->elementAt(row, col)->addWidget(widget);
}

void TableLayout::addWidget(WWidget *widget)
{
	table_->elementAt(currRow_, currCol_)->addWidget(widget);
}

void TableLayout::setLength(const unsigned short col, const unsigned char  per)
{
	table_->columnAt(col)->setWidth(WLength(per, WLength::Percentage));
}

void TableLayout::setLength(const unsigned char  per)
{
	table_->columnAt(currCol_)->setWidth(WLength(per, WLength::Percentage));
}

void TableLayout::setAlignment(const unsigned short row, const unsigned short col, 
								Wt::AlignmentFlag alignment)
{
	table_->elementAt(row, col)->setContentAlignment(alignment);
}

void TableLayout::setAlignment(Wt::AlignmentFlag alignment)
{
	table_->elementAt(currRow_, currCol_)->setContentAlignment(alignment);
}

void TableLayout::setPadding(const unsigned short row, const unsigned short col,
								const unsigned short pad)
{
	table_->elementAt(row, col)->setPadding(pad);
}

void TableLayout::setPadding(const unsigned short pad)
{
	table_->elementAt(currRow_, currCol_)->setPadding(pad);
}

void TableLayout::setStyleClass(const WString &style)
{
	table_->setStyleClass(style);
}

void TableLayout::setMargin(const unsigned short row, const unsigned short col,
					const unsigned short margin)
{
	table_->elementAt(row, col)->setMargin(margin);
}