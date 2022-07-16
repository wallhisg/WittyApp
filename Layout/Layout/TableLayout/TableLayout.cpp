#include "TableLayout.h"

TableLayout::TableLayout()
{
	vLayout_ = new WVBoxLayout();
	vLayout_->addWidget(table_);
}

void TableLayout::setStyleClass(const WString &style)
{
	table_->setStyleClass(style);
}

void TableLayout::setStyleClassCell(const int row, const int col, 
								const WString &style)
{
	WWidget *widget = table_->elementAt(row, col);
	widget->setStyleClass(style);
}

void TableLayout::setStyleClassRow(const int row, const WString &style)
{
	WTableRow *tableRow = table_->rowAt(row);
	tableRow->setStyleClass(style);
}

void TableLayout::setStyleClassColumn(const int col, const WString &style)
{
	WTableColumn *tableCol = table_->columnAt(col);
	tableCol->setStyleClass(style);
}

void TableLayout::setBlankRowHeight(const int row, const int height)
{
	WTableRow *currRow = table_->rowAt(row);
	currRow->setHeight(height);
}

void TableLayout::setBlankRowHeight(const int row, const WString &style)
{
	WTableRow *currRow = table_->rowAt(row);
	currRow->setStyleClass(style);
}

void TableLayout::setBlankLeftWidth(const int percentage)
{
	WTableColumn *leftCol = table_->columnAt(0);
	leftCol->setWidth(WLength(percentage, WLength::Percentage));
	offsetColLeft_ = 1;
}

void TableLayout::setBlankLeftWidth(const WString &style)
{
	WTableColumn *leftCol = table_->columnAt(0);
	leftCol->setStyleClass(style);
	offsetColLeft_ = 1;
}

void TableLayout::setBlankRightWidth(const int percentage)
{
	int lastCol = table_->columnCount();

	WTableColumn *rightCol = table_->columnAt(lastCol);
	rightCol->setWidth(WLength(percentage, WLength::Percentage));
}

void TableLayout::setBlankRightWidth(const WString &style)
{
	offsetColRight_ = table_->columnCount();

	WTableColumn *rightCol = table_->columnAt(offsetColRight_);
	rightCol->setStyleClass(style);
}

void TableLayout::setBlankTopHeight(const int height)
{
	WTableRow *firstRow = table_->rowAt(0);
	firstRow->setHeight(height);
	offsetRowTop_ = 1;
}

void TableLayout::setBlankTopHeight(const WString &style)
{
	WTableRow *firstRow = table_->rowAt(0);
	firstRow->setStyleClass(style);
	offsetRowTop_ = 1;
}

void TableLayout::setBlankBottonHeight(const int height)
{
	offsetRowBotton_ = table_->rowCount();
	WTableRow *lastRow = table_->rowAt(offsetRowBotton_);
	lastRow->setHeight(height);
}

void TableLayout::setBlankBottonHeight(const WString &style)
{
	offsetRowBotton_ = table_->rowCount();
	WTableRow *lastRow = table_->rowAt(offsetRowBotton_);
	lastRow->setStyleClass(style);
}
