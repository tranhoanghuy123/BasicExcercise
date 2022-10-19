#include"Methods.h"
//COMMENT 1 ĐOẠN CODE: BÔI ĐEN ĐOẠN CODE --> ẤN CTRL + K + C
//UNCOMMENT 1 ĐOẠN CODE: BÔI ĐEN ĐOẠN CODE --> ẤN CTRL + K + U
// FUNCTIONS BASIC WITH DATA TYPE INTERGE
void alloc(int*& a,int n)
{
	a = new int[n];
}
void recall(int* a)
{
	delete[100]a;
}
void input(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Phan tu thu " << i << " : "; cin >> *(a + i);
	}
}
void output_reverse(int* a, int n)
{
	int* p = a;
	for ( p = a+n-1; p >= a; --p)
	{
		cout << *p <<" ";
	}
	//return a;
}
void output(int* a, int n)
{
	int* p = a;
	for (p = a ; p < a+n; ++p)
	{
		cout << *p << " ";
	}
	//return a;
}
int count_prime(int* a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (check_prime(*(a + i)))
			count++;
	}
	return count;
}
void pointer_del(int* &a, int pos, int &n)
{
	int* temp = new int[n];
	for (int i = 0; i < n; i++)
	{
		*(temp + i) = *(a + i);
	}
	for (int i = pos; i < n; i++)
	{
		*(temp + i) = *(temp + i + 1);
	}
	n--;
	for (int i = 0; i < n; i++)
	{
		*(a + i) = *(temp + i);
	}
	recall(temp);
}
void insert(int* &a, int &n, int pos,int val)
{
	n++;
	int* temp = new int[n];
	for (int i = 0; i < n; i++)
	{
		*(temp+i) =*(a+i);
	}
	alloc(a, n);
	for (int i = n - 1; i > pos; i--)
	{
		*(temp + i) = *(temp + i - 1);
	}
	*(temp + pos) = val;
	for (int i = 0; i < n; i++)
	{
		*(a + i) = *(temp + i);
	}
	recall(temp);
}
void max_and_index_of_max(int* a, int n)
{
	int* p = a;
	int* max = &a[0];
	int i_max = 0;
	for (p = a; p < a + n; ++p)
	{
		if (*max < *(p))
		{
			*max = *(p);
			i_max++;
		}
	}
	cout << *max<<endl;
	cout << i_max;
}
void inter_sorting(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (*(a + i) > *(a + j))
			{
				swap(*(a + i), *(a + j));
			}
		}
	}
	//output(a, n);
}
void pointer_sorting(int*& a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (*(a + i) > *(a + j))
			{
				swap(*(a + i), *(a + j));
			}
			if ((*(a + i) < *(a + j)) && (*(a + i) < 0) && (*(a + j) < 0))
				{
					swap(*(a + i), *(a + j));
				}
		}
	}
	//output(a, n);
}
// SERIES MATRIX IN POINTER
void input_matrix(int **matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "Phan tu thu " << j << " tai dong " << i << ": "; cin >> *(*(matrix + (i * m)) + j);
		}
	}
}
void output_matrix(int** matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << *(matrix + (i * m) + j)<<"\t";
		}
		cout << endl;
	}
}
void sorting_row(int** matrix, int n, int m)
{
	int temp;
	for (int k = 0; k < m; ++k)
	{
		for (int j = 0; j < n-1; ++j)
		{
			for (int i = n - 1; i > j; --i)
			{
				if (*(*(matrix + k) + i) > *(*(matrix + k) + i-1))
					swap(*(*(matrix + k) + i), *(*(matrix + k) + i-1));
			}
		}
	}
}
void sort_row_up(int a[][10], int n, int m)
{
	for (int k = 0; k < m; k++)
		for (int i = 0; i < n - 1; i++)
			for (int j = n - 1; j > i; --j)
				if (a[k][j] < a[k][j - 1])
				{
					swap(a[k][j], a[k][j - 1]);
					*(*(a + i) + j) = *(*(a + i) + j);
				}
}
int main()
{
	int /**a,*/*matrix; int n, m;
	cout << "Nhap so dong: "; cin >> n;
	cout << "Nhap so cot: "; cin >> m;
	alloc(matrix,n * m);
	//cout << "Nhap n= "; cin >> n;
	//alloc(a,n);
	//input(a, n);
	//insert(a, n, 4, 13);
	//pointer_del(a, 4, n);
	//pointer_sorting(a, n);
	//output(a, n);
	//recall(a);
	//output_reverse(a, n);
	//max_and_index_of_max(a, n);
	//inter_sorting(a, n);
	input_matrix(&matrix, n, m);
	sorting_row(&matrix, n, m);
	output_matrix(&matrix, n, m);
	recall(matrix);
	cout << endl;
	return 0;
}