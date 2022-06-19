#include "DeviceWidget.h"

DeviceWidget::DeviceWidget(Server &server, const string* parameter,  Wt::WContainerWidget *parent)
    : Wt::WContainerWidget(parent),
      param_(parameter),
      server_(server)
{
    Wt::WApplication *app = Wt::WApplication::instance();

    btnState_ = new WPushButton("Button state", this);
    if (*param_ == "1")
    {
        btnState_->setText("ON");
    }
    else
        btnState_->setText("OFF");

    server_.connect(this, app->bind(boost::bind(&DeviceWidget::updateData, this)));

    app->enableUpdates(true);

    addWidget(btnState_);
    cout << "********************" << endl;
    cout << "PARAMETER: " << *param_ << endl;

    btnState_->clicked().connect(this, &DeviceWidget::ToggleState);

}

DeviceWidget::~DeviceWidget()
{
    Wt::WApplication::instance()->enableUpdates(false);
}

void DeviceWidget::updateData()
{

    Wt::WApplication::instance()->triggerUpdate();
}

void DeviceWidget::ToggleState()
{
    if (btnState_->text() == "ON")
        btnState_->setText("OFF");
    else
        btnState_->setText("ON");
}

