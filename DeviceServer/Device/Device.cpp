#include "Device.h"

bool Device::connect(struct device device)
{

	return true;
}

bool Devices::insertDevice(struct device device)
{
	boost::recursive_mutex::scoped_lock lock(mutex_);

	string id = device.id.toUTF8();

	if (devices_.count(id) == 0)
	{
		struct device device_ = device;
		devices_[id]  = device_;

		return true;
	}
	else
		return false;
}

bool Devices::eraseDevice(struct device device)
{
	boost::recursive_mutex::scoped_lock lock(mutex_);

	string id = device.id.toUTF8();

	return devices_.erase(id) == 1;
}
