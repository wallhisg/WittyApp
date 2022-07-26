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

#include <Layout.h>

using namespace std;
using namespace Wt;

class Header : public Layout
{
public:
	Header();
	
	~Header()
	{

	}

	virtual void render();

private:

};

#endif	//	HEADER_H

