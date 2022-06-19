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
#include <Server.h>
#include <DeviceWidget.h>

namespace Wt {
    class WApplication;
    class WPushButton;
    class WText;
    class WLineEdit;
    class WTextArea;
}

class ClientEvent;

/**
 * \defgroup chatexample Chat example
 */
/*@{*/

/*! \brief A self-contained device widget.
 */
class ServerWidget : public Wt::WContainerWidget,
			 public Server::Client
{
public:
    ServerWidget(Server& server, Wt::WContainerWidget *parent = 0);

    ~ServerWidget();

    void connect();
    void disconnect();
    void letLogin();
    void login();
    void loggedIn();

    void startServer();

    void logout();

    Server& server() { return server_; }

    int userCount() { return users_.size(); }

    const Wt::WString& userName() const { return user_; }

    void createClientLayout();
    void renderDeviceWidget();
    void createDeviceLayout();

protected:

protected:
    bool loggedIn() const;

private:
    // Server
    Server&     server_;

    typedef std::map<Wt::WString, bool> UserMap;
    UserMap users_;

    // Device Widget
    WContainerWidget* wcDevice_;
    DeviceWidgetMap deviceMap_;
    bool    loggedIn_;

    Wt::WString user_;

    void createDeviceWidget(struct device& device);
    void createDeviceWidget();

    /* called from another session */
    void processClientEvent(const ClientEvent& event);
    void processWebEvent(const WebEvent& event);
    void processDeviceEvent(const DeviceEvent& event);
};

/*@}*/

#endif // ServerWidget
