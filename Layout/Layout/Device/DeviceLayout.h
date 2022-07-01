#ifndef DEVICE_LAYOUT_H
#define DEVICE_LAYOUT_H

#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WContainerWidget>
#include <Wt/WWidget>
#include <Wt/WTable>
#include <Wt/WText>
#include <Wt/WPushButton>

#include <WTableLayout.h>

using namespace std;
using namespace Wt;

struct device {
	WString id;
	WString name;
	WString ip;
	WString value;
};

class DeviceWidget
{
public:
	struct Widget {
		WText *id;
		WText *ip;
		WText *name;
		WText *value;
	};

	DeviceWidget(struct device device)
	{
		// WText *id = new WText(device.id);
		// WText *ip = new WText(device.ip);
		// WText *name = new WText(device.name);
		// WText *value = new WText(device.value);

		widget_ = new Widget();
		widget_->id = new WText("ID: " + device.id);
		widget_->id->setStyleClass("dev-id");

		widget_->ip = new WText("IP: " + device.ip);
		widget_->ip->setStyleClass("dev-ip");

		widget_->name = new WText("Name: " + device.name);
		widget_->name->setStyleClass("dev-name");

		widget_->value = new WText("Value: " + device.value);
		widget_->value->setStyleClass("dev-value");
	}

	struct Widget *widget() { return widget_; }

private:
	struct Widget *widget_;
};

class DeviceLayout : public WVBoxLayout
{
public:
	
	DeviceLayout();
	
	void setDeviceLayout(DeviceWidget::Widget *widget);

	WVBoxLayout *layout() { return this; }

private:
	WTableLayout *wtLayout_;
	DeviceWidget::Widget *widget_;

	void renderId(WWidget *id);
	void renderItems(WWidget *name, WWidget *ip, WWidget *value);
};


#endif	//	DEVICE_LAYOUT_H