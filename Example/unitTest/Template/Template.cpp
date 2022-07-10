#include <Wt/WServer>
#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WEnvironment>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WPushButton>
#include <Wt/WSlider>
#include <Wt/WTimer>
#include <Wt/WBootstrapTheme>
#include <Wt/WCssTheme>

#include "ServerApplication.h"


WApplication *createApplication(const WEnvironment& env)
{
    return new ServerAppication(env);
}

int main(int argc, char **argv)
{
    try {
        Wt::WServer server(argv[0]);
        server.setServerConfiguration(argc, argv, WTHTTP_CONFIGURATION);
        Wt::log("info")<<"Server is starting ....";

        server.addEntryPoint(Wt::Application, createApplication);

        if (server.start()) {
            Wt::WServer::waitForShutdown(argv[0]);
            server.stop();
        }
    } catch (Wt::WServer::Exception& e) {
        std::cerr << e.what() << "\n";
    } catch (std::exception& e) {
        std::cerr << "exception: " << e.what() << "\n";
    } return 0;
}
