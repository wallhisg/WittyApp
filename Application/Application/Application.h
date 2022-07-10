#ifndef APPLICATION_H
#define APPLICATION_H

#include <Wt/WServer>
#include <Wt/WEnvironment>
#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WTimer>
#include <Wt/WBootstrapTheme>
#include <Wt/WCssTheme>

using namespace Wt;
using namespace std;

class ServerAppication : public WApplication 
{
	
public:
	ServerAppication(const WEnvironment& env);
	void InitApplication();
	
	void setBootstrapTheme();
	void title(string title);

	void requireJavaScript(string path);
	void setAppRoot(string path);
	void setCss(string path);

private:
	const WEnvironment& env_;
	const std::string *themePtr_; 
	Wt::WBootstrapTheme *bootstrapTheme_;
	Wt::WCssTheme *cssTheme_;
};

ServerAppication::ServerAppication(const WEnvironment& env)
	: 	WApplication(env),
		env_(env)
{
    InitApplication();
}

void ServerAppication::setBootstrapTheme()
{
	themePtr_ = env_.getParameter("theme");
	std::string theme;
	
	if (!themePtr_)
		theme = "bootstrap3";
	else
		theme = *themePtr_;

	if (theme == "bootstrap3") 
	{
		bootstrapTheme_ = new Wt::WBootstrapTheme(this);
		bootstrapTheme_->setVersion(Wt::WBootstrapTheme::Version3);
		bootstrapTheme_->setResponsive(true);
		this->setTheme(bootstrapTheme_);

		// load the default bootstrap3 (sub-)theme
		this->useStyleSheet("resources/themes/bootstrap/3/bootstrap-theme.min.css");
	} 
	else if (theme == "bootstrap2") 
	{
		bootstrapTheme_ = new Wt::WBootstrapTheme(this);
		bootstrapTheme_->setResponsive(true);
		this->setTheme(bootstrapTheme_);
	} 
	else
	{		
		this->setTheme(new Wt::WCssTheme(theme));	
	}

	// load text bundles (for the tr() function)
	this->messageResourceBundle().use(this->appRoot() + "report");
	this->messageResourceBundle().use(this->appRoot() + "text");
	// this->messageResourceBundle().use(this->appRoot() + "widget");

    // this->require("resources/js/jquery.min.js");
    // this->useStyleSheet("resources/css/style.css");
    // this->useStyleSheet("resources/css/layout.css");
}

void ServerAppication::title(string title)
{
	this->setTitle(title);
}

void ServerAppication::requireJavaScript(string path)
{
	this->require(path);
}

void ServerAppication::setAppRoot(string path)
{
	this->messageResourceBundle().use(this->appRoot() + path);
}

void  ServerAppication::setCss(string path)
{
	this->useStyleSheet(path);
}

#endif	//	APPLICATION_H