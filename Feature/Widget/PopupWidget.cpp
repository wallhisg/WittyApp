
#include "PopupWidget.h"

PopupWidget::PopupWidget(Server& server, const string* parameter, Wt::WContainerWidget *parent)
    : Wt::WContainerWidget(parent),
      server_(server),
      param_(parameter)
{
    Wt::WApplication *app = Wt::WApplication::instance();

    textCount_ = new Wt::WText;
    txtUser_ = new WText;
    btnState_ = new WPushButton;

    addWidget(textCount_);
    addWidget(new WBreak());
    addWidget(txtUser_);
    addWidget(new WBreak());
    addWidget(btnState_);
    btnState_->setText("Button State");

    server_.connect(this, app->bind(boost::bind(&PopupWidget::updateData, this)));
    btnState_->clicked().connect(this, &PopupWidget::ToggleState);

    updateData();

    app->enableUpdates(true);
}

void PopupWidget::updateData()
{
    textCount_->setText(Wt::WString("count: {1}").arg(server_.getCount()));
    txtUser_->setText(Wt::WString("users: {1}").arg(server_.getUserCount()));
    btnState_->setText(server_.getButtonState());
    cout << "*********************" << endl;
    cout << "Update UI: " << server_.updateUI() << endl;

    Wt::WApplication::instance()->triggerUpdate();
}

void PopupWidget::ToggleState()
{
    if (server_.getButtonState() == "OFF")
    {
        temp = "ON";
        server_.setButtonState(temp);
        btnState_->setText("ON");
    }
    else
    {
        btnState_->setText("OFF");
        temp = "OFF";
        server_.setButtonState(temp);
    }
}
