#ifndef DEVSERVER_H_
#define DEVSERVER_H_

#include <boost/noncopyable.hpp>

#include <Wt/WSignal>
#include <Wt/WString>
#include <ClientEvent.h>

#include <set>
#include <map>
#include <boost/thread.hpp>

#include <Device.h>
#include <DeviceWResource.h>

class DeviceServer
{
public:
	DeviceServer();

	DeviceWResource* deviceWResource() const { return deviceWR_; } 
	void connect(const DeviceEvent &event);

	// Emit Signal to update widget
	Wt::Signal<ClientEvent>& clientEventSig() { return clientEventSig_; }

	void emitClientEventSig(const ClientEvent &event)
	{
		clientEventSig_.emit(event);
	}

	// DeviceMap
	typedef map<string, struct device> DeviceMap;
	DeviceMap deviceMap();

private:
	DeviceWResource *deviceWR_;
	DeviceMap deviceMap_;
	Wt::Signal<ClientEvent> clientEventSig_;

    // System
    boost::recursive_mutex mutex_;
};



#endif	//	DEVSERVER_H_