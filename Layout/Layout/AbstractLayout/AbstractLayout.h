#ifndef ABSTRACT_LAYOUT_H
#define ABSTRACT_LAYOUT_H

#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WAnimation>

using namespace std;
using namespace Wt;


class Layout
{
public:
	Layout();
	~Layout();

	void addBlankLayoutLeft();
	void setBlankLayoutLeftWidth(int length)
	void addBlankLayoutRight();

	
private:
	WVBoxLayout  *vLayout_;
	WVBoxLayout  *blankLeft_;
	WVBoxLayout  *blankRight_;
}









#endif	//	ABSTRACT_LAYOUT_H