#include "electricBill.h"
#include<iostream>
#include<iomanip>
using namespace std;
electricBill::electricBill()
{
	
}
electricBill::~electricBill()
{

}
electricBill electricBill::getBill(string idOfBill, unsigned int quota, unsigned int price, unsigned short int amoutOfElectric)
{
	this->idOfBill = idOfBill;
	this->quota = quota;
	this->totalMoney = totalMoney;
	this->price = price;
	this->amoutOfElectric = amoutOfElectric;
	return electricBill();
}
void electricBill::printBill()
{
	cout <<setw(20)<<right<<"*"<< "***********************************************************\n";
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(40) << "HOA DON TIEN DIEN" <<setw(19)<<right<<"*" <<endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" <<setw(3)<<""<< "Ten Khach Hang: " <<this->nameOfCustomer<<setw(13)<<right<<"Ma KH: "<<this ->idOfCustomer<<setw(5)<<right<<"*"<< endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << setw(59) << right << "*" << endl;
	cout << setw(20) << right << "*" << "***********************************************************\n";

}
