#ifndef CONTENT_H
#define CONTENT_H

#include <Wt/WLayout>
#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WContainerWidget>
#include <Wt/WWidget>
#include <Wt/WImage>
#include <Wt/WTable>
#include <Wt/WText>
#include <Wt/WPushButton>

#include <WTableLayout.h>

using namespace std;
using namespace Wt;

class Content 
{
public:
	Content();

	void addParagraph(WText *wText);
	void addWidget(WWidget *widget);
	void addWTableLayout(WTableLayout *wtLayout);
	void addLayout(WLayout *layout);

	WVBoxLayout *vLayout() const { return contentLayout_; }

private:
	WVBoxLayout *contentLayout_;
};


#endif	//	CONTENT_H