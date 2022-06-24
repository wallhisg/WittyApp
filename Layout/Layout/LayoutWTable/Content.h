#ifndef CONTENT_H
#define CONTENT_H

#include <Wt/WVBoxLayout>
#include <Wt/WTable>
#include <Wt/WWidget>

using namespace std;
using namespace Wt;

class ContentLayout  : public WTable
{
public:
	// Content 00
	void addContentWidget_At00(WWidget *widget);
	void setContentLenghtPercentage_At00(const unsigned char &per);
	void setContentAlignment_At00(Wt::AlignmentFlag alignment);
	void setContentPadding_At00(const unsigned short &pad);
	// Content 01
	void addContentWidget_At01(WWidget *widget);
	void setContentLenghtPercentage_At01(const unsigned char &per);
	void setContentAlignment_At01(Wt::AlignmentFlag alignment);
	void setContentPadding_At01(const unsigned short &pad);
private:


};

#endif	//	CONTENT_H