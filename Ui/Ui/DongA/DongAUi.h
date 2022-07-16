#ifndef DONGA_UI_H
#define DONGA_UI_H

#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WContainerWidget>
#include <Wt/WWidget>
#include <Wt/WImage>
#include <Wt/WText>

#include <Table.h>
#include <TableLayout.h>

#include <Ui.h>


class DongAUi : public Ui
{
public:
	DongAUi(WVBoxLayout *parent);

	virtual void createUi();
	virtual void renderHeader();
	virtual void renderContent();
	virtual void renderFooter();

private:
	WVBoxLayout *mainLayout_;
};

#endif	//	DONGA_UI_H