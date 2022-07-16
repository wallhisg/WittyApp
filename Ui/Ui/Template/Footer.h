#ifndef FOOTER_H
#define FOOTER_H

#include <Wt/WText>
#include <TableLayout.h>

using namespace std;
using namespace Wt;

class Footer : public TableLayout
{
public:
	Footer();
	~Footer()
	{
		delete email_;
		delete phone_;
		delete address_;
	}
	
	void renderFooter();

private:
	WText *address_;
	WText *phone_;
	WText *email_;
};




#endif	//	FOOTER_H