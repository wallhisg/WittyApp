/*
 * Copyright (C) 2010 Emweb bvba, Kessel-Lo, Belgium.
 *
 * See the LICENSE file for terms of use.
 */
#include <Wt/WApplication>
#include <Wt/WEnvironment>
#include <Wt/WText>
#include <Wt/WMessageBox>
#include <Wt/WServer>


#include "src/Server/Server.h"
#include "PopupWidget.h"

class ServerApplication : public Wt::WApplication
{
public:
    ServerApplication(const Wt::WEnvironment& env, Server& server)
        : WApplication(env),
          server_(server),
          env_(env)
    {
        popupWidget_ = new PopupWidget(server_, env_.getParameter("param"), root());
        setCssTheme("");
        root()->addWidget(popupWidget_);

        popupWidgetPC_ = new PopupWidget(server_, env_.getParameter("param"), root());
        setCssTheme("");
        root()->addWidget(popupWidgetPC_);
    }

private:
    Server& server_;
    const WEnvironment& env_;
    PopupWidget* popupWidget_;
    PopupWidget* popupWidgetPC_;
};


Wt::WApplication *createApplication(const Wt::WEnvironment& env, Server& server)
{
    return new ServerApplication(env, server);
}

int main(int argc, char **argv)
{
    Wt::WServer server(argc, argv, WTHTTP_CONFIGURATION);
    Server PushServer(server);

    server.addEntryPoint(Wt::Application,
                 boost::bind(createApplication, _1,
                     boost::ref(PushServer)));

    if (server.start()) {
      int sig = Wt::WServer::waitForShutdown();
      std::cerr << "Shutting down: (signal = " << sig << ")" << std::endl;
      server.stop();
    }
}
