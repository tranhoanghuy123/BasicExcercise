#include<iostream>
using namespace std;
//COMMENT 1 ĐOẠN CODE: BÔI ĐEN ĐOẠN CODE --> ẤN CTRL + K + C
//UNCOMMENT 1 ĐOẠN CODE: BÔI ĐEN ĐOẠN CODE --> ẤN CTRL + K + U
int sum(int n)
{
	//s(n)=1+2+3+4+...+n
	if (n == 0)
		return 0;
	return n + sum(n-1);

}
int count_digit(int n)
{
	if (n == 0)
		return 0;
	return 1+count_digit(n/10);
}
int sum_digit(int n)
{
	if (n == 0)
		return 0;
	return (n % 10) + sum_digit(n / 10);
}
int sum_digit_odd(int n)
{
	if (n == 0)
		return 0;
	if ((n % 10) % 2 == 1)
		return 1 + sum_digit_odd(n / 10);
	return sum_digit_odd(n / 10);
}
long int factorial(int n)
{
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}
double sum1(int n)//hàm tính tổng s= 1/1+1/2+...+1/n viết kiểu đệ quy
{
	do
	{
		//cout << "Nhap n= "; cin >> n;
		if (n == 0)
		{
			cout << "Loi roi Moi nhap lai!\n";
		}
		else
		{
			if (n == 1)
				return 1;
			return 1.0 / n + sum1(n - 1);
		}
	} while (n == 0);
}
int sum_digit_even(int n)
{
	//int sum = 0;
	if (n == 2)
		return 2;
	if(n%2==0)
		return n + sum_digit_even(n - 2);
	return  sum_digit_even(n - 1);
	
	/*for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			sum += i;
		}
	}
	return sum;*/
}
double sum2(int n)
{
	if (n == 1)
		return 1;
	if(n%2!=0)
		return 1.0/n + sum2(n - 2);
	return 1.0* sum2(n - 1);
}
long sum_factorial(int n)
{
	if (n == 1)
		return 1;
	return factorial(n)+sum_factorial(n-1);
}
int main()
{
	cout << sum_factorial(5);
	//cout << sum2(14);
	//cout << sum_digit_even(20)<<endl;
	//cout << sum1(10);
	//cout << factorial(10);
	cout<<endl;
	return 0;
}