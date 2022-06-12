#include "Device.h"

#include <iostream>

void printDeviceInfo(struct device device);


bool Device::jsonParser(const string devInfo)
{
	Wt::Json::Object result;
	Wt::Json::ParseError e;
	bool flag = false;
	
	flag = Json::parse(devInfo, result, e);
	if (!flag)
		return false;
	else
	{
		try
		{
			Json::parse(devInfo, result);

			device_.id = result.get("id");
			device_.ip = result.get("ip");
			device_.name = result.get("name");
			device_.value = result.get("value");

			printDeviceInfo(device_);

			return true;
		}
		catch (Wt::WException &exp)
		{
			std::cout << "exception:" << exp.what() << std::endl;
			return false;
		}
	}

}


void printDeviceInfo(struct device device)
{
	std::cout << "**************************" << std::endl;
	std::cout << "id: " << device.id << std::endl;
	std::cout << "ip: " << device.ip << std::endl;
	std::cout << "na: " << device.name << std::endl;
	std::cout << "id: " << device.value << std::endl;
	std::cout << "**************************" << std::endl;
}