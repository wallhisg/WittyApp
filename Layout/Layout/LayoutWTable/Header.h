#ifndef LAYOUT_WTABLE_HEADER_H
#define LAYOUT_WTABLE_HEADER_H

#include <Wt/WVBoxLayout>
#include <Wt/WTable>
#include <Wt/WWidget>

using namespace std;
using namespace Wt;

class HeaderLayout  : public WTable
{
public:
	// Header 00
	void addHeaderWidget_At00(WWidget *widget);
	void setHeaderLenghtPercentage_At00(const unsigned char &per);
	void setContentAlignment_At00(Wt::AlignmentFlag alignment);
	void setHeaderPadding_At00(const unsigned short &pad);
	// Header 01
	void addHeaderWidget_At01(WWidget *widget);
	void setHeaderLenghtPercentage_At01(const unsigned char &per);
	void setContentAlignment_At01(Wt::AlignmentFlag alignment);
	void setHeaderPadding_At01(const unsigned short &pad);
private:


};


#endif	//	LAYOUT_WTABLE_HEADER_H