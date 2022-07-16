/*
 * Copyright (C) 2008 Emweb bv, Herent, Belgium.
 *
 * See the LICENSE file for terms of use.
 */

#include "WebServer.h"
#include <Wt/WServer>

#include <iostream>
#include <boost/lexical_cast.hpp>

using namespace Wt;

WebServer::WebServer(Wt::WServer& server)
  : server_(server)
{ 
}

bool WebServer::connect(Client *client,
			             const ClientEventCallback& handleEvent)
{
    boost::recursive_mutex::scoped_lock lock(mutex_);

    if (clients_.count(client) == 0)
    {
        ClientInfo clientInfo;
  
        clientInfo.sessionId = WApplication::instance()->sessionId();
        clientInfo.eventCallback = handleEvent;

        clients_[client] = clientInfo;

        return true;
    } else
        return false;
}

bool WebServer::disconnect(Client *client)
{
    boost::recursive_mutex::scoped_lock lock(mutex_);

    return clients_.erase(client) == 1;
}

bool WebServer::login(const WString& user)
{
    boost::recursive_mutex::scoped_lock lock(mutex_);
  
    if (users_.find(user) == users_.end())
    {
        users_.insert(user);

        postClientEvent(ClientEvent(ClientEvent::Type::User, WebEvent(WebEvent::Login, user)));

        return true;
    } else
        return false;
}

void WebServer::logout(const WString& user)
{
    boost::recursive_mutex::scoped_lock lock(mutex_);

    UserSet::iterator i = users_.find(user);

    if (i != users_.end())
    {
        users_.erase(i);
        postClientEvent(ClientEvent(ClientEvent::Type::User, WebEvent(WebEvent::Logout, user)));
    }
}

void WebServer::postClientEvent(const ClientEvent& event)
{
    std::cout << "**************************" << std::endl;
    std::cout << "postClientEvent" << std::endl;
    boost::recursive_mutex::scoped_lock lock(mutex_);

    WApplication *app = WApplication::instance();

    for (ClientMap::const_iterator i = clients_.begin(); i != clients_.end();
       ++i) {
    /*
     * If the user corresponds to the current application, we directly
     * call the call back method. This avoids an unnecessary delay for
     * the update to the user causing the event.
     *
     * For other uses, we post it to their session. By posting the
     * event, we avoid dead-lock scenarios, race conditions, and
     * delivering the event to a session that is just about to be
     * terminated.
     */
    if (app && app->sessionId() == i->second.sessionId)
      i->second.eventCallback(event);
    else
      server_.post(i->second.sessionId,
		   boost::bind(i->second.eventCallback, event));
  }
}

WebServer::UserSet WebServer::users()
{
    boost::recursive_mutex::scoped_lock lock(mutex_);

    UserSet result = users_;

    return result;
}

void WebServer::postDeviceEvent(const DeviceEvent& event)
{

    DeviceEvent::Type type = event.type();
    struct device device = event.device();

    switch (type)
    {
        case DeviceEvent::Type::Attach:
        {
            postClientEvent(ClientEvent(ClientEvent::Type::Device,
                                        DeviceEvent(DeviceEvent::Type::Attach, device)));
            break;
        }
        default:
            break;
    }
}