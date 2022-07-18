#include "TableLayout.h"

TableLayout::TableLayout()
{
	vLayout_ = new WVBoxLayout();
	vLayout_->addWidget(this->table_);
}

void TableLayout::addLayout(TableLayout *tableLayout)
{
	if (vLayout_ != tableLayout->vLayout_)
	{
		insertLayout(tableLayout->vLayout_);
	}
}

void  TableLayout::addLayout(WVBoxLayout *layout)
{
	if (vLayout_ != layout)
	{
		insertLayout(layout);
	}
}

void TableLayout::removeLayout(TableLayout *tableLayout)
{
	eraseLayout(tableLayout->vLayout_);
}

void TableLayout::removeLayout(WVBoxLayout *layout)
{
	eraseLayout(layout);
}

