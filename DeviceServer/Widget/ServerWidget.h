// This may look like C code, but it's really -*- C++ -*-
/*
 * Copyright (C) 2008 Emweb bv, Herent, Belgium.
 *
 * See the LICENSE file for terms of use.
 */

#ifndef ServerWidget_H_
#define ServerWidget_H_

#include <Wt/WContainerWidget>
#include <Wt/WJavaScript>
#include <Wt/WSound>

#include "Server.h"

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

/*! \brief A self-contained chat widget.
 */
class ServerWidget : public Wt::WContainerWidget,
			 public Server::Client
{
public:
  /*! \brief Create a chat widget that will connect to the given server.
   */
  ServerWidget(Server& server, Wt::WContainerWidget *parent = 0);

  /*! \brief Delete a chat widget.
   */
  ~ServerWidget();

  void connect();
  void disconnect();


  /*! \brief Show a simple login screen.
   */
  void letLogin();

  /*! \brief Start a chat for the given user.
   *
   * Returns false if the user could not login.
   */
  bool startChat(const Wt::WString& user);

  void logout();

  Server& server() { return server_; }

  int userCount() { return users_.size(); }

  const Wt::WString& userName() const { return user_; }

protected:
  virtual void createLayout(Wt::WWidget *messages, Wt::WWidget *userList,
			    Wt::WWidget *messageEdit,
			    Wt::WWidget *sendButton, Wt::WWidget *logoutButton);

protected:
  bool loggedIn() const;

private:
  typedef std::map<Wt::WString, bool> UserMap;
  UserMap users_;

  Server&     server_;
  
  bool                  loggedIn_;


  Wt::WString           user_;

  void login();

  /* called from another session */
  void processClientEvent(const ClientEvent& event);
  void processWebEvent(const WebEvent& event);
  void processDevicecEvent(const DeviceEvent& event);
};

/*@}*/

#endif // ServerWidget
