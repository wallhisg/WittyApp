#include "Devices.h"

Devices::Devices()
{
    update_ = false;
}

bool Devices::connect(DeviceDescriptor *device, const DeviceEventCallback &handleEvent)
{
    if (devices_.count(device) == 0)
    {
        cout << "Add device into Map" << endl;
        return true;
    }
    return false;
}

bool Devices::JsonProcess(const string &input)
{
    /*
    cout << "String input" << input << endl;
    JsonChecker = Wt::Json::parse(input, result, e);
    if (!JsonChecker)
    {
        cout << "Can not paser this device" << endl;
        return false;
    }
    else
    {
        try
        {
            string paserInput = input;
            Wt::Json::parse(paserInput, result);

            Wt::WString x = result.get("WS1");
            cout << "Switch 1" << x << endl;
        }
        catch (boost::system::system_error &e)
        {
            cout << "ERROR: " << e.what() << endl;
            cout << "Error when paser this device" << endl;
            return false;
        }
    }
    */
    cout << "String input: " << input << endl;
    ok = Wt::Json::parse(input, result, e);
    if (!ok)
    {
        std::cout << "Can not paser json" << endl;
        return false;
    }
    else
    {
        try
        {
            string paserinput = input;
            Wt::Json::parse(paserinput, result);

            std::cout << result.size() << std::endl;

            Wt::WString deviceName = result.get("DeviceName");
            std::cout << "Device name: "<< deviceName << std::endl;

            Wt::WString stateSW = result.get("Switch 1");
            std::cout << "Cong tac Switch 1: "<< stateSW << std::endl;

            update_ = true;
            return true;

        }
        catch (Wt::WException &exp)
        {
            std::cout << "exception:" << exp.what() << std::endl;

            return false;
        }
    }
}

void Devices::postDeviceEvent(const DeviceEvent &devEvent)
{

}


Devices::~Devices()
{

}



