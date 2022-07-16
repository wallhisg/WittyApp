#include "DeviceServer.h"

DeviceServer::DeviceServer(Wt::WServer& server)
	: server_(server)
{
	deviceWR_ = new DeviceWResource();
	server_.addResource(deviceWR_, "/resource");
	deviceWR_->devConEventSig().connect(SLOT(this, DeviceServer::eventHandler));
}


bool DeviceServer::connect(Client *client, const DeviceEventCallback& handleEvent)
{
	boost::recursive_mutex::scoped_lock lock(mutex_);
	    if (clients_.count(client) == 0)
    {
        ClientInfo clientInfo;
  
        clientInfo.sessionId = WApplication::instance()->sessionId();
        clientInfo.eventCallback = handleEvent;

        clients_[client] = clientInfo;

        return true;
    } else
        return false;
}

void DeviceServer::changeValue(struct device& device)
{
    std::cout << "**************************" << std::endl;
    std::cout << "DeviceServer::changeValue" << device.value << std::endl;    

	updateDeviceMap(device);
	postDeviceEvent(DeviceEvent(DeviceEvent::Type::ChangeValue, 
								device));

}

void DeviceServer::updateDeviceMap(struct device& device)
{
	devices_.updateDevice(device);
    postDeviceEvent(DeviceEvent(DeviceEvent::Type::ChangeValue, device));
}

Devices::DeviceMap DeviceServer::deviceMap()
{
    boost::recursive_mutex::scoped_lock lock(mutex_);
    Devices::DeviceMap res = devices_.deviceMap();
    return res;
}

void DeviceServer::eventHandler(const DeviceEvent &event)
{
	const DeviceEvent::Type type = event.type();
	const struct device dev = event.device();

	switch (type)
	{
		case DeviceEvent::Type::Connect:
		{
			// if dev not in map
			if (devices_.insertDevice(dev))
				postDeviceEvent(event);
			break;
		}
		default:
			break;
	}
}

void DeviceServer::postDeviceEvent(const DeviceEvent& event)
{
    boost::recursive_mutex::scoped_lock lock(mutex_);

    WApplication *app = WApplication::instance();

    for (ClientMap::const_iterator it = clients_.begin(); it != clients_.end();
       ++it) {
    /*
     * If the user corresponds to the current application, we directly
     * call the call back method. This avoids an unnecessary delay for
     * the update to the user causing the event.
     *
     * For other uses, we post it to their session. By posting the
     * event, we avoid dead-lock scenarios, race conditions, and
     * delivering the event to a session that is just about to be
     * terminated.
     */
    if (app && app->sessionId() == it->second.sessionId)
      it->second.eventCallback(event);
    else
      server_.post(it->second.sessionId,
		   boost::bind(it->second.eventCallback, event));
  }
}
