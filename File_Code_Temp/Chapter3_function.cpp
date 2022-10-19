#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
//COMMENT 1 ĐOẠN CODE: BÔI ĐEN ĐOẠN CODE --> ẤN CTRL + K + C
//UNCOMMENT 1 ĐOẠN CODE: BÔI ĐEN ĐOẠN CODE --> ẤN CTRL + K + U
char hoa(char ch)
{
	//đổi ký tự chữ ra chữ hoa, các ký tự khác giữ nguyên
	if (ch >= 'a' && ch <= 'z')
	{
		ch -= 32;
	}
	return ch;
}
char thuong(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		ch += 32;
	}
	return ch;
}
int min(int a, int b)
{
	return (a <= b) * a + (b < a) * b;// (a <= b) --> trả về kiểu bool là 0 hoặc 1 --> 0*a + 1*b --> b hoặc ngược lại
}
int min4(int a, int b, int c, int d)
{
	return min(min(a, b), min(c, d));
}
int sodao(int n)
{
	int mod, res = 0;
	while (n > 0)
	{
		mod = n % 10;
		res = res * 10 + mod;
		n /= 10;
	}
	return res;
}
int nguyento(int n)
{
	//kiểm tra n có phải là số nguyên tố hay ko?  (1:ngtố,0: ko ngtố).
	int dem = 0;
	if (n < 0)
		return 0;
	if (n <= 3 && n > 0)
		return 1;
	for (int i = 1; i <= n; ++i)
		if (n % i == 0)
			++dem;
	if (dem > 2)
		return 0;
	return 1;


}
int doixung(int n)
{
	//kiểm tra n có phải là số đối xứng hay ko?
	// Số nguyên n gọi là số đối xứng nếu đọc từ trái qua phải, hay từ phải qua trái đều được số giống nhau.Ví dụ : 11, 121, 101 là các số đối xứng.
	int sum = 0, mod, temp;
	for (temp = n; n != 0; n = n / 10)
	{
		mod = n % 10;
		sum = sum * 10 + mod;
	}
	if (sum == temp)
		return 1;
	return 0;
}
int chinhphuong(int n)
{
	// kiểm tra n có chinh phương hay ko?
	// số chính phương là 1 số mà khi lấy căn bậc ra 1 số nguyên; điều kiện là số đó phải là nguyên dương
	int a = sqrt(n); // a là biến để lấy kết quả căn bậc 2 của n
	if (n < 0)
		return 0;
	if (n == a*a)
		return 1;
	return 0;

}
int hoanchinh(int n)
{
	//kiểm tra 1 số có phải là số hoàn chỉnh hay không?
	 /* +Số hoàn chỉnh là một số nguyên dương mà tổng các ước nguyên dương chính thức của nó (số nguyên dương bị nó chia hết ngoại trừ nó) bằng chính nó.
		+Nghĩa là 1 số nguyên dương khi tổng các ước của nó (trừ số đó) = chính số đó 
		+ quy ước 0: sai; 1: đúng */
	int sum = 0;
	if (n < 0)
		return 0;
	for (int i = 1; i <= n/2; i++)  // giới hạn số lần lặp của 1 vòng lặp vì khi n/i luôn luôn nhỏ hơn hoặc bằng n/2!
	{
		if (n % i == 0)
			sum += i;
	}
	if (sum == n)
		return 1;
	return 0;
}
int chieudai(int n)
{
	//trả về chiều dài của một số nguyên.
	int i=1; // i là biến đếm số n gồm bao nhiêu số !
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return i;
}
int fibo(int n)
{
	//  in ra phần tử thứ n của dãy fibonancy
	//  giả sử f(0)=f(1)=1
		/*Dãy Fibonacci là dãy vô hạn các số tự nhiên bắt đầu bằng hai phần tử 0 và 1 hoặc 1 và 1, 
		+ các phần tử sau đó được thiết lập theo quy tắc mỗi phần tử luôn bằng tổng hai phần tử trước nó
		+ Viet bang Recursion (de quy) :v */
	if (n ==0 || n==1)
		return 1;
	return fibo(n - 1) + fibo(n - 2);
}
int UCLN(int a, int b)
{
	// trả về ước chung lớn nhất của 2 số nguyên.
	// mô ta thuật toán :  khi a > b --> a = a - b --> trừ đến khi nào a = b thì dừng!
	if (a == 0 || b == 0)
		return a + b;
	while (a != b)
	{
		if (a > b)
		{
			 a = a - b;
		}
		else
			 b = b - a;
	}
	return a; // return a;
}
int BCNN(int a, int b)
{
	// trả về bội chung nhỏ nhất của 2 số nguyên.
	// mô ta thuật toán :  Bội chung nhỏ nhất của 1 số được thực hiện qua công thức BCNN(a,b)=(a*b)/UCLN(a,b)
	//if (a == 0 || b == 0)
	//	return a + b;
	//while (a != b)
	//{
	//	if (a > b)
	//	{
	//		a = a - b;
	//	}
	//	else
	//		b = b - a;
	//}
	//return b; // return a;
	return (a * b) / UCLN(a, b); // vì đã có sẳn 1 hàm tính ước chung lớn nhất ở trên, nếu không có thì uncomment ra :)) !
}
// SERIES FUNCTIONS CONVERT !!!!
int D2B(int n)
{
	// đổi số thập phân ra nhị phân
	// cần biến bit_num = 0 lưu dãy bit khi đổi
	// +  biến index = 1 lưu chỉ số
	// +  biến mod là kq của phép tính n%2.
	// DESCRIPTION: + Chia n cho 2 đến khi thương là 0, và lưu lại số dư.
	//				+ Sau khi có được tất cả các số dư ta đảo ngược số dư ( từ dưới lên) là thu được dãy bit
	// Ví dụ : số n = 12 => bit_num = 1100
	int bit_num = 0, index = 1, mod;
	while (n > 0 )
	{
		mod = n % 2;
		bit_num = bit_num + (index * mod);
		n = n / 2;
		index = index * 10;
	}
	return bit_num;
}
//3 ham duoi luoi viet qua :))
int B2D(int n)
{
	// đổi số nhị phân ra thập phân
	return 0;
}
int D2O(int n)
{
	//đổi số thập phân ra bát phân phân
	return 0;
}
int O2D(int n)
{
	//đổi số bát phân ra thập phân
	return 0;
}
//MENU TEST :))
void menu()
{
	char ch;
	int a, b, c, d;
	int x, n;//biến x dùng để select các function trong menu,biến n là số cần tính!
	for (int i = 0; i < 86; i++)
	{
		if (i == 86 / 2)
		{
			cout << "MENU";
		}
		else
		{
			cout << "*";
		}
	}
	cout << endl;
	cout << "0.Exit" << left << endl;
	cout << "1.Chuyen chu thuong ra hoa " << setw(20) << left << "\t" << "2.Chuyen chu hoa ra chu thuong" << right << endl;
	cout << "3.So nho nhat trong 4 so " << setw(20) << left << "\t" << "4.So dao cua 1 so" << right <<  endl;
	cout << "5.Kiem tra so nguyen to " << setw(20) << left << "\t" << "6.Kiem tra so doi xung" << right <<  endl;
	cout << "7.Kiem tra so chinh phuong " << setw(20) << left << "\t" << "8.Kiem tra so hoan chinh" << right <<  endl;
	cout << "9.Tinh chieu dai cua 1 so " << setw(20) << left << "\t" << "10.Ket qua cua fibo" << right <<  endl;
	cout << "11.Uoc chung lon nhat " << setw(21) << left << "\t\t" << "12.Boi chung nho nhat" << right <<  endl;
	for (int i = 0; i < 82; i++)
	{
		if (i == 86 / 2)
		{
			cout << "KET THUC" ;
		}
		else
		{
			cout << "*";
		}
	}
	cout << endl;
	cout << "Nhap lua chon cua ban: "; cin >> x;
	if (x == 0)
	{
		exit(0);
	}
	else 
		if (x == 1 || x == 2)
	{
		cout << "Nhap ky tu can chuyen: "; cin >> ch;
	}
		else
			if (x == 3)
			{
				cout << "Nhap a= "; cin >> a;
				cout << "Nhap b= "; cin >> b;
				cout << "Nhap c= "; cin >> c;
				cout << "Nhap d= "; cin >> d;
			}
			else
				if (x == 11 || x == 12)
				{
					cout << "Nhap a= "; cin >> a;
					cout << "Nhap b= "; cin >> b;
				}
				else
				{
					cout << "Nhap n= "; cin >> n;
				}
	switch (x)
	{
	case 1: cout << hoa(ch)<<endl; break;
	case 2:cout << thuong(ch) << endl ; break;
	case 3:cout<<min4(a,b,c,d)<<endl; break;
	case 4: cout << sodao(n)<<endl; break;
	case 5: cout << nguyento(n) << endl; break;
	case 6:cout << doixung(n) << endl; break;
	case 7:cout << chinhphuong(n) << endl; break;
	case 8:cout << hoanchinh(n) << endl; break;
	case 9: cout << chieudai(n) << endl; break;
	case 10: cout << fibo(n) << endl; break;
	case 11:cout << UCLN(a,b) << endl; break;
	case 12:cout << BCNN(a,b) << endl; break;
	default: cout << "Ban da nhap sai! \n"; break;
	}
}
int main()
{
	menu();
	cout << endl;
	return 0;
}