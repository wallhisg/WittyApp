#include <HelloApplication.h>
#include <ServerWidget.h>


HelloApplication::HelloApplication(const WEnvironment& env)
    : WApplication(env)

{
    addMetaHeader("viewport", "width=device-width, initial-scale=1, maximum-scale=1");
    
    ServerWidget *server = new ServerWidget(root());
    server->setStyleClass("DeviceWidget");
    
    struct device device_;

    
}

