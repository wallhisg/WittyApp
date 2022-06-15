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

#include <DeviceWidget.h>

class ServerWidget : public Wt::WContainerWidget
{
public:
	ServerWidget(Wt::WContainerWidget *parent = 0);

private:
	DeviceWidget *devWidget;
};

#endif