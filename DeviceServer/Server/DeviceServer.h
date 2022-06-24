#ifndef DEVICESERVER_H
#define DEVICESERVER_H

#include <Wt/WSignal>
#include <Wt/WString>
#include <Wt/WServer>

#include <ClientEvent.h>

#include <boost/noncopyable.hpp>
#include <boost/thread.hpp>
#include <set>
#include <map>

#include <Device.h>
#include <DeviceWResource.h>
#include <WebServer.h>

class DeviceWResource;
class DeviceEvent;


class DeviceServer : public WebServer::Client
{
public:

	DeviceServer(Wt::WServer& server);
	bool connect(Client *client, const DeviceEventCallback &event);

	void changeValue(struct device& device);
	void updateDeviceMap(struct device& device);

	DeviceWResource* deviceWResource() const { return deviceWR_; } 

	// Emit Signal to update widget
	Wt::Signal<DeviceEvent>& deviceEventSig() { return deviceEventSig_; }

	void emitDeviceEventSig(const DeviceEvent &event)
	{
		deviceEventSig_.emit(event);
	}

	
	Devices::DeviceMap deviceMap();
	void setDeviceWResource(DeviceWResource *deviceWR) { deviceWR_ = deviceWR; }
private:
	Wt::WServer& server_;
	DeviceWResource *deviceWR_;
	Devices devices_;

	Wt::Signal<DeviceEvent> deviceEventSig_;

	// Client
	struct ClientInfo 
	{
		std::string sessionId;
		DeviceEventCallback eventCallback;
	};

	typedef map<Client *, ClientInfo> ClientMap;
	ClientMap clients_;

	// System
	boost::recursive_mutex mutex_;

	void eventHandler(const DeviceEvent &event);
	void postDeviceEvent(const DeviceEvent& event);
};

#endif	//	DEVICESERVER_H
