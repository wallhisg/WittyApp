#ifndef SERVER_WIDGET_H
#define SERVER_WIDGET_H

#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WContainerWidget>
#include <Wt/WWidget>
#include <Wt/WImage>
#include <Wt/WText>

#include <TableLayout.h>
#include <Header.h>
#include <Content.h>

class ServerWidget
{
public:
	ServerWidget(WVBoxLayout *parent);
	~ServerWidget()
	{
		mainLayout_->removeItem(header_->vLayout());
		delete headerIcon_;
		delete headerBanner_;
		delete header_;

		mainLayout_->removeItem(content_->vLayout());
		delete tbl_tr_devId_;
		delete content_;
	}

	void createUi();
	void renderHeader();
	void renderContent();

private:
	WVBoxLayout *mainLayout_;

	// Header
	Header *header_;
	Wt::WImage* headerIcon_;
	WText *headerBanner_;
	// Content
	Content *content_;
	WText *tbl_tr_devId_;
};


#endif	//	SERVER_WIDGET_H