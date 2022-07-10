#include "Content.h"

Content::Content()
{
	contentLayout_ = new WVBoxLayout();
}

void Content::addParagraph(WText *wText)
{
	contentLayout_->addWidget(wText);
}

void Content::addWidget(WWidget *widget)
{
	contentLayout_->addWidget(widget);
}

void Content::addWTableLayout(WTableLayout *wtLayout)
{
	contentLayout_->addWidget(wtLayout);
}

void Content::addLayout(WLayout *layout)
{
	contentLayout_->addLayout(layout);
}