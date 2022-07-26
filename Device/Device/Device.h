#ifndef DEVICE_H
#define DEVICE_H

#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WContainerWidget>
#include <Wt/WWidget>
#include <Wt/WTable>
#include <Wt/WText>
#include <Wt/WPushButton>
#include <Wt/WString>

#include <boost/noncopyable.hpp>
#include <boost/thread.hpp>
#include <set>
#include <map>
#include <iostream>
#include <string.h>

using namespace std;
using namespace Wt;

struct device {
	WString id;
	WString name;
	WString ip;
	WString value;
};

class DeviceEvent;

class Device
{
public:
    Device()
    {}

    Device(struct device device)
    {
        device_ = device;
    }
	
	bool connect(struct device device);
	
	struct device getDeviceInfo() const { return device_; }
	const string getIdString() const { return device_.id.toUTF8(); }

	void setId(const WString id) { device_.id = id; }
	void setIp(const WString ip) { device_.ip = ip; }
	void setName(const WString name) { device_.name = name; }
	void setValue(const WString value) { device_.value = value; }

private:
    struct device device_;
};



class Devices
{
public:

    bool insertDevice(struct device device);
    bool eraseDevice(const struct device& device);
    void updateDevice(const struct device device);

	typedef map<string, struct device> DeviceMap;
	DeviceMap deviceMap() const { return devices_; }

private:
	DeviceMap devices_;
	boost::recursive_mutex mutex_;

	friend class DeviceServer;	
};

#endif	//	DEVICE_H