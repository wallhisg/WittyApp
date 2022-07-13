#ifndef WTABLE_LAYOUT
#define WTABLE_LAYOUT

#include <Wt/WVBoxLayout>
#include <Wt/WTable>
#include <Wt/WWidget>

using namespace std;
using namespace Wt;

class TableLayout
{
public:
	TableLayout()
		:	currRow_(0),
			currCol_(0)
	{
		table_ = new WTable();
	}

	~TableLayout()
	{
		delete table_;
	}

	void setRow(const unsigned short row) { currRow_ = row; }
	void setColumn(const unsigned short col) { currCol_ = col; }

	unsigned short getRow() const { return currRow_; }
	unsigned short getCol() const { return currCol_; }

	void addTrWidget(WWidget *widget);
	void addTrWidget(const unsigned short col, WWidget *widget);
	void addWidget(const unsigned short row, const unsigned short col, 
					WWidget *widget);

	void addWidget(WWidget *widget);

	void setLength(const unsigned short col, const unsigned char  per);
	void setLength(const unsigned char  per);

	void setAlignment(const unsigned short row, const unsigned short col, 
						Wt::AlignmentFlag alignment);
	void setAlignment(Wt::AlignmentFlag alignment);

	void setPadding(const unsigned short row, const unsigned short col,
					const unsigned short pad);
	void setPadding(const unsigned short pad);
	void setMargin(const unsigned short row, const unsigned short col,
					const unsigned short margin);

	void setStyleClass(const WString &style);

	WTable *table() { return table_; }

private:
	unsigned short currRow_;
	unsigned short currCol_;
	
	WTable *table_;
};

#endif	//	WTABLE_LAYOUT