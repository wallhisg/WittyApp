#include "Footer.h"

Footer::Footer()
{
	address_ = new WText(WString::tr("footer.address"));
	phone_ = new WText(WString::tr("footer.phone"));
	email_ = new WText(WString::tr("footer.email"));

	renderFooter();
}

void Footer::renderFooter()
{
	this->setStyleClass("footer-table");

	// Col 0
	this->addWidget(0, 0, NULL);
	this->setLength(0, 25);
	this->setStyleClassColumn(0, "footer-col-left");
	
	// Col 1
	this->addWidget(0, 1, address_);
	this->addWidget(1, 1, phone_);
	this->addWidget(2, 1, email_);
	this->setStyleClassColumn(1, "footer-col-middle");
	
	// Col 2
	this->addWidget(0, 0, NULL);
	this->setLength(2, 25);
	this->setStyleClassColumn(2, "footer-col-right");
}