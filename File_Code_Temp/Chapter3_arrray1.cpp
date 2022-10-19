#include"Methods.h"
//COMMENT 1 ĐOẠN CODE: BÔI ĐEN ĐOẠN CODE --> ẤN CTRL + K + C
//UNCOMMENT 1 ĐOẠN CODE: BÔI ĐEN ĐOẠN CODE --> ẤN CTRL + K + U
void input_array(int a[], int n)
{
	cout << "Nhap Mang \n";
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]: ";
		cin >> a[i];
	}
}
void output_array(int a[], int n)
{
	cout << "Xuat mang \n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int serch(int a[], int n, int key)
{
	int i = 0;
	for (i; i < n; i++)
		if (a[i] == key)
			return i;
	return -1;
}
int sum_even_array(int a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
			sum = sum + a[i];
	}
	return sum;
}
bool check_prime(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;
	return true;
}
int count_prime(int a[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (check_prime(a[i]))
			count++;
	return count;
}
bool check_array_even(int a[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)

			count++;
	}
	if (count == n)
		return true;
	return false;
}
bool check_array_prime(int a[], int n)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (check_prime(a[i]))
			count++;
	}
	if (count == n)
		return true;
	return false;
}
bool check_square_number(int n)
{
	int a = sqrt(n); //biến a lấy kq của căn bậc 2 của n
	if (n < 0)
		return false;
	if (n == a * a)
		return true;
	return false;
}
bool check_array_square_number(int a[], int n)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (check_square_number(a[i]))
			count++;
	}
	if (count == n)
		return true;
	return false;
}
bool check_array_raise(int a[], int n)
{
	int check = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n - 1; ++j)
		{
			if (a[i] > a[j])
				check++;

		}
	}
	if (check == 0)
		return true;
	return false;
}
int count1(int a[], int n) // đếm có bao nhiêu số chia hết cho 4 mà kh chia hết cho 5
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] % 4 == 0 && a[i] % 5 != 0)
			count++;
	}
	return count;
}
int sum_not_prime(int a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		if (!check_prime(a[i]))
			sum += a[i];
	}
	return sum;
}
int times_appear_array(int a[], int n, int key)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == key)
			count++;
	}
	return count;
}
int fibo(int n)
{
	if (n == 1 || n == 2)
		return 1;
	return fibo(n - 1) + fibo(n - 2);
}
//bool check_fibo(int m)
//{
//	int check = 0;
//	for (int i = 0; i <= m;++i)
//	{
//		if (fibo(i) == m)
//			check++;
//	}
//	if (check == 1)
//		return true;
//	return false;
//}
int count_fibo(int a[], int n)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= a[i]; ++j)
		{
			if (a[i] == fibo(j))
			{
				count++;
			}
		}
	return count;
}
int compare_even_odd(int a[], int n)
{
	int ceven = 0, codd = 0;//cenve = count even & codd = count odd
	for (int i = 0; i < n; ++i)
	{
		if (a[i] % 2 == 0)
			++ceven;
		else
			++codd;
	}
	if (ceven == codd)
		return 0;
	else
		if (ceven > codd)
			return -1;
	return 1;
}
int count2(int a[], int n)//count2 là hàm đếm số lượng phần tử kề nhau mà cả 2 đều chẵn
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		{
			if (a[i] % 2 == 0 && a[i + 1] % 2 == 0)
				count++;
		}
	}
	return count;
}
int count3(int a[], int n)// count3 là hàm trả về số lượng phần tử kề nhau trái dấu
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] < 0 && a[i + 1] < 0)
			count++;
	}
	return count;
}
int count4(int a[], int n)//count 4 là hàm trả về số lượng phần tử kề nhau cùng dấu và trị tuyệt đối của số trước < số sau
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (((a[i] > 0 && a[i + 1] > 0) || (a[i] < 0 && a[i + 1] < 0)) && abs(a[i]) < abs(a[i + 1]))
			count++;
	}
	return count;
}
int count5(int a[], int n)// count 5 là hàm đếm số lượng các giá trị phân biệt
{
	int count = 0, flag;// kỹ thuật cờ hiệu, flag là biến cờ hiệu
	for (int i = 0; i < n; ++i)
	{
		flag = 1;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[i] == a[j])
				flag = 0;
		}
		if (flag == 1)
			count++;
	}
	return count;
}
int locate_final_x(int a[], int n, int key)
{
	for (int i = n - 1; i >= 0; --i)
	{
		if (key == a[i])
			return i;
	}
	return -1;
}
int locate_first_prime(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (check_prime(a[i]))
			return i;
	}
	return -1;
}
int min_of_array(int a[], int n)
{
	int min = a[0];
	for (int i = 0; i < n; ++i)
	{
		if (a[i] < min)
			min = a[i];
	}
	return min;
}
int min_positive_of_array(int a[], int n)
{
	int min;
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			flag++;
		}
		if (flag > 0)
		{
			min = a[i];
			for (i = i + 1; i < n; i++)
			{
				if ((a[i] > 0) && (min > a[i]))
				{
					min = a[i];
				}
			}
			return min;
		}
	}
	return -1;
}
int furthest_x(int a[], int n, int key)// giá trị của phần tử xa x nhất trong mảng
{
	int index = 0, temp, dist = abs(a[0] - key);
	for (int i = 1; i < n; ++i)
	{
		temp = abs(a[i] - key);
		if (dist < temp)
		{
			dist = temp;
			index = i;
		}
	}
	return a[index];
}
int nearest_x(int a[], int n, int key)
{
	int index = 0, temp, dist = abs(a[0] - key);
	for (int i = 1; i < n; ++i)
	{
		temp = abs(a[i] - key);
		if (dist > temp)
		{
			dist = temp;
			index = i;
		}
	}
	return a[index];
}
int first_element_has_final_digit_odd(int a[], int n)
{
	int temp, i = 0;
	for (; i < n; ++i)
	{
		temp = a[i] % 10;
		if (temp % 2 != 0)
		{
			return a[i];
		}
		continue;
	}
	return i;
}
void plit_prime_to_array(int a[], int n)
{
	int b[10], x = 0;
	for (int i = 0; i < n; ++i)
	{
		if (check_prime(a[i]))
		{
			b[x] = a[i];
			++x;
		}
	}
	output_array(b, x);
}
void del(int a[], int index, int& n)
{
	for (int i = index; i < n; ++i)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void plit_array_3(int a[], int n)//tach mang thanh 3 mang 1 chua duong 1 chua am va 1 chua 0
{
	int b[10], c[10], d[10]; // b[] là mảng chứa số dương, c[] là mảng chưa số âm d[] chứa số 0
	int x = 0, y = 0, z = 0;// x là index của b[],y là index của c[], z là index của d[];
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > 0)
		{
			b[x] = a[i];
			++x;

		}
		else
			if (a[i] < 0)
			{
				c[y] = a[i];
				++y;
			}
			else
				if (a[i] == 0)
				{
					d[z] = a[i];
					++z;
				}
	}
	output_array(b, x);
	cout << endl;
	output_array(c, y);
	cout << endl;
	output_array(d, z);
	cout << endl;
}
void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}
void inter_sort_up(int a[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}
void merge_sort_up(int a[], int b[], int n, int m)
{
	const int nc = n + m;
	int c[nc];
	inter_sort_up(a, n);
	inter_sort_up(b, m);
	int idxA = 0, idxB = 0;
	for (int i = 0; i < nc; ++i)
	{
		if (idxA < n && idxB < m)// kiểm tra vị trí của pt A , pt B có trong mảng a[] b[] không
		{
			if (a[idxA] < b[idxB])// so sánh phần tử tại vị trí A so với phần tử của mảng b tại vtB, nếu a[vt]<b[vt] trộn a[vt] vào c[]
			{
				c[i] = a[idxA++];// nghĩa là a[idxA] > b[idxB] => c[i]=a[idxA];idxA++;
			}
			else
			{
				c[i] = b[idxB++];// trường hợp ngược lại của điều kiện trên
			}
		}
		else // thêm trường hợp nếu vị trí pt B = m => phần tử vượt quá khỏi mảng b => thêm pt cuối cùng của mảng a[] vào c[]
			if (idxB == m)
			{
				c[i] = a[idxA++];
			}
			else// ngược lại của cái trên => thêm pt cuối của mảng b[] vào c[]
			{
				c[i] = b[idxB++];
			}
	}
	output_array(c, nc);//xuất mảng đề test

}
void merge_sort_down(int a[], int b[], int n, int m)
{
	int nc = n + m;
	int c[20];
	inter_sort_up(a, n);
	inter_sort_up(b, m);
	int idxA = n - 1, idxB = m - 1;
	for (int i = 0; i < nc; ++i)
	{
		if (idxA < n && idxB < m)
		{
			if (a[idxA] < b[idxB])
			{
				c[i] = b[idxB--];
			}
			else
			{
				c[i] = a[idxA--];
			}
		}
		else
			if (idxA < 0)
			{
				c[i] = b[idxB--];
			}
			else
			{
				c[i] = a[idxA--];
			}
	}
	output_array(c, nc);//xuất mảng đề test
}
void inter_sort_down(int a[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (a[i] < a[j])
				swap(a[i], a[j]);
		}
	}
	//output_array(a, n);
}
void sort1(int a[], int n)// sắp xếp số dương tăng dần, số âm giữ vị trí
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (a[i] > a[j] && a[i] > 0 && a[j] > 0)
				swap(a[i], a[j]);
			continue;
		}
	}
	output_array(a, n);
}
void sort2(int a[], int n)//sắp xếp mảng có só lẻ tăng dần số khác giữ nguyên
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (a[i] > a[j] && a[i] > 0 && a[j] > 0 && a[i] % 2 != 0 && a[j] % 2 != 0)
				swap(a[i], a[j]);
			continue;
		}
	}
	output_array(a, n);
}
void sort3(int a[], int n) //sắp xếp số nguyên tố tăng dần số khác giữ nguyên vị trí
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (check_prime(a[i]) == true && check_prime(a[j]) == true && a[i] > a[j])
				swap(a[i], a[j]);
			continue;
		}
	}
	output_array(a, n);
}
void sort4(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (a[i] < a[j])
			{
				swap(a[i], a[j]);
			}
			else

			{
				if (a[i] < 0 && (a[i] > a[j]))
				{
					swap(a[i], a[j]);
				}
			}
		}
	}

	output_array(a, n);
}
void insert(int a[], int& n, int pos, int val)
{
	for (int i = n - 1; i > pos; --i)
	{
		a[i] = a[i - 1];
	}
	a[pos] = val;
	//output_array(a, n);
}
void insert_num_next_pirme(int a[], int n, int x)
{
	for (int i = 0; i < n; ++i)
	{
		if (check_prime(a[i]))
		{
			insert(a, n, i + 1, x);
			++i;
		}
	}
	output_array(a, n);
}
void fix_prime_to_x(int a[], int n, int x)
{
	for (int i = 0; i < n; ++i)
	{
		if (check_prime(a[i]))
		{
			a[i] = x;
		}
		continue;
	}
	output_array(a, n);
}
void del_all_x(int a[], int n, int x)
{
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == x)
		{
			del(a, i, n);
			--i;
		}
	}
	output_array(a, n);
}
void del1(int a[], int n)//xóa phần tử trùng nhau chỉ giữ lại 1
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (a[i] == a[j])
			{
				del(a, j, n);
			}
		}
	}
	output_array(a, n);
}
void insert_x_unchange_up_array(int a[], int& n, int x)
{
	/*insert(a, n, 3, x);
	inter_sort_up(a, n);
	output_array(a, n);*/
	inter_sort_up(a, n);
	for (int i = 0; i < n; ++i)
	{
		if (x < a[i])
		{
			insert(a, n, i, x);
			break;
		}
	}
	output_array(a, n);
}
void input_sort_down(int a[], int n)
{
	input_array(a, n);
	inter_sort_down(a, n);
	output_array(a, n);
}
int num[10] = { 0 };
void appear_digit_in_array(int a[], int n)// số từ 0-9 xuất hiện trong mảng bao nhiêu lần
{

	int unit, temp;
	// khởi tạo mảng đếm số 0-9 mặc định là 0
	for (int i = 0; i < n; ++i)
	{
		//cout << i << " ";
		temp = abs(a[i]); // lấy giá trị dương để đếm
		do
		{
			unit = temp % 10;//  tách phần tử ra các chữ số 0-9 
			temp /= 10;
			num[unit]++;// phần tử thứ unit +1
		} while (temp != 0);
	}
	cout << endl;
	//output_array(num, 10);
}
int digit_appear_min(int a[], int n)
{
	//int unit, temp;
	//int num[10] = { 0 };// khởi tạo mảng đếm số 0-9 mặc định là 0
	//for (int i = 0; i < n; ++i)
	//{
	//	temp = abs(a[i]); // lấy giá trị dương để đếm
	//	do
	//	{
	//		unit = temp % 10;//  tách phần tử ra các chữ số 0-9 
	//		temp /= 10;
	//		num[unit]++;// phần tử thứ unit +1
	//	} while (temp != 0);
	//}
	//int *num;
	appear_digit_in_array(a, n);
	//output_array(num, 10);
	int min = 1000, x_min = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (num[i] > 0)
		{
			if (num[i] < min)
			{
				min = num[i];
				x_min = i;
			}
		}
	}
	return x_min;
}
int digit_disappear_array(int a[], int n)
{
	int x = 0;// biến trả về kết quả chữ số không xuất hiện trong mảng
	appear_digit_in_array(a, n);
	for (int i = 0; i < 10; ++i)
	{
		if (num[i] == 0)
		{
			x = i;
			break;
		}
	}
	return x;
}
int gcd(int a, int b)
{
	if (a == 0 || b == 0)
		return a + b;
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
			b = b - a;
	}
	return a;
	/*if (a % b == 0)
		return b;
	return gcd(a, x % b);*/ // dùng đệ quy tìm ước chung lớn nhất theo thuật toán Eculic
}
int lcm(int a, int b)
{
	return (a / gcd(a, b)) * b;
}
int gcd_array(int a[], int n)
{
	int gcdn = a[0];
	for (int i = 0; i < n; ++i)
	{
		gcdn = gcd(gcdn, a[i]);
	}
	return gcdn;
}
int lcm_array(int a[], int n)
{
	int lcm_num = a[0];
	for (int i = 0; i < n; ++i)
	{
		lcm_num = lcm(lcm_num, a[i]);
	}
	return lcm_num;
}
int main()
{
	int a[10] = {};
	int b[10] = {};
	int n = sizeof(a) / sizeof(int);
	int m = sizeof(b) / sizeof(int);
	int key, x, val;
	int pos, select, index;
	for (int i = 0; i < 124; ++i) // in dấu '=' cho đẹp không thì in thủ công cũng được
	{
		if (i == 124 / 2)
		{
			cout << "menu";
		}
		else
		{
			cout << "=";
		}
	}
	// XUẤT RA CÁC THÀNH PHẦN TRONG MENU
	cout << endl;
	cout << "0.exit" << left << endl;
	cout << "1.nhap/xuat mang " << setw(38) << left << "\t" << "2.tim kiem phan tu trong mang" << right << endl;
	cout << "3.tinh tong cac phan tu chan " << setw(30) << left << "\t" << "4.dem so luong so nguyen to" << right << endl;
	cout << "5.kiem tra mang toan chan " << setw(30) << left << "\t" << "6.kiem tra mang toan nguyen to" << right << endl;
	cout << "7.kiem tra mang tang dan " << setw(30) << left << "\t" << "8.so luong so chia het cho 4 ma khong chia het cho 5" << right << endl;
	cout << "9.tong cac phan tu khac so nguyen to " << setw(22) << left << "\t" << "10.so x xuat hien bao nhieu lan" << right << endl;
	cout << "11.so sanh so luong pt chan & le " << setw(22) << left << "\t" << "12.dem so luong ke nhau chan" << right << endl;
	cout << "13.so luong pt ke nhau trai dau" << setw(30) << left << "\t" << "14.so luong pt ke nhau cung dau & tri tuyet doi so truoc < so sau" << right << endl;
	cout << "15.so luong cac gia tri phan biet" << setw(22) << left << "\t" << "16.vi tri cuoi cung cua so x" << right << endl;
	cout << "17.vi tri so nguyen to dau tien" << setw(30) << left << "\t" << "18.phan tu nho nhat cua mang" << right << endl;
	cout << "19.so duong nho nhat cu mang" << setw(30) << left << "\t" << "20.gia tri cua phan tu xa x nhat" << right << endl;
	cout << "21.gia tri cua phan tu gan x nhat" << setw(22) << left << "\t" << "22.phan tu dau tien co chu so cuoi la le" << right << endl;
	cout << "23.tach cac so nguyen to ra mang khac" << setw(22) << left << "\t" << "24.xoa 1 phan tu trong mang" << right << endl;
	cout << "25.tach mang thanh 3 mang duong/am/0" << setw(22) << left << "\t" << "26.sap xep mang tang dan" << right << endl;
	cout << "27.tron 2 mang sau do sap xep giam dan" << setw(22) << left << "\t" << "28.tron 2 mang sau do sap xep tang dan" << right << endl;
	cout << "29.sap xep mang giam dan" << setw(30) << left << "\t" << "30.sap xep so duong tang dan" << right << endl;
	cout << "31.sap xep so le tang dan" << setw(30) << left << "\t" << "32.sap xep so nguyen to tang dan" << right << endl;
	cout << "33.sap xep so duong giam dan den 0 den so am tang dan" << setw(6) << left << "\t" << "34.chen pt x vao mang" << right << endl;
	cout << "35.chen 1 so sau so nguyen to" << setw(30) << left << "\t" << "36.sua so nguyen to thanh x" << right << endl;
	cout << "37.xoa tat ca so x" << setw(38) << left << "\t" << "38.them x vao ma thu tu sap xep cua mang khong doi" << right << endl;
	cout << "39.nhap mang sau do sap xep giam dan" << setw(22) << left << "\t" << "40.dem so luong so 0-9 xuat hien bao nhieu lan trong mang" << right << endl;
	cout << "41.chu so xuat hien  it nhat" << setw(30) << left << "\t" << "42.chu so khong xuat hien" << right << endl;
	cout << "43.uoc chung lon nhat cua mang" << setw(30) << left << "\t" << "44.boi chung nho nhat cua mang" << right << endl;
	for (int i = 0; i < 100; ++i)
	{
		if (i == 50)
		{
			cout << "developed by huy toc dai :))";
		}
		else
		{
			cout << "=";
		}
	}
	cout << endl;
	cout << "nhap lua chon cua ban: "; cin >>  select;// NHẬP LỰA CHỌN ĐỂ THỰC HIỆN TỪNG Ý TRONG MENU, Ở ĐÂY MÌNH CÒN DỞ
	input_array(a, n);								// VÌ CHỈ NHẬP ĐƯỢC 1 LẦN, CÒN MUỐN NHIỀU NHIỀU LẦN BẠN CÓ THỂ NHÉT NÓ VÀO DO {} WHILE();
	switch (select)	// DÙNG SWICHT CASE ĐỂ THỰC HIỆN CÁC Ý TRONG MENU, MỖI 1 CASE LÀ 1 CHỨC NĂNG								
	{
	case 0: exit(0); break;
	case 1: output_array(a, n); break;
	case 2: cout << "nhap so can tim: "; cin >> key; cout<<serch(a, n, key); break;
	case 3: cout << sum_even_array(a, n); break;
	case 4: cout << count_prime(a, n); break;
	case 5: cout << check_array_even(a, n); break;
	case 6: cout << check_array_prime(a, n); break;
	case 7: cout << check_array_raise(a, n); break;
	case 8: cout << count1(a, n); break;
	case 9: cout << sum_not_prime(a, n); break;
	case 10:cout << "nhap so can kiem tra: "; cin >> key; cout << times_appear_array(a, n, key); break;
	case 11: cout << compare_even_odd(a, n); break;
	case 12: cout << count2(a, n); break;
	case 13: cout << count3(a, n); break;
	case 14: cout << count4(a, n); break;
	case 15: cout << count5(a, n); break;
	case 16:cout << "nhap so can kiem tra: "; cin >> key; cout << locate_final_x(a, n, key); break;
	case 17: cout << locate_first_prime(a, n); break;
	case 18: cout << min_of_array(a, n); break;
	case 19: cout << min_positive_of_array(a, n); break;
	case 20: cout << "nhap so can kiem tra: "; cin >> key; cout << furthest_x(a, n, key); break;
	case 21: cout << "nhap so can kiem tra: "; cin >> key; cout << nearest_x(a, n, key); break;
	case 22: cout << first_element_has_final_digit_odd(a, n); break;
	case 23: plit_prime_to_array(a, n); break;
	case 24:cout << "nhap vi tri can xoa: "; cin >> index; del(a, index, n); output_array(a, n); break;
	case 25: plit_array_3(a, n); break;
	case 26: inter_sort_up(a, n); break;
	case 27: input_array(b, m); merge_sort_down(a, b, n, m); break;
	case 28: input_array(b, m); merge_sort_up(a, b, n, m); break;
	case 29: inter_sort_down(a, n); break;
	case 30: sort1(a, n); break;
	case 31: sort2(a, n); break;
	case 32: sort3(a, n); break;
	case 33: sort4(a, n); break;
	case 34: cout << "nhap phan tu can chen: "; cin >> val; cout << "nhap vi tri can chen: "; cin >> pos; insert(a, n, pos, val); output_array(a, n); break;
	case 35: cout << "nhap so can chen: "; cin >> x; insert_num_next_pirme(a, n, x); break;
	case 36:cout << "nhap so thay the: "; cin >> x; fix_prime_to_x(a, n, x); break;
	case 37: cout << "nhap so can xoa: "; cin >> x; del_all_x(a, n, x); break;
	case 38: cout << "nhap so can chen: "; cin >> x; insert_x_unchange_up_array(a, n, x); break;
	case 39: inter_sort_down(a, n); break;
	case 40: appear_digit_in_array(a, n); output_array(num, n); break;
	case 41: digit_appear_min(a, n); break;
	case 42: digit_disappear_array(a, n); break;
	case 43:cout << gcd_array(a, n); break;
	case 44: cout << lcm_array(a, n); break;
	}
	cout << endl;
	return 0;
}