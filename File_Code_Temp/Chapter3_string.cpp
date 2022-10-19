#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string.h>
//#include "functionsBasic.h"
using namespace std;
//COMMENT 1 ĐOẠN CODE: BÔI ĐEN ĐOẠN CODE --> ẤN CTRL + K + C
//UNCOMMENT 1 ĐOẠN CODE: BÔI ĐEN ĐOẠN CODE --> ẤN CTRL + K + U
char upper(char ch)
{
	//đổi ký tự chữ ra chữ hoa, các ký tự khác giữ nguyên
	if (ch >= 'a' && ch <= 'z')
	{
		ch -= 32;
	}
	return ch;
}
char lower(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		ch += 32;
	}
	return ch;
	
}
int str_lenght(char *s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		++i;
	}
	return i;
}
void str_lw(char s[])
{
	int len = str_lenght(s);
	for (int i = 0; i < len; ++i)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
	}
	//out << s << endl;
}
void str_upper(char s[])
{
	int len = strlen(s);
	for (int i = 0; i < len; ++i)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
	}
	//cout << s << endl;
}
void proper(char s[])
{
	int len = strlen(s);
	s[0] = upper(s[0]);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == ' ')
		{
			s[i+1]=upper(s[i + 1]);
		}
	}
	//cout << s << endl;
}
void output_word(char* s)
{
	int lenght = strlen(s);
	for (int i = 0; i < lenght; ++i)
	{
		if (s[i] != ' ')
		{
			cout << s[i];
		}
		else
		{
			if (s[i] == ' ')
			{
				cout << endl;
			}
		}
	}
}
void word_longest(char* s)
{
	int len = strlen(s);// chiều dài của chuỗi
	char temp[20]={};//chuỗi tạm để lưu từ cần kiểm tra
	int j = 0;// chỉ số của chuỗi temp
	char result[40]={};// chuỗi lưu kết quả
	int maxlenght = 0;
  	for (int i = 0; i <= len; ++i)
	{
		if (s[i] != ' ' && s[i] != '\0')
		{
			temp[j++] = s[i];// khi ký tự thứ i của s[] khác ký tự trống thì gán ký tự đó vào temp[] và j+1
		}
		else
		{
			temp[j] = '\0';// chuẩn hóa lại chuỗi tạm
			if (strlen(temp) > maxlenght)
			{
				strcpy(result, temp);// coppy toàn bộ temp vào result
				maxlenght = strlen(temp);
			}
			j = 0;// bắt đầu lại từ đầu
		}
	}
	output_word(result);// xuất từ có độ dài lớn nhất
}
void standard_string(char* s)
{
	// chuẩn chuỗi --> vd có chuỗi "   TrAn    hOaNg   hUy    " --> "Tran Hoang Huy"
	int len = strlen(s);
	while (s[0] == ' ')//  xóa ký tự thừa ở đầu chuỗi
	{
		strcpy(s, s + 1);
	}
	while (s[len - 1] == ' ') // xóa ký tự thừa ở cuối
	{
		len--;
		s[len] = '\0';
	}
	for (int i = 0; i < len; ++i)// xóa giữa
	{
		
		if (s[i] == ' ' && s[i+1] == ' ')
		{
			for (int j = i; j < len; ++j)
			{
				s[j] = s[j + 1];
			}
			--i;
		}
	}
	str_lw(s);
	s[0]=upper(s[0]);
	for (int i = 1; i < len; ++i)
	{
		if (s[i] == ' ')
		{
			s[i+1]=upper(s[i + 1]);
		}
	}
	cout << s;
}
int search_char(char* s, char x)
{
	int index = 0;
	while (s[index] != x)
	{
		++index;
	}
	return index;
}
void del_one_char(char* s, int pos)
{
	int len = strlen(s);
	for (int i = pos; i < len; ++i)
	{
		s[i] = s[i + 1];
	}
	len--;
	s[len] = '\0';
}
char* del_right(char* s, int len)
{
	int len_s = strlen(s);
	s[len_s - len] = '\0';
	return s;
}
char* del_left(char* s, int len)
{
	while (len>0)
	{
		strcpy(s, s + 1);
		len--;
	}
	return s;
}
void del_all_char_x(char* s, char x)
{
	int len = strlen(s);
	for (int i = 0; i < len; ++i)
	{
		if (s[i] == x)
		{
			del_one_char(s, i);
			i--;
		}
	}
	//cout << s;
}
char* del_char_at_pos(char* s, char x, int pos)
{
	int len = strlen(s);
	for (int i = pos; i < len; ++i)
	{
		if (s[i] == x)
		{
			del_one_char(s,i);
			i--;
		}
	}
	return s;
}
char* del_len_char_at_pos(char* s, int pos, int len)
{
	int lenght = strlen(s);
	if (pos >= lenght)
	{
		return s;
	}
	else
	{
		if (pos + len > lenght)
		{
			len = lenght - pos;//khi số lượng ký tự cần xóa tại pos > chiều dài chuỗi ---> số lượng ký tự cần xóa = từ vị trí xóa cho hết chuỗi
		}
		for (int i = 0; i <= lenght-pos-len; ++i) // i chạy từ 0--> khi bằng số lượng ký tự còn lại tính từ vị trí len
		{
			s[pos+i] = s[pos+len+i];
		}
		return s;
	}
}
void insert(char* s, char ch, int pos)
{
	int len = strlen(s);
	for (int i = len; i > pos; --i)
	{
		s[i] = s[i - 1];
	}
	s[pos] = ch;
}
char* insert_subs(char* s, char* subs, int pos)
{
	int len_subs = strlen(subs);
	int j=0;
	for (int i = pos; i < len_subs + pos; i++)
	{
		insert(s, subs[j++], i);
	}
	return s;
}
char* str_cut_left(char* s, int len)
{
	char* result= new char[40];
	for (int i = 0; i <= len; ++i)
	{
		result[i] = s[i];
	}
	result[len] = '\0';
	return result;
}
char* str_cut_right(char* s, int len)
{
	char* result = new char;
	int len_s = strlen(s),j=0;
	for (int i = len_s-len; i < len_s ; i++)
	{
		result[j++] = s[i];
	}
	result[len] = '\0';
	return result;
}
char* str_cut_mid(char* s, int pos, int len)
{
	char* result = new char[40];
	if (pos == 0)
	{
		str_cut_left(s, len);
	}
	else
		if (pos + len == strlen(s))
		{
			str_cut_right(s, len);
		}
		else
		{
			for (int i = 0; i <= len; ++i)
			{
				result[i] = s[i + pos];
			}
			result[len] = '\0';
			return result;
		}
}
char* str_cut_mid_reverse(char* s, int pos, int len)
{
	char* result = new char[40];
	for (int i = 0; i <= len; ++i)
	{
		result[i] = s[pos+len-i-1];
	}
	result[len] = '\0';
	return result;
}
// SYNTAX CREATE DYNAMIC ARRAY OF CHAR: char *<nameOfArray>=new char[<widthOfArray>]
int main()
{
	//char s[100] = "Tran Hoannnng Huynnn";
	char s[100] = "abcd efgh klm 123";
	//char subs[40] = "abcdefed";
	//char s[40];
	//cout << str_lenght(s) << endl;
	//str_lw(s);
	//output_word(s);
	/*cout << "Nhap chuoi: ";
	cin.getline(s, 40);*/
	//word_longest(s);
	//str_lw(s);
	//str_upper(s);
	//standed_string(s);
	//del_all_char_x(s, 'n');
	//cout<<del_right(s, 5);
	//cout<<del_left(s, 5);
	//cout<<del_char_at_pos(s, 'n',8);
	//cout << del_len_char_at_pos(s, 8, 3);
	//cout << insert(s, 'h', 5);
	//cout << insert_subs(s, subs, strlen(s));
	//cout << str_cut_left(s, 10);
	//cout << str_cut_right(s, 6);
	//cout << str_cut_mid(s, 3,6);
	//cout << str_cut_mid_reverse(s, 2,10);
	proper(s);
	//cout << s;
	cout << endl;
	return 0;
}