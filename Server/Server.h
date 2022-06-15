// This may look like C code, but it's really -*- C++ -*-
/*
 * Copyright (C) 2008 Emweb bv, Herent, Belgium.
 *
 * See the LICENSE file for terms of use.
 */
#ifndef Server_H_
#define Server_H_

#include <boost/noncopyable.hpp>

#include <Wt/WSignal>
#include <Wt/WString>
#include <ClientEvent.h>

#include <set>
#include <map>
#include <boost/thread.hpp>

#include <Device.h>
#include <DeviceWResource.h>
#include <DevServer.h>

namespace Wt {
  class WServer;
}

/*! \brief A simple chat server
 */
class Server : boost::noncopyable
{
public:
  /*
   * A reference to a client.
   */
  class Client
  {
  };

  /*! \brief Create a new chat server.
   */
  Server(Wt::WServer& server);

  /*! \brief Connects to the chat server.
   *
   * The passed callback method is posted to when a new chat event is
   * received.
   *
   * Returns whether the client has been connected (or false if the client
   * was already connected).
   */
  bool connect(Client *client, const ClientEventCallback& handleEvent);

  /*! \brief Disconnect from the chat server.
   *
   * Returns whether the client has been disconnected (or false if the client
   * was not connected).
   */  
  bool disconnect(Client *client);

  /*! \brief Try to login with given user name.
   *
   * Returns false if the login was not successful.
   */
  bool login(const Wt::WString& user);

  /*! \brief Logout from the server.
   */
  void logout(const Wt::WString& user);

  /*! \brief Changes the name.
   */
  bool changeName(const Wt::WString& user, const Wt::WString& newUser);

  /*! \brief Get a suggestion for a guest user name.
   */
  Wt::WString suggestGuest();

  /*! \brief Send a message on behalve of a user.
   */
  void sendMessage(const Wt::WString& user, const Wt::WString& message);

  /*! \brief Typedef for a collection of user names.
   */
  typedef std::set<Wt::WString> UserSet;

  /*! \brief Get the users currently logged in.
   */
  UserSet users();

 private:
  // Server
  Wt::WServer& server_;
  DeviceServer devServer_;

  // Client
  struct ClientInfo {
    std::string sessionId;
    ClientEventCallback eventCallback;
  };

  typedef std::map<Client *, ClientInfo> ClientMap;

  boost::recursive_mutex mutex_;
  ClientMap clients_;
  UserSet users_;
  void postClientEvent(const ClientEvent& event);

 };

/*@}*/

#endif // Server_H_
