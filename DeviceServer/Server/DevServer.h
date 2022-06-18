#ifndef DEVSERVER_H
#define DEVSERVER_H


#include <Wt/WSignal>
#include <Wt/WString>
#include <ClientEvent.h>

#include <boost/noncopyable.hpp>
#include <boost/thread.hpp>
#include <set>
#include <map>

#include <Device.h>
#include <DeviceWResource.h>

class DeviceWResource;
class DeviceEvent;

class DeviceServer
{
public:
	DeviceServer();

	DeviceWResource* deviceWResource() const { return deviceWR_; } 
	void connect(const DeviceEvent &event);

	// Emit Signal to update widget
    Wt::Signal<DeviceEvent>& deviceEventSig() { return deviceEventSig_; }

    void emitDeviceEventSig(const DeviceEvent &event)
	{
        deviceEventSig_.emit(event);
	}

	Devices::DeviceMap deviceMap();

private:
	DeviceWResource *deviceWR_;
	Devices devices_;

    Wt::Signal<DeviceEvent> deviceEventSig_;

    // System
    boost::recursive_mutex mutex_;
};



#endif	//	DEVSERVER_H_
