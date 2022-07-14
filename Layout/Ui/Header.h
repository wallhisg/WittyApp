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

#include <Table.h>

using namespace std;
using namespace Wt;

class Header : public Table
{
public:
	Header();
	
	~Header()
	{
		delete vLayout_;
	}
	void renderIcon(const unsigned short row, const short col, WImage *icon);
	void renderBanner(const unsigned short row, const short col, WWidget *banner);

	WVBoxLayout *vLayout() const { return vLayout_; }

private:
	WVBoxLayout *vLayout_;
};

#endif	//	HEADER_H

