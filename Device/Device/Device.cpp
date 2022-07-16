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

bool Devices::eraseDevice(const struct device& device)
{
	boost::recursive_mutex::scoped_lock lock(mutex_);

	string id = device.id.toUTF8();

	return devices_.erase(id) == 1;
}
void Devices::updateDevice(const struct device device)
{
    std::cout << "**************************" << std::endl;
    std::cout << "Devices::updateDevice: " << device.value << std::endl;
	struct device dev = device;
	devices_.at(device.id.toUTF8()) = dev;

	struct device dev1 =  devices_.at(device.id.toUTF8());

        for (Devices::DeviceMap::const_iterator it = devices_.begin();
            it != devices_.end(); ++it)
        {
        	std::cout << "Devices::updateDevice: " << it->second.value << std::endl;
        }
}