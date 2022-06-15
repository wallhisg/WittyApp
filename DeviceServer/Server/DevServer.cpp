#include "DevServer.h"

DeviceServer::DeviceServer()
{
	deviceWR_ = new DeviceWResource();
	deviceWR_->devEventSig().connect(SLOT(this, DeviceServer::connect));
}

void DeviceServer::connect(const DeviceEvent &event)
{
	boost::recursive_mutex::scoped_lock lock(mutex_);
	struct device device = event.device();

	string devId = device.id.toUTF8();

	if (deviceMap_.count(devId) == 0)
	{
		// Add struct device to map
		deviceMap_[devId] = device;
		// Emit Signal => postClientEvent => processDevicecEvent => render widget
		emitClientEventSig(ClientEvent(ClientEvent::Type::Device, 
						   DeviceEvent(DeviceEvent::Type::Attach, device)));
	}

}

DeviceServer::DeviceMap DeviceServer::deviceMap()
{
    boost::recursive_mutex::scoped_lock lock(mutex_);
    DeviceMap res = deviceMap_;
    return res;
}