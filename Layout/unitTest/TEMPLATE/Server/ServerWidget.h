#ifndef SERVER_WIDGET_H
#define SERVER_WIDGET_H

#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WContainerWidget>
#include <Wt/WWidget>
#include <Wt/WImage>
#include <Wt/WText>

using namespace std;
using namespace Wt;

class ServerWidget
{
public:
	ServerWidget(WVBoxLayout *parent);
	~ServerWidget()
	{

	}

	void createUi();

private:
	WVBoxLayout *mainLayout_;


};


#endif	//	SERVER_WIDGET_H

