#include "Layout.h"
#include <TreeView.h>

Layout::Layout(WVBoxLayout *parent)
	: mainLayout_(parent)
{
	mainLayout_->addWidget(new WText("Tree view example"));

}

void Layout::createUi()
{
	renderHeader();
	renderContent();
}

void Layout::setHeaderStyle()
{

}

void Layout::renderHeader()
{

}

void Layout::setContentStyle()
{
	
}

void Layout::renderContent()
{

}