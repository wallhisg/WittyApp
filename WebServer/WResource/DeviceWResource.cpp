#include "DeviceWResource.h"

// static void printDeviceInfo(struct device device);

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

        devInfo_ = request.getParameter("devInfo");

        if (devInfo_ !=0 )
        {
            ostream& out = response.out();
            out << *devInfo_ << endl;
            
            if (jsonParserDevice(*devInfo_))
            {
                emitDeviceConEventSig(DeviceEvent(DeviceEvent::Type::Connect, this->device_));
            }

		}
    }
    catch (std::exception& e)
    {
            cout << "ERROR: " << e.what() << endl;
            throw;
    }
}

bool DeviceWResource::jsonParserDevice(const string devInfo)
{
    Wt::Json::Object result;
    Wt::Json::ParseError e;
    bool res = false;
    
    res = Json::parse(devInfo, result, e);
    if (!res)
        return false;
    else
    {
        try
        {
            Json::parse(devInfo, result);

            device_.id = result.get("id");
            device_.ip = result.get("ip");
            device_.name = result.get("name");
            device_.value = result.get("value");

            // printDeviceInfo(device_);

            return true;
        }
        catch (Wt::WException &exp)
        {
            std::cout << "exception:" << exp.what() << std::endl;
            return false;
        }
    }
}

// void printDeviceInfo(struct device device)
// {
//     std::cout << "**************************" << std::endl;
//     std::cout << "id: " << device.id << std::endl;
//     std::cout << "ip: " << device.ip << std::endl;
//     std::cout << "na: " << device.name << std::endl;
//     std::cout << "id: " << device.value << std::endl;
//     std::cout << "**************************" << std::endl;
// }