#include "Content.h"

Content::Content()
{
	vLayout_ = new WVBoxLayout();
	renderContent();

}

void Content::renderContent()
{

	vLayout_->addWidget(this->table());
}