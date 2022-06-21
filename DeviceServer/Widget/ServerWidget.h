// This may look like C code, but it's really -*- C++ -*-
/*
 * Copyright (C) 2008 Emweb bv, Herent, Belgium.
 *
 * See the LICENSE file for terms of use.
 */

#ifndef ServerWidget_H
#define ServerWidget_H

#include <Wt/WContainerWidget>
#include <Wt/WJavaScript>
#include <Wt/WSound>

#include <Device.h>
#include <WebServer.h>
#include <DeviceServer.h>
#include <DeviceWidget.h>

namespace Wt {
    class WApplication;
    class WPushButton;
    class WText;
    class WLineEdit;
    class WTextArea;
}

class ClientEvent;

class ServerWidget : public Wt::WContainerWidget,
			 public WebServer::Client
{
public:
    ServerWidget(WebServer& server, 
                    DeviceServer& deviceServer, 
                    Wt::WContainerWidget *parent = 0);

    ~ServerWidget();

    void connect();
    void disconnect();
    void letLogin();
    void login();
    void loggedIn();

    void startServer();

    void logout();

    WebServer& server() { return webServer_; }

    int userCount() { return users_.size(); }

    const Wt::WString& userName() const { return user_; }

    void createClientLayout();
    void renderDeviceWidget();
    void createDeviceLayout();

protected:
    bool loggedIn() const;

private:
    // Server manager
    WebServer& webServer_;
    DeviceServer& deviceServer_;

    //  User manager
    typedef std::map<Wt::WString, bool> UserMap;
    UserMap users_;
    bool    loggedIn_;
    Wt::WString user_;

    //  Device Widget manager
    WContainerWidget* wcDevice_;
    DeviceWidgetMap deviceWidgetMap_;

    void createDeviceWidget(struct device& device);
    void createDeviceWidget();
    void processDeviceWidgetEvent(const DeviceWidgetEvent &event);

    /*  Events handler
        called from another session */
    void processClientEvent(const ClientEvent& event);
    void processWebEvent(const WebEvent& event);
    void processDeviceEvent(const DeviceEvent& event);
};

/*@}*/

#endif // ServerWidget
