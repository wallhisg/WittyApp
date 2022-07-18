#ifndef LAYOUT_H
#define LAYOUT_H

#include <TableLayout.h>

class Layout : public TableLayout
{
public:
	Layout();
	virtual ~Layout()
	{
		
	}

	virtual void render() = 0;

private:

};


#endif	//	LAYOUT_H