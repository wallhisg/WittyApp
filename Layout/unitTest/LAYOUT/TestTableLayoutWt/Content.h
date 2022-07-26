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

#include <vector>
#include <Table.h>

using namespace std;
using namespace Wt;

class Content : public Table
{
public:
	Content();
	~Content()
	{
		delete vLayout_;
	}
	
	void renderContent();

	WVBoxLayout *vLayout() const { return vLayout_; }

private:
	WVBoxLayout *vLayout_;
	
};

#endif	//	CONTENT_H