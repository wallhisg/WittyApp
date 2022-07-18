#ifndef SERVER_WIDGET_H
#define SERVER_WIDGET_H

#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WContainerWidget>
#include <Wt/WWidget>
#include <Wt/WImage>
#include <Wt/WText>

#include <Table.h>
#include <TableLayout.h>
#include "Header.h"
#include <Content.h>

class ServerWidget
{
public:
	ServerWidget(WVBoxLayout *parent);
	~ServerWidget()
	{
		mainLayout_->removeItem(header_->vLayout());
		// mainLayout_->removeItem(content_->vLayout());
		
		delete header_;
		delete content_;
	}

	void createUi();
	void renderHeader();


private:
	WVBoxLayout *mainLayout_;
	TableLayout *header_;
	TableLayout *content_;
};


#endif	//	SERVER_WIDGET_H

