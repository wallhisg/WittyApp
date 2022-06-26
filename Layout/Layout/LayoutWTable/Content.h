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
	ContentLayout()
		:	currRow_(0),
			currCol_(0)
	{}

	void setRow(const unsigned short row) { currRow_ = row; }
	void setColumn(const unsigned short col) { currCol_ = col; }

	unsigned short getRow() const { return currRow_; }
	unsigned short getCol() const { return currCol_; }

	void addWidget(const unsigned short row, const unsigned short col, 
					WWidget *widget);

	void setLength(const unsigned short col, const unsigned char  per);

	void setAlignment(const unsigned short row, const unsigned short col, 
						Wt::AlignmentFlag alignment);
	void setPadding(const unsigned short row, const unsigned short col,
					const unsigned short pad);

private:
	unsigned short currRow_;
	unsigned short currCol_;

};

#endif	//	CONTENT_H