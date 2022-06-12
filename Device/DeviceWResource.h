#ifndef DEVICEWRESOURE_H_
#define DEVICEWRESOURE_H_

#include <Wt/WResource>
#include <Wt/WSignal>
#include <Wt/Http/Request>
#include <Wt/Http/Response>
#include <Wt/Json/Object>
#include <Wt/Json/Parser>
#include <Wt/Json/Array>
#include <Wt/WString>

#include <boost/lexical_cast.hpp>

#include <Device.h>

using namespace Wt;
using namespace std;

class DeviceWResource : public WResource
{
public:
	~DeviceWResource();

	// Trigger when device attach
    Wt::Signal<Device, DeviceEvent>& devEventSig() { return devEventSig_; }

    void emitDeviceEventSig(Device device, const DeviceEvent &event)
    {
        devEventSig_.emit(device, event);
    }

protected:
	void handleRequest(const Http::Request &request, Http::Response &response);

private:
	Wt::Signal<Device, DeviceEvent> devEventSig_;
};







#endif	//	DEVICEWRESOURE_H_