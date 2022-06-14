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
		:	device_(device)
	{

	}
	Device()
	{

	}
	// Move out later
	bool jsonParser(const string devInfo);
	
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
	enum Type { attach, deatach, Rename, Message };
	Type type() const { return type_; }
	const Wt::WString& user() const { return user_; }
	const Wt::WString& message() const { return message_; }
	const Wt::WString& data() const { return data_; }
	
	const string& id() const { return id_; }
	
	DeviceEvent(Type type, const Wt::WString& user,
		const Wt::WString& data = Wt::WString::Empty)
		: type_(type), user_(user), data_(data)
	{ 
	}

	DeviceEvent(Device device)
		:	device_(device)
	{
	}

	DeviceEvent(Type type)
		: type_(type)
	{
	}

	DeviceEvent(Type type, const string &id)
		: type_(type),
			id_(id)
	{
	}	

private:
  Type type_;
  Wt::WString user_;
  Wt::WString data_;
  Wt::WString message_;
  Device device_;
  string id_;



	friend class Server;
};

typedef boost::function<void (const DeviceEvent&)> DeviceEventCallback;



#endif	//	DEVICE_H_
