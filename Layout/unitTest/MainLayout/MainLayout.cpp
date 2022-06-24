#include "MainLayout.h"


ServerAppication::ServerAppication(const WEnvironment& env)
	: 	WApplication(env)
{
	setTitle("MainLayout");
	addMetaHeader("viewport", "width=device-width, initial-scale=1, maximum-scale=1");

	const std::string *themePtr = env.getParameter("theme");
	std::string theme;
	
	if (!themePtr)
		theme = "bootstrap3";
	else
		theme = *themePtr;

	if (theme == "bootstrap3") 
	{
		Wt::WBootstrapTheme *bootstrapTheme = new Wt::WBootstrapTheme(this);
		bootstrapTheme->setVersion(Wt::WBootstrapTheme::Version3);
		bootstrapTheme->setResponsive(true);
		this->setTheme(bootstrapTheme);

		// load the default bootstrap3 (sub-)theme
		this->useStyleSheet("resources/themes/bootstrap/3/bootstrap-theme.min.css");
	} 
	else if (theme == "bootstrap2") 
	{
		Wt::WBootstrapTheme *bootstrapTheme = new Wt::WBootstrapTheme(this);
		bootstrapTheme->setResponsive(true);
		this->setTheme(bootstrapTheme);
	} 
	else
	{		
		this->setTheme(new Wt::WCssTheme(theme));	
	}

	// load text bundles (for the tr() function)
	this->messageResourceBundle().use(this->appRoot() + "report");
	this->messageResourceBundle().use(this->appRoot() + "text");
	this->messageResourceBundle().use(this->appRoot() + "layout");

    this->useStyleSheet("resources/css/style.css");
    this->require("resources/jquery.min.js");
    this->require("resources/index.js");

	mainLayout_ = new Wt::WVBoxLayout();
	mainContainer_ = new Wt::WContainerWidget();
	mainContainer_->setLayout(mainLayout_);
	root()->addWidget(mainContainer_);
	createUi();
}

void ServerAppication::createUi()
{
	renderHeader();

}

WApplication *createApplication(const WEnvironment& env)
{
    return new ServerAppication(env);
}

int main(int argc, char **argv)
{
	return WRun(argc, argv, &createApplication);
}