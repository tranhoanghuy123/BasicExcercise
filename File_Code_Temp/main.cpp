#include"Methods.h"
#include "electricBill.h"
int main()
{
	electricBill bill;
	bill.getBill("00000001", 50, 10000, 900);
	bill.get("Nguyen Van A", "00000NVA01");
	bill.printBill();
	cout << endl;
	return 0;
}