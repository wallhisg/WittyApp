#ifndef HEADER_H
#define HEADER_H

#include <Wt/WImage>
#include <Wt/WText>
#include <Layout.h>

using namespace std;
using namespace Wt;

class Header : public Layout
{
public:
	Header();


	virtual ~Header()
	{

	}
	
	virtual void render();
	
private:
};

#endif	//	HEADER_H