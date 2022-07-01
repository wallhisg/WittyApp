#include "TreeView.h"


TreeView::TreeView(WStandardItemModel *model, const WString& titleText)
	: model_(model)
{
	device_ = model_->item(0, 0)->child(0, 0);

	// WPanel *panel = new WPanel(this);
	// panel->setCentralWidget(treeView_ = new WTreeView());
	WTreeView *treeView_ = new WTreeView(this);
	treeView_->setAlternatingRowColors(true);

	treeView_->setModel(model_);

	treeView_->setColumnAlignment(0, AlignLeft);
	treeView_->setColumnAlignment(1, AlignCenter);

	/*
	* Expand the first (and single) top level node
	*/
	treeView_->setExpanded(model->index(0, 0), true);
	treeView_->setExpanded(model->index(0, 0, model->index(0, 0)), true);
}

WStandardItemModel *TreeView::createModel(WObject *parent)
{
	/*
	* Setup a model.
	*
	*/
	WStandardItemModel *result = new WStandardItemModel(0, 2, parent);

	/*
	* Headers ...
	*/
	result->setHeaderData(0, Horizontal, std::string("Device"));
	result->setHeaderData(1, Horizontal, std::string("Value"));

	/*
	* ... and data
	*/
	WStandardItem *devItem;

	result->appendRow(devItem = deviceItem("ID"));
	devItem->appendRow(devInfo("Name", "BTN"));
	devItem->appendRow(devInfo("IP", "192.168.1.1"));

	return result;
}

WStandardItem *TreeView::deviceItem(const std::string& devItem)
{
	WStandardItem *result = new WStandardItem(devItem);
	result->setColumnCount(2);
	return result;
}

std::vector<WStandardItem *>
TreeView::devInfo(const std::string& name, const std::string& ip)
{
	std::vector<WStandardItem *> result;
	WStandardItem *item;

	// column 0: name
	item = new WStandardItem(WString::fromUTF8(name));
	result.push_back(item);


	// column 2: value
	item = new WStandardItem(ip);
	result.push_back(item);

	return result;
}