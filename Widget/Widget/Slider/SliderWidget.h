#ifndef SLIDERWIDGET
#define SLIDERWIDGET

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WTemplate>
#include <Wt/WJavaScript>
#include <Wt/WString>
#include <string>

using namespace Wt;
using namespace std;

class SliderWidget : public WContainerWidget
{
public:
    SliderWidget()
    {
        cout << "SliderWidget Struct: " << endl;

        template_ = new WTemplate(Wt::WString::tr("blog-login"));
        addWidget(template_);
        state = false;
        changeState();
        clicked().connect(boost::bind(&SliderWidget::changeState, this));
    }

    void changeState()
    {
        cout << "templateText: " << template_->templateText();
        if (state == true)
        {
            state = false;
            stateStr = "OFF";
            this->doJavaScript(
                                "$('.button-wrap').on(\"click\", function(){"
                                "$(this).removeClass('button-active');"
                                "});"
                                );

        }
        else
        {
            state = true;
            stateStr = "ON";
            this->doJavaScript(
                                "$('.button-wrap').on(\"click\", function(){"
                                "$(this).addClass('button-active');"
                                "});"
                                );

        }
        //this->doJavaScript("func('" + stateStr + "');");
        cout << "State: " << state << endl;

    }
    void acd()
    {
        this->doJavaScript(
                            "$('.button-wrap').on(\"click\", function(){"
                            "$(this).addClass('button-active');"
                            "});"
                            );
    }
private:
    WTemplate* template_;
    bool state;
    string stateStr = "ON";
};

#endif // SLIDERWIDGET

