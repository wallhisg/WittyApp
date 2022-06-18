#include <HelloApplication.h>

using namespace Wt;

WApplication *createApplication(const WEnvironment& env)
{
  return new HelloApplication(env);
}

int main(int argc, char **argv)
{
  return WRun(argc, argv, &createApplication);
}