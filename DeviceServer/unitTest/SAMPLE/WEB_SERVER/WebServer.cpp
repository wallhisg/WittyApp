/*
 * Copyright (C) 2008 Emweb bv, Herent, Belgium.
 *
 * See the LICENSE file for terms of use.
 */

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WEnvironment>
#include <Wt/WPushButton>
#include <Wt/WServer>
#include <Wt/WText>
#include <Wt/WTimer>

#include "Server.h"


using namespace Wt;

/**
 * @addtogroup chatexample
 */
/*@{*/

/*! \brief A chat demo application.
 */
class ServerAppication : public WApplication
{
public:
  /*! \brief Create a new instance.
   */
  ServerAppication(const WEnvironment& env, Server& server);

private:
  Server& server_;

};

ServerAppication::ServerAppication(const WEnvironment& env,
				 Server& server)
  : WApplication(env),
    server_(server)
{
  setTitle("Wt Chat");

  root()->addWidget(new WText(WString::tr("introduction")));

}




WApplication *createApplication(const WEnvironment& env,
				Server& server)
{
  return new ServerAppication(env, server);
}

int main(int argc, char **argv)
{
  Wt::WServer server(argc, argv, WTHTTP_CONFIGURATION);
  Server chatServer(server);

  /*
   * We add two entry points: one for the full-window application,
   * and one for a widget that can be integrated in another page.
   */
  server.addEntryPoint(Wt::Application,
		       boost::bind(createApplication, _1,
				   boost::ref(chatServer)));

  if (server.start()) {
    int sig = Wt::WServer::waitForShutdown();
    std::cerr << "Shutting down: (signal = " << sig << ")" << std::endl;
    server.stop();
  }
}

/*@}*/
