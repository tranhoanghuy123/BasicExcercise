#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//Bài2.
//Cho mảng một chiều chứa n phần tử thuộc kiểu số nguyên.Hãy viết chương trình :
//-Ghi thông tin vào tệp nhị phân “ vao.dat”
//- Đọc thông tin từ tệp.
//- Tìm phần tử hoàn hảo trong mảng.
//- Sắp xếp mảng theo thứ tự giảm dần
//Kết quả ghi vào tệp văn bản“luu.txt
void ghiFile(fstream& f,int n)
{
	int dem = 0;
	int dulieu;
	f.open("vao.dat", ios::out);
	while (dem <= n)
	{
		cout << "Nhap pt: "; cin >> dulieu;
		f << dulieu<<" ";
		dem++;
	}
	f.close();
}
void docFile(fstream& f, int a[],int &n)
{
	n = 0;int  biendoc;
	f.open("vao.dat", ios::in);
	while (f >> biendoc)
	{
		a[n] = biendoc;
		cout << biendoc << " ";
		n++;
	}
	cout << endl;
	f.close();
}
bool soHoanHao(int n)
{
	//kiểm tra 1 số có phải là số hoàn chỉnh hay không?
	 /* +số hoàn chỉnh là một số nguyên dương mà tổng các ước nguyên dương chính thức của nó (số nguyên dương bị nó chia hết ngoại trừ nó) bằng chính nó.
		+nghĩa là 1 số nguyên dương khi tổng các ước của nó (trừ số đó) = chính số đó
		+ quy ước 0: sai; 1: đúng */
	int sum = 0;
	if (n < 0)
		return false;
	for (int i = 1; i <= n/2; i++)  // giới hạn số lần lặp của 1 vòng lặp vì khi n/i luôn luôn nhỏ hơn hoặc bằng n/2!
	{
		if (n % i == 0)
			sum += i;
	}
	return n == sum;
}
void kiemTraSoHoanHao(int a[], int n,int b[],int &nb)
{
	nb = 0;
	for (int i = 0; i < n; i++)
	{
		if (soHoanHao(a[i]))
		{
			b[nb] = a[i];
			nb++;
		}
	}
}
void sapXepGiamDan(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}
void luuFile(fstream& f1,int a[],int n)
{
	string s="So hoan hao: ";
	int nb, b[100];
	kiemTraSoHoanHao(a, n, b, nb);
	f1.open("luu.txt", ios::out);
	f1 << s;
	for (int i = 0; i < nb; i++)
	{
		f1 << b[i] << " ";
	}
	f1 << "\n";
	sapXepGiamDan(a, n);
	for (int i = 0; i < n; i++)
	{
		f1 << a[i] << " ";
	}
	f1.close();
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout  << a[i]<<" ";
	}
	cout << endl;
}
int main()
{
	fstream f,f1;
	int n,a[100];
	int b[100], nb;
	cout << "Nhap so luong pt: "; cin >> n;
	ghiFile(f, n);
	system("CLS");
	cout << "Du lieu trong file la: ";
	docFile(f, a, n);
	cout << "Cac so hoan hao co trong file: ";
	kiemTraSoHoanHao(a, n,b,nb);
	output(b, nb);
	cout << "Mang sau khi sap xep giam dan la: ";
	sapXepGiamDan(a, n);
	output(a, n);
	luuFile(f1, a, n);
	cout << endl;
	return 0;
}