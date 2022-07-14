#include "TableLayout.h"

TableLayout::TableLayout()
{
	vLayout_ = new WVBoxLayout();
	vLayout_->addWidget(this->table());
}

void TableLayout::setStyleClass(const WString &style)
{
	this->table()->setStyleClass(style);
}

void TableLayout::setStyleClassCell(const unsigned short row, const unsigned short col, 
								const WString &style)
{
	WWidget *widget = this->table()->elementAt(row, col);
	widget->setStyleClass(style);
}

void TableLayout::setStyleClassRow(const unsigned short row, const WString &style)
{
	WTableRow *tableRow = this->table()->rowAt(row);
	tableRow->setStyleClass(style);
}

void TableLayout::setStyleClassColumn(const unsigned short col, const WString &style)
{
	WTableColumn *tableCol = this->table()->columnAt(col);
	tableCol->setStyleClass(style);
}