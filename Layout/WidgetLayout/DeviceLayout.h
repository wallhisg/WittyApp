#ifndef DEVICE_LAYOUT_H
#define DEVICE_LAYOUT_H

#include <Wt/WWidget>
#include <Layout.h>

class DeviceLayout : public Layout
{
public:
	DeviceLayout();
	~DeviceLayout()
	{

	}

	void render();
	
	void renderId(WWidget *widget);
	void renderName(WWidget *widget);
	void renderIp(WWidget *widget);
	void renderValue(WWidget *widget);
	void renderControl(WWidget *widget);

private:

};







#endif	//	DEVICE_LAYOUT_H