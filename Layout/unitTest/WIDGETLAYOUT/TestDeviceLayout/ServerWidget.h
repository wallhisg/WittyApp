#ifndef SERVER_WIDGET_H
#define SERVER_WIDGET_H

#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WContainerWidget>
#include <Wt/WWidget>
#include <Wt/WImage>
#include <Wt/WText>

#include <Device.h>
#include <DeviceLayout.h>

using namespace std;
using namespace Wt;

class ServerWidget
{
public:
	ServerWidget(WVBoxLayout *parent);
	~ServerWidget()
	{
		mainLayout_->removeItem(devLayout_->layout());
		delete devLayout_;
	}

	void createUi();

private:
	WVBoxLayout *mainLayout_;

	DeviceLayout *devLayout_;
	struct device device_;
};


#endif	//	SERVER_WIDGET_H

