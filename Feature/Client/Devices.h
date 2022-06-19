#ifndef CLIENT_H
#define CLIENT_H

#include <Wt/Json/Object>
#include <Wt/Json/Parser>
#include <Wt/Json/Array>

#include <Wt/WSignal>
#include <boost/noncopyable.hpp>
#include <boost/system/system_error.hpp>
#include <set>
#include <map>
#include <string>

using namespace std;

class DeviceDescriptor
{
public:
    enum Type { DeviceName, DeviceType };

    Type type() const { return type_; }
    const string& devicename() const { return deviceName_; }
    const string& devicetype() const { return deviceType_; }

private:
    Type type_;
    string deviceName_;
    string deviceType_;
    string descriptor_;

    DeviceDescriptor(Type type, string& descriptor)
        : type_(type), descriptor_(descriptor)
    {
    }
    friend class Devices;
};


class DeviceEvent
{
public:
    enum Type { Device, Message, Status, Data };

    /*! \brief Get the event type.
     */
    Type type() const { return type_; }

    /*! \brief Get the device who caused the event.
     */
    const string& device() const { return device_; }

    /*! \brief Get the message of the event.
     */
    const string& message() const { return message_; }

    /*! \brief Get the extra data for this event.
     */
    const string& data() const { return data_; }

private:
    Type type_;
    string device_;
    string message_;
    string data_;
    bool status_;

    DeviceEvent(Type type, string& device, bool status)
        : type_(type), device_(device), status_(status)
    {

    }
    friend class Devices;
};

typedef boost::function<void (const DeviceEvent&)> DeviceEventCallback;


class Devices
{
public:
    /*
    class Device{
    };
    */
    Devices();
    ~Devices();

    bool connect(DeviceDescriptor *device, const DeviceEventCallback &handleEvent);

    //typedef std::set<Wt::WString> DeviceSet;
    bool JsonProcess(string const& input);
    bool getupdate() const { return update_; }
    void postDeviceEvent(const DeviceEvent& devEvent);
private:
    struct DeviceInfo{
        string deviceName;
        DeviceEventCallback eventCallback;
    };

    DeviceInfo devicesInfo_;
    //DeviceSet devices_;

    typedef std::map<DeviceDescriptor*, DeviceInfo> DeviceMap;
    DeviceMap devices_;



    // JSON paser device
    Wt::Json::Object result;
    Wt::Json::ParseError e;
    bool JsonChecker;
    bool ok;
    bool update_;
};

#endif // CLIENT_H
