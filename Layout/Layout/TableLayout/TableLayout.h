#ifndef TABLE_LAYOUT_H
#define TABLE_LAYOUT_H

#include <Wt/WLayout>
#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WAnimation>
#include <vector>
#include <TableStyle.h>

using namespace std;
using namespace Wt;

class TableLayout : public TableStyle
{
public:
	TableLayout();

	~TableLayout()
	{
		vLayout_->removeWidget(this->table_);
		eraseLayout();
		delete vLayout_;
	}

	void addLayout(TableLayout *tableLayout);
	void addLayout(WVBoxLayout *layout);

	void removeLayout(TableLayout *tableLayout);
	void removeLayout(WVBoxLayout *layout);


	WVBoxLayout *layout() const { return vLayout_; }
private:
	WVBoxLayout *vLayout_;

	vector<WVBoxLayout *> layouts_;

	void insertLayout(WVBoxLayout *layout)
	{
		vLayout_->addItem(layout);
		layouts_.push_back(layout);
	}

	void eraseLayout()
	{
		for (vector<WVBoxLayout *>::iterator it = layouts_.begin(); 
				it != layouts_.end(); ++it)
		{
			vLayout_->removeItem(*it);
		}	
	}

	void eraseLayout(WVBoxLayout *layout)
	{
		for (vector<WVBoxLayout *>::iterator it = layouts_.begin(); 
				it != layouts_.end(); ++it)
		{
			if (*it == layout)
			{
				vLayout_->removeItem(*it);
				/**
				
					TODO:
					- fix it later use LinkedList
				 */
				
				// layouts_.delete(it);	<---
			}
		}	
	}
};

#endif	//	TABLE_LAYOUT_H