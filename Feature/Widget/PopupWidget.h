#ifndef CLIENT
#define CLIENT

#include <Wt/WApplication>
#include <Wt/WText>
#include <Wt/WMessageBox>
#include <Wt/WServer>
#include <Wt/WPushButton>
#include <boost/thread.hpp>

#include <Server.h>

using namespace Wt;
using namespace std;

/*
 * A widget which displays the server data, keeping itself up-to-date
 * using server push.
 */
class PopupWidget : public  Wt::WContainerWidget,
         public Server::Client
{
public:

    PopupWidget(Server& server, const string* parameter, Wt::WContainerWidget *parent = 0);

    Server& server() { return server_; }

    ~PopupWidget() {
        server_.disconnect(this);
        Wt::WApplication::instance()->enableUpdates(false);
    }

    void updateData();
    void ToggleState();

private:
    Server& server_;
    Wt::WText* textCount_;
    Wt::WText* txtUser_;
    Wt::WString wsState_;
    string state_;
    string temp = "ON";
    WPushButton* btnState_;
    const string* param_;



};
#endif // CLIENT

