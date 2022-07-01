#ifndef MAINLAYOUT_H
#define MAINLAYOUT_H

#include <Wt/WApplication>
#include <Wt/WEnvironment>
#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WContainerWidget>
#include <Wt/WPushButton>
#include <Wt/WServer>
#include <Wt/WImage>
#include <Wt/WText>
#include <Wt/WPushButton>
#include <Wt/WSlider>
#include <Wt/WTimer>
#include <Wt/WBootstrapTheme>
#include <Wt/WCssTheme>

#include "Layout.h"
#include "TreeView.h"

using namespace Wt;
using namespace std;

class ServerAppication : public WApplication 
{
public:
	ServerAppication(const WEnvironment& env);

private:
    Wt::WContainerWidget *mainContainer_;
    Wt::WVBoxLayout *mainLayout_;
    WTableLayout *header_;
    WTableLayout *content_;

};

#endif	//	MAINLAYOUT_H