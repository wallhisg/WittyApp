#ifndef DEVICE_WIDGET_MAP_H
#define DEVICE_WIDGET_MAP_H

#include "DeviceWidget.h"

class DeviceWidgetMap : boost::noncopyable
 {
 public:
    bool insertDeviceWidget(DeviceWidget *deviceWidget);
    bool eraseDeviceWidget(DeviceWidget *deviceWidget);

    DeviceWidget* getWidget(const string& id);
    DeviceWidget* getWidget(const WString& id);

    typedef map<string, DeviceWidget *>  WidgetMap;
    WidgetMap widgetMap();

 private:
    boost::recursive_mutex mutex_;
    WidgetMap widgetMap_;
};

#endif	//	DEVICE_WIDGET_MAP_H