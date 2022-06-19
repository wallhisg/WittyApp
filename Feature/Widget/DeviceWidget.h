#ifndef DEVICEWIDGET_H
#define DEVICEWIDGET_H

#include <Wt/WApplication>
#include <Wt/WEnvironment>
#include <Wt/WServer>
#include <Wt/WContainerWidget>
#include <Wt/WPushButton>

#include <boost/thread.hpp>

using namespace Wt;
using namespace std;

class Server;

class DeviceWidget : public  Wt::WContainerWidget
{
public:
    DeviceWidget(Server &server, const string* parameter, Wt::WContainerWidget *parent = 0);
    ~DeviceWidget();

    void updateData();
    void ToggleState();

private:
    Server& server_;
    WPushButton* btnState_;
    const string* param_;

};

#endif // DEVICEWIDGET_H
