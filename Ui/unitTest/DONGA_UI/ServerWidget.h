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
#include <DongAUi.h>

class ServerWidget
{
public:
	ServerWidget(WVBoxLayout *parent);
	~ServerWidget()
	{
		delete dongAUi_;
	}

	void createUi();

private:
	WVBoxLayout *mainLayout_;

	DongAUi *dongAUi_;

};


#endif	//	SERVER_WIDGET_H
