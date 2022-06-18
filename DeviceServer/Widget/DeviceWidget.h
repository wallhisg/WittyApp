#ifndef DEVICEWIDGET_H
#define DEVICEWIDGET_H

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

#include "Device.h"

using namespace Wt;
using namespace std;

class DeviceWidget;

class WWidgetEvent {
 public:
    enum Type { Button, Slider };
    Type type() const { return type_; }

    struct device device() const { return device_; }
 private:
    Type type_;
    struct device device_;
    DeviceWidget *deviceWidget_;

    WWidgetEvent(Type type, struct device device)
        :	type_(type)
    {
        device_ = device;
    }

    WWidgetEvent(Type type, DeviceWidget *deviceWidget)
        :	type_(type),
            deviceWidget_(deviceWidget)
    {}

    friend class DeviceWidget;
};

class DeviceWidget : public WContainerWidget 
{
 public:
    DeviceWidget(WContainerWidget *parent)
        : WContainerWidget(parent) 
    {}

    DeviceWidget(struct device& device, WContainerWidget *parent)
        :   WContainerWidget(parent),
            device_(&device)
    {
        createWidget(device);
    }

    DeviceWidget(struct device& device)
        :   device_(&device)
    {
        createWidget(device);
    }
    ~DeviceWidget()
    {}

    void changeName(WString name);
    const string getId() const { return device_->id.toUTF8(); }

    void createWidget(struct device& device);
    void createLayout(WWidget *id, WWidget *ip, WWidget *name, WWidget *control);
    void setDeviceLayout(WContainerWidget *wcDevice);
    void processWidgetEvent(const WWidgetEvent &event);


private:
    struct device *device_;
    WVBoxLayout *vLayout;
    WText *id;
    WText *ip;
    WText *name_;
};

class DeviceWidgetMap : boost::noncopyable
 {
 public:
    bool insertDeviceWidget(DeviceWidget *deviceWidget);
    bool eraseDeviceWidget(DeviceWidget *deviceWidget);

    DeviceWidget* getWidget(const string& id);

    typedef map<string, DeviceWidget *>  WidgetMap;
    WidgetMap widgetMap();

 private:
    boost::recursive_mutex mutex_;
    WidgetMap widgetMap_;
};

 #endif // DEVICEWIDGET_H
