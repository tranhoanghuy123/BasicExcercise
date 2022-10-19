#define _CRT_SECURE_NO_WARNINGS
#include "Methods.h"
//COMMENT 1 ĐOẠN CODE: BÔI ĐEN ĐOẠN CODE --> ẤN CTRL + K + C
//UNCOMMENT 1 ĐOẠN CODE: BÔI ĐEN ĐOẠN CODE --> ẤN CTRL + K + U
void excercise1(char ch)
{
	/*1. Nhập vào một kí tự. Hỏi kí tự đó có phải là chữ cái không? Nếu là chữ cái thì là
	chữ cái thường hay chữ in hoa ?*/
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
	{
		if (ch >= 'A' && ch <= 'Z')
		{
			cout << "Day la ky tu Hoa \n";
		}
		if (ch >= 'a' && ch <= 'z')
		{
			{
				cout << "Day la ky tu thuong \n";
			}
		}
	}
	else
		cout << "Day khong phai la chu cai! \n";
}
//EXCERCISE 2
bool isSquareNumber(int n)
{
	int temp = sqrt(n);
	if (temp * temp == n)
	{
		return true;
	}
	return false;
}
bool isPrime(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return n > 1;
}
bool isPerfectNumber(int n)
{
	// Số hoàn chỉnh là 1 số có tổng các ước ngoài trừ chính nó = chính nó
	// EXAMPLE: 6 có các ước là 1 2 3 6 --> 1+2+3 = 6 --> là số hoàn chỉnh
	int sumOfdivisors = 0; // biến chứa tổng các ước
	for (int i = 1; i < n; i++)
		if(n%i==0)
			sumOfdivisors += i;
	return (n == sumOfdivisors);
}
bool isSymmetry(int n)
{
	//kiểm tra n có phải là số đối xứng hay ko?
	// số nguyên n gọi là số đối xứng nếu đọc từ trái qua phải, hay từ phải qua trái đều được số giống nhau.ví dụ : 11, 121, 101 là các số đối xứng.
	int sum = 0, mod, temp;
	for (temp = n; n != 0; n = n / 10)
	{
		mod = n % 10;
		sum = sum * 10 + mod;
	}
	if (sum == temp)
		return 1;
	return 0;
}
int findMaxDigit(int n)
{
	int mod, max = n % 10;
	while (n != 0)
	{
		mod = n % 10;
		if (mod > max)
			max = mod;
		n /= 10;
	}
	return max;
}
int sum_digit_odd(int n)
{
	int mod, sum = 0;
	while (n != 0)
	{
		mod = n % 10;
		if (mod %2 !=0)
			sum+=mod;
		n /= 10;
	}
	return sum;
}
bool isFullDigitEven(int n)
{
	int count1 = 0, count2 = 0;// count1: là biến đếm số lượng chữ số của n, count2 là biến đếm chữ số chẵn
	while (n != 0)
	{
		if ((n % 10) % 2 == 0)
			count2++;
		count1++;
		n /= 10;
	}
	return count1 == count2 ? true : false;
}
int natureOfNumber(int n)// kiểm tra chữ số tăng hay giảm hay kh tăng kh giảm
{
	//Quy ước: 1: tăng dần, -1: kh tăng kh giảm, 0: giảm dần
	int mod1, mod2;
	bool flag = true;// cờ này kiểm tra xem có tăng hay kh? nếu kh tăng sẽ xảy ra 2TH: TH1(GIẢM) TH2(KH TĂNG KH GIẢM)
	bool flag1 = true;// cờ này kiểm tra xem có giảm hay kh?
	while (n != 0)
	{
		mod1 = n % 10;
		n /= 10;
		mod2 = n % 10;
		if (mod1 < mod2)
			flag = false;
		if(mod1 > mod2 && n%10 !=0) // IMPORTANT: (n%10 !=0) bởi vì nếu lấy tới số đầu tiên là mod1 --> số mod2 sẽ là 0 --> kết quả sai
			flag1 = false;
	}
	if (flag)
		return 1;
	if (flag1)
		return 0;
	return -1;
}
//EXCERCISE 3
int sum(int n) // a.S = 1 + 2 + 3 + ... + n
{
	return n * (n + 1) / 2;// dùng công thức
}
double sum1(int n) //b. S=1/1+1/2+...+1/n
{
	double sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += 1.0 / i;
	}
	return sum;
}
int factorial(int n) //c. P=1*2*3*..n
{
	int result = 0;
	for (int i = 1; i <= n; i++)
		result *= i;
	return result;
}
int sumFactorial(int n)// d. S=1!+2!+... n!
{
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		result += factorial(i);
	}
	return result;
}
int sumEvenNumber(int n) //e. S=2+4+6...+k (k=n-1 nếu n lẻ và bằng n nếu n chẵn)
{
	int result = 0;
	for (int i = 2; i <= n; i += 2)
	{
		result += i;
	}
	return result;
}
double sum2(int n) //f. S=1/1+1/3+1/5...+1/k (k=n nếu n lẻ và bằng n+1 nếu n chẵn)
{
	double result = 0;
	for (int i = 1; i <= n; i += 2)
		result += 1.0 / i;
	return result;
}
double sum3(int n) //g.S = sqrt(1 ^ 2 + 2 ^ 2 + ...n ^ 2))
{
	double result = 0;
	for (int i = 1; i <= n; i++)
		result += i * i;
	return sqrt(result) * 1.0;
}
double sum4(int n) //h. S=sqrt(3+sqrt(3+sqrt(3+...+sqrt(3)))
{
	double result = 0;
	for (int i = 1; i <= n; i++)
	{
		result = sqrt(result +3);
	}
	return result * 1.0;
}
//double sum5(int n) //i. S=sqrt(1+sqrt(2+sqrt(3+...+sqrt(n)))
//{
//	/*double result = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		
//	}
//	return result;*/
//}
//EXCERCISE 7
void printPrimeLessN(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (isPrime(i))
			cout << i << " ";
	}
	cout << endl;
}
int sumPrimeLessN(int n)
{
	int sum = 0;
	for (int i = 2; i < n; i++)
	{
		if (isPrime(i))
			sum += i;
	}
	return sum;
}
void printNPrime(int n)
{
	int count = 0,  index = 2;
	while (count < n)
	{
		if (isPrime(index))
		{
			cout << index << " ";
			count++;
		}
		index++;
	}
}
int sumNprime(int n)
{
	int sum = 0, index = 2,count =0;
	while (count < n)
	{
		if (isPrime(index))
		{
			sum += index;
			count++;
		}
		index++;
	}
	return sum;
}
//EXCERCISE 8
void printAllPerfectNumberLessN(int n)
{
	for (int i = 6; i < n; i++)
	{
		if (isPerfectNumber(i))
		{
			cout << i << " ";
		}
	}
	cout << endl;
}
//EXCERCISE 9
void ex9()
{
	//In ra màn hình tất cả các số nguyên trong phạm vi từ 10->99 sao cho tích của 2
	//	chữ số bằng 2 lần tổng của chúng
	for (int i = 10; i < 100; i++)
	{
		if(((i %10)*(i/10) == (i%10+i/10)*2))
			cout<<i<<" ";
	}
}
//EXCERCISE 10
int gcd_C2(int a, int b)
{
	a = abs(a);
	b = abs(b);
	// thuật toán dùng đệ quy
	return (b == 0) ? a : gcd(b, a % b); // toán tử bậc 3 (ternary operator)
}
//EXCERCISE 11
int lcm_C2(int a, int b)
{
	return (a / gcd(a, b)) * b;
}
//EXCERCISE 12
int calculateFibo(int n)// tính số fibo thứ n
{
	//dùng công thức tính
	double phi = (1 + sqrt(5)) / 2.0;
	return round(pow(phi, n) / sqrt(5));
}
void printFibo(int n) // in n số fibo đầu tiên
{
	for (int i = 0; i < n; i++)
	{
		cout << calculateFibo(i)<<" ";
	}
	cout << endl;
}
int sumFibo(int n) // tổng n số fibo đầu tiên
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum+= calculateFibo(i);
	}
	return sum;
}
//EXCERCISE 13

int main()
{
	//char ch; // biến ký tự đầu vào
	/*cout << "Nhap vao ky tu: "; cin >> ch;
	excercise1(ch);*/

	//EXCERCISE 2
	/*int n;
	do
	{
		cout << "Nhap n = "; cin >> n;
		if (n <= 0)
			cout << "Gia tri khong hop le. Nhap lai!\n";
	} while (n<=0);*/
	////cout << isSquareNumber(n);
	////cout << isPrime(n);
	////cout << isSymmetry(n);
	////cout << findMaxDigit(n);
	////cout << natureOfNumber(n);

	//EXCERCISE 3
	//cout << sum(n);
	//cout << sum1(n);
	//cout << factorial(n);
	//cout << sumFactorial(n);
	//cout << sumEvenNumber(n);
	//cout << sum2(n);
	//cout << sum3(n);
	//cout << sum4(n);
	//cout << sum5(n);


	//EXCERCISE 7
	//printPrimeLessN(n);
	//cout << sumPrimeLessN(n);
	//printNPrime(n);
	//cout << sumNprime(n);

	//EXCERCISE 8
	//printAllPerfectNumberLessN(n);

	//EXCERCISE 9
	//ex9();

	//EXCERCISE 10
	//cout << gcd_C2(10, 8);

	//EXCERCISE 11
	//cout << lcm_C2(6969, 9669);

	//EXCERCISE 12
	//cout << calculateFibo(10);
	//printFibo(15);
	//cout << sumFibo(15);

	//EXCERCISE 13



	cout << endl;
	return 0;
}