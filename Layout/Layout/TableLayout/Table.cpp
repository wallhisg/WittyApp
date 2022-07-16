#include "Table.h"


void Table::addTrWidget(WWidget *widget)
{
	if (widget != NULL)
		table_->elementAt(0, offsetColLeft_ + currCol_)->addWidget(widget);
}

void Table::addTrWidget(const int col, WWidget *widget)
{
	if (widget != NULL)
		table_->elementAt(0, offsetColLeft_ + col)->addWidget(widget);
}

void Table::addWidget(const int row, int col, 
							WWidget *widget)
{
	if (widget != NULL)
		table_->elementAt(offsetRowTop_ + row, offsetColLeft_ + col)->addWidget(widget);
}

void Table::addWidget(WWidget *widget)
{
	if (widget != NULL)
		table_->elementAt(currRow_, offsetColLeft_ + currCol_)->addWidget(widget);
}

void Table::setLength(const int col, const int  percentage)
{
	table_->columnAt(offsetColLeft_ + col)->setWidth(WLength(percentage, WLength::Percentage));
}

void Table::setLength(const int  percentage)
{
	table_->columnAt(offsetColLeft_ + currCol_)->setWidth(WLength(percentage, WLength::Percentage));
}

void Table::setAlignment(const int row, const int col, 
								Wt::AlignmentFlag alignment)
{
	table_->elementAt(offsetRowTop_ + row, offsetColLeft_ + col)->setContentAlignment(alignment);
}

void Table::setAlignment(Wt::AlignmentFlag alignment)
{
	table_->elementAt(currRow_, offsetColLeft_ + currCol_)->setContentAlignment(alignment);
}

void Table::setPadding(const int row, const int col,
								const int pad)
{
	table_->elementAt(offsetRowTop_ + row, offsetColLeft_ + col)->setPadding(pad);
}

void Table::setPadding(const int pad)
{
	table_->elementAt(offsetRowTop_ + currRow_, offsetColLeft_ + currCol_)->setPadding(pad);
}

void Table::setMargin(const int row, const int col,
					const int margin)
{
	table_->elementAt(offsetRowTop_ + row, offsetColLeft_ + col)->setMargin(margin);
}

