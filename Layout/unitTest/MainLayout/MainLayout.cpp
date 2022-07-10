#include "MainLayout.h"


ServerAppication::ServerAppication(const WEnvironment& env)
	: 	WApplication(env)
{
	setTitle("MainLayout");
	addMetaHeader("viewport", "width=device-width, initial-scale=1, maximum-scale=1");

	const std::string *themePtr_ = env.getParameter("theme");
	std::string theme;
	
	if (!themePtr_)
		theme = "bootstrap3";
	else
		theme = *themePtr_;

	if (theme == "bootstrap3") 
	{
		bootstrapTheme = new Wt::WBootstrapTheme(this);
		bootstrapTheme->setVersion(Wt::WBootstrapTheme::Version3);
		bootstrapTheme->setResponsive(true);
		this->setTheme(bootstrapTheme);
		this->useStyleSheet("resources/themes/bootstrap/3/bootstrap-theme.min.css");
	} 
	else if (theme == "bootstrap2") 
	{
		bootstrapTheme = new Wt::WBootstrapTheme(this);
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

    this->require("resources/js/jquery.min.js");
    // this->instance()->doJavaScript("document.write('<script src=\"http://'+location.host.split(':')[0]+':35729/livereload.js\"></'+'script>')");

    this->useStyleSheet("resources/css/style.css");
    this->useStyleSheet("resources/css/layout.css");

	mainLayout_ = new Wt::WVBoxLayout();
	mainContainer_ = new Wt::WContainerWidget();
	mainContainer_->setLayout(mainLayout_);
	root()->addWidget(mainContainer_);

	layout_ = new Layout(mainLayout_);

	layout_->createUi();


}
 
WApplication *createApplication(const WEnvironment& env)
{
    return new ServerAppication(env);
}

int main(int argc, char **argv)
{
	return WRun(argc, argv, &createApplication);
}