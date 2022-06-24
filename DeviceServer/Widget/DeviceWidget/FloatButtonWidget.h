#ifndef FLOATBUTTONWIDGET_H
#define FLOATBUTTONWIDGET_H

#include <Wt/WContainerWidget>
#include <Wt/WPaintedWidget>
#include <Wt/WPainterPath>
#include <Wt/WPainter>

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
  }
};

class FloatButton : public WContainerWidget
{
public:
    FloatButton() : jsDoubleClicked_(this, "doubleclicked")
    {
        setMargin(0, Top);
        addWidget(new PaintButton(this));
        setStyleClass("button-main");
//        this->clicked().connect(this, &FloatButton::doubleClickedAction);
        this->doJavaScript("$('#" + this->id() + "').dblclick("
                                                 "function()"
                                                 "{"
                                                 + jsDoubleClicked_.createCall() +
                                                 "});");
    }
/*
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
*/
    JSlot doubleClickSlot;
    JSignal<void>& jsDoubleClicked() { return jsDoubleClicked_; }

private:
    JSignal<void> jsDoubleClicked_;
};

#endif // FLOATBUTTONWIDGET_H

