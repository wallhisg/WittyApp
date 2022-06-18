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
#include "Server.h"

using namespace Wt;

ServerWidget::ServerWidget(Server& server,
				   Wt::WContainerWidget *parent)
  : WContainerWidget(parent),
    server_(server),
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
    if (server_.connect
            (this, boost::bind(&ServerWidget::processClientEvent, this, _1)))
        Wt::WApplication::instance()->enableUpdates(true);
}

void ServerWidget::disconnect()
{
    if (server_.disconnect(this))
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

        // create device widget from Device server
        std::cout << "**************************" << std::endl;
        cout << "ServerWidget::startServer" << endl;
        Devices::DeviceMap devMap = server_.deviceMap();

        for (Devices::DeviceMap::const_iterator it = devMap.begin();
            it != devMap.end(); ++it)
        {
            std::cout << "**************************" << std::endl;
            cout << "postDeviceEvent: " << it->first << endl;
            struct device device = it->second;
            DeviceWidget *devWidget = new DeviceWidget(device, this);
            // this->addWidget(devWidget);
        }

        createClientLayout();
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

void ServerWidget::createClientLayout()
{

}

void ServerWidget::createDeviceWidget()
{
    
}

void ServerWidget::createDeviceWidget(struct device &device)
{
    DeviceWidget *devWidget = new DeviceWidget(device, this);
}

void ServerWidget::createDeviceLayout() {
}



bool ServerWidget::loggedIn() const
{
    return loggedIn_;
}

void ServerWidget::processClientEvent(const ClientEvent& event) {
    
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
    std::cout << "processDeviceEvent" << std::endl;

    struct device device;
    device = event.device();

    createDeviceWidget(device);


}

