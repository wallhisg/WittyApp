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

#include "LayoutWTable/Header.h"

using namespace Wt;
using namespace std;

class ServerAppication : public WApplication 
{
public:
	ServerAppication(const WEnvironment& env);

	void createUi();
	void renderHeader();
	void renderContent();

private:
    Wt::WContainerWidget *mainContainer_;
    Wt::WVBoxLayout *mainLayout_;
    HeaderLayout *header_;

};

void ServerAppication::renderHeader()
{
	// Create WTable Layout
	HeaderLayout *header_ = new HeaderLayout();

	// Header 00
	Wt::WImage* headerIcon;
	headerIcon = new Wt::WImage("resources/icons/DongA.png");

	header_->addHeaderWidget_At00(headerIcon);
	header_->setHeaderLenghtPercentage_At00(25);
	header_->setContentAlignment_At00(AlignLeft);

	// Header 01
	WText *headerAt01 = new WText(WString::tr("header"));
	header_->addHeaderWidget_At01(headerAt01);
	header_->setContentAlignment_At01(AlignCenter);
	
	mainLayout_->addWidget(header_);
}

void ServerAppication::renderContent()
{

}


#endif	//	MAINLAYOUT_H