#ifndef UI_H
#define UI_H

#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WContainerWidget>
#include <Wt/WWidget>
#include <Wt/WImage>
#include <Wt/WText>

#include <Table.h>
#include <TableLayout.h>

#include <Header.h>
#include <Content.h>
#include <Footer.h>

class Ui
{
public:
	Ui(WVBoxLayout *parent)
		: mainLayout_(parent)
	{
		header_ = new Header();
		content_ = new Content();
		footer_ = new Footer();
	}

	virtual ~Ui()
	{
		mainLayout_->removeItem(footer_->vLayout());
		mainLayout_->removeItem(content_->vLayout());
		mainLayout_->removeItem(header_->vLayout());

		delete footer_;
		delete content_;
		delete header_;
	}
	
	void changeLayout(WVBoxLayout *newLayout)
	{

	}
	
	void createUi()
	{
		renderHeader();
		renderContent();
		renderFooter();
	}

protected:
	virtual void renderHeader() = 0;
	virtual void renderContent() = 0;
	virtual void renderFooter() = 0;

	Header *header_;
	Content *content_;
	Footer *footer_;

private:
	WVBoxLayout *mainLayout_;
};
#endif	//	UI_H
