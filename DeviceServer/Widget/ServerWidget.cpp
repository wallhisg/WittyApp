/*
 * Copyright (C) 2008 Emweb bv, Herent, Belgium.
 *
 * See the LICENSE file for terms of use.
 */

#include "ServerWidget.h"
#include "Server.h"

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

using namespace Wt;

ServerWidget::ServerWidget(Server& server,
				   Wt::WContainerWidget *parent)
  : WContainerWidget(parent),
    server_(server),
    loggedIn_(false)
{
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
  if (!loggedIn()) {

  }
}

void ServerWidget::logout()
{
    disconnect();
}

void ServerWidget::createLayout(WWidget *messages, WWidget *userList,
				    WWidget *messageEdit,
				    WWidget *sendButton, WWidget *logoutButton)
{
  /*
   * Create a vertical layout, which will hold 3 rows,
   * organized like this:
   *
   * WVBoxLayout
   * --------------------------------------------
   * | nested WHBoxLayout (vertical stretch=1)  |
   * |                              |           |
   * |  messages                    | userList  |
   * |   (horizontal stretch=1)     |           |
   * |                              |           |
   * --------------------------------------------
   * | message edit area                        |
   * --------------------------------------------
   * | WHBoxLayout                              |
   * | send | logout                            |
   * --------------------------------------------
   */
  WVBoxLayout *vLayout = new WVBoxLayout();

  // Create a horizontal layout for the messages | userslist.
  WHBoxLayout *hLayout = new WHBoxLayout();

  // Add widget to horizontal layout with stretch = 1
  hLayout->addWidget(messages, 1);
  messages->setStyleClass("chat-msgs");

    // Add another widget to horizontal layout with stretch = 0
  hLayout->addWidget(userList);
  userList->setStyleClass("chat-users");

  hLayout->setResizable(0, true);

  // Add nested layout to vertical layout with stretch = 1
  vLayout->addLayout(hLayout, 1);

  // Add widget to vertical layout with stretch = 0
  vLayout->addWidget(messageEdit);
  messageEdit->setStyleClass("chat-noedit");

  // Create a horizontal layout for the buttons.
  hLayout = new WHBoxLayout();

  // Add button to horizontal layout with stretch = 0
  hLayout->addWidget(sendButton);

  // Add button to horizontal layout with stretch = 0
  hLayout->addWidget(logoutButton);

  // Add nested layout to vertical layout with stretch = 0
  vLayout->addLayout(hLayout, 0, AlignLeft);

  setLayout(vLayout);
}

bool ServerWidget::loggedIn() const
{
  return loggedIn_;
}


bool ServerWidget::startChat(const WString& user)
{
  /*
   * When logging in, we pass our processClientEvent method as the function that
   * is used to indicate a new chat event for this user.
   */

    connect();

    return true;
}

void ServerWidget::processClientEvent(const ClientEvent& event)
{

    switch (event.type())
    {
        case ClientEvent::Type::User:
        {
            processWebEvent(event.webEvent());
            break;
        }
        case ClientEvent::Type::Device:
        {
            processDevicecEvent(event.devEvent());
            break;
        }
        default:
            break;
    }
}

void ServerWidget::processWebEvent(const WebEvent& event)
{
  WApplication *app = WApplication::instance();

  /*
   * This is where the "server-push" happens. The chat server posts to this
   * event from other sessions, see Server::postClientEvent()
   */

  /*
   * Format and append the line to the conversation.
   *
   * This is also the step where the automatic XSS filtering will kick in:
   * - if another user tried to pass on some JavaScript, it is filtered away.
   * - if another user did not provide valid XHTML, the text is automatically
   *   interpreted as PlainText
   */

  /*
   * If it is not a plain message, also update the user list.
   */
  if (event.type() != WebEvent::Message) {
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

void ServerWidget::processDevicecEvent(const DeviceEvent& event)
{
    std::cout << "**************************" << std::endl;
    std::cout << "processDevicecEvent" << std::endl;
    struct device device;
    device = event.device();

        

}