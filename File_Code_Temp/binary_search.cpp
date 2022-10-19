#define _CRT_SECURE_NO_WARNINGS
#include "Methods.h"
#include<ctime>
int binarySearch(int a[], int left, int right, int key)
{
	if (right >= left)
	{
		int mid = left + (right - left) / 2;

		if (a[mid] == key)
		{
			return mid;
		}
		if (a[mid] > key)
			return binarySearch(a, left, mid -1, key);
		return binarySearch(a, mid + 1, right, key);
	}
	return -1;
}
int search(int a[], int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == key)
			return i;
	}
	return -1;
}
int main()
{
	int a[100000];
	for (int i = 0; i < 100000; i++)
	{
		a[i] = i;
	}
	cout << binarySearch(a, 0, 9999, 9999) << endl;
	return 0;
}