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

#include <Header.h>
#include <Content.h>
#include <Footer.h>

class ServerWidget
{
public:
	ServerWidget(WVBoxLayout *parent);
	~ServerWidget()
	{
		mainLayout_->removeItem(footer_->vLayout());
		mainLayout_->removeItem(content_->vLayout());
		mainLayout_->removeItem(header_->vLayout());

		delete footer_;
		delete content_;
		delete header_;
	}

	void createUi();

	void renderHeader();
	void renderContent();
	void renderFooter();

private:
	WVBoxLayout *mainLayout_;

	Header *header_;
	Content *content_;
	Footer *footer_;
};


#endif	//	SERVER_WIDGET_H
