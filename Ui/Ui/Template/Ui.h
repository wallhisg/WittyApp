#ifndef UI_H
#define UI_H

#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WContainerWidget>
#include <Wt/WWidget>
#include <Wt/WImage>
#include <Wt/WText>

#include <Header.h>

class Ui
{
public:
	Ui(WVBoxLayout *parent)
		: mainLayout_(parent)
	{

	}

	~Ui()
	{
		delete header_;
	}
	

	
	void renderUi()
	{
		header_ = new Header();
		header_->render();
	}

protected:



private:
	WVBoxLayout *mainLayout_;

	Header *header_;
};

#endif	//	UI_H
