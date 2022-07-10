#ifndef DEVICE_H
#define DEVICE_H

#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WContainerWidget>
#include <Wt/WWidget>
#include <Wt/WTable>
#include <Wt/WText>
#include <Wt/WPushButton>
#include <Wt/WString>

using namespace std;
using namespace Wt;

struct device {
	WString id;
	WString name;
	WString ip;
	WString value;
};

#endif	//	DEVICE_H