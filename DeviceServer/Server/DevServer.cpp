#include "DevServer.h"

DeviceServer::DeviceServer()
{
	deviceWR_ = new DeviceWResource();
	deviceWR_->devConEventSig().connect(SLOT(this, DeviceServer::connect));
}

void DeviceServer::connect(const DeviceEvent& event)
{
	boost::recursive_mutex::scoped_lock lock(mutex_);
	struct device device = event.device();

	string devId = device.id.toUTF8();

	// Check device not exist
	if (devices_.insertDevice(device))
	{
		// Add struct device to map succeed -> New device
		// Emit Signal => processDevicecEvent => postClientEvent => render new widget
        emitDeviceEventSig(DeviceEvent(DeviceEvent::Type::Attach, device));
	}
}

Devices::DeviceMap DeviceServer::deviceMap()
{
    boost::recursive_mutex::scoped_lock lock(mutex_);
    Devices::DeviceMap res = devices_.deviceMap();
    return res;
}