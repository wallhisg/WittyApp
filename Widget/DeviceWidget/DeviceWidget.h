#ifndef DEVICE_WIDGET_H
#define DEVICE_WIDGET_H

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WEnvironment>
#include <Wt/WInPlaceEdit>
#include <Wt/WHBoxLayout>
#include <Wt/WVBoxLayout>
#include <Wt/WWidget>
#include <Wt/WLabel>
#include <Wt/WLineEdit>
#include <Wt/WTemplate>
#include <Wt/WText>
#include <Wt/WTextArea>
#include <Wt/WPushButton>
#include <Wt/WCheckBox>
#include <Wt/Http/Client>
#include <Wt/WString>
#include <boost/noncopyable.hpp>
#include <boost/thread.hpp>
#include <boost/lexical_cast.hpp>
#include <set>
#include <map>

#include <Device.h>

using namespace std;
using namespace Wt;

class DeviceWidget;


class DeviceWidgetEvent {
 public:
    enum Type { ChangeName, ChangeValue };
    Type type() const { return type_; }

    struct device device() const { return device_; }
 private:
    Type type_;
    struct device device_;
    DeviceWidget *deviceWidget_;

    DeviceWidgetEvent(Type type, struct device device)
        :	type_(type)
    {
        device_ = device;
    }

    DeviceWidgetEvent(Type type, DeviceWidget *deviceWidget)
        :	type_(type),
            deviceWidget_(deviceWidget)
    {}

    friend class DeviceWidget;
};

class DeviceWidget : public WContainerWidget 
{
public:
	struct Widget {
		WText *id;
		WText *ip;
		WText *name;
		WText *value;
	};

    DeviceWidget(struct device device, WContainerWidget *parent)
        :   WContainerWidget(parent),
            device_(device)
    {
        createWidget();
    }

	DeviceWidget(struct device device)
	{
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

    // Signal trigger when control clicked
    Wt::Signal<DeviceWidgetEvent>& deviceWidgetEventSig() { return deviceWidgetEventSig_; }


    void changeName(WString name);
    void changeValue(struct device& device);

    const string getId() const { return device_.id.toUTF8(); }

    void createWidget();
    void createLayout(WWidget *id, WWidget *ip, WWidget *name, WWidget *control);
    void setDeviceLayout(WContainerWidget *wcDevice);
    void processWidgetEvent(const DeviceWidgetEvent &event);
	struct Widget *widget() { return widget_; }

private:
	struct Widget *widget_;

    struct device device_;

    WPushButton *control_;
    WText *id_;
    WText *ip_;
    WText *name_;

    Wt::Signal<DeviceWidgetEvent> deviceWidgetEventSig_;
    void emitDeviceWidgetEventSig(const DeviceWidgetEvent &event)
    {
        deviceWidgetEventSig_.emit(event);
    }	
};


#endif	//	DEVICE_WIDGET_H