#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <Wt/WApplication>
#include <Wt/WEnvironment>
#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WContainerWidget>
#include <Wt/WPushButton>
#include <Wt/WServer>
#include <Wt/WText>
#include <Wt/WPushButton>
#include <Wt/WSlider>
#include <Wt/WTimer>
#include <Wt/WBootstrapTheme>
#include <Wt/WCssTheme>

#include <Layout.h>

using namespace Wt;
using namespace std;

class ServerAppication : public WApplication 
{
public:
	ServerAppication(const WEnvironment& env);
	void initBootStrap();
	void initApproot();

	void createUi();
private:

    Wt::WVBoxLayout *mainLayout_;
    Wt::WContainerWidget *mainContainer_;
};

void ServerAppication::initBootStrap()
{
	Wt::WBootstrapTheme *bootstrapTheme = new Wt::WBootstrapTheme(this);
	bootstrapTheme->setVersion(Wt::WBootstrapTheme::Version3);
	bootstrapTheme->setResponsive(true);
	this->setTheme(bootstrapTheme);


	// load the default bootstrap3 (sub-)theme
	this->useStyleSheet("resources/themes/bootstrap/3/bootstrap-theme.min.css");

	std::string theme = "bootstrap3";
	this->setTheme(new Wt::WCssTheme(theme));
}

void ServerAppication::initApproot()
{
	// load text bundles (for the tr() function)
	this->messageResourceBundle().use(this->appRoot() + "report");
	this->messageResourceBundle().use(this->appRoot() + "text");
	this->messageResourceBundle().use(this->appRoot() + "WidgetXml");

    this->useStyleSheet("resources/style.css");
    this->require("resources/jquery.min.js");
    this->require("resources/index.js");
}

#endif	//	TEMPLATE_H