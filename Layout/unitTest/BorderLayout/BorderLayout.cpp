#include <Wt/WApplication>

#include <Wt/WContainerWidget>

#include <Wt/WStackedWidget>

#include <Wt/WMenu>

#include <Wt/WBorderLayout>

#include <Wt/WText>

using namespace Wt;

class HelloApp : public Wt::WApplication

{

public:

    HelloApp(const Wt::WEnvironment& env):

        Wt::WApplication(env)

    {

      WBorderLayout *contentLayout_ = new WBorderLayout();

      root()->setLayout(contentLayout_);

      container_ = new Wt::WContainerWidget();

      tabNav_ = new Wt::WMenu(new Wt::WStackedWidget(), Wt::Horizontal);

      tabNav_->setRenderAsList(true);

      tabNav_->setStyleClass("menu");

      tabNav_->contentsStack()->setOverflow(WContainerWidget::OverflowAuto);

      Wt::WContainerWidget* menuDiv = new Wt::WContainerWidget();

      menuDiv->setStyleClass("headerNav");

      menuDiv->addWidget(tabNav_);

      // Add tab widgets

      container_->addWidget(menuDiv);

      contentLayout_->addWidget(container_, Wt::WBorderLayout::North);

      contentLayout_->addWidget(tabNav_->contentsStack(), Wt::WBorderLayout::Center);

      contentLayout_->addWidget(new WText("This is south"), Wt::WBorderLayout::South);

      tabNav_->addItem("Test1", new WText("<div>Contents 1</div>"));

      std::string contents2;

      for (unsigned i = 0; i < 100; ++i)

      contents2 += "<div>More contents 2</div>";

      tabNav_->addItem("Test2", new WText(contents2));

      styleSheet().addRule(".menu li ",

               "display: inline-block; "

               "width: 50%;");

    }

private:

    WContainerWidget *container_;

    WMenu *tabNav_;

};

Wt::WApplication *createApplication(const Wt::WEnvironment& env)

{

    return new HelloApp(env);

}

int main(int argc, char **argv)

{

    return Wt::WRun(argc, argv, &createApplication);

}
