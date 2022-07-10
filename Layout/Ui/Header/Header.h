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

#include <WTableLayout.h>

using namespace std;
using namespace Wt;

class Header
{
public:
	Header(WImage *headerIcon, WText *headerBanner);
	
	WVBoxLayout *vLayout() const { return headerLayout_; }

private:

	WVBoxLayout *headerLayout_;
	WTableLayout *headerWt_;

	WImage *headerIcon_;
	WText *headerBanner_;

	void renderHeader();
};


#endif	//	HEADER_H

