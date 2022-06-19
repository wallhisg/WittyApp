#ifndef SERVER_H
#define SERVER_H

#include <Wt/WServer>
#include <boost/noncopyable.hpp>
#include <boost/thread.hpp>

#include <set>
#include <map>
#include <boost/lexical_cast.hpp>

#include <RESTful.h>
#include <Devices.h>

namespace Wt {
  class WServer;
}

using namespace Wt;
using namespace std;

typedef boost::function<void()> ClientEventCallback;

class Server : boost::noncopyable
{
public:

    class Client
    {};

    Server(Wt::WServer& server);
    ~Server();
    // WebServer Side
    void connect(Client *client, const ClientEventCallback &handleEvent);
    void disconnect(Client *client);
    int getCount() const;
    int getUserCount() const;

    void setButtonState(const string& state) { btnState_ = state; }
    string getButtonState() const { return btnState_; }
    bool updateUI() const { return devices_->getupdate(); }

    // Device Side
    void DeviceConnect();
    void postDeviceHandle(std::string parameter)
    {
        std::cout << "***********************" << std::endl;
        std::cout << "Print parameter: " << parameter << std::endl;
        devices_->JsonProcess(parameter);
    }

private:
    Wt::WServer& server_;
    Restful* httpServer_;
    bool updatdeIterm_;
    bool stop_;
    int counter_ = 0;
    int users_ = 0;
    string btnState_;
    mutable boost::mutex mutex_;
    boost::thread thread_;
    boost::thread threadClk_;

    //TimerWidget* timerWidget;


    struct ClientInfo {
        std::string sessionId;
        ClientEventCallback eventCallback;
    };
    typedef std::map<Client *, ClientInfo> ClientMap;
    ClientMap clients_;

    void run();
    Devices* devices_;
};

#endif // SERVER_H
