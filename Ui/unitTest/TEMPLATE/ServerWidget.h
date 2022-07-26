#ifndef SERVER_WIDGET_H
#define SERVER_WIDGET_H

#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WContainerWidget>
#include <Wt/WWidget>
#include <Wt/WImage>
#include <Wt/WText>

#include <Ui.h>

class ServerWidget
{
public:
	ServerWidget(WVBoxLayout *parent);
	~ServerWidget()
	{

	}

	void createUi();

private:
	WVBoxLayout *mainLayout_;

	Ui *ui_;
};


#endif	//	SERVER_WIDGET_H
