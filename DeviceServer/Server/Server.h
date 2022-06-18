// This may look like C code, but it's really -*- C++ -*-
/*
 * Copyright (C) 2008 Emweb bv, Herent, Belgium.
 *
 * See the LICENSE file for terms of use.
 */
#ifndef Server_H
#define Server_H

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

  Server(Wt::WServer& server);

  bool connect(Client *client, const ClientEventCallback& handleEvent);

  bool disconnect(Client *client);

  bool login(const Wt::WString& user);

  void logout(const Wt::WString& user);

  typedef std::set<Wt::WString> UserSet;

  UserSet users();
  Devices::DeviceMap deviceMap() { return devServer_.deviceMap(); }

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
  void postDeviceEvent(const DeviceEvent& event);

};

#endif // Server_H
