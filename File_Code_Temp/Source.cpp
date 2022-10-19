#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "Methods.h"
int a[200];
using namespace std;
void tao200So(int a[])
{
	for (int i = 0; i < 200; i++)
	{
		a[i] = rand();
	}
}
void inSoChiaHetCho7(int a[])
{
	for (int i = 0; i < 200; i++)
	{
		if (a[i] % 7 == 0)
		{
			cout << a[i] << " ";
		}

	}
	cout << endl;
}
char* delAllEvenDigit(char*& str)
{
	auto lenght = strlen(str);
	for (int i = 0; i < lenght; i++)
	{
		/*if (str[i] == '0' || str[i] == '2' || str[i] == '4' || str[i] == '6' || str[i] == '8')
		{
			strcpy(str + i, str + i + 1);
			i--;
		}*/
		if (str[i] >= '0' && str[i] <= '9' && ((int)str[i] % 2 == 0))
		{
			strcpy(str + i, str + i + 1);
			i--;
		}
	}
	return str;
}
/*
*  Cho dữ liệu đầu vào là 1 số nguyên dương. Thực hiện yêu cầu sau:
*
*		Hiển thị số đó ra màn hình dưới dạng chữ.
*		Ví dụ đầu vào là số nguyên dương: 123456 ---> Mot Hai Ba Bon Nam Sau
*/
string nameOfNum[10] =
{
	"Khong",
	"Mot",
	"Hai",
	"Ba",
	"Bon",
	"Nam",
	"Sau",
	"Bay",
	"Tam",
	"Chin",
};
void inChu(int n)
{
	string s = to_string(n); // chuyển số n sang dạng chuỗi
	const char* str = s.c_str(); // convert chuỗi s có kiểu string sang xâu str có kiểu char*. Lưu ý  phải có const
	for (int i = 0; i < strlen(str); i++) // duyệt các phần tử trong xâu str
	{
		cout << nameOfNum[(int)str[i] - 48] << " "; // chuyển kiểu từ char -> int. Lưu ý phải -48 bởi vì số 5 trong ASCII là 53 -> 53-48 = 5
	}
}
int main()
{
	/*char* str = new char[40];
	strcpy(str, "12sdasd241asda4 12 asd13 23ad");
	cout << delAllEvenDigit(str);
	cout << endl;
	delete[]str;*/
	/*int n = 30;
	double phi = (1 + sqrt(5))/2.0;
	cout << round(pow(phi, n)/sqrt(5)) << endl;
	cout << fibo(29) << endl;*/
	//inChu(5671212412);
	int a[4][4] = 
	{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,13,411},
		{12,23,37,412},
	};
	bool flag;
	int max = -1;
	for (int i = 0; i < 4; i++)
	{
		flag = false;
		if (check_prime(a[i][4 - i + 1]))
		{
			flag = true;
		}
		if (flag && max < a[i][4 - i + 1])
		{
			max = a[i][4 - i + 1];
		}
	}
	cout << max << endl;
	return 0;
}