#ifndef FLOATBUTTONWIDGET_H
#define FLOATBUTTONWIDGET_H

#include <Wt/WContainerWidget>
#include <Wt/WPaintedWidget>
#include <Wt/WPainterPath>
#include <Wt/WPainter>
#include <Wt/WText>

using namespace Wt;
using namespace std;

class SizeAwareContainerWidget : public Wt::WContainerWidget
{
public:
    SizeAwareContainerWidget (Wt::WContainerWidget *parent=0) : Wt::WContainerWidget (parent)
    {
        setLayoutSizeAware( true );

    }

    virtual void layoutSizeChanged( int w, int h )
    {
        std::cout << "*** The SizeAwareContainerWidget size changed to: " << w << ", " << h << "\n";
    }
};

class PaintButton : public Wt::WPaintedWidget
{
public:

    PaintButton(Wt::WContainerWidget* parent)
    : WPaintedWidget(parent)
    {
        resize(70, 70);
        setMargin(0, Bottom);
    }

  void paintEvent(WPaintDevice *paintDevice)
  {
    WPainter painter(paintDevice);
    painter.setRenderHint(WPainter::Antialiasing);
    painter.setBrush(WBrush(Wt::red));
    painter.setPen(Wt::red);
    painter.drawEllipse(WRectF(5, 5, 60, 60));
    painter.drawText(0, 0, 60, 60, Wt::AlignCenter | Wt::AlignTop,
                         "Clear");
  }
};

class FloatButton : public WContainerWidget
{
public:
    FloatButton() : jsDoubleClicked_(this, "doubleclicked")
    {
        this->setMargin(0, Top);
        this->addWidget(new PaintButton(this));
        this->setStyleClass("button-main");
        this->clicked().connect(this, &FloatButton::doubleClickedAction);
        this->doJavaScript("$('#" + this->id() + "').dblclick("
                                                 "function()"
                                                 "{"
                                                 + jsDoubleClicked_.createCall() +
                                                 "});");

        cout << "******************" << endl;
        cout << "FloatButton id" << this->id() << endl;
    }

    void clickedAction()
    {
        cout << "******************" << endl;
        cout << "Main Single Click" << endl;
    }

    void doubleClickedAction()
    {
        cout << "******************" << endl;
        cout << "Main Double Click" << endl;
    }

    JSlot doubleClickSlot;
    JSignal<void>& jsDoubleClicked() { return jsDoubleClicked_; }

private:
    JSignal<void> jsDoubleClicked_;
};

#endif // FLOATBUTTONWIDGET_H

