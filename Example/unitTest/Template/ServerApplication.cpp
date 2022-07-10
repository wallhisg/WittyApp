#include "ServerApplication.h"

void ServerAppication::InitApplication()
{
	this->title("Server Application");
	this->addMetaHeader("viewport", "width=device-width, initial-scale=1, maximum-scale=1");
	
	this->setBootstrapTheme();

	// require JavaScript
	this->requireJavaScript("resources/js/jquery.min.js");

	// set xml
	this->setAppRoot("report");
	this->setAppRoot("text");
	this->setAppRoot("widget");

	// setCss
	this->setCss("resources/css/layout.css");
	this->setCss("resources/css/style.css");
}

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