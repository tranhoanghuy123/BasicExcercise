#include<cstring>
#include<iostream>
using namespace std;
#pragma once
class Customer
{
public:
	string nameOfCustomer;
	string idOfCustomer;
	Customer();
	~Customer();
	Customer get(string nameOfCustomer, string idOfCustomer);	
};

