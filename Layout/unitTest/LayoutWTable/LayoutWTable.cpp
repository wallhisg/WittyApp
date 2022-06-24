/*
+---------------------WVBoxLayout-------------------------+
| +---------------------WTable--------------------------+ |
| |                                                     | |
| | +------+----------WHBoxLayout-(my 'header')-------+ | |
| | |WImage|WText                                     | | |
| | +------+------------------------------------------+ | |
| |                                                     | |
| +-----------------------------------------------------+ |
| |                                                     | |
| |WText (this cell gets toggled between hidden/visible | |
| |                                                     | |
| +-----------------------------------------------------+ |
+---------------------------------------------------------+
|                                                         |
|WText                                                    |
|                                                         |
+---------------------------------------------------------+
*/
//============================================================================
// Test case for trying to figure out how to keep 'header' stretched.
//============================================================================

#include <Wt/WApplication>
#include <Wt/WText>
#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WContainerWidget>
#include <Wt/WTable>
#include <Wt/WImage>

// Leave the following #define enabled to use a WHBoxLayout, otherwise
// comment it out to use WTable. Either way it does not act as desired. What
// I want is for my clickable 'header' to always fill the available
// horizontal space regardless if the content cell  below it is hidden or
// visible.
#define TRY_WHBOXLAYOUT	1

class MyApplication : public Wt::WApplication
{
    public:
        MyApplication(const Wt::WEnvironment& env);
private slots:
        void headerClicked();
    private:
        void createUi();
        Wt::WVBoxLayout *mainLayout;
        Wt::WContainerWidget *mainContainer;
        Wt::WTable* upperContentTable;
#ifdef TRY_WHBOXLAYOUT
        Wt::WContainerWidget* header;
        Wt::WHBoxLayout* headerLayout;
#else
        Wt::WTable* header;
#endif
        Wt::WImage* headerIcon;
        Wt::WText* headerText;
};

MyApplication::MyApplication(const Wt::WEnvironment& env) : Wt::WApplication(env)
{
    createUi();
}

// toggle the content area between hidden & visible when the header is clicked
void MyApplication::headerClicked()
{
    if (upperContentTable->elementAt(1, 0)->isVisible())
    {
        upperContentTable->elementAt(1, 0)->hide();
    }
    else
    {
        upperContentTable->elementAt(1, 0)->show();
    }
}

// This enum is just for improved readability.
enum { DONT_STRETCH = 0, DO_STRETCH = 1 };

void MyApplication::createUi()
{
    mainContainer = new Wt::WContainerWidget(root());
    root()->addWidget(mainContainer);
    mainLayout = new Wt::WVBoxLayout();
    mainContainer->setLayout(mainLayout);

#ifdef TRY_WHBOXLAYOUT
    header = new Wt::WContainerWidget();
    headerLayout = new Wt::WHBoxLayout();
    header->setLayout(headerLayout);
#else
    header = new Wt::WTable();
#endif

    headerIcon = new Wt::WImage("myicon.png");
    headerText = new Wt::WText(Wt::WString("This is the header text"));

#ifdef TRY_WHBOXLAYOUT
    headerLayout->addWidget(headerIcon, DONT_STRETCH);
    headerLayout->addWidget(headerText, DO_STRETCH); // ineffective?
#else
    header->elementAt(0, 0)->addWidget(headerIcon);
    header->elementAt(0, 1)->addWidget(headerText);

    // setting width to 100% doesn't help
    header->elementAt(0, 1)->resize(Wt::WLength(100, Wt::WLength::Percentage),
        Wt::WLength());
#endif

    upperContentTable = new Wt::WTable();
    upperContentTable->elementAt(0, 0)->addWidget(header);
    upperContentTable->elementAt(1, 0)->addWidget(
        new Wt::WText(Wt::WString(
        "Upper Pane Content Upper Pane Content Upper Pane Content Upper Pane "
        "Content Upper Pane Content Upper Pane Content Upper Pane Content "
        "Upper Pane Content Upper Pane Content Upper Pane Content Upper Pane "
        "Content Upper Pane Content Upper Pane Content Upper Pane Content "
        "Upper Pane Content Upper Pane Content Upper Pane Content Upper Pane "
        "Content Upper Pane Content Upper Pane Content Upper Pane Content "
        "Upper Pane Content Upper Pane Content Upper Pane Content Upper Pane "
        "Content Upper Pane Content Upper Pane Content Upper Pane Content "
        "Upper Pane Content Upper Pane Content Upper Pane Content Upper Pane "
        "Content Upper Pane Content Upper Pane Content Upper Pane Content "
        "Upper Pane Content")));
    upperContentTable->elementAt(0, 0)->setStyleClass(
        Wt::WString("my-header"));
    upperContentTable->setWidth(Wt::WLength(100, Wt::WLength::Percentage)); // <=== fixes problem

    upperContentTable->elementAt(0, 0)->clicked().connect(this,
        &MyApplication::headerClicked);

    mainLayout->addWidget(upperContentTable, DONT_STRETCH);
    mainLayout->addWidget(new Wt::WText(Wt::WString(
        "Lower Pane Content Lower Pane Content Lower Pane Content Lower Pane "
        "Content Lower Pane Content Lower Pane Content Lower Pane Content "
        "Lower Pane Content Lower Pane Content Lower Pane Content Lower Pane "
        "Content Lower Pane Content ")), DO_STRETCH);
    mainLayout->setResizable(0, true);

    styleSheet().addRule(".my-header", "background: #CDD6E9; cursor:pointer;");
}

Wt::WApplication *createApplication(const Wt::WEnvironment& env)
{
    return new MyApplication(env);
}

int main(int argc, char **argv)
{
    return Wt::WRun(argc, argv, &createApplication);
}