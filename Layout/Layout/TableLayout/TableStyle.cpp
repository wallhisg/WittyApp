#include "TableStyle.h"

TableStyle::TableStyle()
{

}

void TableStyle::setStyleClass(const WString &style)
{
	table_->setStyleClass(style);
}

void TableStyle::setStyleClassCell(const int row, const int col, 
								const WString &style)
{
	WWidget *widget = table_->elementAt(row, col);
	widget->setStyleClass(style);
}

void TableStyle::setStyleClassRow(const int row, const WString &style)
{
	WTableRow *tableRow = table_->rowAt(row);
	tableRow->setStyleClass(style);
}

void TableStyle::setStyleClassColumn(const int col, const WString &style)
{
	WTableColumn *tableCol = table_->columnAt(col);
	tableCol->setStyleClass(style);
}

void TableStyle::setBlankRowHeight(const int row, const int height)
{
	WTableRow *currRow = table_->rowAt(row);
	currRow->setHeight(height);
}

void TableStyle::setBlankRowHeight(const int row, const WString &style)
{
	WTableRow *currRow = table_->rowAt(row);
	currRow->setStyleClass(style);
}

void TableStyle::setBlankLeftWidth(const int percentage)
{
	WTableColumn *leftCol = table_->columnAt(0);
	leftCol->setWidth(WLength(percentage, WLength::Percentage));
	offsetColLeft_ = 1;
}

void TableStyle::setBlankLeftWidth(const WString &style)
{
	WTableColumn *leftCol = table_->columnAt(0);
	leftCol->setStyleClass(style);
	offsetColLeft_ = 1;
}

void TableStyle::setBlankRightWidth(const int percentage)
{
	int lastCol = table_->columnCount();

	WTableColumn *rightCol = table_->columnAt(lastCol);
	rightCol->setWidth(WLength(percentage, WLength::Percentage));
}

void TableStyle::setBlankRightWidth(const WString &style)
{
	offsetColRight_ = table_->columnCount();

	WTableColumn *rightCol = table_->columnAt(offsetColRight_);
	rightCol->setStyleClass(style);
}

void TableStyle::setBlankTopHeight(const int height)
{
	WTableRow *firstRow = table_->rowAt(0);
	firstRow->setHeight(height);
	offsetRowTop_ = 1;
}

void TableStyle::setBlankTopHeight(const WString &style)
{
	WTableRow *firstRow = table_->rowAt(0);
	firstRow->setStyleClass(style);
	offsetRowTop_ = 1;
}

void TableStyle::setBlankBottonHeight(const int height)
{
	offsetRowBotton_ = table_->rowCount();
	WTableRow *lastRow = table_->rowAt(offsetRowBotton_);
	lastRow->setHeight(height);
}

void TableStyle::setBlankBottonHeight(const WString &style)
{
	offsetRowBotton_ = table_->rowCount();
	WTableRow *lastRow = table_->rowAt(offsetRowBotton_);
	lastRow->setStyleClass(style);
}
