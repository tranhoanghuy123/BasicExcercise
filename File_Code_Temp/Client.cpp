#define _CRT_SECURE_NO_WARNINGS
#include"Methods.h"
struct abc
{
	char fullName[30];
	char birthDay[12];
	float point;
};
abc input_1_abc(abc& a)
{
	cout << "Nhap ten: "; cin.getline(a.fullName, 30);
	cout << "Nhap ngay sinh: "; cin.getline(a.birthDay, 12);
	cout << "Nhap diem: "; cin >> a.point;
	cin.ignore();
	return a;
}
void input_list(abc a[], int lenght)
{
	for (int i = 0; i < lenght; i++)
	{
		input_1_abc(a[i]);
	}
}
void output_1_abc(abc a)
{
	cout << setw(20) << left << a.fullName << setw(30) << left<<a.birthDay<<a.point<<endl;
}
void output_list(abc a[], int lenght)
{
	cout << setw(20) << left << "Ho ten" << setw(30) << left << "Ho ten" << "Diem" << endl;
	for (int i = 0; i < lenght; i++)
	{
		output_1_abc(a[i]);
	}
}
int main()
{
	/*char *a=new char[100];
	int n;
	cout << "Nhap chieu dai cua du lieu: "; cin >> n;
	cin.ignore();
	input_array<char>(a, n);
	standard_string<char>(a);
	output_array<char>(a, n);
	cout << endl;
	delete[100]a;*/
	//abc a[10];
	// //char* fullName =new char[10];
	//// cout << "Nhap ten: "; cin.getline(fullName, 10);
	////string fullName = "123";
	//int lenght,pos;
	//cout << "Nhap chieu so luong: "; cin >> lenght;
	//cin.ignore();
	//input_list(a, lenght);
	/*cout << "Nhap vi tri can them: "; cin >> pos; cin.ignore();
	a[pos] = input_1_abc(a[pos]);
	insert<abc>(a, lenght, pos, a[pos]);*/
	//del<abc>(a, 1, lenght);
	//swap_test(a[2], a[3]);
	//output_list(a, lenght);
	//cout << setw(50) << setfill('*')<<"";
	/*string s = "11111344114";
	long long  n = 11111344114111111111;*/
	//cout << n;
	string s;
	fstream f;
	f.open("E://Studies/kyThuatLapTrinh/unins000.dat", ios::in);
	while (f >> s)
	{
		cout << s<<" ";
		//cout << endl;
	}
	cout << endl;
	return 0;
}