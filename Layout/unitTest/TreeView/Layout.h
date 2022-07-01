#ifndef LAYOUT_H
#define LAYOUT_H

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

#include "WTableLayout.h"

using namespace Wt;
using namespace std;

/*
	Main Layout
	*****************************************************************
	*			| Noi dung		|	Noi dung chinh					*
	*****************************************************************
	*********	-----------------------------------------------------	<- HLayout
	*Header	*	|					TEN DON VI						|	
	*		*	|				TEN PHONG BAN/KHOA					|
	*********	-----------------------------------------------------	<- HLayout
	*		*	| THIET BI  	|		THONG TIN CHUNG				|
	*		*	|				|									|
	*		*	-----------------------------------------------------				
	*		*	| Thiet bi 1	|		Thong tin thiet bi 1		|
	* Noi	*	|				|	ID:								|
	* dung	*	|				|	NAME:							|
	*		*	|				|	IP:								|
	*		*	|				|		 [WIDGET]					|
	*		*	|				|									|
	*		*	-----------------------------------------------------
	*		*	| Thiet bi 2	|		Thong tin thiet bi 2		|
	*		*	|				|	ID:								|
	*		*	|				|	NAME:							|
	*		*	|				|	IP:								|
	*		*	|				|		[WIDGET]					|
	*********	-----------------------------------------------------
	*Footer	*	|	THONG TIN THEM									|
	*********	-----------------------------------------------------
*/

class Layout
{
public:
	Layout(WVBoxLayout *parent);
	void createUi();

	void renderHeader();
	void setHeaderStyle();
	
	void renderContent();
	void setContentStyle();

private:
	WVBoxLayout *mainLayout_;
    WTableLayout *header_;
    WTableLayout *content_;	
};








#endif	//	LAYOUT_H