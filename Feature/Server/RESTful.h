#ifndef RESTFUL
#define RESTFUL

#include <Wt/WResource>
#include <Wt/WSignal>
#include <Wt/Http/Request>
#include <Wt/Http/Response>

#include <boost/thread.hpp>
#include <fstream>
#include <streambuf>
#include <iostream>

using namespace Wt;
using namespace std;

class Restful : public Wt::WResource
{
public:
    Wt::Signal<std::string>& httpSig() {return httpSig_;} // accessor
    void emithttpSig(std::string i)
    {
        httpSig_.emit(i);
    }
    virtual ~Restful()
    {
        beingDeleted();
    }
private:
    Wt::Signal<std::string> httpSig_;
    std::string param_;

protected:
    void handleRequest(const Http::Request &request, Http::Response &response)
    {
        try
        {
            const std::string* param;
            param = request.getParameter("param");
            if (param !=0 )
            {
                std::cout << "***********************" << std::endl;
                std::cout << "PARAM: " << *param << endl;
                ostream& out = response.out();
                out << *param << endl;
                param_ = *param;
                emithttpSig(param_);
            }
        }
        catch (std::exception& e)
        {
                cout << "ERROR: " << e.what() << endl;
                throw;
        }
    }
};

#endif // RESTFUL

