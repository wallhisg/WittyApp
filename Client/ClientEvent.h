// This may look like C code, but it's really -*- C++ -*-
/*
 * Copyright (C) 2008 Emweb bv, Herent, Belgium.
 *
 * See the LICENSE file for terms of use.
 */
#ifndef CLIENTEVENT_H_
#define CLIENTEVENT_H_

#include <boost/noncopyable.hpp>

#include <Wt/WSignal>
#include <Wt/WString>

#include <set>
#include <map>
#include <boost/thread.hpp>

namespace Wt {
  class WServer;
}

/**
 * @addtogroup chatexample
 */
/*@{*/

/*! \brief Encapsulate a chat event.
 */
class ClientEvent
{
public:
  /*! \brief Enumeration for the event type.
   */
  enum Type { Login, Logout, Rename, Message };

  /*! \brief Get the event type.
   */
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

  /*! \brief Get the message formatted as HTML, rendered for the given user.
   *
   * The \p format indicates how the message should be formatted.
   */
  const Wt::WString formattedHTML(const Wt::WString& user,
				  Wt::TextFormat format) const;

private:
  Type type_;
  Wt::WString user_;
  Wt::WString data_;
  Wt::WString message_;

  /*
   * Both user and html will be formatted as html
   */
  ClientEvent(const Wt::WString& user, const Wt::WString& message)
    : type_(Message), user_(user), message_(message)
  { }

  ClientEvent(Type type, const Wt::WString& user,
	    const Wt::WString& data = Wt::WString::Empty)
    : type_(type), user_(user), data_(data)
  { }

  friend class Server;
};

typedef boost::function<void (const ClientEvent&)> ClientEventCallback;

/*@}*/

#endif // CLIENTEVENT_H_
