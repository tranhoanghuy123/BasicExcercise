#define  _CRT_SECURE_NO_WARNINGS
#include"Methods.h"
//COMMENT 1 ĐOẠN CODE: BÔI ĐEN ĐOẠN CODE --> ẤN CTRL + K + C
//UNCOMMENT 1 ĐOẠN CODE: BÔI ĐEN ĐOẠN CODE --> ẤN CTRL + K + U
struct Fraction
{
	int numerator, denominator;
};
void compact(Fraction& f)
{
	int temp = gcd(f.numerator, f.denominator);
	f.numerator /= temp;
	f.denominator /= temp;
}
void input_fraction(Fraction &f)
{
	do
	{
		cout << "Nhap tu so: "; cin >> f.numerator;
		cout << "Nhap mau so: "; cin >> f.denominator;
		if (f.denominator == 0)
		{
			cout << "ERROR: DIVIDE BY ZERO! \n";
		}
	} while (f.denominator == 0);
	
}
void output_fraction(Fraction f)
{
	compact(f);
	if (f.denominator < 0)
	{
		cout << "Phan so: " << f.numerator*(-1) << "/" << f.denominator*(-1) << endl;
	}
	else
		cout << "Phan so: " << f.numerator << "/" << f.denominator << endl;
}
Fraction sum(Fraction f, Fraction f1)
{
	Fraction sum;
	int temp = lcm(f.denominator, f1.denominator);
	sum.numerator = (f.numerator * (temp / f.denominator)) + (f1.numerator * (temp / f1.denominator));
	sum.denominator = temp;
	output_fraction(sum);
	return sum;
}
Fraction subtract(Fraction f, Fraction f1)
{
	Fraction subtract;
	int temp = lcm(f.denominator, f1.denominator);
	subtract.numerator = (f.numerator * (temp / f.denominator)) - (f1.numerator * (temp / f1.denominator));
	subtract.denominator = temp;
	output_fraction(subtract);
	return subtract;
}
Fraction product(Fraction f, Fraction f1)
{
	Fraction product;
	product.numerator = f.numerator * f1.numerator;
	product.denominator = f.denominator * f1.denominator;
	output_fraction(product);
	return product;
}
Fraction divide(Fraction f, Fraction f1)
{
	Fraction divide;
	divide.numerator = f.numerator * f1.denominator;
	divide.denominator = f.denominator * f1.numerator;
	output_fraction(divide);
	return divide;
}
struct Point
{
	float x,y;//tọa độ (x,y)
};
void input_point(Point& p)
{
	cout << "Nhap x= "; cin >> p.x;
	cout << "Nhap y= "; cin >> p.y;
}
void output_point(Point p)
{
	cout << "(" << p.x << "," << p.y << ") \t";
}
double distance(Point p, Point p1)
{
	double distance = 1.0 * sqrt(pow(p.x-p1.x,2) + pow(p.y - p1.y, 2));
	return distance;
}
double area_Point(Point p, Point p1, Point p2)
{
	double a = distance(p, p1);
	double b = distance(p, p2);
	double c = distance(p1, p2);
	double temp = (a + b + c) / 2.0;
	double s = 1.0*sqrt(temp * (temp - a) * (temp - b) * (temp - c));
	return s;
}
struct Date
{
	int day, month, year;
};
bool check_year(Date d)
{
	if (d.year % 400 == 0 || (d.year % 4 == 0 && d.year % 100 != 0))
	{
		return true;
	}
	return false;
}
short int date[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
short int date_of_month(Date d)
{
	if (check_year(d))
	{
		date[2] = 29;
	}
	return date[d.month];
}
void input_date(Date& d)
{
	do
	{
		cout << "Nhap thang: "; cin >> d.month;
	
	} while (d.month < 0 || d.month > 12 );
	do
	{
		cout << "Nhap nam: "; cin >> d.year;
	} while (d.year < 1);
	do
	{
		cout << "Nhap ngay: "; cin >> d.day;
	} while (d.day > date_of_month(d) || d.day <= 0);
}
void output_date(Date d)
{
	cout << d.day << "/" << d.month << "/" << d.year /*<< endl*/;
}
int index_of_day(Date d)
{
	int index = d.day;
	Date i;
	i.year = d.year;
	for ( i.month = 1; i.month < d.month; i.month++)
	{
		index += date_of_month(i);
	}
	return index;
}

struct City
{
	short int id;
	char name[31];
	float area;
};
void input_city(City& c)
{
	cout << "Nhap ma tinh: "; cin >> c.id; cin.ignore();
	cout << "Nhap ten tinh: "; cin.getline(c.name, 31);
	cout << "Nhap dien tich: "; cin >> c.area;
}
void output_city(City c)
{
	cout << setw(10) << left << "Ma Tinh" << setw(35) << left << "Ten Tinh" << setw(10) << right << "Dien tich \n";
	cout << setw(10) << left << c.id << setw(30) << left << c.name << setw(10) << right << c.area << endl;
}
struct MiklBox
{
	char logo[21];
	float weight;
	Date expiry;
};
void input_miklBox(MiklBox& mb)
{
	cout << "Nhap nhan hieu: "; cin.getline(mb.logo, 21);
	cout << "Nhap trong luong: "; cin >> mb.weight;
	cout << "Nhap Han su dung! \n";
	input_date(mb.expiry);
}
void output_miklBox(MiklBox mb)
{
	cout << setw(30) << left << "Nhan Hieu" << setw(15) << left << "Trong Luong" << setw(30) << right << "Han Su Dung \n";
	cout << setw(30) << left << mb.logo << setw(15) << left << mb.weight << setw(20) << right << mb.expiry.day << left << "/" << mb.expiry.month << left << "/" << mb.expiry.year << endl;
}
struct Time
{
	short int hours, minute, second;
};
struct Ticket 
{
	char name[21];
	int price;
	Time time;
	Date date;
};
void input_time(Time& t)
{
	do
	{
		cout << "Nhap gio: "; cin >> t.hours;
		cout << "Nhap phut: "; cin >> t.minute;
		cout << "Nhap giay: "; cin >> t.second;
	} while ((t.hours < 0 || t.hours >23 )|| (t.minute < 0 || t.minute > 59) || (t.second < 0 || t.second > 59));
}
void output_time(Time t)
{
	cout << t.hours << ":" << t.minute << ":" << t.second;
}
void input_ticket(Ticket& tic)
{
	cout << "Nhap ten ve: "; cin.getline(tic.name, 21);
	cout << "Nhap gia ve: "; cin >> tic.price;
	cin.ignore();
	input_time(tic.time);
	cin.ignore();
	input_date(tic.date);
}
void output_ticket(Ticket tic)
{
	cout << "******************************************************\n";
	cout << endl;
	cout << endl;
	cout  <<setfill(' ')<< setw(32)<< tic.name << endl;
	cout << endl;
	cout << endl;
	cout << "Xuat chieu: " << tic.time.hours << ":" << tic.time.minute << ":" << tic.time.second <<"      "<<setw(20)<<right<<"Gia ve: "<<tic.price<< endl;
	cout << "-------------------------- \n";
	cout << "Ngay chieu: " << tic.date.day << "/" << tic.date.month << "/" << tic.date.year << "     \n";
	cout << endl;
	cout << endl;
	cout << "******************************************************\n";
}
struct Goods
{
	char name[21];
	unsigned int price;
	unsigned int inventory;
};
void input_goods(Goods& g)
{
	cout << "Nhap ten mat hang: "; cin.getline(g.name, 21);
	cout << "Nhap don gia: "; cin >> g.price;
	cout << "Nhap so luong hang ton kho: "; cin >> g.inventory;
}
void output_goods(Goods g)
{
	cout << setw(30) << left << "TEN HANG" << setw(20) << left << "DON GIA" << setw(20) << right << "SO LUONG HANG TON \n";
	cout << setw(30) << left << g.name << setw(20) << left << g.price << setw(10) << right << g.inventory << endl;
}
struct Flight
{
	char id[6];
	Date date;
	Time time;
	char from[21];
	char to[21];
};
void input_flight(Flight& fli)
{
	cout << "Nhap Ma chuyen bay: "; cin.getline(fli.id, 6);
	input_date(fli.date);
	input_time(fli.time);
	cout << "Nhap noi di: "; cin.getline(fli.from,21);
	cin.ignore();
	cout << "Nhap noi den: "; cin.getline(fli.to,21);
	cin.ignore();
}
void output_flight(Flight fli)
{
	cout << setw(20) << left << "Ma chuyen bay" << setw(20) << left << "Ngay bay" << setw(20) << left << "Gio bay" << setw(30) << left << "Noi di" << setw(20) << right << "Noi den\n";
	cout << setw(20) << left << fli.id << /*setw(20) << left <<*/ fli.date.day<<left<<"/"<<left<<fli.date.month<<left<<"/"<<left<<fli.date.year << setw(20) << left << fli.time.hours<<left<<":"<<left<<fli.time.minute<<left<<":"<<left<<fli.time.second << setw(30) << left << "Noi di" << setw(20) << right << "Noi den\n";
	// XỬ LÝ SAU
}
struct Player
{
	char id[11];
	char name[31];
	Date birthday;
};
void input_player(Player& pl)
{
	cout << "Nhap ma cau thu: "; cin.getline(pl.id, 11);
	cout << "Nhap ten cau thu: "; cin.getline(pl.name, 31);
	input_date(pl.birthday);
	cin.ignore();
}
void output_player(Player pl)
{
	/*cout << setw(20) << left << "Ma cau thu" << setw(40) << left << "Ten cau thu" << setw(10) << "Ngay sinh \n";*/
	cout << setw(20) << left << pl.id << setw(40) << left << pl.name; output_date(pl.birthday);
}
struct Team
{
	char id[6];
	char name[31];
	Player list[30];
};
void input_team(Team& team,int n)
{
	cin.ignore();
	cout << "Nhap ma doi bong: "; cin.getline(team.id, 6);
	cout << "Nhap ten doi bong: "; cin.getline(team.name, 31);
	for (int i = 0; i < n; i++)
	{
			input_player(team.list[i]);
			if (!team.list[i-1].id)
			{
				input_player(team.list[i+1]);
			}
			else
			{
				cout << "Nhap lai! \n";
				input_player(team.list[i]);
			}
		
	}
}
void output_team(Team team, int n)
{
	cout << setw(20) << left << "Ma doi bong" << setw(20) << right << "Ten doi bong" << endl;
	cout << setw(20) << left << team.id << setw(20) << right << team.name << endl;
	cout << "Danh sach cau thu: \n";
	cout << setw(20) << left << "Ma cau thu" << setw(40) << left << "Ten cau thu" << setw(10) << "Ngay sinh \n";
	for (int i = 0; i < n; i++)
	{
		output_player(team.list[i]);
		cout << endl;
	}
}
struct Employee
{
	char id[6];
	char name[31];
	float salary;
};
void input_employee(Employee& emp)
{
	cin.ignore();
	cout << "Nhap ma nhan vien: "; cin.getline(emp.id, 6);
	cout << "Nhap ten nhan vien: "; cin.getline(emp.name, 31);
	cout << "Nhap luong cua nhan vien: "; cin >> emp.salary;
}
void output_employee(Employee emp)
{

}
int main()
{
	//Fraction f, f1; START STRUCT FRACTION
	//input_fraction(f);
	//input_fraction(f1);
	////sum(f, f1);
	////subtract(f, f1);
	////product(f, f1);
	////divide(f, f1);
	///*output_fraction(f);
	//output_fraction(f1);*/ END STRUCT FRACTION
	//STRUCT POINT
	/*Point p,p1;
	input_point(p);
	input_point(p1);
	cout << distance(p, p1);*/
	//STRUCT DATE
	Date d;
	input_date(d);
	output_date(d);
	cout << endl;
	cout<<index_of_day(d);

	/*City c;
	input_city(c);
	output_city(c);*/

	/*MiklBox mb;
	input_miklBox(mb);
	output_miklBox(mb);*/

	/*Ticket tic;
	input_ticket(tic);
	output_ticket(tic);*/

	/*Goods g;
	input_goods(g);
	output_goods(g);*/

	/*Flight fli;
	input_flight(fli);
	output_flight(fli);*/

	/*Player pl;
	input_player(pl);
	output_player(pl);*/

	/*Team team;
	int n;
	cout << "Nhap so luong cau thu: "; cin >> n;
	input_team(team,n);
	output_team(team,n);*/


	cout << endl;
	return 0;
}