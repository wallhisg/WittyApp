#ifndef DEVICE_H_
#define DEVICE_H_

#include <Wt/Json/Object>
#include <Wt/Json/Parser>
#include <Wt/Json/Array>
#include <Wt/WString>

#include <boost/noncopyable.hpp>
#include <boost/thread.hpp>
#include <set>
#include <map>
#include <string.h>
#include <iostream>

using namespace std;
using namespace Wt;

enum device_type {BUTTON, SLIDER};
class DeviceEvent;

struct device {
	WString id;
	WString ip;
	WString name;
	WString value;
	device_type type;
};

class Device
{
public:
	Device(struct device device)
	{}
	Device()
	{}
	
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

class DeviceEvent
{
public:
	DeviceEvent()
	{}

	enum Type { Connect, Disconnect, Attach, Deatach};
	Type type() const { return type_; }
	
  DeviceEvent(Type type)
  	:	type_(type)
	{
	}

  DeviceEvent(Type type, struct device &device)
  	:	type_(type)
	{
		device_ = device;
	}

	struct device device() const { return device_; }

private:
  Type type_;
  struct device device_;

	friend class Server;
};

typedef boost::function<void (const DeviceEvent&)> DeviceEventCallback;

#endif	//	DEVICE_H_
