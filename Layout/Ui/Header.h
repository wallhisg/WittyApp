#ifndef HEADER_H
#define HEADER_H

#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WContainerWidget>
#include <Wt/WWidget>
#include <Wt/WImage>
#include <Wt/WTable>
#include <Wt/WText>
#include <Wt/WPushButton>

#include <TableLayout.h>

using namespace std;
using namespace Wt;

class Header : public TableLayout
{
public:
	Header(WImage *headerIcon, WText *headerBanner);
	~Header()
	{
		delete vLayout_;
	}

	WVBoxLayout *vLayout() const { return vLayout_; }

private:
	WVBoxLayout *vLayout_;

	WImage *headerIcon_;
	WText *headerBanner_;

	void renderHeader();
};

#endif	//	HEADER_H

