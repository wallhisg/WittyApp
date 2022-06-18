#ifndef SERVER_H_
#define SERVER_H_

#include <Wt/WContainerWidget>
#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WWidget>
#include <Wt/WPushButton>
#include <Wt/WSlider>
#include <Wt/WText>
#include <Wt/WJavaScript>
#include <Wt/WSound>
#include <Wt/Http/Client>

#include <boost/noncopyable.hpp>
#include <boost/thread.hpp>
#include <set>
#include <map>

#include "DeviceWidget.h"

using namespace std; 
using namespace Wt;

class ServerWidget : public Wt::WContainerWidget
{
public:
	ServerWidget(Wt::WContainerWidget *parent = 0);

	bool loggedIn() const;


	void addDeviceWidget(struct device& device);
    void renderDeviceWidget();


private:
	bool loggedIn_;

	WContainerWidget* wcDevice_;
    DeviceWidgetMap devMap_;
};

#endif
