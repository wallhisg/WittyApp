#ifndef SERVER_H
#define SERVER_H

#include <boost/noncopyable.hpp>

#include <Wt/WSignal>
#include <Wt/WString>

#include <set>
#include <map>
#include <boost/thread.hpp>

#include <ClientEvent.h>
#include <Device.h>
#include <DeviceWResource.h>

namespace Wt {
	class WServer;
}


class WebServer : boost::noncopyable
{
public:
	/*
	* A reference to a client.
	*/
	class Client
	{
	};

	WebServer(Wt::WServer& server);

	bool connect(Client *client, const ClientEventCallback& handleEvent);

	bool disconnect(Client *client);

	bool login(const Wt::WString& user);

	void logout(const Wt::WString& user);

	typedef std::set<Wt::WString> UserSet;
	UserSet users();

private:
	// Server
	Wt::WServer& server_;

	// Client
	struct ClientInfo {
		std::string sessionId;
		ClientEventCallback eventCallback;
	};

	typedef std::map<Client *, ClientInfo> ClientMap;

	boost::recursive_mutex mutex_;
	ClientMap clients_;

	UserSet users_;

	void postClientEvent(const ClientEvent& event);
	void postDeviceEvent(const DeviceEvent& event);

	friend class DeviceServer;
};

#endif // SERVER_H
