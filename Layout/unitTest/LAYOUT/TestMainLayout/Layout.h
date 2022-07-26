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

#include <Table.h>
#include <DeviceLayout.h>
#include <Header.h>


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
	*********	-----------------------------------------------------	<- HLayout	-	C0
	*		*	| THIET BI  	|		THONG TIN CHUNG				|
	*		*	|				|									|
	*		*	-----------------------------------------------------	<- HLayout	-	C1				
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
	~Layout()
	{
		delete headerIcon;
		delete banner;
		// delete header;
	// 	delete tbl_tr_devWt_;
	}

	void createUi();

	void renderHeader();
	void renderContent();
	
	void renderDeviceId(struct device &device);
	void renderDeviceItem(struct device &device);

	void renderDeviceLayout(struct device &device);
private:
	WVBoxLayout *mainLayout_;

	// Header
	Wt::WImage* headerIcon;
	WText *banner;
	Header *header;
	// Content
    // Table *tbl_tr_devWt_;
};








#endif	//	LAYOUT_H