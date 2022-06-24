#ifndef LAYOUT_H
#define LAYOUT_H

#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>

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
class MainLayout : public WVBoxLayout
{
public:
	MainLayout()
	{
		header_ = new WHBoxLayout();
		this->addLayout(header_);

		footer_ = new WHBoxLayout();
		this->addLayout(footer_);

	}

	WHBoxLayout* header() { return header_; }
	WHBoxLayout* footer() { return footer_; }

private:
	WHBoxLayout *header_;
	WHBoxLayout *footer_;



};






#endif	//	LAYOUT_H