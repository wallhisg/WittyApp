#include "DeviceWResource.h"

DeviceWResource::~DeviceWResource()
{
	beingDeleted();
}

void DeviceWResource::handleRequest(const Http::Request &request, Http::Response &response)
{
    try
    {
        const std::string* devInfo_;
        WString clientAddr;
        clientAddr = request.clientAddress();
        std::cout << "**************************" << std::endl;
        std::cout << "handleRequest - Client Address: " << clientAddr << std::endl;
        devInfo_ = request.getParameter("devInfo");
        std::cout << "handleRequest - device Info: " << *devInfo_ << std::endl;

        if (devInfo_ !=0 )
        {
            std::cout << "**************************" << std::endl;
            ostream& out = response.out();
            out << *devInfo_ << endl;
            
            // Check later memmory release maybe put device manager in this class
            Device *device = new Device();
            if (device->jsonParser(*devInfo_))
            {
                emitDeviceEventSig(*device, DeviceEvent(DeviceEvent::Type::attach));
            }

		}
    }
    catch (std::exception& e)
    {
            cout << "ERROR: " << e.what() << endl;
            throw;
    }
}