#include "Methods.h"
#include <vector>
struct Student
{
	char id[10];
	char name[30];
	int age;
};
void createStudent(Student& student)
{
	cout << "Nhap id: "; cin.getline(student.id, 10);
	cout << "Nhap ten: "; cin.getline(student.name, 30);
	cout << "Nhap tuoi: "; cin >> student.age;
	cin.ignore();
	//return student;
}
void createList(vector<Student> &list, int lenght)
{
	Student temp;
	for (int i = 0; i < lenght; i++)
	{
		createStudent(temp);
		list.push_back(temp);
	}
}
void printList(vector<Student> list, int lenght)
{
	for (int i = 0; i < lenght; i++)
	{
		cout << setw(15) << left << list[i].id << setw(35) << left << list[i].name << setw(10) << left << list[i].age << endl;
	}
}
int main()
{
	vector<Student> list;
	int lenght = 2;
	createList(list, lenght);
	printList(list, lenght);
	cout << endl;
	/*auto x = 100000000000000000;
	cout << sizeof(x) << endl;*/

	return 0;
}