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
		delete vLayout_;
	}
	void setStyleClass(const WString &style);
	void setStyleClassCell(const unsigned short row, const unsigned short col, const WString &style);
	void setStyleClassRow(const unsigned short row, const WString &style);
	void setStyleClassColumn(const unsigned short col, const WString &style);
	
	WVBoxLayout *vLayout() const { return vLayout_; }

private:
	WVBoxLayout *vLayout_;
};







#endif	//	TABLE_LAYOUT
