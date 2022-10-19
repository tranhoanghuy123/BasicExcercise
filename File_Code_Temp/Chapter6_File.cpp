#define _CRT_SECURE_NO_WARNINGS
#include "Methods.h"
//#include <cstdlib>
//#include <io.h>
//#include <fcntl.h>
// BỎ COMMENT: BÔI ĐEN ĐOẠN CẦN BỎ --> ẤN CTRL + K + U
// COMMENT 1 ĐOẠN BÔI ĐEN ĐOẠN CẦN COMMENT --> ẤN CTRL + K + C
using namespace std;
//int * find_fifty_prime()
//{
//	int a[50],count = 0;
//	int prime = 2,index = 0;
//	while (count < 50)
//	{
//		if (check_prime(prime))
//		{
//			a[count] = prime;
//			count++;
//		}
//		prime++;
//	}
//	return a;
//	//output(a, 50);
//}
//void write_file(fstream& f) // ghi 50 số nguyên tố đầu tiên vào file
//{
//	f.open("E://Studies/kyThuatLapTrinh/prime.txt", ios::out);
//	int  count = 0;
//	int prime = 2;
//	while (count < 50)
//	{
//		if (check_prime(prime))
//		{
//			f <<" "<< prime;
//			count++;
//			if (count % 10 == 0)
//				f << "\n";
//		}
//		prime++;
//	}
//	f.close();
//}
//void read_file(fstream &f) //đọc 50 số nguyên tố đầu tiên từ file
//{
//	int readElementOfFile;
//	int count=0;
//	f.open("E://Studies/kyThuatLapTrinh/prime.txt", ios::in);
//	while (f >> readElementOfFile)
//	{
//		count++;
//		cout <<readElementOfFile<< "\t";
//		if (count %10 == 0)
//			cout << endl;
//	}
//	f.close();
//}
//void  write_file(fstream& f) // . Lưu vào tập tin (có tên tùy ý nhập từ bàn phím) các ký tự gõ từ bàn phím (dừng khi gõ dấu chấm), mỗi ký tự cách nhau bởi 1 khoảng trắng, xuống dòng khi kết thúc file
//{
//	char character;
//	f.open("E://Studies/kyThuatLapTrinh/excercise1.txt", ios::out);
//	do
//	{
//		cout << "Nhap ky tu: ";
//		cin >> character;
//		f <<" "<< character;
//	} while (character != '.');
//	f << "\n";
//	f.close();
//}
//void read_file(fstream& f) . Lưu vào tập tin (có tên tùy ý nhập từ bàn phím) các ký tự gõ từ bàn phím (dừng khi gõ dấu chấm), mỗi ký tự cách nhau bởi 1 khoảng trắng, xuống dòng khi kết thúc file
//{
//	char ch;
//	f.open("E://Studies/kyThuatLapTrinh/excercise1.txt", ios::in);
//	while (f >> ch)
//	{
//		cout <<" " <<ch;
//	}
//}
//void write_file(fstream& f)
//{
//	string pathFile;
//	int input,count = 0;
//	cout<<"Nhap duong dan cua file: "; getline(cin, pathFile);
//	f.open(pathFile, ios::out);
//	cout << "Bat dau nhap: ";
//	do
//	{
//		cin >> input;
//		f << input << "\t"; count++;
//		if (count % 10 == 0)
//		{
//			f << "\n";
//		}
//	} while (input != 0);
//}
//void read_file(fstream &f)
//{
//	//string pathFile;
//	int input, count = 0;
//	//cout << "Nhap duong dan cua file: "; getline(cin, pathFile);
//	f.open("E://Studies/kyThuatLapTrinh/excercise2.txt", ios::in);
//	while (f >> input)
//	{
//		cout << "\t" << input;
//		count++;
//		if (count % 10 == 0)
//		{
//			cout << endl;
//		}
//	}
//	f.close();
//}
//void plit_file_even_odd(fstream& f)
//{
//	fstream f1, f2;// f1 là file chẵn, f2 là file lẻ
//	int input,ceven=0,codd=0;
//	f.open("E://Studies/kyThuatLapTrinh/excercise2.txt", ios::in);
//	f1.open("E://Studies/kyThuatLapTrinh/excercise2_even.txt", ios::out);
//	f2.open("E://Studies/kyThuatLapTrinh/excercise2_odd.txt", ios::out);
//	while (f >> input)
//	{
//		if (input % 2 == 0)
//		{
//			f1 <<"\t"<< input;
//			ceven++;
//			if (ceven % 10 == 0)
//			{
//				f1 << "\n";
//			}
//		}
//		else
//		{
//			f2 << "\t" << input;
//			codd++;
//			if (codd % 10 == 0)
//			{
//				f2 << "\n";
//			}
//		}
//	}
//	f2 <<"\t"<< 2015;
//	f1.close();
//	f2.close();
//}
//void write_file(fstream& f)
//{
//	string lineOfPoem;
//	//bool check;bool check2 = false;//check2 là biến kiểm tra dòng chẵn hay lẻ
//	//cout << "------------------------------------------------------------\n\n";
//	//cout <<setw(20)<<""<<"Lua chon the tho\n";
//	//cout << setw(40) << left << "0.Luc bat" << "1.The tho khac \n\n";
//	//cout << "------------------------------------------------------------\n\n";
//	//cout << "Nhap lua chon: "; cin >> check;
//	f.open("E://Studies/kyThuatLapTrinh/excercise3.txt", ios::out);
//	do
//	{
//		/*getline(cin, lineOfPoem);
//		if (lineOfPoem.length() == 6 || lineOfPoem.length() == 8)
//		{
//			if (lineOfPoem.length() == 6)
//			{
//
//			}
//		}*/
//		getline(cin, lineOfPoem);
//		f << lineOfPoem << "\n";
//		//if (check == true)
//		//{
//		//	f << lineOfPoem << "\n";
//		//}
//		//else
//		//{
//		//		//getline(cin, lineOfPoem);
//		//		if (check2)
//		//		{
//		//			f << lineOfPoem << "\n";
//		//			check2 = false;
//		//		}
//		//		else
//		//		{
//		//			f << setw(4) << left << "" << lineOfPoem << "\n";
//		//			check2 = true;
//		//		}
//		//}
//	} while (lineOfPoem.at(lineOfPoem.length()-1) != '.');
//	f.close();
//}
//void read_file(fstream& f)
//{
//	string lineOfPoem;
//	f.open("E://Studies/kyThuatLapTrinh/excercise3.txt", ios::in);
//	while (f >> lineOfPoem)
//	{
//		cout << lineOfPoem;
//		if (lineOfPoem.at(lineOfPoem.length() - 1)  == '\0')
//			cout << endl;
//	}
//	f.close();
//}
//struct Student
//{
//	char fullName[30], id[10], birthDay[13];
//	float point;
//};
//void write_file(fstream& f,int n)
//{
//	Student s;
//	f.open("E://Studies/kyThuatLapTrinh/excercise4.txt", ios::out|ios::binary);
//	if (!f)
//	{
//		cout << "Khong the mo file \n";
//	}
//	else
//	{
//		for (int i = 0; i < n; i++)
//		{
//			cout << "Nhap ma: "; cin.getline(s.id, 10);
//			cout << "Nhap ten: "; cin.getline(s.fullName, 30);
//			cout << "Nhap ngay sinh: "; cin.getline(s.birthDay, 13);
//			cout << "Nhap diem: "; cin >> s.point; cin.ignore();
//			f.write((char*)(&s), sizeof(s));
//		}
//	}
//	f.close();
//}
//void filter_student_with_point(fstream& f, Student a[],int &n, float point,string fileName) // point là điểm cần lọc ra
//{
//	n = 0;
//	fstream filePoint;
//	f.open("E://Studies/kyThuatLapTrinh/excercise4.txt", ios::in | ios::binary);
//	filePoint.open(fileName, ios::out | ios::binary);
//	if (!f)
//		cout << "Khong the mo file! \n";
//	else
//	{
//		while (f.read((char*)&a[n], sizeof(a[n])))
//		{
//			if (a[n].point >= point)
//			{
//				filePoint.write((char*)&a[n], sizeof(a[n]));
//			}
//			n++;
//		}
//		f.close();
//	}
//	/*for (int i = 0; i < n; i++)
//	{
//		if (a[i].point >= point)
//		{
//			filePoint.write((char*)&a[i], sizeof(a[i]));
//		}
//	}*/
//	filePoint.close();
//}
//void read_file_point(fstream& f, Student a[], int& n, string fileName)
//{
//	n = 0;
//	f.open(fileName, ios::in | ios::binary);
//	if (!f)
//		cout << "Khong the mo file! \n";
//	else
//	{
//		while (f.read((char*)&a[n], sizeof(a[n])))
//		{
//			n++;
//		}
//		f.close();
//	}
//}
//void title()
//{
//	cout << setw(15) << left << "Ma SV" << setw(35) << left << "Ho va ten" << setw(18) << left << "Ngay sinh" << "Diem\n";
//}
//void output_student(Student a[], int n)
//{
//	title();
//	for (int i = 0; i < n; i++)
//	{
//		cout<< setw(15) << left << a[i].id << setw(35) << left <<a[i].fullName << setw(18) << left << a[i].birthDay << a[i].point<<endl;
//	}
//}
struct Student
{
	char id[10];
	char fullName[30];
	char birthDay[15];
	char gender[4];
	float word, excel, powerPoint;// point of three subject 
};
void write_file(fstream& f, int n)
{
	Student s;
		f.open("E://Studies/kyThuatLapTrinh/excercise5.txt", ios::out|ios::binary);
		if (!f)
		{
			cout << "Khong the mo file \n";
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				cout << "Nhap ma: "; cin.getline(s.id, 10);
				cout << "Nhap ten: "; cin.getline(s.fullName, 30); standard_string(s.fullName);
				cout << "Nhap ngay sinh: "; cin.getline(s.birthDay, 15);
				cout << "Nhap gioi tinh: "; cin.getline(s.gender, 4);
				cout << "Nhap diem Word: "; cin >> s.word; 
				cout << "Nhap diem Excel: "; cin >> s.excel; 
				cout << "Nhap diem Power Point: "; cin >> s.powerPoint; 
				cin.ignore();
				f.write((char*)(&s), sizeof(s));
			}
		}
		f.close();
}
void read_file(fstream& f, Student a[], int& n)
{
	n = 0;
	f.open("E://Studies/kyThuatLapTrinh/excercise5.txt", ios::in | ios::binary);
	if (!f)
		cout << "Loi file! \n";
	else
	{
		while (f.read((char*)&a[n], sizeof(a[n])))
		{
			n++;
		}
	}
	f.close();
}
int search_with_id(Student a[], int lenght, char tempId[11])
{
	for (int i = 0; i < lenght; i++)
	{
		if (strcmp(a[i].id, tempId) == 0)
		{
			return i;
		}
	}
	return -1;
}
void title()
{
	cout << setw(12) << left << "Ma SV" << setw(30) << left << "Ho va ten" << setw(16) << left << "Ngay Sinh" << setw(10) 
		<< left << "GT" << setw(10) << left
		<< "Word" << setw(10) << left << "Excel" << "Power Point\n";
}
void ouput_1_student(Student stu)
{
	cout << setw(12) << left << stu.id << setw(30) << left << stu.fullName << setw(16) << left << stu.birthDay << setw(10)
		<< left << stu.gender << setw(10) << left
		<< stu.word << setw(10) << left << stu.excel << stu.powerPoint << endl;
}
void output_list_student(Student a[], int lenght)
{
	title();
	for (int i = 0; i < lenght; i++)
	{
		ouput_1_student(a[i]);
	}
}
void watch_student_with_id(Student a[], int lenght, char id[11])
{
	int temp = search_with_id(a, lenght, id);
	if (temp != -1)
	{
		title();
		ouput_1_student(a[temp]);
	}
	else
	{
		cout << "Khong ton tai sinh vien trongg danh sach!\n";
	}
}
void insert_student(Student a[], int& lenght, int pos)
{
	++lenght;
	for (int i = lenght - 1; i > pos; i--)
	{
		a[i] = a[i - 1];
	}
	cout << "Nhap ma: "; cin.getline(a[pos].id, 10);
	cout << "Nhap ten: "; cin.getline(a[pos].fullName, 30); standard_string(a[pos].fullName);
	cout << "Nhap ngay sinh: "; cin.getline(a[pos].birthDay, 15);
	cout << "Nhap gioi tinh: "; cin.getline(a[pos].gender, 4);
	cout << "Nhap diem Word: "; cin >> a[pos].word;
	cout << "Nhap diem Excel: "; cin >> a[pos].excel;
	cout << "Nhap diem Power Point: "; cin >> a[pos].powerPoint;
	cin.ignore();
}
void del_student_with_id(Student a[], int& lenght, char* id)
{
	int pos = search_with_id(a, lenght, id);
	if (pos != -1)
	{
		del<Student>(a, pos, lenght);// đây là hàm định nghĩa trong file header
	}
	else
	{
		cout << "Khong ton tai sinh vien! \n";
	}
}
//Sửa thông tin thì copy từ file Struct_Student.cpp rồi sửa lại
int main()
{
	fstream f;
	Student a[8];
	int n;
	//write_file(f);
	
	//EXCERCISE 4
	// string fileName;
	//write_file(f,8);
	// cout<<"Nhap duong dan: ";getline(cin,fileName);
	//filter_student_with_point(f, a, n, 7,fileName);
	//read_file_point(f, a, n,fileName);
	//output_student(a, n);
	
	//EXCERCISE 5
	/*char id[11];
	cout << "Nhap ma can kiem tra: ";
	cin.getline(id, 11);*/
	//title();
	//write_file(f, 8);
	read_file(f, a, n);
	output_list_student(a, n);
	//watch_student_with_id(a, n, id);
	
	
	//read_file(f);
	// 
	// 
	// 
	//plit_file_even_odd(f);
	cout << endl;
	return 0;
}