#ifndef DEVICEWIDGET_H_
#define DEVICEWIDGET_H_
 
#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WEnvironment>
#include <Wt/WInPlaceEdit>
#include <Wt/WHBoxLayout>
#include <Wt/WVBoxLayout>
#include <Wt/WLabel>
#include <Wt/WLineEdit>
#include <Wt/WTemplate>
#include <Wt/WText>
#include <Wt/WTextArea>
#include <Wt/WPushButton>
#include <Wt/WCheckBox>


using namespace Wt;

struct device 
{
	WString id;
	WString ip;
	WString name;
	WString type;
};

class DeviceWidget : public Wt::WContainerWidget
{
public:
	DeviceWidget(WContainerWidget *parent = 0)
		:	WContainerWidget(parent)
	{
		this->addWidget(new Wt::WText("Device Widget"));
	}

	~DeviceWidget()
	{}

	// void createLayout();


private:
	struct device device_;

};

#endif