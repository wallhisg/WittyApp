#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <Wt/WObject>
#include <Wt/WContainerWidget>
#include <Wt/WPanel>
#include <Wt/WStandardItemModel>
#include <Wt/WStandardItem>
#include <Wt/WTreeView>
#include <Wt/WText>
#include <Wt/WLink>
#include <Wt/WString>
#include <string>
#include <vector>

using namespace Wt;
using namespace std;

/**
	TODO:
	- Remember finish ~Treeview()
 */

class TreeView : public WContainerWidget
{
public:
	TreeView(WStandardItemModel *model, const WString& titleText);
	~TreeView()
	{

	}

	static WStandardItemModel *createModel(WObject *parent);

private:
	WStandardItem *device_;
	WStandardItemModel *model_;
	WTreeView *treeView_;

	static WStandardItem *deviceItem(const string &devId);
  	static std::vector<Wt::WStandardItem *> devInfo(const std::string& name,
						    						const std::string& ip);
};

#endif	//	TREEVIEW_H