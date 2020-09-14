#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

void ChuanHoaMalop(char *s)
{
	int i;
	while(s[0] == ' ')
		strcpy( &s[0], &s[1]);
	strupr(s);
	while(s[strlen(s)-1] == ' ')
	{
		s[strlen(s)-1]= '\0';
	}
}

void XetMaLop(char *s,int &demml)
{
	int demc=0,dems=0,demg=0;
	for(int k=1;k<4;k++){
	for(int i=0;i<strlen(s);i++)
	{
		if(k==1){
			if(int(s[i])>=65 && int(s[i])<=90)
			{
				demc=1;
				break;
			}
			else
			{
				demc=0;
			}
		}
		else if(k==2)
		{
			if(int(s[i])>=48 && int(s[i])<=57)
			{
				dems=1;
				break;
			}
			else
			{
				dems=0;
			}
		}
		else if(k==3)
		{
			if(int(s[i])==45)
			{
				demg=1;
				break;
			}
			else
			{
				demg=0;
			}
		}
	}}
	if(dems==0 || demc==0 || demg==0)
	{
		demml=0;
	}
	else
	{
		demml=1;
	}
}

//Chuan hoa ho ten
void ChuanHoaHoten(char *s){
	int i;
	//dau xau
	while(s[0] == ' ')
		strcpy( &s[0], &s[1]);
	//cuoixau
	while(s[strlen(s)-1] == ' ')
	{
		s[strlen(s)-1]= '\0';
	}
	//giua
	for(i=0;i<strlen(s);i++)
	if(s[i]==' ' && s[i+1]==' ')
	{
		strcpy(&s[i] , &s[i+1]);
		i--;
	}
	strlwr(s);//viet thuong tat ca xau
	s[0]=toupper(s[0]);
	for(i=0; i<strlen(s);i++)
	{
		if(s[i]==' ')
			s[i+1]=toupper(s[i+1]);
	}	
}

//Kiem tra ten co so ko
void ChuanHoaHoten1(char *s,int &demht)
{
	int i;
	for(i=0;i<strlen(s);i++)
	{
		if(int(s[i])>=48 && int(s[i])<=57 )
		{
			demht=0;
			break;
		}
		else if(s[1]==' ')
		{
			demht=0;
			break;
		}
		else
		{
			demht=1;
		}
	}
}

void XetMasv1(char *s,int &demsv)//Kiem tra ma sinh vien la so
{
	int i;
	for(i=0;i<strlen(s);i++)
	{
		if(int(s[i])<48 || int(s[i])>57)
		{
			demsv=0;
			break;
		}
		else
		{
			if(s[i]!=' ')
			{
				demsv=1;
			}
		}
	}
}
void XetMasv(char *s,int &dem)//Dem so ky tu
{
	int i;
	dem=0;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]!=' ')
		{
			dem++;
		}
	}
}
void XetNgayS(int ngay,int thang,int nam,int &dems)
{
	
	if(thang<1 || thang>12)
	{
		dems=0;
	}
	else if(nam <=1990 || nam>=2016)
	{
		dems=0;
	}
	else 
	{
		switch(thang)
		{
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				{
					if(ngay<1 || ngay>31)
					{
						dems=0;
					}
					else
					{
						dems=1;
					}
				}
				break;
			case 4: case 6: case 9: case 11:
				{
					if(ngay<1 || ngay >30)
					{
						dems=0;
					}
					else
					{
						dems=1;
					}
				}
				break;
			case 2:
				{
					if(nam%4==0)
					{
						if(ngay<1 || ngay>29)
						{
							dems=0;
						}
						else
						{
							dems=1;
						}
					}
					else
					{
						if(ngay<1 || ngay>28)
						{
							dems=0;
						}
						else
						{
							dems=1;
						}
					}
				}
				break;
		}
	}
}
void XetDiem(char *s,int &demd)
{
	if(strlen(s)==2)
	{
		if(int(s[0])==49 && int (s[1])==48)
		{
			demd=1;
		}
		else demd=0;
	}
	else
	{
		if(int(s[0])>=48 && int (s[0])<=57)
		{
			demd=1;
		}
		else demd=0;
	}
}

