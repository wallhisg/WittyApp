#include "DeviceWidget.h"


void DeviceWidget::changeName(WString name)
{
    device_->name = name;
    name_->setText(name);
}

void DeviceWidget::createWidget(struct device& device)
{
    device_ = &device;

    id_ = new WText(device_->id);
    ip_ = new WText(device_->ip);
    name_ = new WText(device_->name + " = " + device_->value);
    WPushButton *control = new WPushButton(device_->name);

    control->clicked().connect(
        boost::bind(&DeviceWidget::processWidgetEvent, this,
                    WWidgetEvent(WWidgetEvent::Type::Button, device)));

    createLayout(id_, ip_, name_, control);
}

/*
    ---------------------------------------------
    | id						| ip			|
    ---------------------------------------------
    | name										|
    ---------------------------------------------
    |				Control						|
    ---------------------------------------------
*/

void DeviceWidget::createLayout(WWidget *id, WWidget *ip,
                                WWidget *name, WWidget *control)
{
    WVBoxLayout *vLayout = new WVBoxLayout();

    WHBoxLayout *hLayout = new WHBoxLayout();
    hLayout->addWidget(id, 1);
    hLayout->addWidget(ip);

    vLayout->addLayout(hLayout, 1);

    // Add widget to vertical layout with stretch = 0
    vLayout->addWidget(name);
    vLayout->addWidget(control);
    this->setLayout(vLayout);
}

void DeviceWidget::setDeviceLayout(WContainerWidget *wcDevice)
{
    wcDevice->setLayout(vLayout);
}

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

void DeviceWidget::processWidgetEvent(const WWidgetEvent &event)
{

    struct device device_ = event.device();
    switch (event.type())
    {

        case WWidgetEvent::Type::Button:
        {
            std::cout << "**************************" << std::endl;
            std::cout << "WWidgetEvent" << std::endl;
            std::cout << "device_.id: " << device_.id <<std::endl;
            std::cout << "device_.ip: " << device_.ip <<std::endl;
            std::cout << "device_.name: " << device_.name <<std::endl;
            std::cout << "device_.type: " << device_.type <<std::endl;

            struct device device = event.device();

            if (device.value == "0")
            {
                device.value = "1";
            }
            else
            {

            }

            break;
        }
        case WWidgetEvent::Type::Slider:
        {

            break;
        }
        default:
            break;
    }
}