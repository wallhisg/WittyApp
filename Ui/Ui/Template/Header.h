#ifndef HEADER_H
#define HEADER_H

#include <Wt/WImage>
#include <Wt/WText>
#include <TableLayout.h>

using namespace std;
using namespace Wt;

class Header : public TableLayout
{
public:
	Header();
	~Header()
	{
		delete icon_;
		delete banner_;
	}
	
	void renderHeader();
	
private:
	WImage *icon_;
	WText *banner_; 
};

#endif	//	HEADER_H