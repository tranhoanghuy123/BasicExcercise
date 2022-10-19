#include "Customer.h"
#pragma once
class electricBill:public Customer
{
private: 
	unsigned int quota;
	unsigned long totalMoney;
	unsigned int price;
	unsigned short int amoutOfElectric;
	string idOfBill;
public:
	electricBill();
	~electricBill();
	electricBill getBill(string idOfBill,unsigned int quota, unsigned int price, unsigned short int amoutOfElectric);

	void printBill();

};

