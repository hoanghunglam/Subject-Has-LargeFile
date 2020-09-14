#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include"LibGraph.h"
typedef struct{
	char ten[30];
	long MaSV;
	int ng,th,n;
	char lop[30];
	int diem;
}SinhVien;
typedef struct{
	char ten[30];
	char MaSV[10];
	char ngay[15];
	char lop[15];
	char diem[5];
	char temp[40];
}Data;
typedef struct{
	char malop[15];
	int xs;
	int g;
	int k;
	int tb;
	int yeu;
	int tong;
}ThongKe;
void ControlIn(); void ControlOut(char *,char *); void ControlArrangement(); void ControlSearch(); void ControlStatistics(); void ControlNoti(SinhVien *data);
void Manage(); void ReturnGDNhap();
void ThemHoSo(SinhVien *data); void Input(SinhVien *data); void PrintData(char *tenfile, int i, int k);
void SXMaSV(); void SXDiem(); void SXTen(); void SXMaLop(); void SXNgaySinh();
void TimKiemTen(); void TimKiemMaSV(); void TimKiemLop(); void TimKiemNgaySinh(); void TimKiemDiem();
void ThongKeSinhVien(); void InDuLieuThongKe(int, int);
void Frame(int cot,int dong){ //Tao Khung
	gotoxy(cot,dong-1);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	gotoxy(cot,dong);
	printf("");
	gotoxy(cot,dong+1);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}
void FrameNho(int cot, int dong){
	gotoxy(cot,dong-1);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,187);
	gotoxy(cot,dong);
	printf("");
	gotoxy(cot,dong+1);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,188);	
}
void DongKeNgang(int x, int y){//35 characters
	gotoxy(x,y);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
}
void KeDoc(int x1,int y1,int y2){//Toa do x1 dai bat dau tu dong thu y1 den y2
	for(int i=y1;i<y2;i++){
		gotoxy(x1,i);
		printf("%c",179);
	}
}
void DeleteAtPos(int ToaDoX1,int ToaDoX2,int ToaDoY1,int ToaDoY2){
	for(int i=ToaDoY1;i<=ToaDoY2;i++)
		for(int j=ToaDoX1;j<=ToaDoX2;j+=6){
			SetBGColor(11);
			gotoxy(j,i);
			printf("      ");
		}
}
void GD(){
	system("cls");
	gotoxy(1,1);
	printf("\t\t\t\t\t   BO MON: THUC TAP KY THUAT LAP TRINH");
	gotoxy(40,3);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%cMENU%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196
	,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	
	gotoxy(48,5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
		
	SetBGColor(9);
	Frame(8,9);
	gotoxy(8,9);
	printf("%c  NHAP DU LIEU  %c",186,186);
	
	Frame(30,9);
	gotoxy(30,9);
	printf("%c  XUAT DU LIEU  %c",186,186);
	
	Frame(52,9);
	gotoxy(52,9);
	printf("%c    SAP XEP     %c",186,186);
	
	Frame(74,9);
	gotoxy(74,9);
	printf("%c    TIM KIEM    %c",186,186);
	
	Frame(96,9);
	gotoxy(96,9);
	printf("%c   THONG KE     %c",186,186);
}
void GDNhap(){
	gotoxy(33,3);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%cNHAP HO SO SINH VIEN%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196
	,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	
	gotoxy(48,5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);

	gotoxy(42,12);
	printf("%c",218);
	gotoxy(42,27);
	printf("%c",192);
	
	KeDoc(42,13,27);
	KeDoc(55,13,27);
	KeDoc(78,13,27);
	
	DongKeNgang(43,12);
	gotoxy(43,14); printf("Ho Va Ten");
	DongKeNgang(43,15);
	gotoxy(43,17); printf("Ma SV");
	SetTeColor(7); gotoxy(59,17); printf("1515xxxx");
	SetTeColor(16);DongKeNgang(43,18);
	gotoxy(43,20); printf("Lop");
	DongKeNgang(43,21);
	gotoxy(43,23); printf("Ngay Sinh");
	SetTeColor(7); gotoxy(59,23); printf("VD: 17 6 1997");
	SetTeColor(16);
	DongKeNgang(43,24);
	gotoxy(43,26); printf("Diem TB");
	SetTeColor(7); gotoxy(59,26); printf("0 < diem < 10");
	SetTeColor(16);
	DongKeNgang(43,27);
	
	gotoxy(78,12);
	printf("%c",191);
	gotoxy(78,27);
	printf("%c",217);
	
	SetBGColor(9);
	Frame(42,31);
	gotoxy(42,31);
	printf("%c  THEM HO SO    %c",186,186);
	
	Frame(62,31);
	gotoxy(62,31);
	printf("%c QUAY LAI MENU  %c",186,186);
	SetBGColor(11);
	gotoxy(42,10); printf("Nhan ESC de THOAT. Nhan phim bat ki de NHAP");
}
void GDXuat(){
	gotoxy(33,3);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%cHIEN THI HO SO%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196
	,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	
	gotoxy(48,5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
	gotoxy(30,8);
	printf("Tong So Ho So: ");
	
	SetBGColor(11);
	gotoxy(30,11);
	printf("%c",218);
	gotoxy(30,29);
	printf("%c",192);
	
	KeDoc(30,12,29);
	DongKeNgang(31,11);DongKeNgang(66,11);
	gotoxy(31,13);
	printf("       Ho Va Ten");
	KeDoc(55,12,29);
	gotoxy(56,13);
	printf("   Ma SV");
	KeDoc(66,12,29);
	gotoxy(67,13);
	printf("   Lop");
	KeDoc(76,12,29);
	gotoxy(77,13);
	printf("  Ngay Sinh");
	KeDoc(90,12,29);
	gotoxy(91,13);
	printf(" Diem TB");
	KeDoc(101,12,29);
	
	gotoxy(101,11);
	printf("%c",191);
	gotoxy(101,29);
	printf("%c",217);
	
	DongKeNgang(31,14);DongKeNgang(66,14);
	DongKeNgang(31,17);DongKeNgang(66,17);
	DongKeNgang(31,20);DongKeNgang(66,20);
	DongKeNgang(31,23);DongKeNgang(66,23);
	DongKeNgang(31,26);DongKeNgang(66,26);
	DongKeNgang(31,29);DongKeNgang(66,29);
	
	SetBGColor(9);
	Frame(30,32);
	gotoxy(30,32);
	printf("%c      Prev      %c",186,186);
	
	Frame(56,32);
	gotoxy(56,32);
	printf("%c      Next      %c",186,186);
	
	Frame(82,32);
	gotoxy(82,32);
	printf("%c      Exit      %c",186,186);
}
void GDSapXep(){
	SetBGColor(9);
	Frame(52,13);
	gotoxy(52,13);
	printf("%c     SX Ten     %c",186,186);
	
	Frame(52,17);
	gotoxy(52,17);
	printf("%c    SX Ma SV    %c",186,186);
	
	Frame(52,21);
	gotoxy(52,21);
	printf("%c    SX Ma Lop   %c",186,186);
	
	Frame(52,25);
	gotoxy(52,25);
	printf("%c  SX Ngay Sinh  %c",186,186);

	Frame(52,29);
	gotoxy(52,29);
	printf("%c    SX Diem     %c",186,186);
	
	Frame(52,33);
	gotoxy(52,33);
	printf("%c     THOAT      %c",186,186);
}
void GDTimKiem(){
	SetBGColor(9);
	Frame(74,13);
	gotoxy(74,13);
	printf("%c  Tim Theo Ten  %c",186,186);
	
	Frame(74,17);
	gotoxy(74,17);
	printf("%c  Tim Theo Lop  %c",186,186);
	
	Frame(74,21);
	gotoxy(74,21);
	printf("%c  Tim Ngay Sinh %c",186,186);
	
	Frame(74,25);
	gotoxy(74,25);
	printf("%c   Tim Ma SV    %c",186,186);

	Frame(74,29);
	gotoxy(74,29);
	printf("%c  Tim Diem TB   %c",186,186);
	
	Frame(74,33);
	gotoxy(74,33);
	printf("%c     THOAT      %c",186,186);
}
void GDTimKiem2(){
	system("cls");
	system("color B0");
	gotoxy(34,3);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%cTIM KIEM SINH VIEN%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196
	,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	
	gotoxy(48,5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
	
	gotoxy(47,14);printf("Nhap noi dung ban muon tim kiem");
	DongKeNgang(45,16);DongKeNgang(45,19);
	KeDoc(44,17,19);KeDoc(80,17,19);
	gotoxy(44,16);printf("%c",218);
	gotoxy(44,19);printf("%c",192);
	gotoxy(80,16);printf("%c",191);
	gotoxy(80,19);printf("%c",217);
}
void GDThongKe(){
	system("cls");
	system("color B0");
	SetBGColor(11);
	gotoxy(33,3);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%cTHONG KE HO SO%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196
	,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	
	gotoxy(48,5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);

	gotoxy(29,9);
	printf("%c",218);
	gotoxy(29,30);
	printf("%c",192);
	gotoxy(100,9);
	printf("%c",191);
	gotoxy(100,30);
	printf("%c",217);
	
	KeDoc(29,10,30);
	KeDoc(40,9,30);
	KeDoc(50,9,30);
	KeDoc(60,9,30);
	KeDoc(70,9,30);
	KeDoc(80,9,30);
	KeDoc(90,9,30);
	KeDoc(100,10,30);
	
	DongKeNgang(30,9);DongKeNgang(65,9);
	DongKeNgang(30,12);DongKeNgang(65,12);
	DongKeNgang(30,15);DongKeNgang(65,15);
	DongKeNgang(30,18);DongKeNgang(65,18);
	DongKeNgang(30,21);DongKeNgang(65,21);
	DongKeNgang(30,24);DongKeNgang(65,24);
	DongKeNgang(30,27);DongKeNgang(65,27);
	DongKeNgang(30,30);DongKeNgang(65,30);
	
	gotoxy(30,11);printf("  Ma Lop  ");
	gotoxy(41,11);printf(" Xuat Sac");
	gotoxy(51,11);printf("  Gioi   ");
	gotoxy(61,11);printf("   Kha   ");
	gotoxy(71,11);printf(" T.Binh  ");
	gotoxy(81,11);printf("   Yeu   ");
	gotoxy(91,11);printf("  Tong   ");
	
	SetBGColor(9);
	Frame(30,32);
	gotoxy(30,32);
	printf("%c      Prev      %c",186,186);
	
	Frame(56,32);
	gotoxy(56,32);
	printf("%c      Next      %c",186,186);
	
	Frame(82,32);
	gotoxy(82,32);
	printf("%c      Exit      %c",186,186);
}
void GDThongBao(){
	DeleteAtPos(42,78,12,27);
	SetBGColor(11);
	
	KeDoc(37,13,27);
	KeDoc(38,16,26);
	KeDoc(87,13,27);
	KeDoc(86,16,26);
	DongKeNgang(38,12);
	DongKeNgang(52,12);
	DongKeNgang(39,15);
	DongKeNgang(51,15);
	DongKeNgang(38,27);
	DongKeNgang(52,27);
	DongKeNgang(39,26);
	DongKeNgang(51,26);
	
	gotoxy(37,12); printf("%c",218);
	gotoxy(37,27); printf("%c",192);
	gotoxy(87,12); printf("%c",191);
	gotoxy(87,27); printf("%c",217);
	
	gotoxy(38,15); printf("%c",218);
	gotoxy(38,26); printf("%c",192);
	gotoxy(86,15); printf("%c",191);
	gotoxy(86,26); printf("%c",217);
	gotoxy(60,14); printf("THONG BAO");
	gotoxy(50,17); printf("Chon co se luu ho so lai.");
	gotoxy(50,18); printf("Chon khong se nhap lai tu dau.");
	
	SetBGColor(9);
	FrameNho(45,22); FrameNho(65,22);
	gotoxy(45,22); printf("%c    CO     %c",186,186);
	gotoxy(65,22); printf("%c   KHONG   %c",186,186);
}
void DoiMauMenu(int X){
	switch (X){
		case 8:
			SetBGColor(12);
			Frame(8,9);
			gotoxy(8,9);
			printf("%c  NHAP DU LIEU  %c",186,186);
			
			SetBGColor(9);
			Frame(30,9);
			gotoxy(30,9);
			printf("%c  XUAT DU LIEU  %c",186,186);
			break;
		case 30:
			SetBGColor(9);
			Frame(8,9);
			gotoxy(8,9);
			printf("%c  NHAP DU LIEU  %c",186,186);
			
			SetBGColor(12);
			Frame(30,9);
			gotoxy(30,9);
			printf("%c  XUAT DU LIEU  %c",186,186);
			
			SetBGColor(9);
			Frame(52,9);
			gotoxy(52,9);
			printf("%c    SAP XEP     %c",186,186);
			break;
		case 52:
			SetBGColor(9);
			Frame(30,9);
			gotoxy(30,9);
			printf("%c  XUAT DU LIEU  %c",186,186);
			
			SetBGColor(12);
			Frame(52,9);
			gotoxy(52,9);
			printf("%c    SAP XEP     %c",186,186);
			
			SetBGColor(9);
			Frame(74,9);
			gotoxy(74,9);
			printf("%c    TIM KIEM    %c",186,186);
			break;
		case 74:
			SetBGColor(9);
			Frame(52,9);
			gotoxy(52,9);
			printf("%c    SAP XEP     %c",186,186);
			
			SetBGColor(12);
			Frame(74,9);
			gotoxy(74,9);
			printf("%c    TIM KIEM    %c",186,186);
			
			SetBGColor(9);
			Frame(96,9);
			gotoxy(96,9);
			printf("%c   THONG KE     %c",186,186);
			break;
		case 96:
			SetBGColor(9);
			Frame(74,9);
			gotoxy(74,9);
			printf("%c    TIM KIEM    %c",186,186);
			
			SetBGColor(12);
			Frame(96,9);
			gotoxy(96,9);
			printf("%c   THONG KE     %c",186,186);
			break;
	}
}
void DoiMauNhap(int X1){
	switch(X1){
		case 42:
			SetBGColor(12);
			Frame(42,31);
			gotoxy(42,31);
			printf("%c  THEM HO SO    %c",186,186);
	
			SetBGColor(9);
			Frame(62,31);
			gotoxy(62,31);
			printf("%c QUAY LAI MENU  %c",186,186);
			break;
		case 62:
			SetBGColor(9);
			Frame(42,31);
			gotoxy(42,31);
			printf("%c  THEM HO SO    %c",186,186);		
			
			SetBGColor(12);
			Frame(62,31);
			gotoxy(62,31);
			printf("%c QUAY LAI MENU  %c",186,186);
			break;
	}
}
void DoiMauXuat(int X2){
	switch(X2){
		case 30:
			SetBGColor(12);
			Frame(30,32);
			gotoxy(30,32);
			printf("%c      Prev      %c",186,186);
			
			SetBGColor(9);
			Frame(56,32);
			gotoxy(56,32);
			printf("%c      Next      %c",186,186);
			break;
		case 50:
			SetBGColor(9);
			Frame(30,32);
			gotoxy(30,32);
			printf("%c      Prev      %c",186,186);
			
			SetBGColor(12);
			Frame(56,32);
			gotoxy(56,32);
			printf("%c      Next      %c",186,186);
			
			SetBGColor(9);
			Frame(82,32);
			gotoxy(82,32);
			printf("%c      Exit      %c",186,186);
			break;
		case 70:
			SetBGColor(9);
			Frame(56,32);
			gotoxy(56,32);
			printf("%c      Next      %c",186,186);
			
			SetBGColor(12);
			Frame(82,32);
			gotoxy(82,32);
			printf("%c      Exit      %c",186,186);
			break;
	}
}
void DoiMauSapXep(int Y){
	switch(Y){
		case 12:
			SetBGColor(12);
			Frame(52,13);
			gotoxy(52,13);
			printf("%c     SX Ten     %c",186,186);
			
			SetBGColor(9);
			Frame(52,17);
			gotoxy(52,17);
			printf("%c    SX Ma SV    %c",186,186);
			break;
		case 16:
			SetBGColor(9);
			Frame(52,13);
			gotoxy(52,13);
			printf("%c     SX Ten     %c",186,186);
			
			SetBGColor(12);
			Frame(52,17);
			gotoxy(52,17);
			printf("%c    SX Ma SV    %c",186,186);
			
			SetBGColor(9);
			Frame(52,21);
			gotoxy(52,21);
			printf("%c    SX Ma Lop   %c",186,186);
			break;
		case 20:
			SetBGColor(9);
			Frame(52,17);
			gotoxy(52,17);
			printf("%c    SX Ma SV    %c",186,186);
			
			SetBGColor(12);
			Frame(52,21);
			gotoxy(52,21);
			printf("%c    SX Ma Lop   %c",186,186);
			
			SetBGColor(9);
			Frame(52,25);
			gotoxy(52,25);
			printf("%c  SX Ngay Sinh  %c",186,186);
			break;
		case 24:
			SetBGColor(9);
			Frame(52,21);
			gotoxy(52,21);
			printf("%c    SX Ma Lop   %c",186,186);
			
			SetBGColor(12);
			Frame(52,25);
			gotoxy(52,25);
			printf("%c  SX Ngay Sinh  %c",186,186);
			
			SetBGColor(9);
			Frame(52,29);
			gotoxy(52,29);
			printf("%c    SX Diem     %c",186,186);
			break;
		case 28:
			SetBGColor(9);
			Frame(52,25);
			gotoxy(52,25);
			printf("%c  SX Ngay Sinh  %c",186,186);
			
			SetBGColor(12);
			Frame(52,29);
			gotoxy(52,29);
			printf("%c    SX Diem     %c",186,186);
			
			SetBGColor(9);
			Frame(52,33);
			gotoxy(52,33);
			printf("%c     THOAT      %c",186,186);
			break;
		case 32:
			SetBGColor(9);
			Frame(52,29);
			gotoxy(52,29);
			printf("%c    SX Diem     %c",186,186);
			
			SetBGColor(12);
			Frame(52,33);
			gotoxy(52,33);
			printf("%c     THOAT      %c",186,186);
			break;
	}
}
void DoiMauTimKiem(int Y1){
	switch(Y1){
		case 12:
			SetBGColor(12);
			Frame(74,13);
			gotoxy(74,13);
			printf("%c  Tim Theo Ten  %c",186,186);
	
			SetBGColor(9);
			Frame(74,17);
			gotoxy(74,17);
			printf("%c  Tim Theo Lop  %c",186,186);
			break;
		case 16:
			SetBGColor(9);
			Frame(74,13);
			gotoxy(74,13);
			printf("%c  Tim Theo Ten  %c",186,186);
	
			SetBGColor(12);
			Frame(74,17);
			gotoxy(74,17);
			printf("%c  Tim Theo Lop  %c",186,186);
			
			SetBGColor(9);
			Frame(74,21);
			gotoxy(74,21);
			printf("%c  Tim Ngay Sinh %c",186,186);
			break;
		case 20:
			SetBGColor(9);
			Frame(74,17);
			gotoxy(74,17);
			printf("%c  Tim Theo Lop  %c",186,186);
			
			SetBGColor(12);
			Frame(74,21);
			gotoxy(74,21);
			printf("%c  Tim Ngay Sinh %c",186,186);
			
			SetBGColor(9);
			Frame(74,25);
			gotoxy(74,25);
			printf("%c   Tim Ma SV    %c",186,186);
			break;
		case 24:
			SetBGColor(9);
			Frame(74,21);
			gotoxy(74,21);
			printf("%c  Tim Ngay Sinh %c",186,186);
			
			SetBGColor(12);
			Frame(74,25);
			gotoxy(74,25);
			printf("%c   Tim Ma SV    %c",186,186);
			
			SetBGColor(9);
			Frame(74,29);
			gotoxy(74,29);
			printf("%c  Tim Diem TB   %c",186,186);
			break;
		case 28:
			SetBGColor(9);
			Frame(74,25);
			gotoxy(74,25);
			printf("%c   Tim Ma SV    %c",186,186);
			
			SetBGColor(12);
			Frame(74,29);
			gotoxy(74,29);
			printf("%c  Tim Diem TB   %c",186,186);
			
			SetBGColor(9);
			Frame(74,33);
			gotoxy(74,33);
			printf("%c     THOAT      %c",186,186);
			break;
		case 32:
			SetBGColor(9);
			Frame(74,29);
			gotoxy(74,29);
			printf("%c  Tim Diem TB   %c",186,186);
			
			SetBGColor(12);
			Frame(74,33);
			gotoxy(74,33);
			printf("%c     THOAT      %c",186,186);
			break;
	}
}
void DoiMauThongBao(int TB1){
	switch(TB1){
		case 111:
		SetBGColor(12);
		FrameNho(45,22); FrameNho(65,22);
		gotoxy(45,22); printf("%c    CO     %c",186,186);
		SetBGColor(9);
		FrameNho(65,22);
		gotoxy(65,22); printf("%c   KHONG   %c",186,186);
		break;
		
		case 112:
		SetBGColor(9);
		FrameNho(45,22); FrameNho(65,22);
		gotoxy(45,22); printf("%c    CO     %c",186,186);
		SetBGColor(12);
		FrameNho(65,22);
		gotoxy(65,22); printf("%c   KHONG   %c",186,186);
		break;
	}
}
void ControlMenu(){       //BAC 2, dieu khien Giao Dien BAC 1
	int x[5]={8,30,52,74,96};
	int X;
	int i=-1;
	char c;
	int dem =1;
	
	while(dem ==1){
		if(_kbhit()){
			c=getch();
			if(c==27)
				exit(1);
			if(c==75 || c==77){
				if(c==75){
					X=x[--i];
					if(i<0){
						i=0;
						X=x[0];
					}
				}
				else{
					X=x[++i];
					if(i>4){
						i=4;
						X=x[4];
					}
				}
			DoiMauMenu(X);
			}
			if(i==0&&c==13){
				ControlIn();
				dem=0;
			}
			if(i==1&&c==13){
				ControlOut((char*)"SoHoSo.txt",(char*)"TTKTLT.txt");
				dem =0;
			}
			if(c==13&&i==2){
				ControlArrangement();
				dem =0;
			}
			if(c==13&&i==3){
				ControlSearch();
				dem=0;
			}
			if(c==13&&i==4){
				ControlStatistics();
				dem=0;
			}
		}
	}	
}
void ControlIn(){         //BAC 1, dieu khien Giao Dien Nhap
	SinhVien *data;
	data=(SinhVien *)calloc (1,sizeof(SinhVien));
	int x1[2]={42,62};
	int X1;
	int i1=-1;
	char c,c1;
	int dem1=1;
	system("cls");
	system("color B0");
	GDNhap();
	_kbhit();
	c=getch();
	if(c!=27){
		DeleteAtPos(42,89,10,10);
		ThemHoSo(data);
	}
	else Manage();
	fflush(stdin);
	while(dem1 ==1){
		if(_kbhit()){
			c1=getch();
			if(c1==75 || c1==77){
				if(c1==75){
					X1=x1[--i1];
					if(i1<0){
						i1=0;
						X1=x1[0];
					}
				}
				else{
					X1=x1[++i1];
					if(i1>1){
						i1=1;
						X1=x1[1];
					}
				}
			DoiMauNhap(X1);
			}
			
			if(i1==0&&c1==13){
				GDThongBao();
				ControlNoti(data);
				dem1=0;
			}
			if(i1==1&&c1==13){
				Manage();
				dem1=0;
			}
		}
	}
}
void ControlOut(char *soluongfile,char *tenfile){        //BAC 1, dieu khien Giao Dien Xuat
	int x=5;
	system("cls");
	system("color B0");
	GDXuat();
	
	int n,i=1,k=5;
	char c2;
	int X2, i2=0, dem2=1, x2[3]={30,50,70};
	FILE *fp;
	fp=fopen(soluongfile,"r");
	fscanf(fp,"%d",&n);
	gotoxy(45,8);
	SetBGColor(11);
	printf("%d",n);
	fclose(fp);
	if(n>=x) PrintData(tenfile,1,5);
	else PrintData(tenfile,1,n);
	while(dem2 ==1){
		if(_kbhit()){
			c2=getch();
			if(c2==75 || c2==77){
				if(c2==75){
					X2=x2[--i2];
					if(i2<0){
						i2=0;
						X2=x2[0];
					}
				}
				else{
					X2=x2[++i2];
					if(i2>2){
						i2=2;
						X2=x2[2];
					}
				}
			DoiMauXuat(X2);
			}
			if(i2==0&&c2==13){
				int y =16;
				i=i-5;
				k=k-5;
				if(i<1){
					k=5;
					i=1;
					PrintData(tenfile,i,k);
				}else{
					PrintData(tenfile,i,k);
				}
				if(k-i!=5){
					k=i+4;
					PrintData(tenfile,i,k);
				}
			}
			if(i2==1&&c2==13){
				int y=16;
				i=i+5;
				k=k+5;
				if(k>n){
					k=n;
					i=n-n%5 +1;
					PrintData(tenfile,i,k);
				}else{
					PrintData(tenfile,i,k);
				}
			}
			if(i2==2&&c2==13){
				Manage();
				dem2=1;
			}
		}
	}
}
void ControlArrangement(){//BAC 1, dieu khien Giao Dien Sap Xep
	GDSapXep();
	int x3[6]={12,16,20,24,28,32};
	int X3;
	int i3=-1;
	char c3;
	int dem3=1;
	
	while(dem3 ==1){
		if(_kbhit()){
			c3=getch();
			if(c3==80 || c3==72){
				if(c3==72){
					X3=x3[--i3];
					if(i3<0){
						i3=0;
						X3=x3[0];
					}
				}
				else{
					X3=x3[++i3];
					if(i3>5){
						i3=5;
						X3=x3[5];
					}
				}
			DoiMauSapXep(X3);
			}
			if(i3==0&&c3==13){
				SXTen();
				dem3=0;
				ControlOut((char*)"SoHoSo.txt",(char*)"Du lieu sap xep.txt");
			}
			if(i3==1&&c3==13){
				SXMaSV();
				dem3=0;
				ControlOut((char*)"SoHoSo.txt",(char*)"Du lieu sap xep.txt");
			}
			if(i3==2&&c3==13){
				SXMaLop();
				dem3=0;
				ControlOut((char*)"SoHoSo.txt",(char*)"Sap xep lop.txt");
			}
			if(i3==3&&c3==13){
				SXNgaySinh();
				dem3=0;
				ControlOut((char*)"SoHoSo.txt",(char*)"Du lieu sap xep.txt");
			}
			if(i3==4&&c3==13){
				SXDiem();
				dem3=0;
				ControlOut((char*)"SoHoSo.txt",(char*)"Du lieu sap xep.txt");
			}
			if(i3==5&&c3==13){
				Manage();
				dem3=0;
			}
		}
	}
}
void ControlSearch(){     //BAC 1, dieu khien Giao Dien Tim Kiem
	GDTimKiem();
	int x4[6]={12,16,20,24,28,32};
	int X4;
	int i4=-1;
	char c4;
	int dem4=1;
	
	while(dem4 ==1){
		if(_kbhit()){
			c4=getch();
			if(c4==80 || c4==72){
				if(c4==72){
					X4=x4[--i4];
					if(i4<0){
						i4=0;
						X4=x4[0];
					}
				}
				else{
					X4=x4[++i4];
					if(i4>5){
						i4=5;
						X4=x4[5];
					}
				}
			DoiMauTimKiem(X4);
			}
			if(i4==0&&c4==13){
				GDTimKiem2();
				TimKiemTen();
				dem4=0;
			}
			if(i4==1&&c4==13){
				GDTimKiem2();
				TimKiemLop();
				dem4=0;
			}
			if(i4==2&&c4==13){
				GDTimKiem2();
				TimKiemNgaySinh();
				dem4=0;
			}
			if(i4==3&&c4==13){
				GDTimKiem2();
				TimKiemMaSV();
				dem4=0;
			}
			if(i4==4&&c4==13){
				GDTimKiem2();
				TimKiemDiem();
				dem4=0;
			}
			if(i4==5&&c4==13){
				Manage();
				dem4=0;
			}
		}
	}
}
void ControlStatistics(){ //BAC 1, dieu khien Giao Dien Thong Ke
	int x=5;
	GDXuat();
	int i=1,k=6,n;
	char c5;
	int X5, i5=0, dem5=1, x5[3]={30,50,70};

	GDThongKe();
	ThongKeSinhVien();
	FILE *fp;
	fp=fopen("Temp.txt","r");
	fscanf(fp,"%d",&n);
	fclose(fp);

	if(n>=x) InDuLieuThongKe(1,6);
	else InDuLieuThongKe(1,n);
	while(dem5 ==1){
		if(_kbhit()){
			c5=getch();
			if(c5==75 || c5==77){
				if(c5==75){
					X5=x5[--i5];
					if(i5<0){
						i5=0;
						X5=x5[0];
					}
				}
				else{
					X5=x5[++i5];
					if(i5>2){
						i5=2;
						X5=x5[2];
					}
				}
			DoiMauXuat(X5);
			}
			if(i5==0&&c5==13){
				i=i-6;
				k=k-6;
				if(i<1){
					k=6;
					i=1;
					InDuLieuThongKe(i,k);
				}else{
					InDuLieuThongKe(i,k);
				}
				if(k-i!=6){
					k=i+5;
					InDuLieuThongKe(i,k);
				}
			}
			if(i5==1&&c5==13){
				int y=16;
				i=i+6;
				k=k+6;
				if(k>n){
					k=n;
					i=n-n%6 +1;
					InDuLieuThongKe(i,k);
				}else{
					InDuLieuThongKe(i,k);
				}
			}
			if(i5==2&&c5==13){
				Manage();
				dem5=1;
			}
		}
	}
}
void ControlNoti(SinhVien *data){
	
	int x5[2]={111,112};
	int X5;
	int i5=-1;
	char c5;
	int dem5 =1;
	while(dem5 ==1){
		if(_kbhit()){
			c5=getch();
			if(c5==75 || c5==77){
				if(c5==75){
					X5=x5[--i5];
					if(i5<0){
						i5=0;
						X5=x5[0];
					}
				}
				else{
					X5=x5[++i5];
					if(i5>1){
						i5=1;
						X5=x5[1];
					}
				}
			DoiMauThongBao(X5);
			}
			if(i5==0&&c5==13){
				Input( data );
				ReturnGDNhap();
				dem5=0;
			}
			if(i5==1&&c5==13){
			ReturnGDNhap();
			dem5=0;
			}
		}
	}
}
void Manage(){            //BAC 3, dieu khien Giao Dien BAC 2
	SetBGColor(11);
	GD();
	ControlMenu();
}		
void ReturnGDNhap(){
	ControlIn();
}
int main(){
	system("color B0");
	system("mode con: cols=123 lines=36");
	Manage();
	getch();																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																				
	return 1;
}
//PHAN BO SUNG
void deletecharacter(char *s,int vt){
	int j, n1=strlen(s);
	for(j=vt; j<=n1-1;++j){
	s[j]=s[j+1];
	}
}
void ChuanHoaTen(char ten[]){//Trong hàm ThemHoSo
	int i,n;
    while(ten[strlen(ten)-1]==' ')
       ten[strlen(ten)-1]=0;
    while(ten[0]==' ')
       deletecharacter(ten,0);
    for(i=0;i<strlen(ten);++i)
       if((ten[i]>=65)&&(ten[i]<=90))
           ten[i]+=32;
    i=0;
    while(i<strlen(ten))
    if((ten[i]==' ')&&(ten[i+1]==' '))
        deletecharacter(ten,i);
    else ++i;
 
    for(i=0;i<strlen(ten);i++)
    if(ten[i]==' ')
        ten[i+1]-=32;	
	
    ten[0]=toupper(ten[0]);     
    i=0;
    while(i<strlen(ten))
    if((ten[i]!=' ')&&(!isalpha(ten[i])))
        deletecharacter(ten,i);
    else ++i;
}
void ChuanHoaLop(char lop[],int *kiemtra){//Trong hàm ThemHoSo
	int i3,n;
	n=strlen(lop);
	if(!isalpha(lop[n+1]))
		*kiemtra = 0;
	else
	*kiemtra = 1;
	while(lop[n]!=' '){
    	n--;
	}
	if((n!=0)&&(isalpha(lop[n+1])))
	*kiemtra=0;
	else 
	*kiemtra =1;
	if(*kiemtra==1){
	while(lop[strlen(lop)-1]==' ')
        lop[strlen(lop)-1]=0;
    while(lop[0]==' ')
        deletecharacter(lop,0);
    while(i3<strlen(lop))
    	if((lop[i3]==' ')&&(lop[i3+1]==' '))
        	deletecharacter(lop,i3);
    	else ++i3;
    for(int i3=0;i3<strlen(lop);++i3)
       if((lop[i3]>=91)&&(lop[i3]<=125))
           lop[i3]-=32;
	gotoxy(56,20);
	printf("%s",lop);
	}
}
void ChuanHoaNgay(int ngay, int thang, int nam,	int *dem){//Trong hàm ThemHoSo
	DeleteAtPos(56,79,23,23);
	gotoxy(78,23);
	printf("%c",179);

	if(thang<1 || thang>12){
		*dem = 0;
	}
	else if(nam <=1990 || nam>=2016){
		*dem = 0;
	}
	else{
		switch(thang){
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				{
					if(ngay<1 || ngay>31){
						*dem = 0;
					}
					else{
						*dem = 1;
					}
				}
				break;
			case 4: case 6: case 9: case 11:
				{
					if(ngay<1 || ngay >30){
						*dem = 0;
					}
					else{
						*dem = 1;
					}
				}
				break;
			case 2:
				{
					if(nam%4==0)
					{
						if(ngay<1 || ngay>29){
							*dem = 0;
						}
						else{
							*dem = 1;
						}
					}
					else{
						if(ngay<1 || ngay>28){
							*dem = 0;
						}
						else{
							*dem = 1;
						}
					}
				}
				break;
		}
	}
	if(*dem==1){
		gotoxy(56,23); printf("%d/%d/%d",ngay,thang,nam);
	}
}
void ThemHoSo(SinhVien *data){ //Trong hàm ControlIn	
	SetBGColor(11);
	int count=0,dem,kt=0,kiemtra;
	do{
		DeleteAtPos(56,97,14,14);
		gotoxy(78,14);
		printf("%c",179);
		gotoxy(56,14);
		gets(data->ten);
	}while(strlen(data->ten)>31||strlen(data->ten)<6);
	fflush(stdin);
	ChuanHoaTen(data->ten);
	DeleteAtPos(56,68,14,14);
	gotoxy(56,14);
	printf("%s",data->ten);

	while(data->MaSV<15150000 || data->MaSV>15159999){
		DeleteAtPos(56,73,17,17);
		gotoxy(56,17);
		scanf("%d",&data->MaSV);
		gotoxy(56,17);
		printf("%d",data->MaSV);
		fflush(stdin);
	}
	while(kt==0){
		DeleteAtPos(56,68,20,20);
		gotoxy(56,20);
		gets(data->lop);
		ChuanHoaLop(data->lop,&kiemtra);
		kt=kiemtra;
	}
	while(count==0){
		DeleteAtPos(56,68,23,23);
		gotoxy(56,23);
		scanf("%d %d %d",&data->ng,&data->th,&data->n);
		ChuanHoaNgay(data->ng,data->th,data->n,&dem);
		count=dem;
	}
	gotoxy(56,26);
	scanf("%d",&data->diem);
	while(data->diem<0 || data->diem >10){
		DeleteAtPos(56,68,26,26);
		gotoxy(56,26);
		scanf("%d",&data->diem);
		DeleteAtPos(56,68,26,26);
		gotoxy(56,26);
		printf("%d",data->diem);
	}
}
void Input(SinhVien *data){
	int n;
	FILE *f,*fp;
	fp=fopen("SoHoSo.txt","r");
	fscanf(fp,"%d",&n);
	fclose(fp);
	fp=fopen("SoHoSo.txt","w");
	n=n+1;
	fprintf(fp,"%d",n);
	fclose(fp);

	f=fopen("TTKTLT.txt","a");
	fprintf(f," %s\n",data->ten);
	fprintf(f,"%d\n",data->MaSV);
	fprintf(f,"%s\n",data->lop);
	fprintf(f,"%d %d %d\n",data->ng,data->th,data->n);
	fprintf(f,"%d\n",data->diem);
	fclose(f);
}
void PrintData(char *tenfile,int i,int k){
	int j,y=16,i1;
	char masv[10],ngay[3],thang[3],nam[5],diem[3];
	char ten[30],lop[10];
	FILE *f;
	f=fopen(tenfile,"r");
	int count=i+5;i1=i;
	for(i1;i1<count;i1++){
		SetBGColor(11);
		gotoxy(31,y); printf("                        ");
		gotoxy(57,y); printf("        ");
		gotoxy(68,y); printf("        ");
		gotoxy(79,y); printf("          ");
		gotoxy(95,y); printf("     ");
		y+=3;
	}
	y=16;
	
	for(j=1;j<=k;++j){
		fgets(ten,30,f);
		fgets(masv,10,f);
		fgets(lop,10,f);
		fgets(ngay,15,f);
		fgets(diem,5,f);
		if(j>=i&&j<=k){
			SetBGColor(11);
			gotoxy(31,y); printf("%d%s",j,ten);
			gotoxy(57,y); printf("%s",masv);
			gotoxy(68,y); printf("%9s",lop);
			gotoxy(79,y); printf("%11s",ngay);
			gotoxy(95,y); printf("%3s",diem);
			y+=3;
		}
	}
	fclose(f);
}
void SXMaSV(){
	Data data[30];
	int i,j,n;
	char tmp[30];
	FILE *f,*fp,*fmsv;
	fp=fopen("SoHoSo.txt","r");
	fscanf(fp,"%d",&n);
	fclose(fp);
	f=fopen("TTKTLT.txt","r");
	for(i=1;i<=n;++i){
		fgets(data[i].ten,30,f);
		fgets(data[i].MaSV,10,f);
		fgets(data[i].lop,10,f);
		fgets(data[i].ngay,15,f);
		fgets(data[i].diem,5,f);
	}
	fclose(f);
	for(int i=1;i<=n;++i){
		for(int j=n;j>i;--j){
			if(stricmp(data[i].MaSV,data[j].MaSV)>0){
            	memcpy(tmp,data[i].MaSV,sizeof(tmp));
            	memcpy(data[i].MaSV,data[j].MaSV,sizeof(data[i].MaSV));
            	memcpy(data[j].MaSV,tmp,sizeof(data[j].MaSV));
            	
            	memcpy(tmp,data[i].ten,sizeof(tmp));
            	memcpy(data[i].ten,data[j].ten,sizeof(data[i].ten));
            	memcpy(data[j].ten,tmp,sizeof(data[j].ten));
            	
            	memcpy(tmp,data[i].lop,sizeof(tmp));
            	memcpy(data[i].lop,data[j].lop,sizeof(data[i].lop));
            	memcpy(data[j].lop,tmp,sizeof(data[j].lop));
            	
				memcpy(tmp,data[i].ngay,sizeof(tmp));
            	memcpy(data[i].ngay,data[j].ngay,sizeof(data[i].ngay));
            	memcpy(data[j].ngay,tmp,sizeof(data[j].ngay));
            	
            	memcpy(tmp,data[i].diem,sizeof(tmp));
            	memcpy(data[i].diem,data[j].diem,sizeof(data[i].diem));
            	memcpy(data[j].diem,tmp,sizeof(data[j].diem));
        	}
        }
    }
    fmsv=fopen("Du lieu sap xep.txt","w");
    for(i=1;i<=n;++i){
		fprintf(fmsv,"%s",data[i].ten);
		fprintf(fmsv,"%s",data[i].MaSV);
		fprintf(fmsv,"%s",data[i].lop);
		fprintf(fmsv,"%s",data[i].ngay);
		fprintf(fmsv,"%s",data[i].diem);
	}
	fclose(fmsv);
}
void SXDiem(){
	Data data[30];
	int i,j,n;
	char tmp[30];
	FILE *f,*fp,*fd;
	fp=fopen("SoHoSo.txt","r");
	fscanf(fp,"%d",&n);
	fclose(fp);
	f=fopen("TTKTLT.txt","r");
	for(i=1;i<=n;++i){
		fgets(data[i].ten,30,f);
		fgets(data[i].MaSV,10,f);
		fgets(data[i].lop,10,f);
		fgets(data[i].ngay,15,f);
		fgets(data[i].diem,5,f);
	}
	fclose(f);
	for(int i=1;i<=n;++i){
		for(int j=n;j>i;--j){
			if(strlen(data[i].diem)!=strlen(data[j].diem)){
				if(strlen(data[i].diem)>strlen(data[j].diem)){
					memcpy(tmp,data[i].MaSV,sizeof(tmp));
    	        	memcpy(data[i].MaSV,data[j].MaSV,sizeof(data[i].MaSV));
	            	memcpy(data[j].MaSV,tmp,sizeof(data[j].MaSV));
            	
        	    	memcpy(tmp,data[i].ten,sizeof(tmp));
    	        	memcpy(data[i].ten,data[j].ten,sizeof(data[i].ten));
	            	memcpy(data[j].ten,tmp,sizeof(data[j].ten));
            	
            		memcpy(tmp,data[i].lop,sizeof(tmp));
            		memcpy(data[i].lop,data[j].lop,sizeof(data[i].lop));
            		memcpy(data[j].lop,tmp,sizeof(data[j].lop));
            	
					memcpy(tmp,data[i].ngay,sizeof(tmp));
    	        	memcpy(data[i].ngay,data[j].ngay,sizeof(data[i].ngay));
	            	memcpy(data[j].ngay,tmp,sizeof(data[j].ngay));
            	
            		memcpy(tmp,data[i].diem,sizeof(tmp));
            		memcpy(data[i].diem,data[j].diem,sizeof(data[i].diem));
            		memcpy(data[j].diem,tmp,sizeof(data[j].diem));
				}
			}
			if(strlen(data[i].diem)==strlen(data[j].diem)){
				if(stricmp(data[i].diem,data[j].diem)>0){
        	    	memcpy(tmp,data[i].MaSV,sizeof(tmp));
    	        	memcpy(data[i].MaSV,data[j].MaSV,sizeof(data[i].MaSV));
	            	memcpy(data[j].MaSV,tmp,sizeof(data[j].MaSV));
            	
        	    	memcpy(tmp,data[i].ten,sizeof(tmp));
    	        	memcpy(data[i].ten,data[j].ten,sizeof(data[i].ten));
	            	memcpy(data[j].ten,tmp,sizeof(data[j].ten));
            	
            		memcpy(tmp,data[i].lop,sizeof(tmp));
            		memcpy(data[i].lop,data[j].lop,sizeof(data[i].lop));
            		memcpy(data[j].lop,tmp,sizeof(data[j].lop));
            	
					memcpy(tmp,data[i].ngay,sizeof(tmp));
    	        	memcpy(data[i].ngay,data[j].ngay,sizeof(data[i].ngay));
	            	memcpy(data[j].ngay,tmp,sizeof(data[j].ngay));
            	
            		memcpy(tmp,data[i].diem,sizeof(tmp));
            		memcpy(data[i].diem,data[j].diem,sizeof(data[i].diem));
            		memcpy(data[j].diem,tmp,sizeof(data[j].diem));
            	}
        	}
        }
    }
    fd=fopen("Du lieu sap xep.txt","w");
    for(i=1;i<=n;++i){
		fprintf(fd,"%s",data[i].ten);
		fprintf(fd,"%s",data[i].MaSV);
		fprintf(fd,"%s",data[i].lop);
		fprintf(fd,"%s",data[i].ngay);
		fprintf(fd,"%s",data[i].diem);
	}
	fclose(fd);
}
void SXTen(){
	Data data[30];
	int i,j,n,count1,dem1,count=0;
	char tmp[35];
	FILE *f,*fp,*ft;
	fp=fopen("SoHoSo.txt","r");
	fscanf(fp,"%d",&n);
	fclose(fp);
	f=fopen("TTKTLT.txt","r");
	for(i=1;i<=n;++i){
		fgets(data[i].ten,30,f);
		fgets(data[i].MaSV,10,f);
		fgets(data[i].lop,10,f);
		fgets(data[i].ngay,15,f);
		fgets(data[i].diem,5,f);
	}
	fclose(f);
	for(int i=1;i<=n;++i){
			dem1=count1=strlen(data[i].ten);
			while(data[i].ten[dem1]!=' '){
				dem1--;
			}
			for(dem1+1;dem1<=count1;dem1++){
			data[i].temp[count]=data[i].ten[dem1+1];
				count++;
			}
			count=0;
	strcat(data[i].temp,data[i].ten);
	}
	for(int i=1;i<=n;++i){
		for(int j=n;j>i;--j){
			if(stricmp(data[i].temp,data[j].temp)>0){
				
				memcpy(tmp,data[i].temp,sizeof(tmp));
            	memcpy(data[i].temp,data[j].temp,sizeof(data[i].temp));
            	memcpy(data[j].temp,tmp,sizeof(data[j].temp));

				memcpy(tmp,data[i].MaSV,sizeof(tmp));
            	memcpy(data[i].MaSV,data[j].MaSV,sizeof(data[i].MaSV));
            	memcpy(data[j].MaSV,tmp,sizeof(data[j].MaSV));
            	
            	memcpy(tmp,data[i].ten,sizeof(tmp));
            	memcpy(data[i].ten,data[j].ten,sizeof(data[i].ten));
            	memcpy(data[j].ten,tmp,sizeof(data[j].ten));
            	
            	memcpy(tmp,data[i].lop,sizeof(tmp));
            	memcpy(data[i].lop,data[j].lop,sizeof(data[i].lop));
            	memcpy(data[j].lop,tmp,sizeof(data[j].lop));
            	
				memcpy(tmp,data[i].ngay,sizeof(tmp));
            	memcpy(data[i].ngay,data[j].ngay,sizeof(data[i].ngay));
            	memcpy(data[j].ngay,tmp,sizeof(data[j].ngay));
            	
            	memcpy(tmp,data[i].diem,sizeof(tmp));
            	memcpy(data[i].diem,data[j].diem,sizeof(data[i].diem));
            	memcpy(data[j].diem,tmp,sizeof(data[j].diem));
        	}
        }
    }
    ft=fopen("Du lieu sap xep.txt","w");
    for(i=1;i<=n;++i){
		fprintf(ft,"%s",data[i].ten);
		fprintf(ft,"%s",data[i].MaSV);
		fprintf(ft,"%s",data[i].lop);
		fprintf(ft,"%s",data[i].ngay);
		fprintf(ft,"%s",data[i].diem);
	}
	fclose(ft);
}
void SXMaLop(){
	Data data[30];
	int i,j,n,count1,dem1,count=0;
	char tmp[35];
	FILE *f,*fp,*fl;
	fp=fopen("SoHoSo.txt","r");
	fscanf(fp,"%d",&n);
	fclose(fp);
	f=fopen("TTKTLT.txt","r");
	for(i=1;i<=n;++i){
		fgets(data[i].ten,30,f);
		fgets(data[i].MaSV,10,f);
		fgets(data[i].lop,10,f);
		fgets(data[i].ngay,15,f);
		fgets(data[i].diem,5,f);
	}
	fclose(f);
	for(int i=1;i<=n;++i){
			dem1=count1=strlen(data[i].lop);
			while(data[i].lop[dem1]!=' '){
				dem1--;
			}
			for(dem1+1;dem1<=count1;dem1++){
			data[i].temp[count]=data[i].lop[dem1+1];
				count++;
			}
			count=0;
	strcat(data[i].temp,data[i].lop);
	}
	for(int i=1;i<=n;++i){
		for(int j=n;j>i;--j){
			if(stricmp(data[i].temp,data[j].temp)>0){
				
				memcpy(tmp,data[i].temp,sizeof(tmp));
            	memcpy(data[i].temp,data[j].temp,sizeof(data[i].temp));
            	memcpy(data[j].temp,tmp,sizeof(data[j].temp));

				memcpy(tmp,data[i].MaSV,sizeof(tmp));
            	memcpy(data[i].MaSV,data[j].MaSV,sizeof(data[i].MaSV));
            	memcpy(data[j].MaSV,tmp,sizeof(data[j].MaSV));
            	
            	memcpy(tmp,data[i].ten,sizeof(tmp));
            	memcpy(data[i].ten,data[j].ten,sizeof(data[i].ten));
            	memcpy(data[j].ten,tmp,sizeof(data[j].ten));
            	
            	memcpy(tmp,data[i].lop,sizeof(tmp));
            	memcpy(data[i].lop,data[j].lop,sizeof(data[i].lop));
            	memcpy(data[j].lop,tmp,sizeof(data[j].lop));
            	
				memcpy(tmp,data[i].ngay,sizeof(tmp));
            	memcpy(data[i].ngay,data[j].ngay,sizeof(data[i].ngay));
            	memcpy(data[j].ngay,tmp,sizeof(data[j].ngay));
            	
            	memcpy(tmp,data[i].diem,sizeof(tmp));
            	memcpy(data[i].diem,data[j].diem,sizeof(data[i].diem));
            	memcpy(data[j].diem,tmp,sizeof(data[j].diem));
        	}
        }
    }
    fl=fopen("Sap xep lop.txt","w");
    for(i=1;i<=n;++i){
		fprintf(fl,"%s",data[i].ten);
		fprintf(fl,"%s",data[i].MaSV);
		fprintf(fl,"%s",data[i].lop);
		fprintf(fl,"%s",data[i].ngay);
		fprintf(fl,"%s",data[i].diem);
	}
	fclose(fl);
}
void SXNgaySinh(){
	Data data[30];
	int j,n,count1,dem1,count=0,vitri,vitri2;
	char tmp[30],tg[30];
	FILE *f,*fp,*fns;
	fp=fopen("SoHoSo.txt","r");
	fscanf(fp,"%d",&n);
	fclose(fp);
	f=fopen("TTKTLT.txt","r");
	for(int i=1;i<=n;++i){
		fgets(data[i].ten,30,f);
		fgets(data[i].MaSV,10,f);
		fgets(data[i].lop,10,f);
		fgets(data[i].ngay,15,f);
		fgets(data[i].diem,5,f);
	}
	fclose(f);
	for(int i=1;i<=n;++i){
		fflush(stdin);
		dem1=count1=strlen(data[i].ngay);
		while(data[i].ngay[dem1]!=' '){
			--dem1;
			vitri=dem1;
		}
		while(dem1>0){
			if(data[i].ngay[dem1]==' '){
				vitri2=dem1;
			}
			--dem1;
		}
		for(vitri2+1;vitri2<vitri-1;++vitri2){
		data[i].temp[count]=data[i].ngay[vitri2+1];
			count++;
		}
		count=0;
		strcat(data[i].temp,data[i].ngay);
		memcpy(tg,data[i].temp,sizeof(tg));

		for(vitri+1;vitri<count1-1;vitri++){
			data[i].temp[count]=data[i].ngay[vitri+1];
			count++;
		}
		count=0;
		strcat(data[i].temp,tg);
	}
	for(int i=1;i<=n;++i){
		for(int j=n;j>i;--j){
			if(strcmp(data[i].temp,data[j].temp)>0){
				
				memcpy(tmp,data[i].temp,sizeof(tmp));
            	memcpy(data[i].temp,data[j].temp,sizeof(data[i].temp));
            	memcpy(data[j].temp,tmp,sizeof(data[j].temp));

				memcpy(tmp,data[i].MaSV,sizeof(tmp));
            	memcpy(data[i].MaSV,data[j].MaSV,sizeof(data[i].MaSV));
            	memcpy(data[j].MaSV,tmp,sizeof(data[j].MaSV));
            	
            	memcpy(tmp,data[i].ten,sizeof(tmp));
            	memcpy(data[i].ten,data[j].ten,sizeof(data[i].ten));
            	memcpy(data[j].ten,tmp,sizeof(data[j].ten));
            	
            	memcpy(tmp,data[i].lop,sizeof(tmp));
            	memcpy(data[i].lop,data[j].lop,sizeof(data[i].lop));
            	memcpy(data[j].lop,tmp,sizeof(data[j].lop));
            	
				memcpy(tmp,data[i].ngay,sizeof(tmp));
            	memcpy(data[i].ngay,data[j].ngay,sizeof(data[i].ngay));
            	memcpy(data[j].ngay,tmp,sizeof(data[j].ngay));
            	
            	memcpy(tmp,data[i].diem,sizeof(tmp));
            	memcpy(data[i].diem,data[j].diem,sizeof(data[i].diem));
            	memcpy(data[j].diem,tmp,sizeof(data[j].diem));
        	}
        }
    }
    fns=fopen("Du lieu sap xep.txt","w");
    for(int i=1;i<=n;++i){
		fprintf(fns,"%s",data[i].ten);
		fprintf(fns,"%s",data[i].MaSV);
		fprintf(fns,"%s",data[i].lop);
		fprintf(fns,"%s",data[i].ngay);
		fprintf(fns,"%s",data[i].diem);
	}
	fclose(fns);
}
void TimKiemTen(){
	Data data[30];
	int dodaic1,dodaic2,n,dem,l=0,A[30];
	char s[30];
	FILE *fp, *f, *ftk, *ff ;
	fp=fopen("SoHoSo.txt","r");
	fscanf(fp,"%d",&n);
	fclose(fp);
	f=fopen("TTKTLT.txt","r");
	for(int i=1;i<=n;i++){
		fgets(data[i].ten,30,f);
		fgets(data[i].MaSV,10,f);
		fgets(data[i].lop,10,f);
		fgets(data[i].ngay,15,f);
		fgets(data[i].diem,5,f);
	}
	fclose(f);
	gotoxy(45,18); gets(s);fflush(stdin);
	ChuanHoaTen(s);
	DeleteAtPos(45,65,18,18);
	gotoxy(45,18); printf("%s",s);
	dodaic1=strlen(s);
	for(int i=1;i<=n;i++){
		dodaic2 = strlen(data[i].ten);
		for(int j=1;j<dodaic2-dodaic1;j++){
			for(int k=0;k<dodaic1;k++){
				data[i].temp[k]=data[i].ten[j+k];
			}
			dem=stricmp(s,data[i].temp);
			if(dem==0){
				A[l]=i;
				l++;
				j=dodaic2-dodaic1;
			}
		}
	}
	l=0;
	ftk=fopen("Du lieu tim kiem.txt","w");
	for(int i=1;i<=n;i++){
		if(A[l]==i){
			fprintf(ftk,"%s",data[i].ten);
			fprintf(ftk,"%s",data[i].MaSV);
			fprintf(ftk,"%s",data[i].lop);
			fprintf(ftk,"%s",data[i].ngay);
			fprintf(ftk,"%s",data[i].diem);
			l++;
		}
	}
	fclose(ftk);
	ff=fopen("Temp.txt","w");
	fprintf(ff,"%d",l);
	fclose(ff);
	if(A[0]!=NULL){
	ControlOut((char*)"Temp.txt",(char*)"Du lieu tim kiem.txt");
	}
	else 
	{
		gotoxy(45,21); printf("Khong co du lieu trung khop!");
	}
	
}
void TimKiemMaSV(){
	Data data[30];
	int dodaic1,dodaic2,n,dem,l=0,A[30];
	char s[30];
	FILE *fp, *f, *ftk, *ff ;
	fp=fopen("SoHoSo.txt","r");
	fscanf(fp,"%d",&n);
	fclose(fp);
	f=fopen("TTKTLT.txt","r");
	for(int i=1;i<=n;i++){
		fgets(data[i].ten,30,f);
		fgets(data[i].MaSV,10,f);
		fgets(data[i].lop,10,f);
		fgets(data[i].ngay,15,f);
		fgets(data[i].diem,5,f);
	}
	fclose(f);
	gotoxy(45,18); gets(s);fflush(stdin);
	dodaic1=strlen(s);
	for(int i=1;i<=n;i++){
		dodaic2 = strlen(data[i].MaSV);
		for(int j=0;j<dodaic2-dodaic1;j++){
			for(int k=0;k<dodaic1;k++){
				data[i].temp[k]=data[i].MaSV[j+k];
			}
			dem=stricmp(s,data[i].temp);
			if(dem==0){
				A[l]=i;
				l++;
				j=dodaic2-dodaic1;
			}
		}
	}
	l=0;
	ftk=fopen("Du lieu tim kiem.txt","w");
	for(int i=1;i<=n;i++){
		if(A[l]==i){
			fprintf(ftk,"%s",data[i].ten);
			fprintf(ftk,"%s",data[i].MaSV);
			fprintf(ftk,"%s",data[i].lop);
			fprintf(ftk,"%s",data[i].ngay);
			fprintf(ftk,"%s",data[i].diem);
			l++;
		}
	}
	fclose(ftk);
	ff=fopen("Temp.txt","w");
	fprintf(ff,"%d",l);
	fclose(ff);
	if(A[0]!=NULL)
	ControlOut((char*)"Temp.txt",(char*)"Du lieu tim kiem.txt");
	else 
	{
		gotoxy(45,21); printf("Khong co du lieu trung khop!");
	}
}
void TimKiemLop(){
	Data data[30];
	int dodaic1,dodaic2,n,dem,l=0,A[30];
	char s[30];
	FILE *fp, *f, *ftk, *ff ;
	fp=fopen("SoHoSo.txt","r");
	fscanf(fp,"%d",&n);
	fclose(fp);
	f=fopen("TTKTLT.txt","r");
	for(int i=1;i<=n;i++){
		fgets(data[i].ten,30,f);
		fgets(data[i].MaSV,10,f);
		fgets(data[i].lop,10,f);
		fgets(data[i].ngay,15,f);
		fgets(data[i].diem,5,f);
	}
	fclose(f);
	gotoxy(45,18); gets(s);fflush(stdin);
	dodaic1=strlen(s);
	for(int i=1;i<=n;i++){
		dodaic2 = strlen(data[i].lop);
		for(int j=0;j<dodaic2-dodaic1;j++){
			for(int k=0;k<dodaic1;k++){
				data[i].temp[k]=data[i].lop[j+k];
			}
			dem=stricmp(s,data[i].temp);
			if(dem==0){
				A[l]=i;
				l++;
				j=dodaic2-dodaic1;
			}
		}
	}
	l=0;
	ftk=fopen("Du lieu tim kiem.txt","w");
	for(int i=1;i<=n;i++){
		if(A[l]==i){
			fprintf(ftk,"%s",data[i].ten);
			fprintf(ftk,"%s",data[i].MaSV);
			fprintf(ftk,"%s",data[i].lop);
			fprintf(ftk,"%s",data[i].ngay);
			fprintf(ftk,"%s",data[i].diem);
			l++;
		}
	}
	fclose(ftk);
	ff=fopen("Temp.txt","w");
	fprintf(ff,"%d",l);
	fclose(ff);
	if(A[0]!=NULL)
		ControlOut((char*)"Temp.txt",(char*)"Du lieu tim kiem.txt");
	else 
	{
		gotoxy(45,21); printf("Khong co du lieu trung khop!");
	}
}
void TimKiemNgaySinh(){
	Data data[30];
	int dodaic1,dodaic2,n,dem,l=0,A[30];
	char s[30];
	FILE *fp, *f, *ftk,*ff ;
	fp=fopen("SoHoSo.txt","r");
	fscanf(fp,"%d",&n);
	fclose(fp);
	f=fopen("TTKTLT.txt","r");
	for(int i=1;i<=n;i++){
		fgets(data[i].ten,30,f);
		fgets(data[i].MaSV,10,f);
		fgets(data[i].lop,10,f);
		fgets(data[i].ngay,15,f);
		fgets(data[i].diem,5,f);
	}
	fclose(f);
	gotoxy(45,18); gets(s);fflush(stdin);
	dodaic1=strlen(s);
	for(int i=1;i<=n;i++){
		dodaic2 = strlen(data[i].ngay);
		for(int j=0;j<dodaic2-dodaic1;j++){
			for(int k=0;k<dodaic1;k++){
				data[i].temp[k]=data[i].ngay[j+k];
			}
			dem=stricmp(s,data[i].temp);
			if(dem==0){
				A[l]=i;
				l++;
				j=dodaic2-dodaic1;
			}
		}
	}
	l=0;
	ftk=fopen("Du lieu tim kiem.txt","w");
	for(int i=1;i<=n;i++){
		if(A[l]==i){
			fprintf(ftk,"%s",data[i].ten);
			fprintf(ftk,"%s",data[i].MaSV);
			fprintf(ftk,"%s",data[i].lop);
			fprintf(ftk,"%s",data[i].ngay);
			fprintf(ftk,"%s",data[i].diem);
			l++;
		}
	}
	fclose(ftk);
	ff=fopen("Temp.txt","w");
	fprintf(ff,"%d",l);
	fclose(ff);
	if(A[0]!=NULL)
		ControlOut((char*)"Temp.txt",(char*)"Du lieu tim kiem.txt");
	else 
	{
		gotoxy(45,21); printf("Khong co du lieu trung khop!");
	}
}
void TimKiemDiem(){
	Data data[30];
	int dodaic1,dodaic2,n,dem,l=0,A[30];
	char s[30];
	FILE *fp, *f, *ftk, *ff ;
	fp=fopen("SoHoSo.txt","r");
	fscanf(fp,"%d",&n);
	fclose(fp);
	f=fopen("TTKTLT.txt","r");
	for(int i=0;i<=n;i++){
		fgets(data[i].ten,30,f);
		fgets(data[i].MaSV,10,f);
		fgets(data[i].lop,10,f);
		fgets(data[i].ngay,15,f);
		fgets(data[i].diem,5,f);
	}
	fclose(f);
	gotoxy(45,18); gets(s);fflush(stdin);
	dodaic1=strlen(s);
	for(int i=1;i<=n;i++){
		dodaic2 = strlen(data[i].diem);
		for(int j=0;j<dodaic2-dodaic1;j++){
			for(int k=0;k<dodaic1;k++){
				data[i].temp[k]=data[i].diem[j+k];
			}
			dem=stricmp(s,data[i].temp);
			if(dem==0){
				A[l]=i;
				l++;
				j=dodaic2-dodaic1;
			}
		}
	}
	l=0;
	ftk=fopen("Du lieu tim kiem.txt","w");
	for(int i=1;i<=n;i++){
		if(A[l]==i){
			fprintf(ftk,"%s",data[i].ten);
			fprintf(ftk,"%s",data[i].MaSV);
			fprintf(ftk,"%s",data[i].lop);
			fprintf(ftk,"%s",data[i].ngay);
			fprintf(ftk,"%s",data[i].diem);
			l++;
		}
	}
	fclose(ftk);
	ff=fopen("Temp.txt","w");
	fprintf(ff,"%d",l);
	fclose(ff);
	if(A[0]!=NULL)
		ControlOut((char*)"Temp.txt",(char*)"Du lieu tim kiem.txt");
	else 
	{
		gotoxy(45,21); printf("Khong co du lieu trung khop!");
	}
}
void ThongKeSinhVien(){
	SXMaLop();
	ThongKe tke[30];
	Data data[30];
	int dem,i,j,l,trans;
	int n;
	FILE *f, *fp, *ft, *ftke;
	fp=fopen("SoHoSo.txt","r");
	fscanf(fp,"%d",&n);
	fclose(fp);
	f=fopen("Sap xep lop.txt","r");
	for(i=1;i<=n;i++){
		fgets(data[i].ten,30,f);
		fgets(data[i].MaSV,10,f);
		fgets(data[i].lop,10,f);
		fgets(data[i].ngay,15,f);
		fgets(data[i].diem,5,f);
	}
	memcpy(tke[0].malop,data[1].lop,sizeof(tke[0].malop));
	for(j=0;j<n;j++){
		tke[j].tong=1;
	}
	j=0;
	for(i=2;i<=n;i++){	
		dem=stricmp(data[i].lop,tke[j].malop);
		if(dem==0){
			tke[j].tong++;
		}
		else{
			j++;
			memcpy(tke[j].malop,data[i].lop,sizeof(tke[j].malop));
		}
	}
	for(i=0;i<=j;i++){
		tke[i].xs=0;
		tke[i].g=0;
		tke[i].k=0;
		tke[i].tb=0;
		tke[i].yeu=0;
		tke[i].tong=0;
	}
	for(i=1;i<=n;i++){
		data[i].lop;
		for(l=0;l<=j;l++){
			dem=stricmp(tke[l].malop,data[i].lop);
			if(dem==0){
				tke[l].tong++;
				trans=atof(data[i].diem);
				if(trans<4){
					tke[l].yeu++;
				}
				else if(trans>=4&&trans<6.5){
					tke[l].tb++;
				}
				else if(trans>=6.5&&trans<8){
					tke[l].k++;
				}
				else if(trans>=8&&trans<9){
					tke[l].g++;
				}
				else
					tke[l].xs++;
			}
		}
	}
	j++;
	ft=fopen("Temp.txt","w");
	fprintf(ft,"%d",j);
	fclose(ft);

	ftke=fopen("Du lieu thong ke.txt","w");
	for(i=0;i<=j;i++){
	fprintf(ftke," %s",tke[i].malop);
	fprintf(ftke,"%d\n",tke[i].xs);
	fprintf(ftke,"%d\n",tke[i].g);
	fprintf(ftke,"%d\n",tke[i].k);
	fprintf(ftke,"%d\n",tke[i].tb);
	fprintf(ftke,"%d\n",tke[i].yeu);
	fprintf(ftke,"%d\n",tke[i].tong);
	}
	fclose(ftke);
}
void InDuLieuThongKe(int i, int k){
	int j,y=14,i1;
	char malop[10],xs[3],gioi[3],kha[3],tb[3],yeu[3],tong[3];
	FILE *f;
	f=fopen("Du lieu thong ke.txt","r");
	int count=i+6;i1=i;
	for(i1;i1<count;i1++){
		SetBGColor(11);
		gotoxy(30,y); printf("         ");
		gotoxy(41,y); printf("         ");
		gotoxy(51,y); printf("         ");
		gotoxy(61,y); printf("         ");
		gotoxy(71,y); printf("         ");
		gotoxy(81,y); printf("         ");
		gotoxy(91,y); printf("         ");
		y+=3;
	}
	y=14;
	
	for(j=1;j<=k;++j){
		fgets(malop,10,f);
		fgets(xs,3,f);
		fgets(gioi,3,f);
		fgets(kha,3,f);
		fgets(tb,3,f);
		fgets(yeu,3,f);
		fgets(tong,3,f);
		if(j>=i&&j<=k){
			SetBGColor(11);
			gotoxy(30,y); printf("%d%s",j,malop);
			gotoxy(41,y); printf("    %s",xs);
			gotoxy(51,y); printf("    %s",gioi);
			gotoxy(61,y); printf("    %s",kha);
			gotoxy(71,y); printf("    %s",tb);
			gotoxy(81,y); printf("    %s",yeu);
			gotoxy(91,y); printf("    %s",tong);
			y+=3;
		}
	}
	fclose(f);
}
