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

	// Trigger when device connect
    Wt::Signal<DeviceEvent>& devEventSig() { return devConEventSig_; }

    void emitDeviceConEventSig(const DeviceEvent &event)
    {
        devConEventSig_.emit(event);
    }

    bool jsonParserDevice(const string devInfo);

protected:
	void handleRequest(const Http::Request &request, Http::Response &response);

private:
	Wt::Signal<DeviceEvent> devConEventSig_;
	struct device device_;
};







#endif	//	DEVICEWRESOURE_H_