#ifndef DEVICE_EVENT_H
#define DEVICE_EVENT_H

#include <Wt/Json/Object>
#include <Wt/Json/Parser>
#include <Wt/Json/Array>
#include <Wt/WString>

#include <boost/noncopyable.hpp>
#include <boost/thread.hpp>
#include <set>
#include <map>
#include <iostream>
#include <string.h>

#include <Device.h>

using namespace std;
using namespace Wt;

struct device;

class DeviceEvent
{
public:
	DeviceEvent()
	{}

	// device => Connect => DeviceServer[DeviceMap(insert)] => Attach => ServerSide
	// ServerSide => Deatach => Disconnect => DeviceServer[DeviceMap(erase)]
	enum Type { Connect, Disconnect, Attach, Deatach, Update, ChangeValue};

	Type type() const { return type_; }
	
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

#endif	//	DEVICE_EVENT_H
