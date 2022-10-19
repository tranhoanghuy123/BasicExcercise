#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
//Câu 1. Tính S(x, n) = x ^ 1 + x ^ 2 + x ^ 3 + ... + x ^ n
//a. Bằng cách dùng vòng lặp			b. Dùng đệ quy
//------------------------------GO------------------------------//
double sumWithLoop(float x, int n)
{
	double result = 0;
	for (int i = 1; i <= n; i++)
	{
		result += pow(x, i);
	}
	return result;
}
double sumWithRecursion(float x, int n)
{
	double result = 0;
	if (n == 1)
		return  x;
	return sumWithRecursion(x, n - 1) + pow(x, n);
}
//Câu 2.(3, 5 điểm) Viết các hàm thực hiện các công việc sau :
//a.Cấp phát động cho n số nguyên
//b.Giải phóng n số nguyên trên
//c.Nhập / xuất n số nguyên
//d.Sắp xếp các số nguyên tố có trong n số nguyên trên tăng dần, hợp số giữ nguyên.
//e.Tìm phần tử có giá trị gần giá trị x nhất(x là số nguyên nhập từ bàn phím)
//f.Thêm sau các số nguyên tố một số nguyên m bất kỳ.
//------------------------------GO------------------------------//
void alloc(int*& array, int lenght)
{
	array = new int[lenght];
}
void recall(int*& array)
{
	delete[] array;
}
void inputArray(int*& array, int lenght)
{
	for (int i = 0; i < lenght; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << ": "; cin >> *(array + i);
	}
}
void printArray(int* array, int lenght)
{
	for (int i = 0; i < lenght; i++)
	{
		cout << *(array + i)<<" ";
	}
	cout << endl;
}
bool check_prime(int n)
{
	for (int i = 2; i < sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return n > 1;
}
void sortingPrimeUp(int* array, int lenght)
{
	for (int i = 0; i < lenght -1; i++)
	{
		for (int j = i + 1; j < lenght; j++)
		{
			if (*(array + i) > *(array + j) && check_prime(*(array + i)) && check_prime(*(array + j)))
			{
				swap(*(array + i), *(array + j));
			}
		}
	}
}
int findNumberIsNearestX(int* array, int lenght, int x)
{
	int result = *(array + 0);
	int distance = abs(*(array + 0) - x);
	for (int i = 0; i < lenght; i++)
	{
		if (distance > abs(*(array + i) - x))
		{
			distance = abs(*(array + i) - x);
			result = *(array + i);
		}
	}
	return result;
}
void insertOneElement(int* &array, int& lenght, int position,int value)
{
	lenght++;
	int* temp = new int[lenght];
	for (int i = 0; i < lenght ; i++)
	{
		*(temp + i) = *(array + i);
	}
	for (int i = lenght -1 ; i > position; i--)
	{
		*(temp + i) = *(temp + i - 1);
	}
	*(temp + position) = value;
	delete[] array;
	array = new int[lenght];
	for (int i = 0; i < lenght; i++)
	{
		*(array + i) = *(temp + i);
	}
	delete[]temp;
}
void delOneElement(int*& array, int lenght, int position)
{
	int* temp = new int[lenght];
	for (int i = 0; i < lenght; i++)
	{
		*(temp + i) = *(array + i);
	}
	for (int i = position; i < lenght;i++)
	{
		*(temp + i) = *(temp + i + 1);
	}
	lenght--;
	delete[] array;
	array = new int[lenght];
	for (int i = 0; i < lenght; i++)
	{
		 *(array + i) = *(temp + i) ;
	}
	recall(temp);
}
void insertValueBesidePrimes(int* &array, int &lenght, int value)
{
	for (int index = 0; index < lenght; index++)
	{
		if (check_prime(*(array + index)))
		{
			insertOneElement(array, lenght, index +1 , value);
			index++;
		}
	}
}
//Câu 3 (1 điểm) Viết hàm : char* Mid(char* s, int pos, int len) trích chuỗi con từ chuỗi s từ vị trí pos dài len ký tự.Ví dụ : s = ”abcdefgh”; Mid(s, 2, 4)}”cdef
//------------------------------GO------------------------------//
char* Mid(char* s, int pos, int len)
{
	char* result = new char[100];
	strncpy(result, s + pos, len);
	result[len ] = '\0';
	return result;
}
//Câu 4 (4 điểm).Hãy khai báo kiểu dữ liệu để biểu diễn thông tin của một nhân viên(NHANVIEN).
//Biết rằng một nhân viên gồm những thành phần sau :
//-Mã nhân viên : chuỗi tối đa 5 ký tự
//- Tên nhân viên : chuỗi tối đa 30 ký tự
//- Ngày sinh : 12 ký tự.
//- Giới tính : 4 ký tự
//- Địa chỉ : 50 ký tự
//- Lương cơ bản ngày : số thực
//- Số ngày công : số thực.
//- Lương thực lĩnh : số thực Lương thực lĩnh = lượng chỉ ngày X số ngày công.
//a.Viết hàm nhập danh sách nhân viên.
//b.Viết hàm xuất danh sách nhân viên.
//c.Sắp xếp danh sách nhân viên giảm dần theo lương.
//d.Xuất danh sách nhân viên nữ
//e.Xóa một nhân viên theo mã
//------------------------------GO------------------------------//
struct Employee
{
	char id[6];
	char fullName[30];
	char birthDay[13];
	char gender[5];
	char adress[51];
	float basicSalary;
	float amoutOfWorkDays;
	float realSalary;
};
int searchIdOfEmployeeInList(Employee list[], int lenght,char idNeedToSearch[6])
{
	for (int i = 0; i < lenght; i++)
	{
		if (strcmp(list[i].id, idNeedToSearch) == 0)
		{
			//Sự khác biệt giữa return và break trong hàm có kiểu trả về
			// Khi gặp câu lệnh return thì hàm sẽ trả về tại kết quả đó và thoát khỏi hàm.
			// Còn break thì chỉ dừng lại ở đó đến khi gặp return mới thoát khỏi hàm nên có thể bị sai số.
			return i; //Valid
		}
	}
	return -1; // Invalid
}
void writeListToFile(fstream &f, int lenght,string filePath)
{
	char idTemp[6];
	Employee temp[100];
	f.open(filePath, ios::out | ios::binary);
	for (int i = 0; i < lenght; i++)
	{
		cout << "Nhap Nhan Vien Thu " << i + 1 << endl;
		do
		{
			cout << "Nhap Ma Nhan Vien: "; cin.getline(idTemp, 6);
			if (searchIdOfEmployeeInList(temp, lenght, idTemp) != -1)
			{
				cout << "Ma Bi Trung! Nhap Lai.\n";
			}
		} while (searchIdOfEmployeeInList(temp, lenght, idTemp) != -1);
		strcpy(temp[i].id, idTemp);
		cout << "Nhap Ten Nhan Vien: "; cin.getline(temp[i].fullName, 30);
		cout << "Nhap Ngay Sinh Nhan Vien: "; cin.getline(temp[i].birthDay, 13);
		cout << "Nhap Gioi Tinh Cua Nhan Vien: "; cin.getline(temp[i].gender, 5);
		cout << "Nhap Dia Chi Cua Nhan Vien: "; cin.getline(temp[i].adress, 51);
		cout << "Nhap Luong Co Ban Nhan Vien: "; cin >> temp[i].basicSalary;
		cout << "Nhap So Ngay Cong Cua Nhan Vien: "; cin >> temp[i].amoutOfWorkDays;
		temp[i].realSalary = temp[i].amoutOfWorkDays * temp[i].basicSalary;
		f.write((char*)(&temp[i]), sizeof(temp[i]));
		cin.ignore();
	}
	f.close();
}
void readFileToList(fstream &f,Employee list[], int& lenght, string filePath)
{
	lenght = 0;
	f.open(filePath, ios::in | ios::binary);
	while (f.read((char*)(&list[lenght]),sizeof(list[lenght])))
	{
		lenght++;
	}
	f.close();
}
void title()
{
	cout << setw(10) << left << "Ma NV" << setw(35) << left << "Ten Nhan Vien" << setw(18) << left << "Ngay Sinh" << setw(10) << left << "GTinh" << setw(55) << left << "Dia Chi" 
		<< setw(17) << left << "Luong CB" << setw(15) << left << "So NCong" << setw(15) << left << "Thuc Linh" << endl;
}
void printOneEmployee(Employee employee)
{
	cout << setw(10) << left << employee.id << setw(35) << left << employee.fullName << setw(18) << left << employee.birthDay << setw(10) << left << employee.gender << setw(55) << left 
		<< employee.adress<< setw(17) << left <<setprecision(3)<<fixed << employee.basicSalary << setw(15) << left << employee.amoutOfWorkDays << setw(15) << left << setprecision(3) 
		<< fixed<< employee.realSalary << endl;
}
void printListEmployee(Employee list[], int lenght)
{
	title();
	for (int i = 0; i < lenght; i++)
	{
		printOneEmployee(list[i]);
	}
}
void sortedUpListEmployeeByRealSalary(Employee list[], int lenght)
{
	for (int i = 0; i < lenght - 1; i++)
	{
		for (int j = i + 1; j < lenght; j++)
		{
			if (list[i].realSalary > list[j].realSalary)
			{
				swap(list[i], list[j]);
			}
		}
	}
}
void printEmployeesHaveGenderAsGirl(Employee list[], int lenght)
{
	title();
	for (int i = 0; i < lenght; i++)
	{
		if (strcmp(list[i].gender, "Nu") == 0)
		{
			printOneEmployee(list[i]);
		}
	}
}
void delOneEmployee(Employee list[], int &lenght, int position)
{
	for (int i = position; i < lenght; i++)
	{
		list[i] = list[i + 1];
	}
	lenght--;
}
bool delEmployeeById(Employee list[], int &lenght, char idNeedToDel[6])
{
	int position = searchIdOfEmployeeInList(list, lenght, idNeedToDel);
	if (position != -1)
	{
		delOneEmployee(list, lenght, position);
		return true;
	}
	return false;
}
int main()
{		//Cau 1
	/*cout << sumWithLoop(3.2, 10) << endl;
	cout << sumWithRecursion(3.2, 10);*/
		//Cau 2
	//int* array;
	//int lenght = 10;
	//alloc(array,lenght);
	//inputArray(array, lenght);
	//sortingPrimeUp(array, lenght);
	//printArray(array, lenght);
	//cout <<"So Gan 20 Nhat La: "<< findNumberIsNearestX(array, lenght, 20) << endl;
	////insertOneElement(array, lenght, 3, 11);
	//insertValueBesidePrimes(array, lenght, -3);
	//cout << "Mang Sau Khi Them -3 Vao Sau So Nguyen To La: ";
	//printArray(array, lenght);
	//recall(array);
		//Cau 3
	/*char s[100];
	strcpy(s, "abcdefgh");
	cout << Mid(s, 2, 4);*/
		//Cau 4
	Employee list[100];
	fstream f;
	int lenght = 4;
	writeListToFile(f, lenght, "Employee.txt");
	readFileToList(f, list, lenght, "Employee.txt");
	sortedUpListEmployeeByRealSalary(list, lenght);

	printListEmployee(list, lenght);
	cout << endl;
	return 0;
}