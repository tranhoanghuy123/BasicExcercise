#include "Customer.h"

Customer::Customer()
{
}

Customer::~Customer()
{
}

Customer Customer::get(string nameOfCustomer, string idOfCustomer)
{
	this->nameOfCustomer = nameOfCustomer;
	this->idOfCustomer = idOfCustomer;
	return Customer();
}
