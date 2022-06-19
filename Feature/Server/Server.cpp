#include "Server.h"

Server::Server(WServer& server)
    : server_(server)
{
    counter_ = 0;
    stop_ = false;
    btnState_ = "ON";
    thread_ = boost::thread(boost::bind(&Server::run, this));
    httpServer_ = new Restful;
    server_.addResource(httpServer_,"/resource");
    httpServer_->httpSig().connect(SLOT(this, Server::postDeviceHandle));
    devices_ = new Devices;
    updatdeIterm_ = false;
}

Server::~Server()
{
    stop_ = true;
    thread_.join();
}

void Server::connect(Client *client, const ClientEventCallback& handleEvent)
{
    boost::mutex::scoped_lock lock(mutex_);

    if (clients_.count(client) == 0)
    {
        ClientInfo clientInfo;
        clientInfo.sessionId = WApplication::instance()->sessionId();
        clientInfo.eventCallback = handleEvent;
        clients_[client] = clientInfo;
        ++users_;
    }
}

void Server::disconnect(Client *client)
{
    --users_;
    boost::mutex::scoped_lock lock(mutex_);
    clients_.erase(client);

}

int Server::getCount() const
{
    boost::mutex::scoped_lock lock(mutex_);
    return counter_;
}

int Server::getUserCount() const
{
    boost::mutex::scoped_lock lock(mutex_);
    return users_;
}

void Server::DeviceConnect()
{

}

void Server::run()
{
  /*
   * This method simulates changes to the data that happen in a background
   * thread.
   */
    for (;;)
    {
        //boost::this_thread::sleep(boost::posix_time::seconds(1));
        boost::this_thread::sleep(boost::posix_time::milliseconds(500));

        if (stop_)
          return;

        {
          boost::mutex::scoped_lock lock(mutex_);
          ++counter_;


            WApplication *app = WApplication::instance();

            for (ClientMap::const_iterator i = clients_.begin(); i != clients_.end();
                 ++i)
            {
                if (app && app->sessionId() == i->second.sessionId)
                    i->second.eventCallback;
                else
                    server_.post(i->second.sessionId, i->second.eventCallback);
            }

        }
    }
}


