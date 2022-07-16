#ifndef TABLE_LAYOUT_H
#define TABLE_LAYOUT_H

#include <Wt/WTableCell>
#include <Wt/WTableRow>
#include <Wt/WTableColumn>

#include "Table.h"


class TableLayout : public Table
{
public:
	TableLayout();

	~TableLayout()
	{
		vLayout_->removeWidget(this->table());
		delete vLayout_;
	}

	void setStyleClass(const WString &style);
	void setStyleClassCell(const int row, const int col, const WString &style);
	void setStyleClassRow(const int row, const WString &style);
	void setStyleClassColumn(const int col, const WString &style);
	
	void setBlankRowHeight(const int row, const int height);
	void setBlankRowHeight(const int row, const WString &style);

	void setBlankLeftWidth(const int percentage);
	void setBlankLeftWidth(const WString &style);
	void setBlankRightWidth(const int percentage);
	void setBlankRightWidth(const WString &style);

	void setBlankTopHeight(const int height);
	void setBlankTopHeight(const WString &style);
	void setBlankBottonHeight(const int height);
	void setBlankBottonHeight(const WString &style);

	WVBoxLayout *vLayout() const { return vLayout_; }

private:
	WVBoxLayout *vLayout_;
};

#endif	//	TABLE_LAYOUT
