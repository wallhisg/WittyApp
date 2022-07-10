#include "Header.h"

Header::Header(WImage *headerIcon, WText *headerBanner)
	: 	headerIcon_(headerIcon),
		headerBanner_(headerBanner)
{
	headerLayout_ = new WVBoxLayout();
	headerWt_ = new WTableLayout();

	renderHeader();
}

void Header::renderHeader()
{
	// render Icon
	headerWt_->addWidget(0, 0, headerIcon_);
	headerWt_->setLength(0, 25);
	headerWt_->setAlignment(0,0, AlignCenter);

	// render banner
	headerWt_->addWidget(0, 1, headerBanner_);
	headerWt_->setAlignment(0, 1, AlignCenter);

	headerLayout_->addWidget(headerWt_);
}