#ifndef TABLE_H
#define TABLE_H

#include <Wt/WContainerWidget>
#include <Wt/WVBoxLayout>
#include <Wt/WTable>
#include <Wt/WWidget>

using namespace std;
using namespace Wt;

class Table
{
public:
	Table()
		: currRow_(0), currCol_(0)
	{
		table_ = new WTable();

		offsetRowTop_ = 0;
		offsetRowBotton_ = 0;
		offsetColLeft_ = 0;
		offsetColRight_ = 0;
	}

	~Table()
	{
		delete table_;
	}

	void setRow(const int row) { currRow_ = row; }
	void setColumn(const int col) { currCol_ = col; }

	int getRow() const { return currRow_; }
	int getCol() const { return currCol_; }

	void addTrWidget(WWidget *widget);
	void addTrWidget(const int col, WWidget *widget);
	void addWidget(const int row, const int col, 
					WWidget *widget);

	void addWidget(WWidget *widget);

	void setLength(const int col, const int percentage);
	void setLength(const int  percentage);

	void setAlignment(const int row, const int col, 
						Wt::AlignmentFlag alignment);
	void setAlignment(Wt::AlignmentFlag alignment);

	void setPadding(const int row, const int col,
					const int pad);
	void setPadding(const int pad);
	void setMargin(const int row, const int col,
					const int margin);

protected:
	WTable *table_;
	int offsetColLeft_;
	int offsetColRight_;
	int offsetRowTop_;
	int offsetRowBotton_;

private:
	int currRow_;
	int currCol_;
};

#endif	//	TABLE_H