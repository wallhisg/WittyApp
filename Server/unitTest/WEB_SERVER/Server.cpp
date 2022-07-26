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

#include <WebServer.h>
#include <ServerWidget.h>
#include <Wt/WBootstrapTheme>
#include <Wt/WCssTheme>

using namespace Wt;
using namespace std;

class Server;
class DeviceServer;

class IoServer
{
public:
	IoServer(WebServer& server, DeviceServer& deviceServer)
		:	server_(server),
		deviceServer_(deviceServer)
	{}

	WebServer& getServer() { return server_; }
	DeviceServer& getDeviceServer() { return deviceServer_; }

private:
	WebServer &server_;
	DeviceServer& deviceServer_;
};

class ServerAppication : public WApplication 
{
public:
	ServerAppication(const WEnvironment& env, 
	WebServer& server,
	DeviceServer& deviceServer);

private:
	WebServer& server_;
	DeviceServer& deviceServer_;
	ServerWidget* serverWidget;
};

ServerAppication::ServerAppication(const WEnvironment& env, WebServer& server, DeviceServer& deviceServer)
	: 	WApplication(env),
		server_(server),
		deviceServer_(deviceServer)
{
	setTitle("Device Manager");
	addMetaHeader("viewport", "width=device-width, initial-scale=1, maximum-scale=1");

	const std::string *themePtr = env.getParameter("theme");
	std::string theme;
	
	if (!themePtr)
		theme = "bootstrap3";
	else
		theme = *themePtr;

	if (theme == "bootstrap3") {
		Wt::WBootstrapTheme *bootstrapTheme = new Wt::WBootstrapTheme(this);
		bootstrapTheme->setVersion(Wt::WBootstrapTheme::Version3);
		bootstrapTheme->setResponsive(true);
		this->setTheme(bootstrapTheme);

		// load the default bootstrap3 (sub-)theme
		// this->useStyleSheet("/home/wall/projects/Web/WittyApp/WittyApp/DeviceServer/build/unitTest/SAMPLE/WEB_SERVER/resources/themes/bootstrap/3/bootstrap-theme.min.css");
		this->useStyleSheet("resources/themes/bootstrap/3/bootstrap-theme.min.css");
		} else if (theme == "bootstrap2") {
		Wt::WBootstrapTheme *bootstrapTheme = new Wt::WBootstrapTheme(this);
		bootstrapTheme->setResponsive(true);
		this->setTheme(bootstrapTheme);
	} else
		this->setTheme(new Wt::WCssTheme(theme));	

	// load text bundles (for the tr() function)
	this->messageResourceBundle().use(this->appRoot() + "report");
	this->messageResourceBundle().use(this->appRoot() + "text");
	// this->messageResourceBundle().use(app->appRoot() + "src");

	serverWidget = new ServerWidget(server_, deviceServer_, root());
}

WApplication *createApplication(const WEnvironment& env, IoServer& ioServer)
{
	return new ServerAppication(env, ioServer.getServer(), ioServer.getDeviceServer());
}

int main(int argc, char **argv)
{
	Wt::WServer server(argc, argv, WTHTTP_CONFIGURATION);
	WebServer webServer(server);
	DeviceServer deviceServer(server);

	IoServer ioServer(webServer, deviceServer);

	/*
	* We add two entry points: one for the full-window application,
	* and one for a widget that can be integrated in another page.
	*/
	server.addEntryPoint(Wt::Application,
	boost::bind(createApplication, _1,
	boost::ref(ioServer)));

	if (server.start()) {
		int sig = Wt::WServer::waitForShutdown();
		std::cerr << "Shutting down: (signal = " << sig << ")" << std::endl;
		server.stop();
	}
}

