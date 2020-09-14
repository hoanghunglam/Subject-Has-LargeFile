#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include"HeaderFile/thuvien.h"
#include"HeaderFile/nhapxuly.h"
#include"HeaderFile/chuanhoa.h"
#define sosv 200
void MainQLSV();
void MoveMSX();
void MoveMTKiem();
void MoveMTKe();
void ThemDS();
void InDS();
void InDS1(int demsosv,int ktsxep);
void MenuSXChon();
void MenuSXChen();
void MenuSXNB();
void MenuSXQS();
void MenuTKiem(int temptkiem);
void SXChon(int tempsx);
void MenuTG(int tempsx);	
void Move3();
void DSTK(char tkiem[],char tkiemnt[],int a);
void ThongKe(int a);
//...........................................Tieu de .............................................//
void Title()
{
	gotoxy(33,1);
	printf("THUC TAP KY THUAT LAP TRINH");
	for(int i=0;i<=94;i++)
	{
		gotoxy(i,2);
		printf("%c",196);
		gotoxy(i,4);
		printf("%c",196);
		gotoxy(47,4);
		printf("%c",194);	
	}
	for(int i=0;i<=94;i++)
	{
		if(i<=35 || i>=58)
		{
			gotoxy(i,3);
			printf("%c",196);
		}
	}		
}
void LineMain()
{
	for(int i=5;i<32;i++)
	{
		gotoxy(47,i);
		printf("%c",179);
	}
}
//Khung List Trai
void FrameLeft(int j,int i)
{
	int m[6]={6,10,14,18,22,26 },m2[6]={8,12,16,20,24,28},m1[6]={7,11,15,19,23,27};
	gotoxy(j,m[i]);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	gotoxy(j,m1[i]);
	printf("%c                                  %c",186,186);
	gotoxy(j,m2[i]);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}
//Khung List Phai
void FrameRight1(int i,int j)
{
	int n[11]={11,14,17,20,18,21,22,25},n2[11]={13,16,19,22,20,23,24,27},n1[11]={12,15,18,21,19,22,23,26};
	gotoxy(i,n[j]);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	gotoxy(i,n1[j]);
	printf("%c                                  %c",186,186);
	gotoxy(i,n2[j]);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}
	//-------------------------------------Khung cua cac MENU Cap 2-------------------------------------------//
//SAP XEP
void Line()
{
	SetBGColor(1);
	gotoxy(47,15);
	printf("%c",195);
	for(int a12=48;a12<53;a12++)
	{
		gotoxy(a12,15);
		printf("%c",196);
    }
}
void FrameRight2()
{
	for(int j=0;j<4;j++)
	{
		FrameRight1(54,j);
	}
	gotoxy(61,12);
	printf("1.CHON");
	gotoxy(61,15);
	printf("2.CHEN");
	gotoxy(61,18);
	printf("3.NOI BOT");
	gotoxy(61,21);
	printf("4.QUICKSORT");
	for(int a11=11;a11<23;a11++)
	{
		gotoxy(53,a11);
		printf("%c",179);
		gotoxy(90,a11);
		printf("%c",179);
	}
	gotoxy(53,15);
	printf("%c",180);
	for(int b11=54;b11<90;b11++)
	{
		gotoxy(b11,10);
		printf("%c",196);
		gotoxy(b11,23);
		printf("%c",196);
	}
	gotoxy(53,10);
	printf("%c",218);
	gotoxy(90,10);
	printf("%c",191);
	gotoxy(53,23);
	printf("%c",192);
	gotoxy(90,23);
	printf("%c",217);

}
//TIM KIEM
void Line3()
{
	SetBGColor(1);
	gotoxy(47,19);
	printf("%c",195);
	for(int a12=48;a12<53;a12++)
	{
		gotoxy(a12,19);
		printf("%c",196);
    }
}
void FrameRight3()
{
	for(int j=4;j<6;j++)
	{
		FrameRight1(54,j);
	}
	gotoxy(61,19);
	printf("1.TUAN TU");
	gotoxy(61,22);
	printf("2.NHI PHAN");
	for(int a11=18;a11<24;a11++)
	{
		gotoxy(53,a11);
		printf("%c",179);
		gotoxy(90,a11);
		printf("%c",179);
	}
	gotoxy(53,19);
	printf("%c",180);
	for(int b11=54;b11<90;b11++)
	{
		gotoxy(b11,17);
		printf("%c",196);
		gotoxy(b11,24);
		printf("%c",196);
	}
	gotoxy(53,17);
	printf("%c",218);
	gotoxy(90,17);
	printf("%c",191);
	gotoxy(53,24);
	printf("%c",192);
	gotoxy(90,24);
	printf("%c",217);

}
//THONG KE
void Line4()
{
	SetBGColor(1);
	gotoxy(47,23);
	printf("%c",195);
	for(int a12=48;a12<53;a12++)
	{
		gotoxy(a12,23);
		printf("%c",196);
    }
}
void FrameRight4()
{
	for(int i=6;i<8;i++)
	{
		FrameRight1(54,i);
	}
	gotoxy(61,23);
	printf("1.SO LUONG SINH VIEN");
	gotoxy(61,26);
	printf("2.KET QUA HOC TAP");
	for(int a11=22;a11<28;a11++)
	{
		gotoxy(53,a11);
		printf("%c",179);
		gotoxy(90,a11);
		printf("%c",179);
	}
	gotoxy(53,23);
	printf("%c",180);
	for(int b11=54;b11<90;b11++)
	{
		gotoxy(b11,21);
		printf("%c",196);
		gotoxy(b11,28);
		printf("%c",196);
	}
	gotoxy(53,21);
	printf("%c",218);
	gotoxy(90,21);
	printf("%c",191);
	gotoxy(53,28);
	printf("%c",192);
	gotoxy(90,28);
	printf("%c",217);

}
		//...........................................End .............................................//
//Danh sach List
void ListMenu1()
{
	gotoxy(14,7);
	printf("1.THEM DANH SACH");
	gotoxy(14,11);
	printf("2.IN DANH SACH");
	gotoxy(14,15);
	printf("3.SAP XEP     %c",175);
	gotoxy(14,19);
	printf("4.TIM KIEM    %c",175);
	gotoxy(14,23);
	printf("5.THONG KE    %c",175);
	gotoxy(14,27);
	printf("6.THOAT");
	gotoxy(0,31);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,193,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
		
}
//---------------------------------------------Thay doi mau cac MENU Cap 1 && Cap2----------------------------------------//
		//Thay doi mau khi tro den o MENU cap 1
void Change(int X){
	switch(X)
	{
		case 7:
			{
				SetBGColor(1);
				FrameLeft(6,1);
				gotoxy(14,11);
				printf("2.IN DANH SACH");
				
				SetBGColor(3);
				FrameLeft(6,0);
				gotoxy(14,7);
				printf("1.THEM DANH SACH");
			}
			break;
		case 11:
			{
				SetBGColor(1);
				FrameLeft(6,2);
				gotoxy(14,15);
				printf("3.SAP XEP     %c",175);
								
				SetBGColor(1);
				FrameLeft(6,0);
				gotoxy(14,7);
				printf("1.THEM DANH SACH");
			
				SetBGColor(3);
				FrameLeft(6,1);
				gotoxy(14,11);
				printf("2.IN DANH SACH");	
			}
			break;
		case 15:
			{
		    	SetBGColor(1);
				FrameLeft(6,3);
				gotoxy(14,19);
				printf("4.TIM KIEM    %c",175);
											
				SetBGColor(1);
				FrameLeft(6,1);
				gotoxy(14,11);
				printf("2.IN DANH SACH");	
			
				SetBGColor(3);
				FrameLeft(6,2);
				gotoxy(14,15);
				printf("3.SAP XEP     %c",175);
			}
				break;
		case 19:
			{										
				SetBGColor(1);
				FrameLeft(6,4);
				gotoxy(14,23);
				printf("5.THONG KE    %c",175);
			
				SetBGColor(1);
				FrameLeft(6,2);
				gotoxy(14,15);
				printf("3.SAP XEP     %c",175);
			
				SetBGColor(3);
				FrameLeft(6,3);
				gotoxy(14,19);
				printf("4.TIM KIEM    %c",175);
			}
				break;
		case 23:
			{												
				SetBGColor(1);
				FrameLeft(6,5);
				gotoxy(14,27);
				printf("6.THOAT");
				
				SetBGColor(1);
				FrameLeft(6,3);
				gotoxy(14,19);
				printf("4.TIM KIEM    %c",175);
			
				SetBGColor(3);
				FrameLeft(6,4);
				gotoxy(14,23);
				printf("5.THONG KE    %c",175);
			}
				break;
		case 27:
			{												
				SetBGColor(1);
				FrameLeft(6,4);
				gotoxy(14,23);
				printf("5.THONG KE    %c",175);
				
				SetBGColor(3);
				FrameLeft(6,5);
				gotoxy(14,27);
				printf("6.THOAT");

			}
				break;
	}
	
}
		//Thay doi mau khi tro den o MENU cap 2 SAP XEP
void Change2(int Y)
{
	switch(Y)
	{
		case 12:
			{	
				SetBGColor(3);
				FrameRight1(54,1);
				gotoxy(61,15);
				printf("2.CHEN");
				
				SetBGColor(4);
				FrameRight1(54,0);
				gotoxy(61,12);
				printf("1.CHON");
			}
			break;
		case 15:
			{
				SetBGColor(3);
				FrameRight1(54,0);
				gotoxy(61,12);
				printf("1.CHON");
				
				SetBGColor(3);
				FrameRight1(54,2);
				gotoxy(61,18);
				printf("3.NOI BOT");
				
				SetBGColor(4);
				FrameRight1(54,1);
				gotoxy(61,15);
				printf("2.CHEN");
			}
			break;
		case 18:
			{
				SetBGColor(3);
				FrameRight1(54,3);
				gotoxy(61,21);
				printf("4.QUICKSORT");
				
				SetBGColor(3);
				FrameRight1(54,1);
				gotoxy(61,15);
				printf("2.CHEN");
				
				SetBGColor(4);
				FrameRight1(54,2);
				gotoxy(61,18);
				printf("3.NOI BOT");
			} 
			break;
		case 21:
			{
				SetBGColor(3);
				FrameRight1(54,2);
				gotoxy(61,18);
				printf("3.NOI BOT");
				
				SetBGColor(4);
				FrameRight1(54,3);
				gotoxy(61,21);
				printf("4.QUICKSORT");
			}
			break;			
	}
}
		//Thay doi mau khi tro den o MENU cap 2 TIM KIEM
void Change3(int A)
{
	switch(A)
	{
		case 19:
			{				
				SetBGColor(3);
				FrameRight1(54,5);
				gotoxy(61,22);
				printf("2.NHI PHAN");
				
				SetBGColor(4);
				FrameRight1(54,4);
				gotoxy(61,19);
				printf("1.TUAN TU");
			}
			break;
		case 22:
			{
				SetBGColor(3);
				FrameRight1(54,4);
				gotoxy(61,19);
				printf("1.TUAN TU");
			
				SetBGColor(4);
				FrameRight1(54,5);
				gotoxy(61,22);
				printf("2.NHI PHAN");
				
			}
			break;
	}
}
		//Thay doi mau khi tro den o MENU cap 2 THONG KE
void Change4(int B)
{
	switch(B)
	{	
		case 23:
			{					
				SetBGColor(3);
				FrameRight1(54,7);
				gotoxy(61,26);
				printf("2.KET QUA HOC TAP");
				
				SetBGColor(4);
				FrameRight1(54,6);
				gotoxy(61,23);
				printf("1.SO LUONG SINH VIEN");				
			}
			break;	
		case 26:
			{
				SetBGColor(3);
				FrameRight1(54,6);
				gotoxy(61,23);
				printf("1.SO LUONG SINH VIEN");
				
				SetBGColor(4);
				FrameRight1(54,7);
				gotoxy(61,26);
				printf("2.KET QUA HOC TAP");
			}
			break;
	}
}
		//...........................................End .............................................//
//Xoa MENU cap 2 khi khong tro toi
void Delete1()
{
	gotoxy(47,15);
	printf("%c",179);
	gotoxy(47,19);
	printf("%c",179);
	gotoxy(47,23);
	printf("%c",179);
}
void Delete(){
	SetBGColor(1);
	for(int j3=6;j3<30;j3++)
	{
		for(int j2=48;j2<91;j2++)
		{
			gotoxy(j2,j3);
			printf(" ");
		}
	}
}
//---------------------------------------------------Bat su kien cho MENU-----------------------------------------//
void Move(int i,int X){
	int demsosv,ktsxep;
	int b;
	MKTSxepr(b);
	int x[6]={7,11,15,19,23,27};
	char c;
	while(1)
	{
		if(kbhit)
		{
			c=getch();
			if(c==72 || c==80)
	 		{
				if(c==80)
				{
					X=x[++i];
					if(i>5)
					{
						X=x[5];
						i=5;
					}
				}	
				else if(c==72)
				{
					X=x[--i];
					if(i<1)
					{
						X=x[0];
						i=0;
					}
				}
				Change(X);
			}
			else if(c==27)
			{
				gotoxy(0,31);
				exit(1);
			}
			else if(c==13||c==77)//Enter va sang phai
			{
				if(X==27 && c!=77)
				{
					gotoxy(0,31);
					exit(1);
				}
				else if(X==15)
				{
					gotoxy(14,15);
					printf("3.SAP XEP     %c%c%c",175,175,175);
					FrameRight2();
					Line();
					SetBGColor(3);
					MoveMSX();		
				}
				else if(X==7 && c!=77)
				{
					ThemDS();
				}
				else if(X==11 && c!=77)
				{
					if(b==0)
					{
						InDS();
					}
					else
					{
						SXChon(b);
					}
				}
				else if(X==19)
				{
					gotoxy(14,19);
					printf("4.TIM KIEM    %c%c%c",175,175,175);
					FrameRight3();
					Line3();
					SetBGColor(3);
					MoveMTKiem();
				}
				else if(X==23)
				{
					gotoxy(14,23);
					printf("5.THONG KE    %c%c%c",175,175,175);
					FrameRight4();
					Line4();
					SetBGColor(3);
					MoveMTKe();
				}				
			}	
		}
	}
}
			//...........................................End .............................................//
//----------------------------------------------Su kien toi cac menu cap 2--------------------------------------------------//
void MoveMSX()
{
	int y[4]={12,15,18,21},Y=0,j=-1,temp1=0;
	char sx;
	while(1)
	{
		if(kbhit())
		{
			sx=getch();
			if((sx==80||sx==72) && temp1 != 1 )//Len xuong MENU cap 2 SAP XEP
			{
				if(sx==80)
				{
					Y=y[++j];
					if(j>3)
					{
						Y=y[3];
						j=3;
					}
				}
				else if(sx==72)
				{
					Y=y[--j];
					if(j<1)
					{
						Y=y[0];
						j=0;
					}
				}
			Change2(Y);
			}
			else if(sx==27 && temp1 != 1 )
			{
				gotoxy(0,31);
				exit(1);
			}
			else if(sx==75 && temp1 != 1 )//Sang trai tat MENU cap 2
			{
				Delete();
				Delete1();
				Change(15);
				Move(2,15);
			}
			else if(sx==13)
			{
				if(Y==12)
				{
					temp1 = 1;
					MenuSXChon();
				}
				else if(Y==15)
				{
					temp1 = 1;
					MenuSXChen();
				}
				else if(Y==18)
				{
					temp1 = 1;
					MenuSXNB();
				}
				else if(Y==21)
				{
					temp1 = 1;
					MenuSXQS();
				}
			}
		}
	}
}
void MoveMTKiem()
{
	int a[2]={19,22},A=0,a1=-1,temp=0;
	char tk;
	while(1)
	{
		if(kbhit())
		{
			tk=getch();
			if(tk==27&& temp!=1 )
			{
				gotoxy(0,31);
				exit(1);
			}
			else if((tk==80||tk==72) && temp!=1 )//Len xuong MENU cap 2
			{
				if(tk==80)
				{
					A=a[++a1];
					if(a1>1)
					{
						A=a[1];
						a1=1;
					}
				}
				else if(tk==72)
				{
					A=a[--a1];
					if(a1<1)
					{
						A=a[0];
						a1=0;
					}
				}
				Change3(A);
			}
			else if(tk==75 && temp!=1 )//Sang trai tat MENU cap 2
			{
				Delete();
				Delete1();
				Change(19);
				Move(3,19);
			}
			else if(tk==13)
			{
				if(A==19)
				{
					temp=1;
					MenuTKiem(1);
				}
				else if(A==22)
				{
					temp=1;
					MenuTKiem(2);
				}
			}
					
		}
	}
}
void MoveMTKe()
{
	int b[2]={23,26},B=0,b1=-1,temp=0,temptk=0;
	char tk1;
	while(1)
	{
		if(kbhit())
		{
			tk1=getch();
			if((tk1==80||tk1==72)&& temp!=1 )//Len xuong MENU cap 2
			{
				if(tk1==80)
				{
					B=b[++b1];
					if(b1>1)
					{
						B=b[1];
						b1=1;
					}
				}
				else if(tk1==72)
				{
					B=b[--b1];
					if(b1<1)
					{
						B=b[0];
						b1=0;
					}
				}
				Change4(B);
			}
			else if(tk1==27&& temp!=1 )
			{
				gotoxy(0,31);
				exit(1);
			}
			else if(tk1==75 && temp!=1 )//Sang trai tat MENU cap 2
			{
				Delete();
				Delete1();
				Change(23);
				Move(4,23);
			}
			else if(tk1==13)
			{
				if(B==23)
				{
					temp=1;
					temptk=1;
					ThongKe(temptk);
				}
				else if(B==26)
				{
					temp=1;
					temptk=2;
					ThongKe(temptk);
				}
			}
		}
	}
}
		//...........................................End .............................................//	
//------------------------------------Ham MAIN Quan Ly Sinh Ly----------------------------------------------//
void MainQLSV()
{
	Title();
	LineMain();
	gotoxy(36,3);
	printf("MENU QUAN LY SINH VIEN");
	
	//Tao khung list menu
	for(int i=0;i<6;i++)
	{
		FrameLeft(6,i);
	}
	ListMenu1();
	gotoxy(0,0);
	Move(-1,0);
	
}
//...........................................End .............................................//
//Tao nut de xu ly su kien
void Button(int j)
{
	gotoxy(15+j,28);
	printf("%c",218);
	gotoxy(26+j,28);
	printf("%c",191);
	gotoxy(15+j,30);
	printf("%c",192);
	gotoxy(26+j,30);
	printf("%c",217);
	
	gotoxy(15+j,29);
	printf("%c",179);
	gotoxy(26+j,29);
	printf("%c",179);
	for(int b11=16;b11<26;b11++)
	{
		gotoxy(b11+j,28);
		printf("%c",196);
		gotoxy(b11+j,30);
		printf("%c",196);
	}
}
//----------------------------------------------------------------------\\
//1.Them Danh Sach
void TitleMenu2(int i)
{
	gotoxy(47,4);
	printf("%c",196);
	gotoxy(0,i);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	
}
void FrameTDS()
{
	for(int j=0;j<5;j++)
	{
		FrameLeft(41,j);
	}
}
void ListTDS()
{
	TextColor(31);
	gotoxy(26,7);
	printf("( AAAA11-1 )");
	gotoxy(26,11);
	printf("( GOM 8 SO )");
	gotoxy(20,15);
	printf("(KO CHUA SO VA KY TU)");
	gotoxy(26,23);
	printf("( INT 01-10 )");
	gotoxy(26,19);
	printf("(DD/MM/YYYY)");
	TextColor(30);
	gotoxy(9,7);
	printf("MA LOP");
	gotoxy(9,11);
	printf("MA SINH VIEN");
	gotoxy(9,15);
	printf("HO VA TEN");
	gotoxy(9,23);
	printf("DIEM TICH LUY");
	gotoxy(9,19);
	printf("NGAY SINH");
}
void ListButton()
{
	SetBGColor(3);
	gotoxy(16,29);
	printf(" NHAP MOI ");
	gotoxy(40,29);
	printf("HOAN THANH");
	gotoxy(64,29);
	printf(" QUAY LAI ");
	Button(0);	Button(24); Button(48);
}

int ChangeTDS(int D)
{
	switch(D)
	{
		case 16:
			{
				SetBGColor(3);
				Button(24);
				gotoxy(40,29);
				printf("HOAN THANH");
				
				SetBGColor(4);
				Button(0);
				gotoxy(16,29);
				printf(" NHAP MOI ");
			}
			break;
		case 40:
			{			
				SetBGColor(3);
				Button(0);
				gotoxy(16,29);
				printf(" NHAP MOI ");
				
				SetBGColor(3);
				Button(48);
				gotoxy(64,29);
				printf(" QUAY LAI ");
				
				SetBGColor(4);
				Button(24);
				gotoxy(40,29);
				printf("HOAN THANH");
			}
			break;
				
		case 64:
			{	
				SetBGColor(3);
				Button(24);
				gotoxy(40,29);
				printf("HOAN THANH");
				
				SetBGColor(4);
				Button(48);
				gotoxy(64,29);
				printf(" QUAY LAI ");
			}
			break;
	}
}
void Xoao1(int k)
{
	int j[5]={7,11,15,19,23};
	gotoxy(57,19);printf("/");
	gotoxy(49,19);printf("/");
	if(k==13 || k==23 ||k==33)
	{
		if(k==13)
		{
			for(int i1=43;i1<=48;i1++)
			{
				gotoxy(i1,j[k-10]);
				printf(" ");
			}
		}
		else if(k==23)
		{
			for(int i1=50;i1<=56;i1++)
			{
				gotoxy(i1,j[k-20]);
				printf(" ");
			}
		}
		else
		{
			for(int i1=58;i1<=95;i1++)
			{
				if(i1!=76)
				{
					gotoxy(i1,j[k-30]);
					printf(" ");
				}
				else
				{
					gotoxy(i1,j[k-30]);
					printf("%c",186);	
				}
			}
		}
	}
	else{
		for(int i=43;i<95;i++)
		{
			if(i!=76)
			{
				gotoxy(i,j[k]);
				printf(" ");
			}
			else
			{
				gotoxy(i,j[k]);
				printf("%c",186);
			}
		}
	}	
}
void NhapTDS(KieuSinhVien *s)
{
	SetBGColor(1);
	do{
	Xoao1(0);
	gotoxy(44,7);
	gets(s->malop);}
	while(strlen(s->malop)>=10);
	do{
	Xoao1(1);
	gotoxy(44,11);
	gets(s->masv);}
	while(strlen(s->masv)>8);
	do{
	Xoao1(2);
	gotoxy(44,15);
	gets(s->hoten);}
	while(strlen(s->hoten)>25);
	do{
	Xoao1(13);
	gotoxy(44,19);
	gets(s->nsc.ngay);}
	while(strlen(s->nsc.ngay)>2);
	do{
	Xoao1(23);
	gotoxy(52,19);
	gets(s->nsc.thang);}
	while(strlen(s->nsc.thang)>2);
	do{
	Xoao1(33);
	gotoxy(60,19);
	gets(s->nsc.nam);}
	while(strlen(s->nsc.nam)>4);
	s->ns.ngay=atoi(s->nsc.ngay);s->ns.thang=atoi(s->nsc.thang);s->ns.nam=atoi(s->nsc.nam);
	do{
	Xoao1(4);
	gotoxy(44,23);
	gets(s->diemc);}
	while(strlen(s->diemc)>2);
}
void DeleteTT()//xoa thong tin khi nhan button trong Them danh sach
{
	SetBGColor(1);
	for(int i=0;i<95;i++)
	{
		gotoxy(i,25);
		printf(" ");
		gotoxy(i,26);
		printf(" ");
	}
}
void Xoao()//Xoa o khi nhap lai
{
	int j[5]={7,11,15,19,23};
	SetBGColor(1);
	for(int k=0;k<5;k++)
	{
		for(int i=43;i<76;i++)
		{
			gotoxy(i,j[k]);
			printf(" ");
		}
	}
	gotoxy(57,19);printf("/");
	gotoxy(49,19);printf("/");

}
//-------------------------------Kiem tra du lieu sinh vien khi nhap vao duoc thong qua qua xuly.h -----------------------------------//
void XetBien(KieuSinhVien *s,int &dem,int &demml,int &demsv,int &demht,int &demd,int &dems,int &demsosv)
{
	ChuanHoaMalop(s->malop);
	ChuanHoaHoten(s->hoten);
	XetMaLop(s->malop,demml);
	XetMasv(s->masv,dem);
	XetMasv1(s->masv,demsv);
	ChuanHoaHoten1(s->hoten,demht);
	XetDiem(s->diemc,demd);
	TronDiem(s->diemc);
	XetNgayS(s->ns.ngay,s->ns.thang,s->ns.nam,dems);
	TextColor(31);
	gotoxy(18,25);
	printf("Chon NHAP MOI de nhap lai hoac HOAN THANH de luu thong tin");
	gotoxy(20,26);
	printf("Hoac QUAY LAI de ra MENU va thong tin khong duoc luu !");
	TextColor(30);
}
//-----------------------------------------Su Kien trong 1.Them Danh sach-----------------------------------------//
void Move2(KieuSinhVien *s,int dem,int demml,int demsv,int demht,int demd,int dems,int demsosv,int &k)
{
	int d[3]={16,40,64},D=0,d1=-1;
	char t;
	Laysosv(demsosv);
	while(1)
	{
	if(kbhit())
	{
		t=getch();
		if(t==77 ||t==75)
		{
			if(t==77)	
			{
				D=d[++d1];
				if(d1>2)
				{
					D=d[2];
					d1=2;
				}
				DeleteTT();
			}
			else if(t==75)
			{
				D=d[--d1];
				if(d1<1)
				{
					D=d[0];
					d1=0;
				}
			}
		ChangeTDS(D);
		}
		else if(t==27)
		{
			SetBGColor(1);
			system("cls");
			MainQLSV();
		}
		else if(t==13 )
		{
			if(D==64)
			{
				SetBGColor(1);
				system("cls");
				MainQLSV();
			}
			else if(D==40)
			{
				d1=-1;
				ListButton();
				SetBGColor(1);
				if(demml==0)
				{
					gotoxy(33,25);
					printf("Ma lop chua hop le.");
					gotoxy(33,26);
					printf("Moi nhap lai dung thong tin !!!");
					
					Xoao1(0);
					gotoxy(44,7);
					gets(s->malop);
					XetBien(s,dem,demml,demsv,demht,demd,dems,demsosv);
				}
				else if(dem!=8)
				{
					gotoxy(33,25);
					printf("Ma sinh vien phai co 8 ky tu, khong duoc de trong. ");
					gotoxy(33,26);
					printf("Moi nhap lai dung thong tin !!!");
					Xoao1(1);
					gotoxy(44,11);
					gets(s->masv);
					XetBien(s,dem,demml,demsv,demht,demd,dems,demsosv);
				}
				else if(demsv==0)
				{
					gotoxy(33,25);
					printf("Ma sinh vien phai la so.");
					gotoxy(33,26);
					printf("Moi nhap lai dung thong tin !!!");
					
					Xoao1(1);
					gotoxy(44,11);
					gets(s->masv);
					XetBien(s,dem,demml,demsv,demht,demd,dems,demsosv);
				}
				else if(demht==0)
				{
					gotoxy(33,25);
					printf("Ho ten khong hop le.");
					gotoxy(33,26);
					printf("Moi nhap lai dung thong tin !!!");
					Xoao1(2);
					gotoxy(44,15);
					gets(s->hoten);
					XetBien(s,dem,demml,demsv,demht,demd,dems,demsosv);
				}
				else if(dems==0)
				{
					gotoxy(33,25);
					printf("Ngay,thang,nam sinh khong hop le.");
					gotoxy(33,26);
					printf("Moi nhap lai dung thong tin !!!");
					Xoao1(3);
					gotoxy(44,19);
					gets(s->nsc.ngay);
					gotoxy(52,19);
					gets(s->nsc.thang);
					gotoxy(60,19);
					gets(s->nsc.nam);
					s->ns.ngay=atoi(s->nsc.ngay);s->ns.thang=atoi(s->nsc.thang);s->ns.nam=atoi(s->nsc.nam);
					XetBien(s,dem,demml,demsv,demht,demd,dems,demsosv);
				}
				else if(demd==0)
				{
					gotoxy(33,25);
					printf("Diem la so nguyen va trong khoang tu 1 - 10.");
					gotoxy(33,26);
					printf("Moi nhap lai dung thong tin !!!");
					Xoao1(4);
					gotoxy(44,23);
					gets(s->diemc);
					XetBien(s,dem,demml,demsv,demht,demd,dems,demsosv);
				}
				else 
				{
					TextColor(31);
					gotoxy(33,26);
					printf("Nhap thong tin thanh cong !!!");
					TextColor(30);
					Input(s);
					fflush(stdin);
					fflush(stdin);
					demsosv++;
					Ghisosv(demsosv);
					MKTSxepw(0);
			 	}
			}
			else if(D==16 )
			{
				Xoao();
				DeleteTT();
				NhapTDS(s);
				XetBien(s,dem,demml,demsv,demht,demd,dems,demsosv);
			}
		}
	}
	}
}
	//...........................................End .............................................//
//------------------------------------------.Ham Tong 1.Them Danh sach-----------------------------------------//
void ThemDS()
{
	int demml,dem,demsv,demht,demd,dems,demsosv,k;
	Laysosv(demsosv);
	KieuSinhVien *s;
	s=(KieuSinhVien *)calloc(3,sizeof(KieuSinhVien));
	SetBGColor(1);
	system("cls");
   	Title();
	TitleMenu2(31);
	gotoxy(36,3);
	printf("   1.THEM DANH SACH");
	ListTDS();
	FrameTDS();
	gotoxy(57,19);printf("/");
	gotoxy(49,19);printf("/");
	TextColor(31);
	gotoxy(20,26);
	printf("Chon NHAP MOI de nhap lai hoac QUAY LAI de ra MENU ! ");
	TextColor(30);
	ListButton();
	Button(0);	Button(24); Button(48);
	gotoxy(0,0);
	Move2(s,dem,demml,demsv,demht,demd,dems,demsosv,k);
	free(s);
	
}
//...............................................................................\\
//2.In Danh Sach

void FormDS(int a)
{
	int z1[7]={2,6,19,30,70,81,92};
	gotoxy(2,8+a);
	printf("%c",218);
	gotoxy(92,8+a);
	printf("%c",191);
	gotoxy(2,10+a);
	printf("%c",192);
	gotoxy(92,10+a);
	printf("%c",217);
		
	for(int i=0;i<7;i++)
	{
		gotoxy(z1[i],9+a);
		printf("%c",179);
	}

	for(int b11=3;b11<92;b11++)
	{
		gotoxy(b11,8+a);
		printf("%c",196);
	}
	if(a==0)
	{
		for(int j=1;j<6;j++)
		{
			gotoxy(z1[j],8+a);
			printf("%c",194);
		}
	}
	else
	{
		for(int j1=1;j1<6;j1++)
		{
			gotoxy(2,8+a);
			printf("%c",195);
			gotoxy(92,8+a);
			printf("%c",180);
			gotoxy(z1[j1],8+a);
			printf("%c",179);
		}
	}
	
}
void FormDS1(int a)
{
	int z1[7]={2,6,19,30,70,81,92};
	TextColor(31);
	gotoxy(65,13+a*2);
	printf("-Nhan DELETE de xoa thong tin-");
	gotoxy(42,14+a*2);
	printf("-Di chuyen va chon thong tin can sua bang phim Enter-");
	gotoxy(60,15+a*2);
	printf("Nhan ESC de quay lai Menu chinh !!!");
	gotoxy(69,6);
	printf("Co tat ca %d sinh vien.",a);
	TextColor(30);
	TitleMenu2(16+a*2);
	for(int i=1;i<=a;i++)
	{
		FormDS(i*2);
	}
	for(int b11=3;b11<92;b11++)
	{
		gotoxy(b11,10+a*2);
		printf("%c",196);
	}
	for(int j1=1;j1<6;j1++)
	{
		gotoxy(z1[j1],10+a*2);
		printf("%c",193);
	}
}

//---------------------------------Ham lay du lieu tu FILE thong qua nhap.h -------------------------------------//
void LayDuLieu(KieuSinhVien s[],int a)
{
	FILE *f;
	f=fopen("ResourceFile/output.txt","rt");
	if(f!=NULL)
	{
		for(int i=1;i<=a;i++)
		{
			fscanf(f,"\n");
			fgets(s[i].malop,20,f);
			fgets(s[i].masv,10,f);
			fgets(s[i].hoten,20,f);
			fgets(s[i].nsc.ngay,30,f);
			fgets(s[i].nsc.thang,30,f);
			fgets(s[i].nsc.nam,30,f);
			fgets(s[i].diemc,20,f);
			gotoxy(4,9+i*2);
			printf("%d",i);
			gotoxy(9,9+i*2);
			printf("%s",s[i].malop);
			gotoxy(21,9+i*2);
			printf("%s",s[i].masv);
			gotoxy(33,9+i*2);
			printf("%s",s[i].hoten);
			gotoxy(71,9+i*2);
			printf("%s",s[i].nsc.ngay);
			gotoxy(73,9+i*2);
			printf("/%s",s[i].nsc.thang);
			gotoxy(76,9+i*2);
			printf("/%s",s[i].nsc.nam);
			gotoxy(86,9+i*2);
			printf("%s",s[i].diemc);
		}
		fclose(f);
	}
}
void ChangeIDS(int F)
{
	gotoxy(3,F);
}
void DInfor(int i)//Xoa Thong tin thanh vien .........................
{
	int demsosv,b,ktsxep;
	Laysosv(demsosv);
	KieuSinhVien s[sosv];
	DLSxep(s,demsosv);
	Input2(s,i);
	b=demsosv-1;
	Ghisosv(b);
	MKTSxepr(ktsxep);
	InDS1(b,ktsxep);
	LayDuLieu(s,b);
	gotoxy(0,0);
	i=0;
	Move3();	
}
//----------------------------------------Phan SUA DANH SACH-------------------------------------------------------//
void ChangeSDS(int Q,int F)
{
	switch(Q)
	{
		case 7:
			gotoxy(7,F);
			break;
		case 20:
			gotoxy(20,F);
			break;
		case 31:
			gotoxy(31,F);
			break;
		case 71:
			gotoxy(71,F);
			break;
		case 82:
			gotoxy(82,F);
			break;
	}
}
void ListButtonSDS()
{
	SetBGColor(3);
	gotoxy(40,29);
	printf("HOAN THANH");
	gotoxy(64,29);
	printf(" QUAY LAI ");
	Button(24); Button(48);
}

int ChangeSTT(int D)
{
	switch(D)
	{
		case 40:
			{							
				SetBGColor(3);
				Button(48);
				gotoxy(64,29);
				printf(" QUAY LAI ");
				
				SetBGColor(4);
				Button(24);
				gotoxy(40,29);
				printf("HOAN THANH");
			}
			break;
				
		case 64:
			{	
				SetBGColor(3);
				Button(24);
				gotoxy(40,29);
				printf("HOAN THANH");
				
				SetBGColor(4);
				Button(48);
				gotoxy(64,29);
				printf(" QUAY LAI ");
			}
			break;
	}
}
void MoveSTT(KieuSinhVien *s,int dem,int demml,int demsv,int demht,int demd,int dems,int demsosv,int &k,int X,int i)
{
	int d[2]={40,64},D=0,d1=-1;
	char t;
	while(1)
	{
	if(kbhit())
	{
		t=getch();
		if(t==77 ||t==75)
		{
			if(t==77)	
			{
				D=d[++d1];
				if(d1>1)
				{
					D=d[1];
					d1=1;
				}
				DeleteTT();
			}
			else if(t==75)
			{
				D=d[--d1];
				if(d1<1)
				{
					D=d[0];
					d1=0;
				}
			}
		ChangeSTT(D);
		}
		else if(t==27)
		{
			SetBGColor(1);
			system("cls");
			MainQLSV();
		}
		else if(t==13)
		{
			if(D==64)
			{
				SetBGColor(1);
				system("cls");
				MainQLSV();
			}
			else if(D==40)
			{
				d1=-1;
				ListButton();
				SetBGColor(1);
				if(X==7 && demml==0)
				{
					gotoxy(33,25);
					printf("Ma lop chua hop le.");
					gotoxy(33,26);
					printf("Moi nhap lai dung thong tin !!!");
					
					Xoao1(0);
					gotoxy(44,7);
					gets(s->malop);
					XetBien(s,dem,demml,demsv,demht,demd,dems,demsosv);
				}
				else if(X==20 && dem!=8)
				{
					gotoxy(33,25);
					printf("Ma sinh vien phai co 8 ky tu, khong duoc de trong. ");
					gotoxy(33,26);
					printf("Moi nhap lai dung thong tin !!!");
					Xoao1(1);
					gotoxy(44,11);
					gets(s->masv);
					XetBien(s,dem,demml,demsv,demht,demd,dems,demsosv);
				}
				else if(X==20 && demsv==0)
				{
						gotoxy(33,25);
						printf("Ma sinh vien phai la so.");
						gotoxy(33,26);
						printf("Moi nhap lai dung thong tin !!!");
						
						Xoao1(1);
						gotoxy(44,11);
						gets(s->masv);
						XetBien(s,dem,demml,demsv,demht,demd,dems,demsosv);
				}
				else if(X==31 && demht==0)
				{
					gotoxy(33,25);
					printf("Ho ten khong hop le.");
					gotoxy(33,26);
					printf("Moi nhap lai dung thong tin !!!");
					Xoao1(2);
					gotoxy(44,15);
					gets(s->hoten);
					XetBien(s,dem,demml,demsv,demht,demd,dems,demsosv);
				}
				else if(X==71 && dems==0)
				{
					gotoxy(33,25);
					printf("Ngay,thang,nam sinh khong hop le.");
					gotoxy(33,26);
					printf("Moi nhap lai dung thong tin !!!");
					Xoao1(3);
					gotoxy(44,19);
					gets(s->nsc.ngay);
					gotoxy(52,19);
					gets(s->nsc.thang);
					gotoxy(60,19);
					gets(s->nsc.nam);
					s->ns.ngay=atoi(s->nsc.ngay);s->ns.thang=atoi(s->nsc.thang);s->ns.nam=atoi(s->nsc.nam);
					XetBien(s,dem,demml,demsv,demht,demd,dems,demsosv);
				}				
				else if(X==82 && demd==0)
				{
					gotoxy(33,25);
					printf("Diem la so nguyen va trong khoang tu 1 - 10.");
					gotoxy(33,26);
					printf("Moi nhap lai dung thong tin !!!");
					Xoao1(4);
					gotoxy(44,23);
					gets(s->diemc);
					XetBien(s,dem,demml,demsv,demht,demd,dems,demsosv);
				}
				else
				{
					gotoxy(33,26);
					printf("Nhap thong tin thanh cong !!!");
					Input3(s,X,i);
					fflush(stdin);
					fflush(stdin);
					MKTSxepw(0);
			 	}
			}
		}
	}
	}
}
void NhapSDS(KieuSinhVien *s,int X,int i)
{
	SetBGColor(1);
	if(X==7)
	{
		gotoxy(44,11);
		printf("%s",s[i].masv);
		gotoxy(44,15);
		printf("%s",s[i].hoten);
		gotoxy(44,19);
		printf("%s",s[i].nsc.ngay);
		gotoxy(52,19);
		printf("%s",s[i].nsc.thang);
		gotoxy(60,19);
		printf("%s",s[i].nsc.nam);
		gotoxy(44,23);
		printf("%s",s[i].diemc);
		do{
		Xoao1(0);
		gotoxy(44,7);
		gets(s[i].malop);}
		while(strlen(s[i].malop)>=10);
	}
	else if(X==20)
	{
		gotoxy(44,7);
		printf("%s",s[i].malop);
		gotoxy(44,15);
		printf("%s",s[i].hoten);
		gotoxy(44,19);
		printf("%s",s[i].nsc.ngay);
		gotoxy(52,19);
		printf("%s",s[i].nsc.thang);
		gotoxy(60,19);
		printf("%s",s[i].nsc.nam);
		gotoxy(44,23);
		printf("%s",s[i].diemc);
		do{
		Xoao1(1);
		gotoxy(44,11);
		gets(s[i].masv);}
		while(strlen(s[i].masv)>8);
	}
	else if(X==31)
	{
		gotoxy(44,7);
		printf("%s",s[i].malop);
		gotoxy(44,11);
		printf("%s",s[i].masv);
		gotoxy(44,19);
		printf("%s",s[i].nsc.ngay);
		gotoxy(52,19);
		printf("%s",s[i].nsc.thang);
		gotoxy(60,19);
		printf("%s",s[i].nsc.nam);
		gotoxy(44,23);
		printf("%s",s[i].diemc);
		do{
		Xoao1(2);
		gotoxy(44,15);
		gets(s[i].hoten);}
		while(strlen(s[i].hoten)>25);
	}
	else if(X==71)
	{
		gotoxy(44,7);
		printf("%s",s[i].malop);
		gotoxy(44,11);
		printf("%s",s[i].masv);
		gotoxy(44,15);
		printf("%s",s[i].hoten);
		gotoxy(44,23);
		printf("%s",s[i].diemc);
		do{
		Xoao1(13);
		TextColor(31);
		gotoxy(29,26);
		printf("Nhap NGAY SINH gom 2 chu so !!!");
		TextColor(30);
		gotoxy(44,19);
		gets(s[i].nsc.ngay);}
		while(strlen(s[i].nsc.ngay)!=2);
		do{
		Xoao1(23);
		TextColor(31);
		gotoxy(29,26);
		printf("Nhap THANG SINH gom 2 chu so !!!");
		TextColor(30);
		gotoxy(52,19);
		gets(s[i].nsc.thang);}
		while(strlen(s[i].nsc.thang)!=2);
		do{
		Xoao1(33);
		TextColor(31);
		gotoxy(29,26);
		printf("Nhap NAM SINH gom 4 chu so !!!");
		TextColor(30);
		gotoxy(60,19);
		gets(s[i].nsc.nam);}
		while(strlen(s[i].nsc.nam)!=4);
		s[i].ns.ngay=atoi(s[i].nsc.ngay);s[i].ns.thang=atoi(s[i].nsc.thang);s[i].ns.nam=atoi(s[i].nsc.nam);
	}
	else if(X==82)
	{
		gotoxy(44,7);
		printf("%s",s[i].malop);
		gotoxy(44,11);
		printf("%s",s[i].masv);
		gotoxy(44,15);
		printf("%s",s[i].hoten);
		gotoxy(44,19);
		printf("%s",s[i].nsc.ngay);
		gotoxy(52,19);
		printf("%s",s[i].nsc.thang);
		gotoxy(60,19);
		printf("%s",s[i].nsc.nam);
		do{
		Xoao1(4);
		TextColor(31);
		gotoxy(29,26);
		printf("Nhap DIEM gom 2 chu so !!!");
		TextColor(30);
		gotoxy(44,23);
		gets(s[i].diemc);}
		while(strlen(s[i].diemc)>2);
	}
}
void XetBienSDS(KieuSinhVien *s,int &dem,int &demml,int &demsv,int &demht,int &demd,int &dems,int &demsosv,int i)
{
	ChuanHoaMalop(s[i].malop);
	ChuanHoaHoten(s[i].hoten);
	XetMaLop(s[i].malop,demml);	
	XetMasv(s[i].masv,dem);
	XetMasv1(s[i].masv,demsv);
	ChuanHoaHoten1(s[i].hoten,demht);
	XetDiem(s[i].diemc,demd);
	TronDiem(s[i].diemc);
	XetNgayS(s[i].ns.ngay,s[i].ns.thang,s[i].ns.nam,dems);
	TextColor(31);
	gotoxy(27,25);
	printf("HOAN THANH de luu thong tin");
	gotoxy(20,26);
	printf("Hoac QUAY LAI de ra MENU va thong tin khong duoc luu !");
	TextColor(30);
}
void SuaDL(int i,int X)
{
	int demml,demsv,demht,demd,dems,dem,demsosv,k;
	Laysosv(demsosv);
	KieuSinhVien *s;
	s=(KieuSinhVien *)calloc(demsosv+1,sizeof( KieuSinhVien ));
	SetBGColor(1);
	system("cls");
  	Title();
	TitleMenu2(31);
	gotoxy(36,3);                
	printf("   SUA THONG TIN SV");
	ListTDS();
	FrameTDS();
	ListButtonSDS();
	Button(24); Button(48);
	gotoxy(0,0);
	DLSua(s,demsosv);
	NhapSDS(s,X,i);
	XetBienSDS(s,dem,demml,demsv,demht,demd,dems,demsosv,i);
	MoveSTT(s,dem,demml,demsv,demht,demd,dems,demsosv,k,X,i);
}
void MoveSDS(int i,int F)
{
	int X=7,x[5]={7,20,31,71,82},x1=0;
	char z;
	while(1)
	{
		if(kbhit())
		{
			z=getch();
			if(z==75||z==77 )//Len xuong MENU cap 2
			{
				
				if(z==77)
				{
					X=x[++x1];
					if(x1>4)
				 	{
						X=x[4];
						x1=4;
					}
				}
				else if(z==75)
				{
					X=x[--x1];
					if(x1<1)
					{
						X=x[0];
						x1=0;
					}
				}
				ChangeSDS(X,F);
			}
			else if(z==27)
			{
				F=0;
				ChangeIDS(F);
				Move3();	
			}
			else if(z==13)
			{
				SuaDL(i,X);
			}
		}
	}
}

//-------------------------------------Su kien len xuong trong 2.In danh sach--------------------------------------//
void Move3()
{
	int a;
	Laysosv(a);
	int *q,i,F=0;
	q=(int*)calloc(a,20);
	for(i=1;i<=a;i++)
	{
		*(q+i)=9+2*i;
	}
	i=0;
	char z;
	while(1)
	{
		if(kbhit())
		{
			z=getch();
			if(z==27)
			{
				SetBGColor(1);
				system("cls");
				MainQLSV();
			}
			else if(z==80 || z==72)
			{
				if(z==80)	
				{
					i=i+1;
					F=*(q+i);
					if(i>a)
					{
						F=16+a*2;
						i=a+1;
					}
				}
				else if(z==72)
				{
					
					i=i-1;
					F=*(q+i);		
					if(i<1)
					{
						F=0;
						i=0;
					}
				}
			ChangeIDS(F);
			}
			else if(z==13)
			{
				int X=7;
				ChangeSDS(X,F);
				MoveSDS(i,F);
			}
			else if(z==83)
			{
				if(a>0 && i!=0 && i!=a+1)
				{
					TextColor(30);
					DInfor(i);
				}
			}
		}
	}
}
void ListIDS()
{
	gotoxy(3,9);
	printf("STT");
	gotoxy(10,9);
	printf("MA LOP");
	gotoxy(22,9);
	printf("MA SV");
	gotoxy(47,9);
	printf("HO VA TEN");
	gotoxy(71,9);
	printf("NGAY SINH");
	gotoxy(85,9);
	printf("DIEM");
}
void InDS1(int demsosv,int ktsxep)
{
	SetBGColor(1);
	system("cls");
	Title();
	gotoxy(36,3);
	printf("    2.IN DANH SACH");
	gotoxy(31,5);
	printf("DANH SACH SINH VIEN TOAN TRUONG");
	ListIDS();
	TextColor(31);
	if(demsosv>0){
	if(ktsxep==0)
	{
		gotoxy(57,7);//14+demsosv*2
		printf("CHU Y: Danh sach chua duoc sap xep !");
	}
	else if(ktsxep==52)
	{
		gotoxy(41,7);
		printf("CHU Y:  Danh sach sap xep DIEM theo chieu giam dan !");
	}
	else if(ktsxep==51)
	{
		gotoxy(41,7);
		printf("CHU Y:  Danh sach sap xep DIEM theo chieu tang dan !");
	}
	else if(ktsxep==11)
	{
		gotoxy(41,7);
		printf("CHU Y:Danh sach sap xep MA LOP theo chieu tang dan !");
	}
	else if(ktsxep==12)
	{
		gotoxy(41,7);
		printf("CHU Y:Danh sach sap xep MA LOP theo chieu giam dan !");
	}
	else if(ktsxep==21)
	{
		gotoxy(41,7);
		printf("CHU Y: Danh sach sap xep MA SV theo chieu tang dan !");
	}
	else if(ktsxep==22)
	{
		gotoxy(41,7);
		printf("CHU Y: Danh sach sap xep MA SV theo chieu giam dan !");
	}
	else if(ktsxep==32)
	{
		gotoxy(41,7);
		printf("CHU Y:Danh sach sap xep HO TEN theo chieu giam dan !");
	}
	else if(ktsxep==31)
	{
		gotoxy(41,7);
		printf("CHU Y:Danh sach sap xep HO TEN theo chieu tang dan !");
	}
	else if(ktsxep==42)
	{
		gotoxy(38,7);
		printf("CHU Y:Danh sach sap xep NGAY SINH theo chieu giam dan !");
	}
	else if(ktsxep==41)
	{
		gotoxy(38,7);
		printf("CHU Y:Danh sach sap xep NGAY SINH theo chieu tang dan !");
	}}
	TextColor(30);
	FormDS(0);
	FormDS1(demsosv);	
}
//-----------------------------------Ham MAIN 2.In Danh Sach --------------------------------------//
void InDS()
{
	int demsosv,ktsxep;
	Laysosv(demsosv);
	KieuSinhVien s[sosv];
	MKTSxepr(ktsxep);
	InDS1(demsosv,ktsxep);
	LayDuLieu(s,demsosv);
	gotoxy(0,0);
	Move3();
}
//........................................................\\
//3.Sap xep
void FrameSX(int a)
{
	FrameLeft(30,a);
}
void ChangeSX(int a)
{
	switch(a)
	{
		case 11:
			{
				SetBGColor(1);
				FrameSX(2);
				gotoxy(40,15);
				printf("2.MA SINH VIEN");
				
				SetBGColor(4);
				FrameSX(1);
				gotoxy(40,11);
				printf("1.MA LOP");
			}
			break;
		case 15:
			{
				SetBGColor(1);
				FrameSX(3);
				gotoxy(40,19);
				printf("3.HO TEN");
				
				SetBGColor(1);
				FrameSX(1);
				gotoxy(40,11);
				printf("1.MA LOP");
				
				SetBGColor(4);
				FrameSX(2);
				gotoxy(40,15);
				printf("2.MA SINH VIEN");
			}
			break;
		case 19:
			{
				SetBGColor(1);
				FrameSX(4);
				gotoxy(40,23);
				printf("4.NGAY SINH");
				
				SetBGColor(1);
				FrameSX(2);
				gotoxy(40,15);
				printf("2.MA SINH VIEN");
				
				SetBGColor(4);
				FrameSX(3);
				gotoxy(40,19);
				printf("3.HO TEN");
			}
			break;
		case 23:
			{
				SetBGColor(1);
				FrameSX(3);
				gotoxy(40,19);
				printf("3.HO TEN");
				
				SetBGColor(1);
				FrameSX(5);
				gotoxy(40,27);
				printf("5.DIEM TRUNG BINH");
				
				SetBGColor(4);
				FrameSX(4);
				gotoxy(40,23);
				printf("4.NGAY SINH");				
			}
			break;
		case 27:
			{
				SetBGColor(1);
				FrameSX(4);
				gotoxy(40,23);
				printf("4.NGAY SINH");
				
				SetBGColor(4);
				FrameSX(5);
				gotoxy(40,27);
				printf("5.DIEM TRUNG BINH");
			}
			break;
	}
	
}
void ListSX()
{
	gotoxy(40,11);
	printf("1.MA LOP");
	gotoxy(40,15);
	printf("2.MA SINH VIEN");
	gotoxy(40,19);
	printf("3.HO TEN");
	gotoxy(40,23);
	printf("4.NGAY SINH");
	gotoxy(40,27);
	printf("5.DIEM TRUNG BINH");
}
                    //Sap xep chon
//--------------------------------------Giao dien Sap xep (CHON) cho cac chuc nang Sap Xep-------------------------------------//
void MoveSXC(int tempsx1)
{
	int y[5]={11,15,19,23,27},Y=0,j=-1,temp=0,tempsx=0;
	char sx1;
	while(1)
	{
		if(kbhit())
		{
			sx1=getch();
			if((sx1==80||sx1==72) && temp!=1 )//Len xuong MENU cap 2 SAP XEP
			{
				if(sx1==80)
				{
					Y=y[++j];
					if(j>4)
					{
						Y=y[4];
						j=4;
					}
				}
				else if(sx1==72)
				{
					Y=y[--j];
					if(j<1)
					{
						Y=y[0];
						j=0;
					}
				}
			ChangeSX(Y);
			}
			else if(sx1==27)
			{
				SetBGColor(1);
				system("cls");
				MainQLSV();
			}
			else if(sx1==13)
			{
				if(Y==11)
				{
					tempsx=1+tempsx1;
					MenuTG(tempsx);
					temp=1;
				}
				else if(Y==15)
				{
					tempsx=2+tempsx1;
					MenuTG(tempsx);
					temp=1;
				}
				else if(Y==19)
				{
					tempsx=3+tempsx1;
					MenuTG(tempsx);
					temp=1;
				}
				else if(Y==23)
				{
					tempsx=4+tempsx1;
					MenuTG(tempsx);
					temp=1;
				}
				else if(Y==27)
				{
					tempsx=5+tempsx1;
					MenuTG(tempsx);
					temp=1;
				}
			}
		}
	}
}
void MenuSXChen()
{
	SetBGColor(1);
	system("cls");
   	Title();
	TitleMenu2(31);
	gotoxy(60,30);
	printf("Nhan ESC de quay lai Menu chinh !!!");
	gotoxy(36,3);                
	printf("       3.SAP XEP     ");
	gotoxy(29,8);
	printf("LUA CHON KHOA DE SAP XEP THEO PP CHEN.");
	for(int j=1;j<6;j++)
	{
		FrameSX(j);
	}
	ListSX();
	gotoxy(0,0);
	MoveSXC(20);	
}
void MenuSXChon()
{
	SetBGColor(1);
	system("cls");
   	Title();
	TitleMenu2(31);
	gotoxy(60,30);
	printf("Nhan ESC de quay lai Menu chinh !!!");
	gotoxy(36,3);                
	printf("       3.SAP XEP     ");
	gotoxy(29,8);
	printf("LUA CHON KHOA DE SAP XEP THEO PP CHON.");
	for(int j=1;j<6;j++)
	{
		FrameSX(j);
	}
	ListSX();
	gotoxy(0,0);
	MoveSXC(10);	
}
void MenuSXNB()
{
	SetBGColor(1);
	system("cls");
   	Title();
	TitleMenu2(31);
	gotoxy(60,30);
	printf("Nhan ESC de quay lai Menu chinh !!!");
	gotoxy(36,3);                
	printf("       3.SAP XEP     ");
	gotoxy(29,8);
	printf("LUA CHON KHOA DE SAP XEP THEO PP NOT BOT.");
	for(int j=1;j<6;j++)
	{
		FrameSX(j);
	}
	ListSX();
	gotoxy(0,0);
	MoveSXC(30);	
}
void MenuSXQS()
{
	SetBGColor(1);
	system("cls");
   	Title();
	TitleMenu2(31);
	gotoxy(60,30);
	printf("Nhan ESC de quay lai Menu chinh !!!");
	gotoxy(36,3);                
	printf("       3.SAP XEP     ");
	gotoxy(27,8);
	printf("LUA CHON KHOA DE SAP XEP THEO PP QUICKSORT.");
	for(int j=1;j<6;j++)
	{
		FrameSX(j);
	}
	ListSX();
	gotoxy(0,0);
	MoveSXC(40);	
}
void SXChen(int temptg2)
{
	int demsosv,ktsxep;
	Laysosv(demsosv);
	KieuSinhVien s[sosv];
	DLSxep(s,demsosv);
	if(temptg2==52){MKTSxepw(52);SapxepEDG(s,demsosv);}
	else if(temptg2==51){MKTSxepw(51);SapxepEDT(s,demsosv);}
	else if(temptg2==11){MKTSxepw(11);SapxepEMLT(s,demsosv);}
	else if(temptg2==12){MKTSxepw(12);SapxepEMLG(s,demsosv);}
	else if(temptg2==21){MKTSxepw(21);SapxepEMST(s,demsosv);}
	else if(temptg2==22){MKTSxepw(22);SapxepEMSG(s,demsosv);}
	else if(temptg2==31){MKTSxepw(31);SapxepEHTT(s,demsosv);}
	else if(temptg2==32){MKTSxepw(32);SapxepEHTG(s,demsosv);}
	else if(temptg2==41){MKTSxepw(41);SapxepENST(s,demsosv);}
	else if(temptg2==42){MKTSxepw(42);SapxepENSG(s,demsosv);}
	Input2(s,0);	
	MKTSxepr(ktsxep);
	InDS1(demsosv,ktsxep);
	LayDuLieu(s,demsosv);
	gotoxy(0,0);
	Move3();		
}
void SXChon(int temptg)
{
	int demsosv,ktsxep;
	Laysosv(demsosv);
	KieuSinhVien s[sosv];
	DLSxep(s,demsosv);
	if(temptg==52){MKTSxepw(52);SapxepCDG(s,demsosv);}
	else if(temptg==51){MKTSxepw(51);SapxepCDT(s,demsosv);}
	else if(temptg==11){MKTSxepw(11);SapxepCMLT(s,demsosv);}
	else if(temptg==12){MKTSxepw(12);SapxepCMLG(s,demsosv);}
	else if(temptg==21){MKTSxepw(21);SapxepCMST(s,demsosv);}
	else if(temptg==22){MKTSxepw(22);SapxepCMSG(s,demsosv);}
	else if(temptg==31){MKTSxepw(31);SapxepCHTT(s,demsosv);}
	else if(temptg==32){MKTSxepw(32);SapxepCHTG(s,demsosv);}
	else if(temptg==41){MKTSxepw(41);SapxepCNST(s,demsosv);}
	else if(temptg==42){MKTSxepw(42);SapxepCNSG(s,demsosv);}
	Input2(s,0);	
	MKTSxepr(ktsxep);
	InDS1(demsosv,ktsxep);
	LayDuLieu(s,demsosv);
	gotoxy(0,0);
	Move3();		
}
void SXNB(int temptg3)
{
	int demsosv,ktsxep;
	Laysosv(demsosv);
	KieuSinhVien s[sosv];
	DLSxep(s,demsosv);
	if(temptg3==52){MKTSxepw(52);SapxepBDG(s,demsosv);}
	else if(temptg3==51){MKTSxepw(51);SapxepBDT(s,demsosv);}
	else if(temptg3==11){MKTSxepw(11);SapxepBMLT(s,demsosv);}
	else if(temptg3==12){MKTSxepw(12);SapxepBMLG(s,demsosv);}
	else if(temptg3==21){MKTSxepw(21);SapxepBMST(s,demsosv);}
	else if(temptg3==22){MKTSxepw(22);SapxepBMSG(s,demsosv);}
	else if(temptg3==31){MKTSxepw(31);SapxepBHTT(s,demsosv);}
	else if(temptg3==32){MKTSxepw(32);SapxepBHTG(s,demsosv);}
	else if(temptg3==41){MKTSxepw(41);SapxepBNST(s,demsosv);}
	else if(temptg3==42){MKTSxepw(42);SapxepBNSG(s,demsosv);}
	Input2(s,0);
	MKTSxepr(ktsxep);
	InDS1(demsosv,ktsxep);
	LayDuLieu(s,demsosv);
	gotoxy(0,0);
	Move3();		
}
void SXQS(int temptg4)
{
	int demsosv,ktsxep;
	Laysosv(demsosv);
	KieuSinhVien s[sosv];
	DLSxep(s,demsosv);
	if(temptg4==52){MKTSxepw(52);SapxepQDG(s,1,demsosv);}
	else if(temptg4==51){MKTSxepw(51);SapxepQDT(s,1,demsosv);}
	else if(temptg4==11){MKTSxepw(11);SapxepQMLT(s,1,demsosv);}
	else if(temptg4==12){MKTSxepw(12);SapxepQMLG(s,1,demsosv);}
	else if(temptg4==21){MKTSxepw(21);SapxepQMST(s,1,demsosv);}
	else if(temptg4==22){MKTSxepw(22);SapxepQMSG(s,1,demsosv);}
	else if(temptg4==31){MKTSxepw(31);SapxepQHTT(s,1,demsosv);}
	else if(temptg4==32){MKTSxepw(32);SapxepQHTG(s,1,demsosv);}
	else if(temptg4==41){MKTSxepw(41);SapxepQNST(s,1,demsosv);}
	else if(temptg4==42){MKTSxepw(42);SapxepQNSG(s,1,demsosv);}
	Input2(s,0);	
	MKTSxepr(ktsxep);
	InDS1(demsosv,ktsxep);
	LayDuLieu(s,demsosv);
	gotoxy(0,0);
	Move3();		
}
//----------------------------------------Menu SX tang giam---------------------------------------------------
void ListSXTG()
{
	gotoxy(36,15);
	printf("1.SAP XEP THEO CHIEU TANG");
	gotoxy(36,19);
	printf("2.SAP XEP THEO CHIEU GIAM");
	gotoxy(45,27);
	printf("THOAT");
}
void ChangeSXTG(int a)
{
	switch(a)
	{
		case 15:
			{
				SetBGColor(1);
				FrameSX(3);
				gotoxy(36,19);
				printf("2.SAP XEP THEO CHIEU GIAM");
				
				SetBGColor(4);
				FrameSX(2);
				gotoxy(36,15);
				printf("1.SAP XEP THEO CHIEU TANG");
			}
			break;
		case 19:
			{				
				SetBGColor(1);
				FrameSX(2);
				gotoxy(36,15);
				printf("1.SAP XEP THEO CHIEU TANG");
				
				SetBGColor(1);
				FrameSX(5);
				gotoxy(45,27);
				printf("THOAT");
				
				SetBGColor(4);
				FrameSX(3);
				gotoxy(36,19);
				printf("2.SAP XEP THEO CHIEU GIAM");
			}
			break;
		case 27:
			{
				SetBGColor(1);
				FrameSX(3);
				gotoxy(36,19);
				printf("2.SAP XEP THEO CHIEU GIAM");
				
				SetBGColor(4);
				FrameSX(5);
				gotoxy(45,27);
				printf("THOAT");				
			}
			break;
	}	
}
//------------------------------------Su kien trong MENU chung Sap Xep tang giam -----------------------------------------//
void MoveSXTG(int tempsx)
{ 
	int sx[5]={15,19,27},SX=0,sx1=-1,ktsxep,demsosv,temp,temptg,temptg3,temptg2,temptg4;
	Laysosv(demsosv);
	char sxt;
	while(1)
	{
		if(kbhit())
		{
			sxt=getch();
			if((sxt==72 || sxt==80)&& temp!=1)
			{
				if(sxt==80)
				{
					SX=sx[++sx1];
					if(sx1>3)
					{
						SX=sx[3];
						sx1=3;
					}
				}	
				else if(sxt==72)
				{
					SX=sx[--sx1];
					if(sx1<1)
					{
						SX=sx[0];
						sx1=0;
					}
				}
				ChangeSXTG(SX);
			}
			else if(sxt==27&& temp!=1)
			{
				SetBGColor(1);
				system("cls");
				MenuSXChon();
			}
			else if(sxt==13)
			{
				if(SX==15)
				{
					if(tempsx==15){temp=1;temptg=51;SXChon(temptg);	}
					else if(tempsx==11){temp=1;temptg=11;SXChon(temptg);}	
					else if(tempsx==12){temp=1;temptg=21;SXChon(temptg);}
					else if(tempsx==13){temp=1;temptg=31;SXChon(temptg);}
					else if(tempsx==14){temp=1;temptg=41;SXChon(temptg);}
					
					else if(tempsx==21){temp=1;temptg2=11;SXChen(temptg2);}
					else if(tempsx==22){temp=1;temptg2=21;SXChen(temptg2);}
					else if(tempsx==23){temp=1;temptg2=31;SXChen(temptg2);}
					else if(tempsx==24){temp=1;temptg2=41;SXChen(temptg2);}
					else if(tempsx==25){temp=1;temptg2=51;SXChen(temptg2);}
					
					else if(tempsx==31){temp=1;temptg3=11;SXNB(temptg3);}
					else if(tempsx==32){temp=1;temptg3=21;SXNB(temptg3);}
					else if(tempsx==33){temp=1;temptg3=31;SXNB(temptg3);}
					else if(tempsx==34){temp=1;temptg3=41;SXNB(temptg3);}
					else if(tempsx==35){temp=1;temptg3=51;SXNB(temptg3);}

					else if(tempsx==41){temp=1;temptg4=11;SXQS(temptg4);}
					else if(tempsx==42){temp=1;temptg4=21;SXQS(temptg4);}
					else if(tempsx==43){temp=1;temptg4=31;SXQS(temptg4);}
					else if(tempsx==44){temp=1;temptg4=41;SXQS(temptg4);}
					else if(tempsx==45){temp=1;temptg4=51;SXQS(temptg4);}
								
				}
				else if(SX==19)
				{
					if(tempsx==15){temp=1;temptg=52;SXChon(temptg);}
					else if(tempsx==11){temp=1;temptg=12;SXChon(temptg);}
					else if(tempsx==12){temp=1;temptg=22;SXChon(temptg);}
					else if(tempsx==13){temp=1;temptg=32;SXChon(temptg);}
					else if(tempsx==14){temp=1;temptg=42;SXChon(temptg);}
					
					else if(tempsx==21){temp=1;temptg2=12;SXChen(temptg2);}
					else if(tempsx==22){temp=1;temptg2=22;SXChen(temptg2);}
					else if(tempsx==23){temp=1;temptg2=32;SXChen(temptg2);}
					else if(tempsx==24){temp=1;temptg2=42;SXChen(temptg2);}
					else if(tempsx==25){temp=1;temptg2=52;SXChen(temptg2);}
					
					else if(tempsx==31){temp=1;temptg3=12;SXNB(temptg3);}
					else if(tempsx==32){temp=1;temptg3=22;SXNB(temptg3);}
					else if(tempsx==33){temp=1;temptg3=32;SXNB(temptg3);}
					else if(tempsx==34){temp=1;temptg3=42;SXNB(temptg3);}
					else if(tempsx==35){temp=1;temptg3=52;SXNB(temptg3);}
					
					else if(tempsx==41){temp=1;temptg4=12;SXQS(temptg4);}
					else if(tempsx==42){temp=1;temptg4=22;SXQS(temptg4);}
					else if(tempsx==43){temp=1;temptg4=32;SXQS(temptg4);}
					else if(tempsx==44){temp=1;temptg4=42;SXQS(temptg4);}
					else if(tempsx==45){temp=1;temptg4=52;SXQS(temptg4);}
				}
				else if(SX==27)
				{
					SetBGColor(1);
					system("cls");
					MenuSXChon();
				}
			}
		}
	}
}
void MenuTG(int tempsx)//Menu sap xep tang giam
{
	SetBGColor(1);
	system("cls");
	Title();
	TitleMenu2(31);
	gotoxy(36,3);                
	printf("       3.SAP XEP     ");
	gotoxy(35,8);
	printf("LUA CHON KHOA DE SAP XEP.");
	for(int j=2;j<6;j++)
	{
		if(j!=4)
		{
			FrameSX(j);
		}
	}
	ListSXTG();
	gotoxy(0,0);
	MoveSXTG(tempsx);		
}
//-----------------------------------------4.TIM KIEM-----------------------------//
void ChangeTKiem(int a)
{
	switch(a)
	{
		case 29:
			SetBGColor(4);
			Button(24);
			gotoxy(40,29);
			printf(" TIM KIEM ");
		break;		
	}
}

void MoveTKiem(char tkiem[],char tkiemnt[],int kttk)
{
	int tk[1]={29},TK=0,tk1=-1;
	char tk2;
	while(1)
	{
		if(kbhit())
		{
			tk2=getch();
			if(tk2==77 || tk2==75)
			{
				if(tk2==77)
				{
					TK=tk[++tk1];
					if(tk1>1)
					{
						TK=tk[0];
						tk1=0;
					}
				}	
				else if(tk2==75)
				{
					TK=tk[--tk1];
					if(tk1<1)
					{
						TK=tk[0];
						tk1=0;
					}
				}
				ChangeTKiem(TK);
			}
			else if(tk2==27)
			{
				SetBGColor(1);
				system("cls");
				if(kttk==11 ||kttk==12||kttk==13||kttk==14||kttk==15)
				{
					MenuTKiem(1);
				}
				else if(kttk==211 ||kttk==221 ||kttk==231 ||kttk==241 ||kttk==251 || kttk==212 ||kttk==222 ||kttk==232 ||kttk==242 ||kttk==252)
				{
					MenuTKiem(2);
				}
			}
			else if(tk2==13)
			{
				if(TK==29)
				{
					if(kttk==12)
					{
						DSTK(tkiem,tkiemnt,12);
					}
					else if(kttk==11)
					{
						DSTK(tkiem,tkiemnt,11);
					}
					else if(kttk==15)
					{
						DSTK(tkiem,tkiemnt,15);
					}
					else if(kttk==14)
					{
						DSTK(tkiem,tkiemnt,14);
					}
					else if(kttk==13)
					{
						DSTK(tkiem,tkiemnt,13);
					}
					else if(kttk==251)
					{
						DSTK(tkiem,tkiemnt,251);
					}
					else if(kttk==252)
					{
						DSTK(tkiem,tkiemnt,252);
					}
					else if(kttk==221)
					{
						DSTK(tkiem,tkiemnt,221);
					}
					else if(kttk==222)
					{
						DSTK(tkiem,tkiemnt,222);
					}
					else if(kttk==211)
					{
						DSTK(tkiem,tkiemnt,211);
					}
					else if(kttk==212)
					{
						DSTK(tkiem,tkiemnt,212);
					}
					else if(kttk==231)
					{
						DSTK(tkiem,tkiemnt,231);
					}
					else if(kttk==232)
					{
						DSTK(tkiem,tkiemnt,232);
					}
					else if(kttk==241)
					{
						DSTK(tkiem,tkiemnt,241);
					}
					else if(kttk==242)
					{
						DSTK(tkiem,tkiemnt,242);
					}
				}
			}
		}
	}			
}
void ListButton1()
{
	SetBGColor(3);
	gotoxy(40,29);
	printf(" TIM KIEM ");
	Button(24);
}
void DLTK(char tkiem[20])
{
	SetBGColor(1);
	gotoxy(34,15);
	gets(tkiem);
	gotoxy(20,20);
	printf("Chon Tim Kiem de tim thong tin hoac nhan ESC de ra MENU");
}
void XoaTB()
{
	for(int u=20;u<85;u++)
	{
		for(int i=20;i<26;i++)
		{
			gotoxy(u,i);
			printf(" ");
		}
	}
	gotoxy(20,20);
	printf("Chon Tim Kiem de tim thong tin hoac nhan ESC de ra MENU");	
}
void DLTKNT(char tkiemnt[20])
{
	int temp=1;
	SetBGColor(1);
	do{
		for(int i=32;i<64;i++)
		{
			gotoxy(i,15);
			printf(" ");
		}
		gotoxy(34,15);
		gets(tkiemnt);
		if((int(tkiemnt[0])==100 && int(tkiemnt[1])==100) && strlen(tkiemnt)==4)
		{
			temp=0;
		}
		else if((int(tkiemnt[0])==109 && int(tkiemnt[1])==109) && strlen(tkiemnt)==4)
		{
			temp=0;
		}
		else if((int(tkiemnt[0])==121 && int(tkiemnt[1])==121) && strlen(tkiemnt)==6)
		{
			temp=0;
		}
	}while(temp==1);
	XoaTB();
}
void FormTKiem(int kttk)
{
	char tkiem[20],tkiemnt[20];
	SetBGColor(1);
	system("cls");
	Title();
	gotoxy(36,3);                
	printf("       4.TIM KIEM     ");
	TitleMenu2(31);
	FrameSX(2);
	gotoxy(35,11);
	printf("NHAP TU KHOA MUON TIM KIEM");
	ListButton1();
	if(kttk==11 || kttk==12 || kttk==15 || kttk==13)
	{
		DLTK(tkiem);
	}
	else if(kttk==14)
	{
		TextColor(28);
		gotoxy(20,20);
		printf("LUU Y: ");
		TextColor(31);
		gotoxy(27,20);
		printf("Nhap ddXX de tim thong tin theo NGAY SINH.");
		gotoxy(27,21);
		printf("Hoac nhap mmXX de tim thong tin theo THANG SINH.");
		gotoxy(27,22);
		printf("Hoac nhap yyXXXX de tim thong tin theo NAM SINH.");
		gotoxy(38,24);
		printf("Voi X la so  !!! ");
		TextColor(30);
		DLTKNT(tkiemnt);
	}
	else if(kttk==211 || kttk==212 || kttk==221 || kttk==222  || kttk==251 || kttk==252)
	{
		DLTK(tkiem);
	}
	else if( kttk==231 || kttk==232)
	{
		TextColor(28);
		gotoxy(20,20);
		printf("LUU Y: ");
		TextColor(31);
		gotoxy(27,20);
		printf("Chi tim duoc TEN trong danh sach.");
		gotoxy(27,21);
		printf("Hoac muon tim day du thong tin chon TIM KIEM TUAN TU.");
		TextColor(30);
		DLTK(tkiem);
		XoaTB();
	}
	else if( kttk==241 || kttk==242)
	{
		TextColor(28);
		gotoxy(20,20);
		printf("LUU Y: ");
		TextColor(31);
		gotoxy(27,20);
		printf("Chi tim duoc NAM SINH trong danh sach.");
		gotoxy(27,21);
		printf("Hoac muon tim day du thong tin chon TIM KIEM TUAN TU.");
		TextColor(30);
		DLTK(tkiem);
		XoaTB();
	}
	MoveTKiem(tkiem,tkiemnt,kttk);
}
void DeleteTK()
{
	SetBGColor(1);
	gotoxy(10,29);
	printf("                                                                             ");
}
void MoveTKiem1() // ...............Di chuyen tim kiem tuan tu
{
	int y[5]={11,15,19,23,27},Y=0,j=-1,temp=0;
	char sx1;
	while(1)
	{
		if(kbhit())
		{
			sx1=getch();
			if((sx1==80||sx1==72) && temp!=1 )//Len xuong MENU cap 2
			{
				if(sx1==80)
				{
					Y=y[++j];
					if(j>4)
					{
						Y=y[4];
						j=4;
					}
				}
				else if(sx1==72)
				{
					Y=y[--j];
					if(j<1)
					{
						Y=y[0];
						j=0;
					}
				}
			ChangeSX(Y);
			}
			else if(sx1==27 && temp!=1)
			{
				SetBGColor(1);
				system("cls");
				MainQLSV();
			}
			else if(sx1==13)
			{
				if(Y==11)
				{
					FormTKiem(11);
					temp=1;
				}
				else if(Y==15)
				{
					FormTKiem(12);
					temp=1;
				}
				else if(Y==19)
				{
					FormTKiem(13);
					temp=1;
				}
				else if(Y==23)
				{
					FormTKiem(14);	
					temp=1;
				}
				else if(Y==27)
				{
					FormTKiem(15);
					temp=1;
				}
			}
		}
	}
}
void TBaoTK()
{
	TextColor(31);
	gotoxy(15,29);
	printf("-- Moi nhap dung lua chon phan sap xep dang hien hanh de tim kiem--");
	TextColor(30);
}
void MoveTKiem2()// ...............Di chuyen tim kiem nhi phan
{	
	int ktsx;
	MKTSxepr(ktsx);
	int y[5]={11,15,19,23,27},Y=0,j=-1,temp=0;
	char tk4;
	while(1)
	{
		if(kbhit())
		{
			tk4=getch();
			if((tk4==80||tk4==72) && temp!=1 )//Len xuong MENU cap 2 
			{
				if(tk4==80)
				{
					DeleteTK();
					Y=y[++j];
					if(j>4)
					{
						Y=y[4];
						j=4;
					}
				}
				else if(tk4==72)
				{
					DeleteTK();
					Y=y[--j];
					if(j<1)
					{
						Y=y[0];
						j=0;
					}
				}
			ChangeSX(Y);
			}
			else if(tk4==27 && temp!=1)
			{
				SetBGColor(1);
				system("cls");
				MainQLSV();
			}
			else if(tk4==13)
			{
				if(Y==11)
				{
					if(ktsx==11)
					{
						FormTKiem(211);
						temp=1;
					}
					if(ktsx==12)
					{
						FormTKiem(212);
						temp=1;
					}
					else
					{
						TBaoTK();
					}
				}
				else if(Y==15)
				{
					if(ktsx ==21)
					{
						FormTKiem(221);
						temp=1;
					}
					if(ktsx==22)
					{
						FormTKiem(222);
						temp=1;
					}
					else
					{
						TBaoTK();
					}
				}
				else if(Y==19)
				{
					
					if(ktsx==31)
					{
						FormTKiem(231);
						temp=1;
					}
					if(ktsx ==32)
					{
						FormTKiem(232);
						temp=1;
					}
					else
					{
						TBaoTK();
					}
				}
				else if(Y==23)
				{
					
					if(ktsx==41)
					{
						FormTKiem(241);
						temp=1;
					}
					if(ktsx ==42)
					{
						FormTKiem(242);
						temp=1;
					}
					else
					{
						TBaoTK();
					}
				}
				else if(Y==27)
				{
				
					if(ktsx==51)
					{
						FormTKiem(251);
						temp=1;
					}
					if(ktsx ==52)
					{
						FormTKiem(252);
						temp=1;
					}
					else
					{
						TBaoTK();
					}
				}
			}
		}
	}
}
void LapDSTK(KieuSinhVien s[],int i)
{
			gotoxy(4,9+i*2);
			printf("%d",i);
			gotoxy(9,9+i*2);
			printf("%s",s[i].malop);
			gotoxy(21,9+i*2);
			printf("%s",s[i].masv);
			gotoxy(33,9+i*2);
			printf("%s",s[i].hoten);
			gotoxy(71,9+i*2);
			printf("%s",s[i].nsc.ngay);
			gotoxy(73,9+i*2);
			printf("/%s",s[i].nsc.thang);
			gotoxy(76,9+i*2);
			printf("/%s",s[i].nsc.nam);
			gotoxy(86,9+i*2);
			printf("%s",s[i].diemc);
}
void MenuTKiem(int temptkiem)//1-tuantu ,2-nhiphan
{
	int ktsx;
	MKTSxepr(ktsx);
	SetBGColor(1);
	system("cls");
   	Title();
	TitleMenu2(31);
	TextColor(31);
	gotoxy(60,30);
	printf("Nhan ESC de quay lai Menu chinh !!!");
	TextColor(30);
	gotoxy(36,3);                
	printf("       4.TIM KIEM     ");
	if(temptkiem==1)
	{
		gotoxy(27,8);
		printf("LUA CHON KHOA DE TIM KIEM BANG PP TUAN TU.");
		for(int j=1;j<6;j++)
		{
			FrameSX(j);
		}
			ListSX();
	}
	else if(temptkiem==2)
	{	
		if(ktsx!=0)
		{
			gotoxy(27,8);
			printf("LUA CHON KHOA DE TIM KIEM BANG PP NHI PHAN.");
			TextColor(31);
			gotoxy(18,29);
			printf("CHU Y: Can sap xep muc tuong ung truoc khi TIM KIEM NHI PHAN. ");
			TextColor(30);
			for(int j=1;j<6;j++)
			{
				FrameSX(j);
			}
				ListSX();
		}
		else
		{
			gotoxy(15,11);
			printf("BAN CHUA SAP XEP DANH SACH NEN SAP XEP BANG PP NHI PHAN KHONG KHA DUNG");
			gotoxy(0,0);
			char tk1;
			while(1)
			{
				if(kbhit())
				{
					tk1=getch();
					if(tk1==27)
					{
						SetBGColor(1);
						system("cls");
						MainQLSV();	
					}
				}
			}		
		}	
	}
	gotoxy(0,0);
	if(temptkiem==1)
	{
		MoveTKiem1();
	}
	else if(temptkiem==2 && ktsx!=0)
	{	
		MoveTKiem2();
	}
 } 
void DSTK(char tkiem[],char tkiemnt[],int a)
{
	int demsosv,l,ktsxep;
	Laysosv(demsosv);
	char dem[20];
	KieuSinhVien s[sosv];
	DLSxep(s,demsosv);
	MKTSxepr(ktsxep);
	InDS1(demsosv,ktsxep);
	LayDuLieu(s,demsosv);
	if(a==12)
	{
		TKTTMasv(tkiem,s,demsosv,dem,l);
		for(int i=0;i<l;i++)
		{
			TextColor(28);
			LapDSTK(s,dem[i]);
		}	
	}
	else if(a==11)
	{
		ChuanHoaMalop(tkiem);
		TKTTMalop(tkiem,s,demsosv,dem,l);
		for(int i=0;i<l;i++)
		{
			TextColor(28);
			LapDSTK(s,dem[i]);
		}
	}
	else if(a==15)
	{
		TronDiem(tkiem);
		TKTTDiem(tkiem,s,demsosv,dem,l);
		for(int i=0;i<l;i++)
		{
			TextColor(28);
			LapDSTK(s,dem[i]);
		}	
	}
	else if(a==14)
	{
		if((int(tkiemnt[0])==100 && int(tkiemnt[1])==100))
		{
			TKTTNS(tkiemnt,s,demsosv,dem,l);
			for(int i=0;i<l;i++)
			{
				TextColor(28);
				LapDSTK(s,dem[i]);
			}	
		}
		else if((int(tkiemnt[0])==109 && int(tkiemnt[1])==109))
		{
			TKTTTS(tkiemnt,s,demsosv,dem,l);
			for(int i=0;i<l;i++)
			{
				TextColor(28);
				LapDSTK(s,dem[i]);
			}	
		}
		else if((int(tkiemnt[0])==121 && int(tkiemnt[1])==121))
		{
			TKTTN(tkiemnt,s,demsosv,dem,l);
			for(int i=0;i<l;i++)
			{
				TextColor(28);
				LapDSTK(s,dem[i]);
			}	
		}
	}
	else if(a==13)
	{
		TKTTHT(tkiem,s,demsosv,dem,l);
		for(int i=0;i<l;i++)
		{
			TextColor(28);
			LapDSTK(s,dem[i]);
		}
	}
	else if(a==251)
	{
		TronDiem(tkiem);
		TKNPDT(tkiem,s,demsosv,dem,l);
		for(int i=0;i<l;i++)
		{
			TextColor(28);
			LapDSTK(s,dem[i]);
		}
	}
	else if(a==252)
	{
		TronDiem(tkiem);
		TKNPDG(tkiem,s,demsosv,dem,l);
		for(int i=0;i<l;i++)
		{
			TextColor(28);
			LapDSTK(s,dem[i]);
		}
	}
	else if(a==221)
	{
		TKNPMSVT(tkiem,s,demsosv,dem,l);
		for(int i=0;i<l;i++)
		{
			TextColor(28);
			LapDSTK(s,dem[i]);
		}
	}
	else if(a==222)
	{
		TKNPMSVG(tkiem,s,demsosv,dem,l);
		for(int i=0;i<l;i++)
		{
			TextColor(28);
			LapDSTK(s,dem[i]);
		}
	}
	else if(a==211)
	{
		ChuanHoaMalop(tkiem);
		TKNPMLT(tkiem,s,demsosv,dem,l);
		for(int i=0;i<l;i++)
		{
			TextColor(28);
			LapDSTK(s,dem[i]);
		}
	}
	else if(a==212)
	{
		TKNPMLG(tkiem,s,demsosv,dem,l);
		for(int i=0;i<l;i++)
		{
			TextColor(28);
			LapDSTK(s,dem[i]);
		}
	}
	else if(a==231)
	{
		TKNPHTT(tkiem,s,demsosv,dem,l);
		for(int i=0;i<l;i++)
		{
			TextColor(28);
			LapDSTK(s,dem[i]);
		}
	}
	else if(a==232)
	{
		TKNPHTG(tkiem,s,demsosv,dem,l);
		for(int i=0;i<l;i++)
		{
			TextColor(28);
			LapDSTK(s,dem[i]);
		}
	}
	else if(a==241)
	{
		TKNPNST(tkiem,s,demsosv,dem,l);
		for(int i=0;i<l;i++)
		{
			TextColor(28);
			LapDSTK(s,dem[i]);
		}
	}
	else if(a==242)
	{
		TKNPNSG(tkiem,s,demsosv,dem,l);
		for(int i=0;i<l;i++)
		{
			TextColor(28);
			LapDSTK(s,dem[i]);
		}
	}
	TextColor(30);
	gotoxy(0,0);
	Move3();
}
//-------------------------------------------------5.THONG KE-----------------------//
//Bang so luong sinh vien
void BangSL1(int a)
{
	gotoxy(14,11+a*2);
	printf("%c",186);
	gotoxy(80,11+a*2);
	printf("%c",186);
	gotoxy(14,12+a*2);
	printf("%c",199);
	gotoxy(80,12+a*2);
	printf("%c",182);
	for(int i=15;i<=79;i++)
	{
		gotoxy(i,12+a*2);
		printf("%c",196);
	}
}
void BangSL(int a)
{
	int b=a+1;
	gotoxy(14,10);	
	printf("%c",186);
	gotoxy(80,10);
	printf("%c",186);
	for(int c=0;c<b+1;c++)
	{
		BangSL1(c);
	}
	for(int i=15;i<=79;i++)
	{
		gotoxy(i,10);
		printf("%c",205);
		gotoxy(i,12+b*2);
		printf("%c",205);
	}
	gotoxy(14,10);
	printf("%c",201);
	gotoxy(80,10);
	printf("%c",187);	
	gotoxy(14,12+b*2);
	printf("%c",200);
	gotoxy(80,12+b*2);
	printf("%c",188);	
	gotoxy(65,10);
	printf("%c",209);
	gotoxy(65,12+b*2);
	printf("%c",207);
	gotoxy(31,10);
	printf("%c",209);
	gotoxy(31,12+a*2);
	printf("%c",193);
	for(int i=11;i<12+b*2;i++)
	{
		gotoxy(65,i);
		printf("%c",179);
		if(i<12+a*2)
		{
			gotoxy(31,i);
			printf("%c",179);
		}
	}	
}
void ListSL(int a)
{
	gotoxy(20,11);
	printf("MA LOP");
	gotoxy(45,11);
	printf("TEN LOP");
	gotoxy(67,11);
	printf("SO SINH VIEN");
	gotoxy(38,11+(a+1)*2);
	printf("TONG");
}
void ChangeTK(int F,int a)
{
	gotoxy(a,F);
}
void MoveTK(int a,int b)
{
	int *q,i,F=0;
	q=(int*)calloc(a+1,sizeof(int));
	for(i=1;i<=a;i++)
	{
		*(q+i)=b+2*i;
	}
	i=0;
	char z;
	while(1)
	{
		if(kbhit())
		{
			z=getch();
			if(z==27)
			{
				SetBGColor(1);
				TextColor(30);
				system("cls");
				MainQLSV();
			}
			else if(z==80 || z==72)
			{
				if(z==80)	
				{
					i=i+1;
					F=*(q+i);
					if(i>a)
					{
						F=18+a*2;
						i=a+1;
					}
				}
				else if(z==72)
				{
					
					i=i-1;
					F=*(q+i);		
					if(i<1)
					{
						F=0;
						i=0;
					}
				}
			if(b==11)
			{
				ChangeTK(F,15);
			}
			else if(b==13)
			{
				ChangeTK(F,1);
			}
			}
		}
	}
}
//Bang ket qua hoc tap
void LineKQ(int b,int c)
{
	gotoxy(b,10);
	printf("%c",209);
	gotoxy(b,14+c*2);
	printf("%c",207);
	for(int i=11;i<=(14+c*2)-1;i++)
	{
		gotoxy(b,i);
		printf("%c",179);
	}
	gotoxy(b,14+c*2);
	printf("%c",207);
	for(int i=13;i<=(14+c*2)-1;i++)
	{
		gotoxy(b+8,i);
		printf("%c",179);
	}
	gotoxy(b+8,12);
	printf("%c",194);
	gotoxy(b+8,14+c*2);
	printf("%c",207);
}
void BangKQ1(int a)
{
	gotoxy(0,15+a*2);
	printf("%c",186);
	gotoxy(91,15+a*2);
	printf("%c",186);
	gotoxy(0,14+a*2);
	printf("%c",199);
	gotoxy(91,14+a*2);
	printf("%c",182);
	for(int i=1;i<=90;i++)
	{
		gotoxy(i,14+a*2);
		printf("%c",196);
	}
}
void BangKQ(int a)
{
	for(int i=1;i<=90;i++)
	{
		gotoxy(i,10);
		printf("%c",205);
	}
	for(int j=11;j<=14;j++)
	{
		gotoxy(0,j);
		printf("%c",186);
		gotoxy(91,j);
		printf("%c",186);
	}
	gotoxy(0,10);
	printf("%c",201);
	gotoxy(91,10);
	printf("%c",187);
	for(int i=12;i<=90;i++)
	{
		gotoxy(i,12);
		printf("%c",196);
	}
	gotoxy(91,12);
	printf("%c",182);
	for(int k=0;k<a;k++)
	{
		BangKQ1(k);
	}	
	gotoxy(11,12);
	printf("%c",195);	
	gotoxy(11,10);
	printf("%c",209);	
	gotoxy(0,14+a*2);
	printf("%c",200);
	gotoxy(91,14+a*2);
	printf("%c",188);
	for(int k=1;k<=90;k++)
	{
		gotoxy(k,14+a*2);
		printf("%c",205);
	}	
	LineKQ(11,a);
	LineKQ(27,a);
	LineKQ(43,a);
	LineKQ(59,a);
	LineKQ(75,a);
}
void ListKQ1(int a)
{
	TextColor(31);
	gotoxy(a,13);
	printf("SL");
	TextColor(27);
	gotoxy(a+8,13);
	printf("%c",37);
	TextColor(30);
}
void ListKQ()
{
	gotoxy(3,12);
	printf("MA LOP");
	gotoxy(16,11);
	printf("XUAT SAC");
	gotoxy(33,11);
	printf("GIOI");
	gotoxy(50,11);
	printf("KHA");
	gotoxy(63,11);
	printf("TRUNG BINH");
	gotoxy(82,11);
	printf("YEU");
	ListKQ1(15);
	ListKQ1(31);
	ListKQ1(47);
	ListKQ1(63);
	ListKQ1(79);
}
void ThongKe(int a)
{
	SetBGColor(1);
	system("cls");
	char *dem;int l, b=1,demsosv,c=1;
	Laysosv(demsosv);
	KieuSinhVien s[sosv];
	Title();
	gotoxy(36,3);
	printf("      3.THONG KE  ");
	DLSxep(s,demsosv);
	if(a==1)
	{
		gotoxy(30,6);
		printf("BANG THONG KE SO LUONG SINH VIEN");
		do{
			dem=(char*)calloc(demsosv+1,sizeof(int));
			Thongke(s,dem,l,b,demsosv);
			b=int(*(dem+(l-1)));
			b++;
			gotoxy(19,11+2*c);
			printf("%s",s[*(dem+(l-1))].malop);
			gotoxy(44,11+2*c);
			printf("%s",s[*(dem+(l-1))].malop);
			gotoxy(72,11+2*c);
			printf("%d",l);
			c++;
			free(dem);
		}while(b<=demsosv);
		BangSL(c-1);
		ListSL(c-1);
		gotoxy(71,11+c*2);
		printf("%d",demsosv);
		gotoxy(60,15+c*2);
		printf("Nhan ESC de quay lai Menu chinh !!!");
		TitleMenu2(16+c*2);
		gotoxy(15,0);
		MoveTK(c,11);
	}
	else
	{
		gotoxy(32,6);
		printf("BANG THONG KE KET QUA HOC TAP");
		do{
			int xs=0,gioi=0,kha=0,tb=0,yeu=0;
			dem=(char*)calloc(demsosv+1,sizeof(char));
			Thongke(s,dem,l,b,demsosv);
			b=int(*(dem+(l-1)));
			b++;
			gotoxy(2,13+2*c);
			printf("%s",s[*(dem+(l-1))].malop);
			for(int i=0;i<l;i++)
			{
				s[*(dem+i)].diem=atoi(s[*(dem+i)].diemc);
				if(s[*(dem+i)].diem>=9 && s[*(dem+i)].diem<=10)
				{
					xs++;
				}
				else if(s[*(dem+i)].diem>=8 && s[*(dem+i)].diem<9)
				{
					gioi++;
				}
				else if(s[*(dem+i)].diem>=7 && s[*(dem+i)].diem<8)
				{
					kha++;
				}
				else if(s[*(dem+i)].diem>=5 && s[*(dem+i)].diem<7)
				{
					tb++;
				}
				else if(s[*(dem+i)].diem<5)
				{
					yeu++;
				}
				if(i==l-1)
				{
					TextColor(31);
					gotoxy(15,13+c*2);
					printf("%d",xs);					
					gotoxy(31,13+c*2);
					printf("%d",gioi);					
					gotoxy(47,13+c*2);
					printf("%d",kha);					
					gotoxy(63,13+c*2);
					printf("%d",tb);					
					gotoxy(79,13+c*2);
					printf("%d",yeu);
					gotoxy(21,13+c*2);
					TextColor(27);
					printf("%.2f",(float)xs/l*100.0);
					gotoxy(37,13+c*2);
					printf("%.2f",(float)gioi/l *100.0);
					gotoxy(53,13+c*2);
					printf("%.2f",(float) kha/l*100.0);
					gotoxy(69,13+c*2);
					printf("%.2f",(float)tb/l*100.0);
					gotoxy(85,13+c*2);
					printf("%.2f",(float)yeu/l*100.0);
					TextColor(30);
				}
			}
			c++;
			free(dem);
		}while(b<=demsosv);
		BangKQ(c-1);
		ListKQ();
		TitleMenu2(16+c*2);
		gotoxy(60,15+c*2);
		printf("Nhan ESC de quay lai Menu chinh !!!");
		gotoxy(1,0);
		MoveTK(c-1,13);
	}
}
int main()
{
	resizeConsole(800,558);
	system("color 1E");
	MainQLSV();
}
