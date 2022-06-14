/*
 * Copyright (C) 2008 Emweb bv, Herent, Belgium.
 *
 * See the LICENSE file for terms of use.
 */

#include "Server.h"
#include <Wt/WServer>

#include <iostream>
#include <boost/lexical_cast.hpp>

using namespace Wt;

const WString WebEvent::formattedHTML(const WString& user,
				       TextFormat format) const
{
  switch (type_) {
  case Login:
    return WString::fromUTF8("<span class='chat-info'>")
      + WWebWidget::escapeText(user_) + " joined.</span>";
  case Logout:
    return WString::fromUTF8("<span class='chat-info'>")
      + ((user == user_) ?
	 WString::fromUTF8("You") :
	 WWebWidget::escapeText(user_))
      + " logged out.</span>";
  case Rename:
    return "<span class='chat-info'>"
      + ((user == data_ || user == user_) ?
	 "You are" :
	 (WWebWidget::escapeText(user_) + " is")) 
      + " now known as " + WWebWidget::escapeText(data_) + ".</span>";
  case Message:{
    WString result;

    result = WString("<span class='")
      + ((user == user_) ?
	 "chat-self" :
	 "chat-user")
      + "'>" + WWebWidget::escapeText(user_) + ":</span>";

    WString msg
      = (format == XHTMLText ? message_ : WWebWidget::escapeText(message_));

    if (message_.toUTF8().find(user.toUTF8()) != std::string::npos)
      return result + "<span class='chat-highlight'>" + msg + "</span>";
    else
      return result + msg;
  }
  default:
    return "";
  }
}


Server::Server(WServer& server)
  : server_(server)
{ 
  deviceWR_ = new DeviceWResource();
  server_.addResource(deviceWR_, "/resource");
  deviceWR_->devEventSig().connect(SLOT(this, Server::deviceAttach));
}

bool Server::connect(Client *client,
			       const ClientEventCallback& handleEvent)
{
  boost::recursive_mutex::scoped_lock lock(mutex_);

  if (clients_.count(client) == 0) {
    ClientInfo clientInfo;
  
    clientInfo.sessionId = WApplication::instance()->sessionId();
    clientInfo.eventCallback = handleEvent;

    clients_[client] = clientInfo;

    return true;
  } else
    return false;
}

bool Server::disconnect(Client *client)
{
  boost::recursive_mutex::scoped_lock lock(mutex_);

  return clients_.erase(client) == 1;
}

bool Server::login(const WString& user)
{
  boost::recursive_mutex::scoped_lock lock(mutex_);
  
  if (users_.find(user) == users_.end()) {
    users_.insert(user);

    postClientEvent(ClientEvent(ClientEvent::Type::User, WebEvent(WebEvent::Login, user)));

    return true;
  } else
    return false;
}

void Server::logout(const WString& user)
{
  boost::recursive_mutex::scoped_lock lock(mutex_);

  UserSet::iterator i = users_.find(user);

  if (i != users_.end()) {
    users_.erase(i);

    postClientEvent(ClientEvent(ClientEvent::Type::User, WebEvent(WebEvent::Logout, user)));
  }
}

bool Server::changeName(const WString& user, const WString& newUser)
{
  if (user == newUser)
    return true;

  boost::recursive_mutex::scoped_lock lock(mutex_);
  
  UserSet::iterator i = users_.find(user);

  if (i != users_.end()) {
    if (users_.count(newUser) == 0) {
      users_.erase(i);
      users_.insert(newUser);

      postClientEvent(ClientEvent(ClientEvent::Type::User, WebEvent(WebEvent::Rename, user, newUser)));

      return true;
    } else
      return false;
  } else
    return false;
}

WString Server::suggestGuest()
{
  boost::recursive_mutex::scoped_lock lock(mutex_);

  for (int i = 1;; ++i) {
    std::string s = "guest " + boost::lexical_cast<std::string>(i);
    WString ss = s;

    if (users_.find(ss) == users_.end())
      return ss;
  }
}

void Server::sendMessage(const WString& user, const WString& message)
{
  postClientEvent(ClientEvent(ClientEvent::Type::User, WebEvent(user, message)));
}

void Server::postClientEvent(const ClientEvent& event)
{
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

Server::UserSet Server::users()
{
  boost::recursive_mutex::scoped_lock lock(mutex_);

  UserSet result = users_;

  return result;
}

void Server::deviceAttach(Device device, const DeviceEvent &event)
{
  boost::recursive_mutex::scoped_lock lock(mutex_);

  string devId = device.getIdString();

  if (deviceMap_.count(devId) == 0)
  {
    deviceMap_[devId] = device;

    // Emit signal to render new device
    
  }
}

Server::DeviceMap Server::deviceMap()
{
    boost::recursive_mutex::scoped_lock lock(mutex_);
    DeviceMap res = deviceMap_;
    return res;
}