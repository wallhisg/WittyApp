#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WEnvironment>
#include <Wt/WPushButton>
#include <Wt/WServer>
#include <Wt/WText>
#include <Wt/WPushButton>
#include <Wt/WSlider>
#include <Wt/WTimer>
#include <Wt/WBootstrapTheme>
#include <Wt/WCssTheme>
#include <SliderWidget.h>


using namespace Wt;
using namespace std;

class ServerAppication : public WApplication 
{
public:
	ServerAppication(const WEnvironment& env);
	void setStateOn();
	void setStateOff();
private:
	SliderWidget* slider;
};

ServerAppication::ServerAppication(const WEnvironment& env)
	: 	WApplication(env)

{
	setTitle("Device Manager");
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
	
{		this->setTheme(new Wt::WCssTheme(theme));	
	}

	// load text bundles (for the tr() function)
	this->messageResourceBundle().use(this->appRoot() + "report");
	this->messageResourceBundle().use(this->appRoot() + "text");
	this->messageResourceBundle().use(this->appRoot() + "WidgetXml");

    this->useStyleSheet("resources/style.css");
    this->require("resources/jquery.min.js");
    this->require("resources/index.js");

    slider = new SliderWidget();
    root()->addWidget(slider);

    WPushButton *btnChange = new WPushButton("Change");
    root()->addWidget(btnChange);
    btnChange->clicked().connect(boost::bind(&ServerAppication::setStateOn, this));


}

void ServerAppication::setStateOn()
{
    slider->acd();

}

void ServerAppication::setStateOff()
{

}


WApplication *createApplication(const WEnvironment& env)
{
    /*
     * You could read information from the environment to decide whether
     * the user has permission to start a new application
     */
    return new ServerAppication(env);
}

int main(int argc, char **argv)
{
return WRun(argc, argv, &createApplication);
}
