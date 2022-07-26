#ifndef DEVICE_LAYOUT_H
#define DEVICE_LAYOUT_H

#include <Wt/WWidget>
#include <Layout.h>
#include <Device.h>

class DeviceLayout : public Layout
{
public:

	DeviceLayout(struct device &device);
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
	struct device &device_;
};







#endif	//	DEVICE_LAYOUT_H