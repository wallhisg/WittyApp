#ifndef APPLICATION_H
#define APPLICATION_H

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

#include "Layout.h"
#include "Table.h"

using namespace Wt;
using namespace std;

class ServerAppication : public WApplication 
{
	
public:
	ServerAppication(const WEnvironment& env);
	
	void WebApplication();
	
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

    Wt::WContainerWidget *mainContainer_;
    Wt::WVBoxLayout *mainLayout_;
    Layout *layout_;
};


#endif	//	APPLICATION_H