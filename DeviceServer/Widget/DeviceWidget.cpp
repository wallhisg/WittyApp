#include "DeviceWidget.h"


void DeviceWidget::changeName(WString name)
{
    // device_.name = name;
    // name_->setText(name);
}

void DeviceWidget::changeValue(struct device device)
{

    control_->setText(device.value);
}

void DeviceWidget::createWidget()
{

    id_ = new WText(device_.id);
    ip_ = new WText(device_.ip);
    name_ = new WText(device_.name + " = " + device_.value);
    control_ = new WPushButton(device_.name);

    control_->clicked().connect(
        boost::bind(&DeviceWidget::processWidgetEvent, this,
                    DeviceWidgetEvent(DeviceWidgetEvent::Type::changeValue, device_)));

    createLayout(id_, ip_, name_, control_);
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

void DeviceWidget::processWidgetEvent(const DeviceWidgetEvent &event)
{
    std::cout << "**************************" << std::endl;
    std::cout << "processWidgetEvent" << std::endl;
    struct device device_ = event.device();
    switch (event.type())
    {

        case DeviceWidgetEvent::Type::changeValue:
        {
            std::cout << "**************************" << std::endl;
            std::cout << "DeviceWidgetEvent" << std::endl;
            std::cout << "device_.id: " << device_.id <<std::endl;
            std::cout << "device_.ip: " << device_.ip <<std::endl;
            std::cout << "device_.name: " << device_.name <<std::endl;
            std::cout << "device_.value: " << device_.value <<std::endl;
            std::cout << "device_.type: " << device_.type <<std::endl;


            struct device device = event.device();

            if (device.value == "0")
            {
                device.value = "1";
                control_->setText(device.value);
            }
            else
            {
                device.value = "0";
                control_->setText(device.value);
            }
            emitDeviceConEventSig(DeviceWidgetEvent(DeviceWidgetEvent::Type::changeValue,
                                                    device));
            break;
        }
        case DeviceWidgetEvent::Type::changeName:
        {

            break;
        }
        default:
            break;
    }
}