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

class DeviceWidgetEvent {
 public:
    enum Type { changeName, changeValue };
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
    DeviceWidget(const struct device& device, WContainerWidget *parent)
        :   WContainerWidget(parent),
            device_(device)
    {
        createWidget();
    }

    ~DeviceWidget()
    {}

    // Signal trigger when control clicked
    Wt::Signal<DeviceWidgetEvent>& deviceWidgetEventSig() { return deviceWidgetEventSig_; }


    void changeName(WString name);
    void changeValue(struct device device);

    const string getId() const { return device_.id.toUTF8(); }

    void createWidget();
    void createLayout(WWidget *id, WWidget *ip, WWidget *name, WWidget *control);
    void setDeviceLayout(WContainerWidget *wcDevice);
    void processWidgetEvent(const DeviceWidgetEvent &event);


private:
    const struct device &device_;

    WPushButton *control_;
    WText *id_;
    WText *ip_;
    WText *name_;

    Wt::Signal<DeviceWidgetEvent> deviceWidgetEventSig_;
    void emitDeviceConEventSig(const DeviceWidgetEvent &event)
    {
        deviceWidgetEventSig_.emit(event);
    }
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
