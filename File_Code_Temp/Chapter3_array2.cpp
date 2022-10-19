#include "Methods.h"
//COMMENT 1 ĐOẠN CODE: BÔI ĐEN ĐOẠN CODE --> ẤN CTRL + K + C
//UNCOMMENT 1 ĐOẠN CODE: BÔI ĐEN ĐOẠN CODE --> ẤN CTRL + K + U
void input(int a[][10], int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << "a[" << i << "][" << j << "]:";
			cin >> a[i][j];
		}
	}
}
void output(int a[][10], int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << a[i][j]<<" ";
		}
		cout << endl;
	}
}
int count_negative_of_array(int a[][10], int n, int m)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] < 0)
			{
				++count;
			}
		}
	}
	return count;
}
int max_of_array(int a[][10], int n, int m)
{
	int max = a[0][0];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] > max)
			{
				max=a[i][j];
			}
		}
	}
	return max;
}
int sum_row_array(int a[][10], int n, int m, int row)//hàm tính tổng các pt trên 1 dòng
{
	int sum = 0;//khởi tạo biến tính tổng
	for (int j = 0; j < m; ++j)//tổng các pt trên 1 dòn --> cột chạy & dòng cố định
	{
		sum += a[row][j];// tính tổng các pt ở cột thứ j khi row cố định
	}
	return sum;//trả về kết quả tổng thu được
}
int row_has_sum_is_max(int a[][10], int n, int m)//dòng có tổng lớn nhất
{
	int temp = sum_row_array(a, n, m, 0);//khởi tạo biến tạm gán bằng tổng các pt dòng đầu tiên
	for (int i = 1; i < n; ++i)//bắt đầu từ dòng thứ 2 tức là i=1
	{
		if (sum_row_array(a, n, m, i) > temp)// nếu có dòng thứ i mà lớn hơn giá trị của biến tạm 
		{
			temp = sum_row_array(a, n, m, i);//thì gán lại giá trị tạm là tổng dòng thứ i tương ứng đó
			return i;//trả về  vị trí dòng thứ i có tổng pt lớn nhất (vì biến i chỉ được khởi tạo trong vòng FOR nên phạm vi chỉ ở đây không return ở ngoài FOR dc
		}
	}
}
void sort_row_up(int a[][10], int n, int m)
{
	for (int k = 0; k < m; k++)
		for (int i = 0; i < n - 1; i++)
			for (int j = n-1; j > i; --j)
				if (a[k][j] < a[k][j-1])
				{
					swap(a[k][j], a[k][j-1]);
				}
	output(a, n, m);
}

void convert_2D_to_1D(int a[][10], int n, int m,int b[10],int k)
{
	//(d,c)=>i;i=d*C+c;d=i/c;c=i%C
	//k = n * m;
	 k = m * n;
	int i = 0;// biến index của mảng 1 chiều b[]
	for (int j = 0; j < n; ++j)//khởi tạo biến j là index của dòng
	{
		for (int l = 0; l < m; ++l)// l là index của cột
		{
			i = j * m + l;// công thức tìm chỉ số của mảng 1 chiều từ mảng 2 chiều
			b[i] = a[j][l];//gán từng phần tử của mảng 2 chiều cho mảng 1 chiều b[]
		}
	}
	//output_array(b, k);
}
//void sort_down(int a[][10], int n, int m)
//{
//	int b[10];
//	int k = m * n;
//	int col=0, row=0;
//	convert_2D_to_1D(a, n, m,b,k);
//	inter_sort_down(b, k);
//	for (int i = 0; i < k; ++i)
//	{
//		col = i%m;
//		row = i / m;
//		a[row][col] = b[i];
//	}
//	output(a, n, m);
//}
// SERIES MA TRẬN VUÔNG (SQUARE MATRIX)
void input_square_matrix(int a[][10], int n)
{
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j <n; ++j)
				{
					cout << "a[" << i << "][" << j << "]= ";
					cin >> a[i][j];
				}
			}
}
void output_square_matrix(int a[][10], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout<< endl;
	}
}
int sum_element_out_main_diagonal(int a[][10], int n)
{
	int sum1 = 0/*, sum2 = 0*/;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			/*sum1 += a[i][j];
			if (i == j)
			{
				sum2 += a[i][j];
			}*/
			
			if (i != j)//khi i==j thi do la pt nam tren duong cheo chinh
			{
				sum1 += a[i][j];
			}
		}
	}
	return sum1 /*- sum2*/;
}
int element_max_main_diagonal(int a[][10], int n)
{
	int max=a[0][0];
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j && max < a[i][j])
			{
				max = a[i][j];
			}
		}
	}
	return max;
}
int count_element_negative_anti_diagonal(int a[][10], int n)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if ((i + j) == (n - 1) && a[i][j] < 0)//i+j=n-1 (tính chất của đường chéo phụ) ví dụ khi i=0;j-->n-1
												  //a[i][n-1] ==> i+j=n-1; tương tự cho i=1;j-->n-2
			{
				++count;
			}
		}
	}
	return count;
}
int count_prime_in2D(int a[][10], int n)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (check_prime(a[i][j]))
			{
				++count;
			}
		}
	}
	return count;
}
int digit_most_appeared(int a[][10], int n)
{
	int num[10] = { 0 };
	int unit, temp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			temp = abs(a[i][j]);
			do
			{
				unit = temp % 10;
				temp /= 10;
				num[unit]++;
			} while (temp != 0);
		}
	}
	int max = num[0],x_max=0;
	for (int i = 0; i < 10; ++i)
	{
		if (num[i] > max)
		{
			max = num[i];
			x_max = i;
		}
	}
	return x_max;
}
//void row_most_even(int a[][10], int n)
//{
//	int count[10] = {0};
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//				if (a[i][j] % 2 == 0)
//				{
//					count[i]++;
//				}
//		}
//	}
//	output_array(count, 3);
//}
//void row_most_prime(int a[][10], int n)
//{
//	int count[10]={0};
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			if (check_prime(a[i][j]))
//			{
//				count[i]++;
//			}
//		}
//	}
//	output_array(count, 3);
//}
int symmetric_and_antisymmetric_matrix(int a[][10], int n)
{
	int sym = 0, antisym = 0;//sym=symmetric matrix; antisym=antisymmetric matrix
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if (a[i][j] == a[j][i])
			{
				 sym++;
			}
			else
				if (a[i][j] == -a[j][i])
				{
					antisym++;
				}
		}
	}
	if (sym == (n * (n - 1)) / 2)
	{
		return 1;
	}
	else
		if (antisym == (n * (n - 1)) / 2)
		{
			return 0;
		}
	return -1;
}
void swap_2row(int a[][10], int n, int row1, int row2)
{
	if (row1 >= 0 && row1 < n && row2 >= 0 && row2 < n)
	{
		for (int j = 0; j < n; ++j)
		{
			swap(a[row1][j], a[row2][j]);
		}
	}
}
void swap_row(int a[][10], int n)
{
	//hoán vị các dòng sao cho cột 0 tăng dần
	for (int i = 0; i < n; ++i)
	{
		if (a[i][0] > a[i + 1][0])
		{
			swap_2row(a, n, i, i + 1);
		}
	}
	output_square_matrix(a, n);
}
void swap_row_sum_up(int a[][10], int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (sum_row_array(a, n, n, i) > sum_row_array(a, 3, 3, i+1))
		{
			swap_2row(a, n, i, i + 1);
		}
	}
	output_square_matrix(a, n);
}
void sum_2_matrix(int a[][10], int b[][10], int n,int k)
{
	int c[][10] = { 0 };
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	output(c, n,n);
}
void dot_2_matrix(int a[][10], int b[][10], int n,int k)
{
	int c[][10] = { 0 };
	int check;
	cout << "Nhap bieu thuc can tinh (1=A*B) (0=B*A)"; cin >> check;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				if (check == 1)
				{
					c[i][j] += a[i][k] * b[k][j];
				}
				else
					c[j][i] += a[k][i] * b[j][k];
			}
		}
	}
	output(c, n, n);
}
void transpose_matrix(int a[][10], int n)
{
	int b[][10] = { 0 };
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			b[j][i] = a[i][j]; // phần tử tại dòng i, cộtj của mảng b=phần tử dòng j cột i của mảng a
			/*ví dụ:  1 2 3		 1 4 7
					  4 5 6 ===> 2 5 8 	
					  7	8 9      3 6 9      b[0][1]=a[1][0]*/
		}
	}
	output(b, 3, 3);
}
int  min_element_of_matrix(int a[][10], int n)
{
	int min = a[0][0];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (a[i][j] < min)
			{
				min = a[i][j];
			}
		}
	}
	return min;
}
int min_element_of_2_matrix(int a[][10], int b[][10], int n,int k)
{
	if (min_element_of_matrix(a, n) < min_element_of_matrix(b, k))
		return min_element_of_matrix(a, n);
	return min_element_of_matrix(b, k);
}
int sum(int c[][10], int n)
{
	if (n == 0)
	{
		return 0;
	}
	return sum(c, n - 1) + c[n - 1][n - 1];
}
//void menu()
//{
//
//}
int main()
{

	//int a[10][10] /*= {11,2,3,2,5,6,23,26,9}*//*{1,5,3,4,-5,6,7,8,-3,-7,11,12,-4,-8,-12,16}*/;
	//int b[10][10] /*= { 1,2,3,4,5,6,7,8,9 }*/;
	int c[10][10];
	input_square_matrix(c, 4);
	output_square_matrix(c, 4);
	cout << sum(c, 4) << endl;
	//int n,m,k;
	//input(a, n, m);
	//output(a, n, m);
	//cout << count_negative_of_array(a, n, m);
	//cout << max_of_array(a, n, m);
	//cout << row_has_sum_is_max(a, n, m);
	//sort_row_up(a, n, m);
	//sort_down(a, n, m);
	//input_square_matrix(a, n);
	//output_square_matrix(a, n);
	//cout << sum_element_out_main_diagonal(a, n);
	//cout << element_max_main_diagonal(a, n);
	//cout << count_element_negative_anti_diagonal(a, n);
	//cout << count_prime_in2D(a, n);
	//cout << digit_most_appeared(a, n);
	//row_most_even(a, n);
	//row_most_prime(a, n);
	//cout<<symmetric_and_antisymmetric_matrix(a, n);
	//swap_row(a, n);
	//swap_row_sum_up(a, n);
	//sum_2_matrix(a, b, n);
	//dot_2_matrix(a, b, n);
	//transpose_matrix(a, n);
	//cout << min_element_of_2_matrix(a, b, n);
	//int select;
	//cout << "=====================================================MENU======================================================\n";
	//cout << "0.Exit"<< endl;
	//cout << "1.Nhap/xuat mang" << setw(70) << "2.So luong so am cua mang" << endl;
	//cout << "3.Gia tri lon nhat cua mang" << setw(57) << "4.Dong co tong lon nhat"<<endl;
	//cout << "5.Sap xep tung dong tang dan" << setw(56) << "6.Sap xep mang giam dan"<< endl;
	//cout << setw(55) << "MA TRAN VUONG" << endl;
	//cout << "7.Nhap/xuat mang" << setw(86) << "8.Tong cac phan tu ngoai duong cheo chinh" << endl;
	//cout << "9.Phan tu lon nhat tren duong cheo chinh" << setw(63) << "10.So luong phan tu am tren duong cheo phu" << endl;
	//cout << "11.So luong so nguyen to trong mang" << setw(57) << "12.Phan tu xuat hien nhieu nhat" << endl;
	//cout << "13.Liet ke cac dong co nhieu so chan nhat" << setw(66) << "14.Liet ke cac dong co nhieu so nguyen to nhat" << endl;
	//cout << "15.KT mang co doi xung hay phan doi xung" << setw(70) << "16.Hoan vi cac dong sao cho thu tu cot 0 tang dan" << endl;
	//cout << "17.Hoan vi cac dong sao cho tong cac pt cua dong tang dan" << setw(25) << "18.Tong cua 2 ma tran" << endl;
	//cout << "19.Tich cua 2 ma tran" << setw(60) << "20.Ma tran chuyen vi" << endl;
	//cout << "21.Phan tu nho nhat trong 2 mang"  << endl;
	//cout << "=====================================================HHUY======================================================\n";
	//cout << "Nhap lua chon cua ban:"; cin >> select;
	//cout << endl;
	//if (select >= 1 && select <= 6)
	//{
	//	do {
	//		cout << "Nhap so dong:"; cin >> n;
	//		cout << "Nhap so cot:"; cin >> m;
	//		if (n <= 0 || m <= 0)
	//		{
	//			cout << "Moi ban nhap lai!" << endl;
	//		}
	//	} while (n <= 0 && m <= 0);
	//	input(a, n, m);
	//}
	//else
	//if(select >=7 && select <=21) {
	//	cout << "Nhap cap cua ma tran:"; cin >> n;
	//	input_square_matrix(a, n);
	//}
	//switch (select)
	//{
	//case 0: exit(0); break;
	//case 1: output(a, n, m); break;
	//case 2:  cout << count_negative_of_array(a, n, m); break;
	//case 3:  cout << max_of_array(a, n, m); break;
	//case 4:  cout << row_has_sum_is_max(a, n, m); break;
	//case 5:  sort_row_up(a, n, m); break;
	////case 6:  sort_down(a, n, m); break;	
	//case 7:  output_square_matrix(a,n); break;
	//case 8:  cout<<sum_element_out_main_diagonal(a,n); break;
	//case 9:  cout<<element_max_main_diagonal(a,n); break;
	//case 10:  cout<<count_element_negative_anti_diagonal(a,n); break;
	//case 11:  cout<<count_prime_in2D(a,n); break;
	//case 12:  cout<<digit_most_appeared(a,n); break;
	////case 13:  row_most_even(a,n); break;
	////case 14:  row_most_prime(a,n); break;
	//case 15:  cout<<symmetric_and_antisymmetric_matrix(a,n); break;
	//case 16:  swap_row(a,n); break;
	//case 17:  swap_row_sum_up(a,n); break;
	//case 18:  cout << "Moi nhap ma tran B" << endl;	cout << "Nhap cap cua ma tran:"; cin >> k; input_square_matrix(b, k); sum_2_matrix(a, b, n,k); break;
	//case 19:  cout << "Moi nhap ma tran B" << endl;	cout << "Nhap cap cua ma tran:"; cin >> k; input_square_matrix(b, k); dot_2_matrix(a,b,n,k); break;
	//case 20:  transpose_matrix(a,n); break;
	//case 21:  cout << "Moi nhap ma tran B" << endl;	cout << "Nhap cap cua ma tran:"; cin >> k; input_square_matrix(b, k); min_element_of_2_matrix(a,b,n,k); break;
	//}
	//cout << endl;

	return 0;
}