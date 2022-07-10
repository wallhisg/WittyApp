#include "DeviceWidgetMap.h"


DeviceWidgetMap::WidgetMap DeviceWidgetMap::widgetMap()
{
    boost::recursive_mutex::scoped_lock lock(mutex_);
    WidgetMap res = widgetMap_;
    return widgetMap_;
}

bool DeviceWidgetMap::insertDeviceWidget(DeviceWidget *deviceWidget)
{
    cout << "insertDeviceWidget" << endl;

    boost::recursive_mutex::scoped_lock lock(mutex_);

    string id = deviceWidget->getId();


    if (widgetMap_.count(id) == 0)
    {
        widgetMap_[id] = deviceWidget;
        return true;
    }
    else
        return false;
}

bool DeviceWidgetMap::eraseDeviceWidget(DeviceWidget *deviceWidget)
{
    boost::recursive_mutex::scoped_lock lock(mutex_);

    string id = deviceWidget->getId();
    return widgetMap_.erase(id) == 1;
}


DeviceWidget* DeviceWidgetMap::getWidget(const string &id)
{
    boost::recursive_mutex::scoped_lock lock(mutex_);

    try {
        DeviceWidget* deviceWidget = widgetMap_.at(id);

        return deviceWidget;
    }
    catch (const std::out_of_range&)
    {
        cout << "Key \"" << id << "\" not found" << endl;
        return nullptr;
    }
}

DeviceWidget* DeviceWidgetMap::getWidget(const WString &id)
{
    boost::recursive_mutex::scoped_lock lock(mutex_);

    try {
        string id_ = id.toUTF8();
        DeviceWidget* deviceWidget = widgetMap_.at(id_);

        return deviceWidget;
    }
    catch (const std::out_of_range&)
    {
        cout << "Key \"" << id << "\" not found" << endl;
        return nullptr;
    }
}