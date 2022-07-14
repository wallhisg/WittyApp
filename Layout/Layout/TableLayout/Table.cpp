#include "Table.h"


void Table::addTrWidget(WWidget *widget)
{
	table_->elementAt(0, currCol_)->addWidget(widget);
}

void Table::addTrWidget(const unsigned short col, WWidget *widget)
{
	table_->elementAt(0, col)->addWidget(widget);
}

void Table::addWidget(const unsigned short row, unsigned short col, 
							WWidget *widget)
{
	table_->elementAt(row, col)->addWidget(widget);
}

void Table::addWidget(WWidget *widget)
{
	table_->elementAt(currRow_, currCol_)->addWidget(widget);
}

void Table::setLength(const unsigned short col, const unsigned char  per)
{
	table_->columnAt(col)->setWidth(WLength(per, WLength::Percentage));
}

void Table::setLength(const unsigned char  per)
{
	table_->columnAt(currCol_)->setWidth(WLength(per, WLength::Percentage));
}

void Table::setAlignment(const unsigned short row, const unsigned short col, 
								Wt::AlignmentFlag alignment)
{
	table_->elementAt(row, col)->setContentAlignment(alignment);
}

void Table::setAlignment(Wt::AlignmentFlag alignment)
{
	table_->elementAt(currRow_, currCol_)->setContentAlignment(alignment);
}

void Table::setPadding(const unsigned short row, const unsigned short col,
								const unsigned short pad)
{
	table_->elementAt(row, col)->setPadding(pad);
}

void Table::setPadding(const unsigned short pad)
{
	table_->elementAt(currRow_, currCol_)->setPadding(pad);
}

void Table::setMargin(const unsigned short row, const unsigned short col,
					const unsigned short margin)
{
	table_->elementAt(row, col)->setMargin(margin);
}