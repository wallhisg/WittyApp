#include <HelloApplication.h>


HelloApplication::HelloApplication(const WEnvironment& env)
    : WApplication(env)

{
    ServerWidget *server = new ServerWidget(root());


}

