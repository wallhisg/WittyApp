/*
 * Copyright (C) 2008 Emweb bv, Herent, Belgium.
 *
 * See the LICENSE file for terms of use.
 */

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

#include <iostream>

#include "ServerWidget.h"
#include "WebServer.h"

using namespace Wt;

ServerWidget::ServerWidget(WebServer& server,
                            DeviceServer& deviceServer, 
				            Wt::WContainerWidget *parent)
  : WContainerWidget(parent),
    webServer_(server),
    deviceServer_(deviceServer),
    loggedIn_(true)
{
    std::cout << "**************************" << std::endl;
    std::cout << "ServerWidget::ServerWidget" << std::endl;

    letLogin();
}

ServerWidget::~ServerWidget()
{
    logout();
}

void ServerWidget::connect()
{
    if (webServer_.connect(this, 
                    boost::bind(&ServerWidget::processClientEvent, this, _1)))
    {
        deviceServer_.connect(this, 
                    boost::bind(&ServerWidget::processDeviceEvent, this, _1));

        Wt::WApplication::instance()->enableUpdates(true);
    }

}

void ServerWidget::disconnect()
{
    if (webServer_.disconnect(this))
        Wt::WApplication::instance()->enableUpdates(false);
}

void ServerWidget::letLogin()
{
    clear();
    login();
}

void ServerWidget::login()
{
    loggedIn_ = true;
    loggedIn();

}

void ServerWidget::loggedIn()
{
    startServer();
}

void ServerWidget::startServer()
{
    connect();

    if (loggedIn_)
    {
        // create WContainerWidget for devices
        wcDevice_ = new WContainerWidget();
        wcDevice_->setOverflow(WContainerWidget::OverflowAuto);
        this->addWidget(wcDevice_);

        // create device widget from Device server and add to device widget map
        createDeviceWidget();
        renderDeviceWidget();
 
    }


    if (!wcDevice_->parent())
    {
        delete  wcDevice_;
        wcDevice_ = 0;
    }
}

void ServerWidget::logout()
{
    disconnect();
}

void ServerWidget::createDeviceWidget()
{
    Devices::DeviceMap devMap = deviceServer_.deviceMap();
    if (devMap.size() > 0)
    {

        struct device device;

        for (Devices::DeviceMap::const_iterator it = devMap.begin();
            it != devMap.end(); ++it)
        {
            device = it->second;

            WContainerWidget *wcDevice = new WContainerWidget();
            DeviceWidget *devWidget = new DeviceWidget(device, wcDevice);

            // Connect device widget event to wiget event handler
            devWidget->deviceWidgetEventSig().connect(SLOT(
                this, ServerWidget::processDeviceWidgetEvent));
            
            // Add to DeviceWidgetMap
            deviceWidgetMap_.insertDeviceWidget(devWidget);

        }
    }
}

void ServerWidget::createDeviceWidget(struct device &device)
{

}


// Put event handler here
void ServerWidget::processDeviceWidgetEvent(const DeviceWidgetEvent &event)
{

    DeviceWidgetEvent::Type type = event.type();
    struct device device = event.device();

    std::cout << "**************************" << std::endl;
    std::cout << "processDeviceWidgetEvent" << std::endl;
    std::cout << "device.value: " << device.value <<std::endl;

    switch (type)
    {
        case DeviceWidgetEvent::Type::ChangeValue:
        {
            deviceServer_.changeValue(device);
            break;
        }
        default:
            break;

    }

}


void ServerWidget::renderDeviceWidget()
{
    DeviceWidgetMap::WidgetMap wgMap = deviceWidgetMap_.widgetMap();

    if (wgMap.size() > 0)
    {
        for (DeviceWidgetMap::WidgetMap::const_iterator it = wgMap.begin();
            it != wgMap.end(); ++it)
        {
            DeviceWidget *devWidget;

            devWidget = it->second;
            wcDevice_->addWidget(devWidget);
        }
    }
}

void ServerWidget::createClientLayout()
{

}

void ServerWidget::createDeviceLayout() {
}



bool ServerWidget::loggedIn() const
{
    return loggedIn_;
}

void ServerWidget::processClientEvent(const ClientEvent& event) 
{
    std::cout << "**************************" << std::endl;
    std::cout << "processClientEvent" << std::endl;    
    switch (event.type())
    {
        case ClientEvent::Type::User:
        {
            processWebEvent(event.webEvent());
            break;
        }
        case ClientEvent::Type::Device:
        {
            processDeviceEvent(event.devEvent());
            break;
        }
        default:
            break;
    }
}

void ServerWidget::processWebEvent(const WebEvent& event)
{
    WApplication *app = WApplication::instance();


    if (event.type() != WebEvent::Message)
    {
        if (event.type() == WebEvent::Rename && event.user() == user_)
            user_ = event.data();
    }

  /*
   * This is the server call: we (schedule to) propagate the updated UI to
   * the client.
   *
   * This schedules an update and returns immediately
   */
    app->triggerUpdate();
}

void ServerWidget::processDeviceEvent(const DeviceEvent& event)
{
    std::cout << "**************************" << std::endl;
    std::cout << "processDeviceEvent" << std::endl;

    WApplication *app = WApplication::instance();
    
    DeviceEvent::Type type = event.type();
    struct device device = event.device();

    // process current sessionid
    switch (type)
    {
        case DeviceEvent::Type::Connect:
        {
            // create device widget
            WContainerWidget *wcDevice = new WContainerWidget();
            DeviceWidget *devWidget = new DeviceWidget(device, wcDevice);
            wcDevice_->addWidget(wcDevice);
            
            // Add to DeviceWidgetMap    
            deviceWidgetMap_.insertDeviceWidget(devWidget);
            break;
        }
        case  DeviceEvent::Type::ChangeValue: 
        {
            DeviceWidget *deviceWidget = deviceWidgetMap_.getWidget(device.id.toUTF8());

            // process other sessionid
            if (deviceWidget != nullptr)
                deviceWidget->changeValue(device);
            break;
        }
        default:
            break;
    }


    app->triggerUpdate();
}

