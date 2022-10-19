#include "Methods.h"
//#pragma execution_character_set( "utf-8" )
void readFile(fstream& f, int a[], int lenght)
{
	f.open("Data.txt", ios::in);
	lenght = 0;
	while (f >> a[lenght])
	{
		lenght++;
	}
	f.close();
}
bool checkPrime(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return n > 1;
}
bool checkSquareNumber(int n)
{
	if (n < 0)
		return false;
	int temp = sqrt(n);//biến a lấy kq của căn bậc 2 của n
	if (n == temp * temp)
		return true;
	return false;
}
void sortingArrayWithInterchangeSort(int a[], int lenght)
{
	for (int i = 0; i < lenght - 1; i++)
	{
		for (int j = i + 1; j < lenght; j++)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}
// có 2 danh sách số nguyên tăng dần --> làm thế nào mà để trộn 2 mảng đó lại nhưng vẫn sắp xếp tangg8 dần
void mergeTwoArrayAndSortIt(int firstArray[],int firstLenght, int secondArray[],int secondLenght) // camel case, dùng _
{
	int lenght = firstLenght + secondLenght;
	int indexFirst = 0;
	int indexSecond = 0;
	int *result = new int [lenght];
	for (int i = 0; i < lenght; i++)
	{
		if (indexFirst < firstLenght && indexSecond < secondLenght)
		{
			if (firstArray[indexFirst] < secondArray[indexSecond])
			{
				result[i] = firstArray[indexFirst];
				indexFirst++;
			}
			else
			{
				result[i] = secondArray[indexSecond];
				indexSecond++;
			}
		}
		else
		{
			if (indexFirst == firstLenght)
			{
				result[i] = secondArray[indexSecond];
				indexSecond++;
			}
			else
			{
				result[i] = firstArray[indexFirst];
				indexFirst++;
			}
		}
	}
	output(result, lenght);
}
int main()
{
	
	int firsArray[5] = { 0,2,4,6,8 };
	int secondArray[5] = { 1,3,5,7,9 };
	//mergeTwoArrayAndSortIt(firsArray, 5, secondArray, 5);
	//fstream f;
	//int lenght = 10;
	//int a[100];
	// 
	//readFile(f, a, lenght);
	//mergeTwoArrayAndSortIt(firstArray, 10, secondArray, 10);
	//cout<<checkPrime(14);
	//sortingArrayWithInterchangeSort(firstArray, 10);
	//output(firstArray, 10);
	//cout << checkSquareNumber(10);
	//cout << checkPrime(2);
	cout << endl;
	return 0;
}