#define _CRT_SECURE_NO_WARNINGS
#include"Methods.h"//DAY LA FILE HEADER TU DINH NGHIA BAO GOM NHUNG FUNCTION & THU VIEN CAN THIET
//COMMENT 1 ĐOẠN CODE: BÔI ĐEN ĐOẠN CODE --> ẤN CTRL + K + C
//UNCOMMENT 1 ĐOẠN CODE: BÔI ĐEN ĐOẠN CODE --> ẤN CTRL + K + U
struct Student
{
	char id[11];
	char name[51];
	char birthDay[13];
	float math, physic, chemist, sum;
};
void input_1_student(Student& stu)
{
	//Khong nhap ma truoc vi de xu ly ma khongg trung nhau
	cout << "Nhap ten sinh vien: "; cin.getline(stu.name, 51); 
	standard_string(stu.name);
	cout << "Nhap ngay sinh: "; cin.getline(stu.birthDay, 13);
	do
	{
		cout << "Nhap diem toan: "; cin >> stu.math;
	} while ((stu.math < 0 || stu.math >10));
	do
	{
		cout << "Nhap diem ly: "; cin >> stu.physic;
	} while ((stu.physic < 0 || stu.physic >10));
	do
	{
		cout << "Nhap diem hoa: "; cin >> stu.chemist;
	} while ((stu.chemist < 0 || stu.chemist >10));
	cin.ignore();
	stu.sum = stu.math + stu.physic + stu.chemist;
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
void input_list_student(Student a[], int lenght)
{
	char tempId[11];
	for (int i = 0; i < lenght; i++)
	{
		do
		{
			cout << "Nhap ma sinh vien: "; cin.getline(tempId, 11);
			if (search_with_id(a, lenght, tempId) != -1)
			{
				cout << "Ma bi trung moi nhap lai! \n";
			}
		} while (search_with_id(a, lenght, tempId) != -1);
		strcpy(a[i].id, tempId);
		input_1_student(a[i]);
	}
}
void title()
{
	cout << setw(6) << left << "STT" << setw(15) << left << "Ma sinh Vien" << setw(30) << left << "Ho Va Ten Sinh Vien" << setw(15) << left << "Ngay sinh" << setw(10) << left << "Toan" << setw(10) << left << "Ly" << setw(10) << left << "Hoa" << setw(10) << left << "Diem Tong" << endl;
}
void ouput_1_student(Student stu)
{
	// HÀM NÀY TRONG FILE HEADER
	cout << setw(15) << left << stu.id << setw(30) << left << stu.name << setw(15) << left << stu.birthDay << setw(10) << left << stu.math << setw(10) << left << stu.physic << setw(10) << left << stu.chemist << setw(10) << left << stu.sum << endl;
}
void output_list_student(Student a[], int lenght)
{
	title();
	for (int i = 0; i < lenght; i++)
	{
		cout << setw(6) << left << i + 1;
		ouput_1_student(a[i]);
	}
}
void sorting_point_sum(Student a[], int lenght)
{
	for (int i = 0; i < lenght - 1; i++)
	{
		for (int j = i + 1; j < lenght; j++)
		{
			if (a[i].sum > a[j].sum)
			{
				swap(a[i], a[j]);
			}
		}
	}
}
//void sorting_id(Student a[], int lenght) // sắp xếp tăng dần theo mã (viết thêm không có trong đề)
//{
//	for (int i = 0; i < lenght - 1; i++)
//	{
//		for (int j = i + 1; j < lenght; j++)
//		{
//			if (strcmp(a[i].id,a[j].id) > 0)
//			{
//				swap(a[i], a[j]);
//			}
//		}
//	}
//}
//void del_student(Student a[], int& lenght, int pos)
//{
//	//XÓA 1 HỌC SINH TẠI VỊ TRÍ BẤT KỲ
//	for (int i = pos; i < lenght; i++)
//	{
//			a[i] = a[i + 1];
//	}
//	--lenght;
//}
void del_student_with_id(Student a[], int &lenght, char* id)
{
	int pos = search_with_id(a, lenght, id);
	if ( pos != -1)
	{
		del<Student>(a, pos,lenght);// đây là hàm định nghĩa trong file header
	}
	else
	{
		cout << "Khong ton tai sinh vien! \n";
	}
}
void insert_student(Student a[], int &lenght, int pos)
{
	char idCheck[11];
	if (pos == lenght ) // TRƯỜNG HỢP THÊM CUỐI
	{
		++lenght;
		do
		{
			cout << "Nhap ma sinh vien: "; cin.getline(idCheck, 11);
			if (search_with_id(a, lenght, idCheck) != -1)
			{
				cout << "Ma bi trung moi nhap lai! \n";
			}
		} while (search_with_id(a, lenght, idCheck) != -1);
		 strcpy(a[pos].id, idCheck);
		 input_1_student(a[pos]);
		 /*cout << "\n Them Cuoi Thanh Cong! \n";*/ // CAI NAY CHI LA TEST XEM CO CHAY KH THOI :))
	}
	else
	{
		++lenght;
		for (int i = lenght - 1; i > pos; i--)
		{
			a[i] = a[i - 1];
		}
		do
		{
			cout << "Nhap ma sinh vien: "; cin.getline(idCheck, 11);
			if (search_with_id(a, lenght, idCheck) != -1)
			{
				cout << "Ma bi trung moi nhap lai! \n";
			}
		} while (search_with_id(a, lenght, idCheck) != -1);
		strcpy(a[pos].id, idCheck);
		input_1_student(a[pos]); 
	}
}
//Fix INFORMATION OF STUDENT!
void fix_id_student(Student a[],int lenght,int pos)
{
	char idFix[11];
	do
	{
		cout << "Nhap ma can sua lai: "; cin.getline(idFix, 11);
		if(search_with_id(a, lenght, idFix) != -1)
		{
			cout << "Ma bi trung moi nhap lai! \n";
		}
	} while (search_with_id(a, lenght, idFix) != -1);
	strcpy(a[pos].id, idFix);
	cout << "\nSua thanh cong!\n";
}
void fix_name_student(Student a[], int pos)
{
	char name[50];
	cout << "Nhap ten can sua lai: "; cin.getline(name, 50);
	strcpy(a[pos].name, name);
	cout << "\nSua thanh cong!\n";
}
void fix_birthDay_student(Student a[], int pos)
{
	char birthDay[13];
	cout << "Nhap ngay sinh can sua lai: "; cin.getline(birthDay, 13);
	strcpy(a[pos].birthDay, birthDay);
	cout << "\nSua thanh cong!\n";
}
void fix_point_student(Student a[], int pos)
{
	int selectFix;
	char check;
	cout << "=========================================\n\n"; // có thể viết cout<< setw(<so luong ky tu can in>) << setfill('<ky tu can in>') << "" <<endl; IMPORTANT: phải thêm (<< "")
	cout << setw(20) << left << "1.Sua diem Toan" << "2.Sua diem Ly\n\n";
	cout << setw(20) << left << "3.Sua diem Hoa" << "4.Thoat chuong trinh\n\n";
	cout << "=========================================\n\n";
	do
	{
		cout << "Nhap lua chon cua ban: "; cin >> selectFix;
		switch (selectFix)
		{
		case 1:
			do
			{
				cout << "Nhap diem toan: "; cin >> a[pos].math;
			} while ((a[pos].math < 0 || a[pos].math >10)); break;
		case 2:
			do
			{
				cout << "Nhap diem ly: "; cin >> a[pos].physic;
			} while ((a[pos].physic < 0 || a[pos].physic >10)); break;
		case 3:
			do
			{
				cout << "Nhap diem hoa: "; cin >> a[pos].chemist;
			} while ((a[pos].chemist < 0 || a[pos].chemist >10)); break;
		case 4: exit(0); break;
		default:cout << "Du lieu khong bi sua! \n";
			break;
		}
		cout << "Ban muon sua diem tiep? Y/N ---> "; cin >> check;
		if (check != 'y' && check != 'Y')
		{
			cout << setw(20) << setfill(' ') << "" << "Ket thuc phan sua diem!" << endl;
		}
		cin.ignore();
	} while (check == 'Y' || check == 'y');
	
	a[pos].sum = a[pos].math + a[pos].physic + a[pos].chemist; //IMPORTANT: cập nhật lại điểm tổng
}
void fix_infor_student(Student a[], int lenght)
{
	int select,pos;
	char checkFix;
	cout << "=========================================\n\n";
	cout << setw(20) << left  << "1.Sua Ma sinh vien" << "2.Sua Ten Sinh vien \n\n";
	cout << setw(20) << left << "3.Sua Ngay Sinh" << "4.Sua Diem" <<"\n\n";
	cout << "=========================================\n\n";
	do
	{
		cout << "Nhap vi tri sinh vien can sua: "; cin >> pos;
		if (pos >= lenght || pos < 0)
			cout << "Vi tri sua khong hop le. Moi ban nhap lai!\n";
	} while (pos >= lenght || pos < 0);
	do
	{
		cout << "Nhap Lua chon cua ban: "; cin >> select; cin.ignore();
		switch (select)
		{
		case 1:fix_id_student(a, lenght, pos); break;
		case 2:fix_name_student(a, pos); break;
		case 3:fix_birthDay_student(a, pos); break;
		case 4:fix_point_student(a, pos); break;
		default:cout << "Chuong trinh khong thay doi!\n";
			break;
		}
		cout << "Ban muon sua tiep? Y/N ---> "; cin >> checkFix;
		if (checkFix != 'y' && checkFix != 'Y')
		{
			cout <<setw(20)<<setfill(' ')<<""<<"Ket thuc phan sua thong tin!"<<endl;
		}
		cin.ignore();
	} while (checkFix=='Y'|| checkFix=='y');
	ouput_1_student(a[pos]);
}
void print_menu()
{
	cout << "------------------------------------------------------------------\n";
	cout << "|                            MENU                                |\n";
	cout << "------------------------------------------------------------------\n";
	cout << setw(26) << left << "|1.Nhap/Xuat danh sach" <<setw(4)<<left<<"|"<<"2.Sap xep danh sach theo diem tong |\n";
	cout << "------------------------------------------------------------------\n";
	cout << setw(26) << left << "|3.Tim Sinh Vien theo ma" <<setw(4) << left << "|" <<"4.Xoa Sinh vien theo ma            |\n";
	cout << "------------------------------------------------------------------\n";
	cout << setw(26) << left << "|5.Them 1 Sinh vien" << setw(4) << left << "|" << "6.Sua thong tin Sinh vien          |\n";
	cout << "------------------------------------------------------------------\n";
}
int main()
{
	Student a[10];
	char *id=new char[11];
	char checkCont;// variable checkCont mean is check continue!
	int lenght,pos,select,temp;
	cout << "Nhap So luong sinh vien: "; cin >> lenght;
	cin.ignore();
	input_list_student(a, lenght);
	cout << endl;
	do
	{
		system("CLS");
		print_menu();
		cout << "Nhap lua chon cua ban: "; cin >> select;
		switch (select)
		{
		case 1:output_list_student(a, lenght); break;
		case 2:sorting_point_sum(a, lenght); /*sorting_id(a, lenght);*/ output_list_student(a, lenght); break;
		case 3:cin.ignore(); cout << "Nhap ma can xu ly: "; cin.getline(id, 11);  temp = search_with_id(a, lenght, id);
			if (temp != -1)
			{
				ouput_1_student(a[temp]);
			}
			else
			{
				cout << "Khong Ton Tai Sinh Vien Can Tim!\n";
			}
			break;
		case 4:cin.ignore(); cout << "Nhap ma can xu ly: "; cin.getline(id, 11); del_student_with_id(a, lenght, id); output_list_student(a, lenght); break;
		case 5:cout << "Nhap vi tri can them: "; cin >> pos; cin.ignore(); insert_student(a, lenght, pos); output_list_student(a, lenght); break;
		case 6:fix_infor_student(a, lenght); break;
		}
		cout << "Ban muon tiep tuc chuong trinh? An Y/N ---> "; cin >> checkCont;
		if (checkCont != 'y' && checkCont != 'Y')
		{
			cout << endl;
			cout << setw(35) << setfill(' ') << "" <<"DAY LA DANH SACH CUOI CUNG!"<<endl;
			cout << endl;
			output_list_student(a, lenght);
		}
		cin.ignore();
	} while (checkCont == 'Y' || checkCont == 'y');
	cout << endl;
	delete[11] id;
	return 0;
}