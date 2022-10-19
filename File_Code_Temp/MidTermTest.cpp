#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
using namespace std;
//EXCERCISE 1
long long recur_product(int n)
{
	if (n == 0)
		return 1;
	return n * recur_product(n - 1);
}
long long array_product(int n)
{
	long long a[100];
	a[0] = 1; 
	for (int i = 1; i <= n; i++)
	{
		a[i] = a[i-1]*i;
	}
	return a[n];
}
long long loop_product(int n)
{
	long long temp=1;
	for (int i = 1; i <= n; i++)
	{
		temp*=i;
	}
	return temp;
}
//TEST 2
void input_str(char s[])
{
	cout << "Nhap chuoi: ";
	cin.getline(s, 100);
}
int count_char_digit(char s[])
{
	int len = strlen(s);
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			count++;
	}
	return count;
}
void del_one_char(char s[],int pos)
{
	int len = strlen(s);
	for (int i = pos; i < len; i++)
	{
		s[i] = s[i + 1];
		
	}
	s[len-1] = '\0';
}
void del_all_digit(char s[])
{
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			del_one_char(s, i);
			i--;
		}
	}
	cout << s;
}
// TEST 3
void alloc(int*& a, int n)
{
	a = new int[n];
	//cout << "Da cap phat thanh cong \n";
}
void recall(int* a)
{
	delete[]a;
	//cout << "Da thu hoi thanh cong \n";
}
void input_array(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i<<": ";
		cin >> *(a + i);
	}
}
void output_array(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(a + i) << "\t";
	}
	cout << endl;
}
int count_number_even_positive(int* a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) > 0 && *(a + i) % 2 == 0)
			count++;
	}
	return count;
}
bool check_prime(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return false;
			break;
		}
	}
	return n > 1;
}
void sorting_prime(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (*(a + i) > *(a + j) && check_prime(*(a + i)) && check_prime(*(a + j)))
				swap(*(a + i), *(a + j));
		}
	}
}
void del_element(int* a, int &n, int pos)
{
	for (int i = pos; i < n; i++)
	{
		*(a + i) = *(a + i + 1);
	}
	n--;
}
void del_all_prime(int* a, int &n) 
{
	int* temp_prime = new int[n];
	for (int i = 0; i < n; i++)
	{
		*(temp_prime + i) = *(a + i);
	}
	for (int i = 0; i < n; i++)
	{
		if (check_prime(*(temp_prime + i)))
		{
			del_element(temp_prime,n,i);
			i--;
		}
	}
	for (int i = 0; i < n; i++)
	{
		 *(a + i) =*(temp_prime + i);
	}
	recall(temp_prime);
}
//TEST 4
void input_2D(int b[][20], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "Nhap pt thu " << j + 1 << " dong thu " << i + 1 << ": ";
			cin >> *(*(b + i) + j);
		}
	}
}
void output_2D(int b[][20], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << *(*(b + i) + j)<<"\t";
		}
		cout << endl;
	}
}
void sorting_2D(int b[20][20], int n, int m)
{
	for (int i = 0; i < n * m -1; i++)
	{
		for (int j = i + 1; j < n * m; j++)
		{
			if (*(*(b + (i / m)) + (i % m)) > *(*(b + (j / m)) + (j % m)))
			{
				swap(*(*(b + i / m) + i % m), *(*(b + j / m) + j % m));
			}
		}
	}
}
//int count5(int a[], int n)// count 5 là hàm đếm số lượng các giá trị phân biệt
//{
//	int count = 0, flag;// kỹ thuật cờ hiệu, flag là biến cờ hiệu
//	for (int i = 0; i < n; ++i)
//	{
//		flag = 1;
//		for (int j = i + 1; j < n; ++j)
//		{
//			if (a[i] == a[j])
//				flag = 0;
//		}
//		if (flag == 1)
//			count++;
//	}
//	return count;
//}
int count_difference(int b[20][20], int n, int m)
{
	int count = 0,flag;
	for (int i = 0; i < n * m ; i++)
	{
		flag = 1;
		for (int j = i + 1; j < n * m; j++)
		{
			if (*(*(b + (i / m)) + (i % m)) == *(*(b + (j / m)) + (j % m)))
			{
				flag = 0;
			}
		}
		if (flag == 1)
			count++;
	}
	return count;
}
void menu_ex1(int n)
{
	int select;
	char check;
	cout << setw(40) << setfill('-') << "" << "\n\n";
	cout << setw(10) << setfill(' ') << "" << "Tinh P = 1.2.3...n\n\n";
	cout << setw(20) << left << "1.Dung de quy" << "2.Dung vong lap\n";
	cout << "3.Dung mang\n\n";
	cout << setw(40) << setfill('-') << "" << "\n\n";
	do
	{
		cout << "Nhap lua chon: "; cin >> select;
		switch (select)
		{
		case 1: cout << "Ket qua cua phep tinh la: " << recur_product(n) << endl; break;
		case 2: cout << "Ket qua cua phep tinh la: " << loop_product(n) << endl; break;
		case 3: cout << "Ket qua cua phep tinh la: " << array_product(n) << endl; break;
		}
		cout << "Ban muon tiep tuc bai 1? Y/N ------> "; cin >> check;
	} while (check == 'y' || check == 'Y');
}
void menu_ex2(char s[])
{
	int select;
	char check;
	cout << setw(43) << setfill('-') << "" << "\n\n";
	cout << setw(10) << setfill(' ') << "" << "Thao tac voi chuoi\n\n";
	cout << setw(20) << left << "1.Dem ky tu so" << "2.Xoa tat ca ky tu so\n\n";
	cout << setw(43) << setfill('-') << "" << "\n\n";
	do
	{
		cout << "Nhap lua chon: "; cin >> select;
		switch (select)
		{
		case 1: cout << "So Luong ky tu so trong chuoi: " << count_char_digit(s) << endl; break;
		case 2: cout << "Chuoi sau khi xoa tat ca ky tu so: "; del_all_digit(s); cout << endl; break;
		}
		cout << "Ban muon tiep tuc bai 2? Y/N ------> "; cin >> check;
	} while (check == 'y' || check == 'Y');
}
void menu_ex3(int *&a,int &n)
{
	int select;
	char check;
	cout << setw(70) << setfill('-') << "" << "\n\n";
	cout << setw(25) << setfill(' ') << "" << "Mang 1 chieu dung con tro\n\n";
	cout << setw(45) << left << "1.Cap Phat Dong" << "2.Thu Hoi\n";
	cout << setw(45) << left << "3.Nhap / Xuat" << "4.So luong so chan duong\n";
	cout << setw(45) << left << "5.Sap xep so nguyen to tang dan " << "6.Xoa tat ca so nguyen to\n\n";
	cout << setw(70) << setfill('-') << "" << "\n\n";
	
	do
	{
		cout << "Nhap lua chon: "; cin >> select;
		switch (select)
		{
		case 1:alloc(a, n); cout << "Cap phat thanh cong!\n";  break;
		case 2:recall(a); cout << "Thu hoi thanh cong!\n"; break;
		case 3:input_array(a, n); output_array(a, n); break;
		case 4: cout << "So luong phan tu chan duong: " << count_number_even_positive(a,n) << endl; break;
		case 5: sorting_prime(a, n); cout << "Mang sau khi sap xep: ";  output_array(a, n); break;
		case 6: del_all_prime(a, n); cout << "Mang sau  khi xoa tat ca so nguyen to: "; output_array(a, n); break;
		}
		cout << "Ban muon tiep tuc bai 3? Y/N ------> "; cin >> check;
	} while (check == 'y' || check == 'Y');
}
void menu_ex4(int b[20][20],int n,int m)
{
	cout << setw(62) << setfill('-') << "" << "\n\n";
	cout << setw(20) << setfill(' ') << "" << "Mang 2 chieu dung con tro\n\n";
	cout << setw(35) << left << "1.Nhap / Xuat" << "2.Sap xep mang tang dan \n";
	cout << setw(35) << left << "3.Dem cac phan tu phan biet" << "4.Exit \n";
	cout << setw(62) << setfill('-') << "" << "\n\n";
	int select;
	char check;
	do
	{
		cout << "Nhap lua chon: "; cin >> select;
		switch (select)
		{
		case 1:input_2D(b, n, m); output_2D(b, n, m); break;
		case 2: sorting_2D(b, n, m); cout << "Ma tran sau khi sap xep: \n"; output_2D(b, n, m); break;
		case 3: cout<<"So luong cac phan tu phan biet: "<<count_difference(b,n,m)<<endl; break;
		case 4: exit(0); break;
		}
		cout << "Ban muon tiep tuc bai 4? Y/N ------> "; cin >> check;
	} while (check == 'y' || check == 'Y');
}
void menu()
{
	cout << setw(40) << setfill('-') << "" << "\n\n";
	cout << setw(14) << setfill(' ') << "" << "Menu Bai Tap\n\n";
	cout << setw(20) << left << "1.Bai tap 1" << "2.Bai Tap 2\n\n";
	cout << setw(20) << left << "3.Bai tap 3" << "4.Bai Tap 4\n\n";
	cout << setw(40) << setfill('-') << "" << "\n\n";
}
int main()
{
	char s[100], checkCont;
	 int n,r,c,*a,na;
	 int b[20][20],select;
	 do
	 {
		 system("CLS");
		 menu();
		 cout << "Nhap lua chon cua ban: "; cin >> select;
		 switch (select)
		 {
		 case 1:cout << "Nhap n= "; cin >> n;
			 menu_ex1(n); break;
		 case 2:cin.ignore(); cout << "Nhap chuoi: "; cin.getline(s, 100);
			 menu_ex2(s); break;
		 case 3: cout << "Nhap so phan tu cua mang: "; cin >> na;
			 menu_ex3(a, na); break;
		 case 4: 
			 cout << "Nhap so dong: "; cin >> r;
			 cout << "Nhap so cot: "; cin >> c;
			 menu_ex4(b, r, c); break;
		 }
		 cout << "Ban muon tiep tuc chuong trinh? Y/N-------> "; cin >> checkCont;
	 } while (checkCont=='Y'|| checkCont =='y');
	
	//input_2D(b, n, m);
	//sorting_2D(b, n, m);
	//output_2D(b, n, m);
	//cout << count_difference(b, n, m);
	////char s[100];
	////int* a,n=7;
	////alloc(a, 10);
	////input_array(a, n);
	////sorting_prime(a, 7);
	////del_all_prime(a, n);
	////output_array(a, n);
	////cout << count_number_even_positive(a, 7);
	////recall(a);
	////input_str(s);
	////del_all_digit(s);
	////cout << count_char_digit(s);
	////cout << loop_product(5);
	////cout << array_product(25); //26! vượt quá giá trị của kiểu long long 
	//menu_ex1();
	//menu_ex2();
	//menu_ex3();
	//menu_ex4();
	//menu();
	cout << endl;
	return 0;
}