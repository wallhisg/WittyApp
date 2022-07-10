#ifndef DEVICE_LAYOUT_H
#define DEVICE_LAYOUT_H


#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WContainerWidget>
#include <Wt/WWidget>
#include <Wt/WTable>
#include <Wt/WText>
#include <Wt/WPushButton>

#include <WTableLayout.h>
#include <Device.h>

using namespace std;
using namespace Wt;

class DeviceLayout : public WVBoxLayout
{
public:
	
	DeviceLayout();

	void renderWidget(DeviceWidget::Widget *widget);

	WVBoxLayout *vLayout() { return this; }

private:
	WTableLayout *wtLayout_;
	WHBoxLayout *devItLayout_;
	WContainerWidget *wc_;

	DeviceWidget::Widget *widget_;

	void renderId(WWidget *id);
	void renderItems(WWidget *name, WWidget *ip, WWidget *value);
};






#endif	//	DEVICE_LAYOUT_H