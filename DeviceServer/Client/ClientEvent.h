// This may look like C code, but it's really -*- C++ -*-
/*
 * Copyright (C) 2008 Emweb bv, Herent, Belgium.
 *
 * See the LICENSE file for terms of use.
 */
#ifndef CLIENTEVENT_H
#define CLIENTEVENT_H

#include <boost/noncopyable.hpp>

#include <Wt/WSignal>
#include <Wt/WString>

#include <set>
#include <map>
#include <boost/thread.hpp>

#include "Device.h"

using namespace Wt;
using namespace std;

namespace Wt {
  class WServer;
}

class WebEvent
{
public:
  WebEvent()
  {}

  enum Type { Login, Logout, Rename, Message, Device, User, Admin  };
  Type type() const { return type_; }

  /*! \brief Get the user who caused the event.
   */
  const Wt::WString& user() const { return user_; }

  /*! \brief Get the message of the event.
   */
  const Wt::WString& message() const { return message_; }

  /*! \brief Get the extra data for this event.
   */
  const Wt::WString& data() const { return data_; }

    /*
   * Both user and html will be formatted as html
   */
  WebEvent(const Wt::WString& user, const Wt::WString& message)
    : type_(Message), user_(user), message_(message)
  { }

  WebEvent(Type type, const Wt::WString& user,
      const Wt::WString& data = Wt::WString::Empty)
    : type_(type), user_(user), data_(data)
  { }


private:
  Type type_;
  Wt::WString user_;
  Wt::WString data_;
  Wt::WString message_;
};

/*@{*/

/*! \brief Encapsulate a chat event.
 */
class ClientEvent
{
public:
  /*! \brief Enumeration for the event type.
   */
  enum Type { User, Device };
  Type type() const { return type_; }

  ClientEvent(Type type, WebEvent webEvent)
    : type_(type),
      webEvent_(webEvent)
  {}

  ClientEvent(Type type, DeviceEvent devEvent)
    : type_(type),
    devEvent_(devEvent)
  {}

  const WebEvent webEvent() const { return webEvent_; }
  const DeviceEvent devEvent() const { return devEvent_; }
private:
  Type type_;
  WebEvent webEvent_;
  DeviceEvent devEvent_;


  friend class Server;
};

typedef boost::function<void (const ClientEvent&)> ClientEventCallback;

/*@}*/

#endif // CLIENTEVENT_H
