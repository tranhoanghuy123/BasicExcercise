#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
//Bài1.Để quản lý các cầu thủ của một đội bóng, người ta lưu trữ các thông tin sau : Mã cầu thủ, Tên cầu thủ, Tuổi, Số huy chương, Thưởng.Viết chương trình thực hiện các công việc sau :
//a)Khai báo cấu trúc để quản lý các cầu thủ
//b)Nhập vào một danh sách n cầu thủ(không nhập trường Thưởng)
//c)Tính thưởng cho các cầu thủ biết nếu
//- Số huy chương > 5 thì Thưởng là500000đ.
//- Số huy chương > 3 thì Thưởng là300000đ.
//- Số huy chương > 2 thì Thưởng là200000đ.
//d) In ra danh sách các cầu thủ với đầy đủ thông tin dưới dạng bảng
//e) Sắp xếp danh sách các cầu thủ theo thứ tự giảm dần của Tuổi.In ds sau sắp xếp.
struct CAUTHU
{
	char ma[11];
	char ten[30];
	 int tuoi,huychuong,thuong;
};
int TimkiemTheoMa(CAUTHU a[], int n,char maTam[11])
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].ma,maTam) == 0)
		{
			return i;
		}
	}
	return -1;
}
char upper(char ch)
{
	//đổi ký tự chữ ra chữ hoa, các ký tự khác giữ nguyên
	if (ch >= 'a' && ch <= 'z')
	{
		ch -= 32;
	}
	return ch;
}
void standard_string(char s[])
{
	// chuẩn chuỗi --> vd có chuỗi "   TrAn    hOaNg   hUy    " --> "Tran Hoang Huy"
	int len = strlen(s);
	while (s[0] == ' ')//  xóa ký tự thừa ở đầu chuỗi
	{
		strcpy(s, s + 1);
	}
	while (s[len - 1] == ' ') // xóa ký tự thừa ở cuối
	{
		len--;
		s[len] = '\0';
	}
	for (int i = 0; i < len; ++i)// xóa giữa
	{

		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			for (int j = i; j < len; ++j)
			{
				s[j] = s[j + 1];
			}
			--i;
		}
	}
	_strlwr(s);
	s[0]=upper(s[0]);
	for (int i = 1; i < len; ++i)
	{
		if (s[i] == ' ')
		{
			s[i + 1] = upper(s[i + 1]);
		}
	}
	//cout << s;
}
void nhap1CT(CAUTHU& c)
{
	cout << "Nhap ten cau thu: "; cin.getline(c.ten, 30); standard_string(c.ten);
	cout << "Nhap tuoi: "; cin >> c.tuoi;
	cout << "Nhap so huy chuong: "; cin >> c.huychuong;
	if (c.huychuong > 2)
	{
		c.thuong = 200000;
	}
	if (c.huychuong > 3)
	{
		c.thuong = 300000;
	}
	if (c.huychuong > 5)
	{
		c.thuong = 500000;
	}
	if (c.huychuong <= 2)
	{
		c.thuong = 0;
	}
	cin.ignore();
}
void tieuDe()
{
	cout << setw(15) << left << "MA CAU THU" << setw(35) << left << "Ten Cau Thu" << setw(12) << left << "TUOI" << setw(8) << left << "HC" << setw(20) << right << "Tien Thuong\n";
}
void nhapDanhSachCT(CAUTHU a[], int n)
{
	char maTam[11];
	for (int i = 0; i < n; i++)
	{
		do
		{
			cout << "Nhap ma cau thu: "; cin.getline(maTam, 11);
			if (TimkiemTheoMa(a, n, maTam) != -1)
			{
				cout << "Ma bi trung moi nhap lai! \n";
			}
		} while (TimkiemTheoMa(a, n, maTam) != -1);
		strcpy(a[i].ma, maTam);
		nhap1CT(a[i]);
	}
}
void xuat1CT(CAUTHU c)
{
	cout << setw(15) << left << c.ma << setw(35) << left << c.ten << setw(12) << left << c.tuoi << setw(8) << left << c.huychuong << setw(20) << right << c.thuong << endl;
}
void xuatDS(CAUTHU a[], int n)
{
	tieuDe();
	for (int i = 0; i < n; i++)
	{
		xuat1CT(a[i]);
	}
}
void sapXepTheoTuoi(CAUTHU a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].tuoi < a[j].tuoi)
				swap(a[i], a[j]);
		}
	}
}
int main()
{
	CAUTHU a[100];
	int n;
	cout << "Nhap so luong cau thu: "; cin >> n; cin.ignore();
	nhapDanhSachCT(a, n);
	sapXepTheoTuoi(a, n);
	xuatDS(a, n);
	cout << endl;
	return 0;
}