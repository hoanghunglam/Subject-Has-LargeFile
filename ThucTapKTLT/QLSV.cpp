#include<stdio.h>
#include<conio.h>
#include<cstdlib>
#include<string.h>
#include<iostream>
#include<windows.h>
#define BLACK 0
#define BLUE 9
#define GREEN 10
#define RED 12
#define YELLOW 14
#define WHITE 15
#define MAX 100000

using namespace std;

struct sinhVien{
	char maLop[10];
	char maSV[10];
	char hoTen[50];
	float diemTB;
	int Ngay;
	int Thang;
	int Nam;
};
struct sinhVien sv[MAX];
int index = 0;

void textColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
 
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;
 
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void ReadFile(char *Filename)  
{
	FILE *f = fopen(Filename, "rb");

	fseek(f, 0, SEEK_END); 
	(index) = (ftell(f) + 1) / sizeof(sinhVien);
											
	fseek(f, 0, SEEK_SET); 
	fread(sv, sizeof(sinhVien),index, f);

	fclose(f);
}  

void WriteFile(char *Filename)
{
	FILE *f = fopen(Filename, "wb");
	if (f == NULL)
	{
		printf("Loi mo tep !");
	}
	else
	{
		fwrite(sv, sizeof(sinhVien), index, f);
	}
	fclose(f);
}

void nhapThongTin()
{
	int kt;
	int l1,l2,k,m;
	int i=0;
	do{
	system("cls");
	printf("Moi ban bat dau nhap sinh vien\n\n\n");	
	do{	
		printf("\nMoi ban nhap ma sinh vien %d:\n",index+1);
		printf("(Chu y: Ma sinh vien gom 8 so tu 0->9)\n");
		fflush(stdin);
		gets(sv[index].maSV);
		l1=strlen(sv[index].maSV);
		if(l1==8)
		{
			for(int j=0;j<l1;j++)
			{
				if( (sv[index].maSV[j] >='0') && (sv[index].maSV[j] <='9') )
				{
					k=0;
				}
				else
				{
					printf("Ma sinh vien phai la cac so nguyen tu 1->9. Vui long nhap lai!\n");
					k=1;
					break;
				}
			}
			for(i=0;i<index;i++)
			{
				if(strcmp(sv[i].maSV, sv[index].maSV) == 0)
				{
					printf("Ma SV bi trung. Vui long nhap lai!\n");
					k=1;
					break;
				}
				else
				{
					k=0;
				}
			}
		}
		else
		{
			printf("Ma sinh vien phai dung 8 ky tu. Vui long nhap lai!\n");
			k=1;
		}   
	}while(k==1);
	printf("\nMoi ban nhap ho ten sinh vien %d: ",index+1);
    fflush(stdin);
    gets(sv[index].hoTen);
    int st=0, en,i0;
	en=strlen(sv[index].hoTen);
	strlwr(sv[index].hoTen);	
	sv[index].hoTen[0]=toupper(sv[index].hoTen[0]);
	for(i0=1;i0<en;i0++)
	{
		if(sv[index].hoTen[i0-1]==' ' && sv[index].hoTen[i0]!=' ')
		sv[index].hoTen[i0]=toupper(sv[index].hoTen[i0]);
	}
	puts(sv[index].hoTen);
    do{
		printf("\nMoi ban nhap nam sinh: ");
		fflush(stdin);
		scanf("%d",&sv[index].Nam);
		if( (sv[index].Nam <1900) || (sv[index].Nam>2001) )
		{
			printf("Ban chi duoc nhap tu 1900->2001\n");
		}
	}while( (sv[index].Nam<1900) || (sv[index].Nam>2001) );  
   do{
		printf("\nMoi ban nhap thang sinh: ");
		fflush(stdin);
		scanf("%d",&sv[index].Thang);
		if( (sv[index].Thang <1) || (sv[index].Thang>12) )
        {
			printf("Ban chi duoc nhap thang sinh tu 1->12\n");
		}
   	}while( (sv[index].Thang<1) || (sv[index].Thang>12) );
 
	if( (sv[index].Thang ==1) || (sv[index].Thang ==3) || (sv[index].Thang ==5) || (sv[index].Thang ==7) || 
	(sv[index].Thang ==8) || (sv[index].Thang ==10) || (sv[index].Thang ==12) )
    {
        do{
           	printf("\nMoi ban nhap ngay sinh: ");
           	fflush(stdin);
      		scanf("%d",&sv[index].Ngay);
 			if( (sv[index].Ngay<1) || (sv[index].Ngay>31) )
      		{
			  printf("Ban chi co the nhap ngay trong khoang tu 1->31\n"); 
			}
		}while( (sv[index].Ngay<1) || (sv[index].Ngay>31) );
	}
    else if( (sv[index].Thang ==4) || (sv[index].Thang ==6) || (sv[index].Thang ==9) || (sv[index].Thang ==11) )
    {
        do{
        	printf("\nMoi ban nhap ngay sinh: ");
        	fflush(stdin);
      		scanf("%d",&sv[index].Ngay);
      		if((sv[index].Ngay<1) || (sv[index].Ngay>30))
      		{
			  printf("Ban chi co the nhap ngay trong khoang tu 1->30\n"); 
			}
		}while( (sv[index].Ngay<1) || (sv[index].Ngay>30) );	
	}
	else
	{
		if(sv[index].Nam %4 ==0)
		{
			do{
          		printf("\nMoi ban nhap ngay sinh: ");
          		fflush(stdin);
      			scanf("%d",&sv[index].Ngay);
      			if((sv[index].Ngay<1) || (sv[index].Ngay>29))
      			{
				  printf("Ban chi co the nhap ngay trong khoang tu 1->29\n"); 
				}
			}while( (sv[index].Ngay<1) || (sv[index].Ngay>29) );
		}
		else
		{
			do{
           		printf("\nMoi ban nhap ngay sinh: ");
           		fflush(stdin);
      			scanf("%d",&sv[index].Ngay);
      			if((sv[index].Ngay<1) || (sv[index].Ngay>28))
      			{
				  printf("Ban chi co the nhap ngay trong khoang tu 1->28\n"); 
				}
			}while( (sv[index].Ngay<1) || (sv[index].Ngay>28) );
		}		
	}
    do{	
		printf("\nMoi ban nhap ma lop: ");
		printf("(Chu y: Ma lop gom 8 so tu 0->9.)\n\n");
		fflush(stdin);
		gets(sv[index].maLop);
		l2=strlen(sv[index].maLop);
		if(l2==8) 
		{
			for(int j2=0;j2<l2;j2++)
			{
				if( (sv[index].maLop[j2] >='0') && (sv[index].maLop[j2] <='9') )
				{
					k=0;
				}
				else
				{
					printf("Ma lop phai la cac so nguyen tu 0->9. Vui long nhap lai!\n");
					k=1;
					break;
				}
			}
		}
		else
		{
			printf("Ma lop phai dung 8 ky tu. Vui long nhap lai!\n");
			k=1;
		}   	
	}while(k==1);
	do{
		printf("\nMoi ban nhap diem trung binh: ");
		fflush(stdin);
		scanf("%f",&sv[index].diemTB);
		if( (sv[index].diemTB<0) || (sv[index].diemTB>10) )
		{
			printf("Ban chi duoc nhap trong khoang 0->10)");
		}
	}while( (sv[index].diemTB<0) || (sv[index].diemTB>10) );	
	index++;
	do{
		printf("\nNeu muon nhap tiep an 1, muon ket thuc an 2: ");
		fflush(stdin);
		scanf("%d",&kt);
		printf("\n\n");
		if(kt == 1)
	    {
	    	i++;
	    	break;
		}
		else if(kt==2)
		{
			textColor(YELLOW);
			break;
		}
		else{
			printf("Lua chon khong co. Vui long thu lai!");
		}
	}while(true);
	}while(kt == 1);
}
void xuatSinhVien(){
	system("cls");
	printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
	printf("\n|   STT     |    MaSV   |       HO   VA   TEN                |   Ngay sinh    | Ma lop     |   Diem TB    |");
	printf("\n+-----------+-----------+------------------------------------+----------------+---------------------------+");
	for(int i=0;i<index;i++)
	{
		if(sv[i].diemTB==10){
			printf("\n| %-5d     | %3s  | %-20s               | %2d/%2d/%2d     | %4s   | %4.2f        |",i+1,sv[i].maSV, sv[i].hoTen,sv[i].Ngay,sv[i].Thang,sv[i].Nam,sv[i].maLop,sv[i].diemTB);
		}
		else{
			printf("\n| %-5d     | %3s  | %-20s               | %2d/%2d/%2d     | %4s   | %4.2f         |",i+1,sv[i].maSV, sv[i].hoTen,sv[i].Ngay,sv[i].Thang,sv[i].Nam,sv[i].maLop,sv[i].diemTB);
		}		
	}
	printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
	printf("\n\n\n");
}
void sua(){
	int kt;
	int l1,l2,k,m;
	int i=0;
    char maSV[8];
    int vitri;
    int chon; 
    int found=0;
	xuatSinhVien();
    printf("\nNhap vao ma sinh vien can sua: ");
    fflush(stdin);
    gets(maSV);
    for(i=0;i<index;i++){
        if(strcmp(sv[i].maSV,maSV)==0){
        	found++;
			vitri=i;
		}
	}
    if (found==0){
    	printf("\nKhong tim thay sinh vien nao co ma la: %s\n",maSV);
        system("pause");
    	textColor(YELLOW);
	}         
 	else
    {
   		system("cls");
      	printf("\n|====================================* THONG TIN SINH VIEN *==============================================|\n");
		printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
		printf("\n|   STT     |    MaSV   |       HO   VA   TEN                |   Ngay sinh    | Ma lop     |   Diem TB    |");
		printf("\n+-----------+-----------+------------------------------------+----------------+---------------------------+");
		if(sv[vitri].diemTB==10){
			printf("\n| %-5d     | %3s  | %-20s               | %2d/%2d/%2d     | %4s   | %4.2f        |",1,sv[vitri].maSV, sv[vitri].hoTen,sv[vitri].Ngay,sv[vitri].Thang,sv[vitri].Nam,sv[vitri].maLop,sv[vitri].diemTB);
		}
		else{
			printf("\n| %-5d     | %3s  | %-20s               | %2d/%2d/%2d     | %4s   | %4.2f         |",1,sv[vitri].maSV, sv[vitri].hoTen,sv[vitri].Ngay,sv[vitri].Thang,sv[vitri].Nam,sv[vitri].maLop,sv[vitri].diemTB);
		}        
        printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
		printf("\n\n\n");
        printf("\nTim thay sinh vien co MaSV: %s",maSV);
        printf("\nChon '1' de sua, '2' de huy hoac 'gia tri bat ky' de thoat\n\nBan chon: ");
        fflush(stdin);
        scanf("%d",&chon);
        if(chon==1)
        {
            printf("\n\nHo ten: ");
            fflush(stdin);
   			gets(sv[vitri].hoTen);
   			int st=0,en,i0;
			en=strlen(sv[vitri].hoTen);
			strlwr(sv[vitri].hoTen);
			sv[vitri].hoTen[0]=toupper(sv[vitri].hoTen[0]);
			for(i0=1;i0<en;i0++)
			{
				if(sv[vitri].hoTen[i0-1]==' ' && sv[vitri].hoTen[i0]!=' ')
				sv[vitri].hoTen[i0]=toupper(sv[vitri].hoTen[i0]);
			}
			puts(sv[vitri].hoTen);
			do{
				printf("\nMoi ban nhap nam sinh: ");
				fflush(stdin);
				scanf("%d",&sv[vitri].Nam);
				if( (sv[vitri].Nam <1900) || (sv[vitri].Nam>2001) )
				{
					printf("Ban chi duoc nhap tu 1900->2001\n");
				}
			}while( (sv[vitri].Nam<1900) || (sv[vitri].Nam>2001) );  
		   do{
				printf("\nMoi ban nhap thang sinh: ");
				fflush(stdin);
				scanf("%d",&sv[vitri].Thang);
				if( (sv[vitri].Thang <1) || (sv[vitri].Thang>12) )
		        {
					printf("Ban chi duoc nhap thang sinh tu 1->12\n");
				}
		   	}while((sv[vitri].Thang<1) || (sv[vitri].Thang>12));
		 
			if( (sv[vitri].Thang ==1) || (sv[vitri].Thang ==3) || (sv[vitri].Thang ==5) || (sv[vitri].Thang ==7) || 
			(sv[vitri].Thang ==8) || (sv[vitri].Thang ==10) || (sv[vitri].Thang ==12) )
		    {
		        do{
		           	printf("\nMoi ban nhap ngay sinh: ");
		           	fflush(stdin);
		      		scanf("%d",&sv[vitri].Ngay);
		 			if( (sv[vitri].Ngay<1) || (sv[vitri].Ngay>31) )
		      		{
					  printf("Ban chi co the nhap ngay trong khoang tu 1->31\n"); 
					}
				}while((sv[vitri].Ngay<1) || (sv[vitri].Ngay>31));
			}
		    else if( (sv[vitri].Thang ==4) || (sv[vitri].Thang ==6) || (sv[vitri].Thang ==9) || (sv[vitri].Thang ==11) )
		    {
		        do{
		        	printf("\nMoi ban nhap ngay sinh: ");
		        	fflush(stdin);
		      		scanf("%d",&sv[vitri].Ngay);
		      		if((sv[vitri].Ngay<1) || (sv[vitri].Ngay>30))
		      		{
					  printf("Ban chi co the nhap ngay trong khoang tu 1->30\n"); 
					}
				}while((sv[vitri].Ngay<1) || (sv[vitri].Ngay>30));	
			}
			else
			{
				if(sv[vitri].Nam %4 ==0)
				{
					do{
		          		printf("\nMoi ban nhap ngay sinh: ");
		          		fflush(stdin);
		      			scanf("%d",&sv[vitri].Ngay);
		      			if((sv[vitri].Ngay<1) || (sv[vitri].Ngay>29))
		      			{
						  printf("Ban chi co the nhap ngay trong khoang tu 1->29\n"); 
						}
					}while((sv[vitri].Ngay<1) || (sv[vitri].Ngay>29));
				}
				else
				{
					do{
		           		printf("\nMoi ban nhap ngay sinh: ");
		           		fflush(stdin);
		      			scanf("%d",&sv[vitri].Ngay);
		      			if((sv[vitri].Ngay<1) || (sv[vitri].Ngay>28))
		      			{
						  printf("Ban chi co the nhap ngay trong khoang tu 1->28\n"); 
						}
					}while((sv[vitri].Ngay<1) || (sv[vitri].Ngay>28));
				}		
			}
			do{	
				printf("\nMoi ban nhap ma lop: ");
				printf("(Chu y: Ma lop gom 8 so tu 0->9)\n\n");
				fflush(stdin);
				gets(sv[vitri].maLop);
				l2=strlen(sv[vitri].maLop);
				if(l2==8) 
				{
					for(int j2=0;j2<l2;j2++)
					{
						if( (sv[vitri].maLop[j2] >='0') && (sv[vitri].maLop[j2] <='9') )
						{
							k = 0;
						}
						else
						{
							printf("Ma lop phai la cac so nguyen tu 0->9. Vui long nhap lai!\n");
							k=1;
							break;
						}
					}
				}
				else
				{
					printf("Ma lop phai dung 8 ky tu. Vui long nhap lai!\n");
					k=1;
				}  	
			}while(k==1);		          			
  			do{
				printf("\nMoi ban nhap diem trung binh: ");
				fflush(stdin);
				scanf("%f",&sv[vitri].diemTB);
				if( (sv[vitri].diemTB<0) || (sv[vitri].diemTB>10) )
				{
					printf("Ban chi duoc nhap trong khoang (0->10))");
				}
			}while( (sv[vitri].diemTB<0) || (sv[vitri].diemTB>10) );
			printf("\nThay doi thanh cong! \n\n\n");
			system("pause");
			sua();
        }
        else if(chon==2){
	    	printf(" \nViec sua bi huy bo\n\n\n");
	        sua();
		}
        else
		{
	        xuatSinhVien();
	        textColor(YELLOW);
		}
    }
}
void xoa(){
	xuatSinhVien();
    char masv[8];
    int vitri;
    int found=0;
    int chon;
    printf("\nNhap vao ma sinh vien can xoa:");
 	fflush(stdin);
	gets(masv);
    for(int i=0;i<index;i++){
		if(strcmp(sv[i].maSV,masv)==0){
			found++;
			vitri=i;
		}
	}
    if (found==0){
    	printf("\nKhong tim thay sinh vien nao co ma la %s\n",masv);
    	system("pause");
    	textColor(YELLOW);
	}      
    else
	{
		system("cls");
	  	printf("\n|====================================* THONG TIN SINH VIEN *==============================================|\n");
		printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
		printf("\n|   STT     |    MaSV   |       HO   VA   TEN                |   Ngay sinh    | Ma lop     |   Diem TB    |");
		printf("\n+-----------+-----------+------------------------------------+----------------+---------------------------+");
	    printf("\n| %-5d     | %3s  | %-20s               | %2d/%2d/%2d     | %4s     | %4.2f         |",1,sv[vitri].maSV, sv[vitri].hoTen,sv[vitri].Ngay,sv[vitri].Thang,sv[vitri].Nam,sv[vitri].maLop,sv[vitri].diemTB);
	    printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
		printf("\n\n\n");
		printf("\nTim thay sinh vien co MaSV: %s ",sv[vitri].maSV);
        printf("\nChon '1' de xoa, '2' de huy hoac 'gia tri bat ky' de thoat\n\nBan chon: ");
        fflush(stdin);
        scanf("%d",&chon);
        if(chon==1)
	    {
	    	index--;
	        printf("\nDa xoa thanh cong\n\n\n");
	        xoa();
	    }
	    else if(chon==2){
	    	printf(" \nViec xoa bi huy bo\n\n\n");
	        xoa();
		}
        else
		{
	        xuatSinhVien();
	        textColor(YELLOW);
		}
	}  
}
char *tachten(const char *s)
{
    char *ptok,name[50];
    strcpy(name,s);
    char *tmp=(char*)malloc(30);
    tmp[0]='\0'; 
 
    ptok=strtok( name, " " ); //chia chuoi str thanh 1 day cac token duoc phan biet rieng re boi dau tach
    while ( ptok != NULL )
    {
        strcat( tmp, " "); //noi chuoi (dest,src)
        strcat( tmp, strrev( ptok ) );
        ptok=strtok( NULL, " " );
    }
    strrev( tmp );
    return tmp;
}
 
int sosanh(char *s1,char *s2)
{ 
    return strcmp(tachten(s1), tachten(s2));
}

void sapxepchonmasv(){
	int i,j;
	sinhVien tmp;
	for (i=0;i<index-1;i++){
		for (j=i+1;j<index;j++)
        {
            if (strcmpi(sv[j].maSV,sv[i].maSV) < 0)
            {
                tmp=sv[i];
                sv[i]=sv[j];
                sv[j]=tmp;
            }
        }
	}
}
void sapxepchonten(){
	int i,j;
	sinhVien tmp;
	for (i=0;i<index-1;i++){
		for (j=i+1;j<index;j++)
        {
        	if (sosanh(sv[j].hoTen,sv[i].hoTen) < 0)
            {
                tmp=sv[i];
                sv[i]=sv[j];
                sv[j]=tmp;
            }
        }
	}
}
void sapxepchonngaysinh(){
	int i,j;
	sinhVien tmp;
	for (i=0;i<index-1;i++){
		for (j=i+1;j<index;j++)
        {
     		if (sv[i].Nam > sv[j].Nam)
   	   	    {
      	 	    tmp=sv[i];
      	 		sv[i]=sv[j];
      			sv[j]=tmp;
    	    }
   		    else if((sv[i].Nam == sv[j].Nam) && (sv[i].Thang > sv[j].Thang ))
     	    {
    		    tmp=sv[i];
      	 		sv[i]=sv[j];
      			sv[j]=tmp;
			}
			else if((sv[i].Nam == sv[j].Nam) && (sv[i].Thang == sv[j].Thang ) &&(sv[i].Ngay > sv[j].Ngay))
     	    {
    		    tmp=sv[i];
      	 		sv[i]=sv[j];
      			sv[j]=tmp;
			}
        }
	}
}
void sapxepchondiem(){
	int i,j;
	sinhVien tmp;
	for(i=0;i<index-1;i++){
		for(j=i+1;j<index;j++)
		{
			if(sv[j].diemTB<sv[i].diemTB)
			{
				tmp=sv[i];
				sv[i]=sv[j];
				sv[j]=tmp;	
			}
		}		
	}
}
void sapxepchenmasv(){
	int i,j;
	sinhVien tmp;
    for(i=1;i<index;i++)
    {
    	j=i-1;
	  	while((j>=0)&&(strcmpi(sv[j+1].maSV,sv[j].maSV) <0))
	  	{
	  		tmp = sv[j+1];
	  	    sv[j+1]=sv[j];
	  	    sv[j] = tmp;
	  		j--;
		}
   }
}
void sapxepchenhoten(){
	int i,j;
	sinhVien tmp;
    for(i=1;i<index;i++)
    {
    	j=i-1;
	  	while((j>=0)&&(sosanh(sv[j+1].hoTen,sv[j].hoTen) <0))
	  	{
	  		tmp = sv[j+1];
	  	    sv[j+1]=sv[j];
	  	    sv[j] = tmp;
	  		j--;
		}
   }
}
void sapxepchennamsinh(){
	int i,j;
	sinhVien tmp;
    for(i=1;i<index;i++)
    {
    	j=i-1;
    	while(j>=0){
    		if(sv[j+1].Nam < sv[j].Nam)
	    	{  		
  				tmp = sv[j+1];
  	  			sv[j+1]=sv[j];
  	  			sv[j] = tmp;
			}
			else if((sv[j+1].Nam == sv[j].Nam) && (sv[j+1].Thang < sv[j].Thang))
	    	{
  				tmp = sv[j+1];
  	  			sv[j+1]=sv[j];
  	  			sv[j] = tmp;
			}
			else if((sv[j+1].Nam == sv[j].Nam ) && (sv[j+1].Thang == sv[j].Thang) && (sv[j+1].Ngay < sv[j].Ngay) )
	    	{
  				tmp = sv[j+1];
  	  			sv[j+1]=sv[j];
  	  			sv[j] = tmp;
			}
			j--;
		}	
	}
}
void sapxepchendiem(){
	int i,j;
	sinhVien tmp;
    for(i=1;i<index;i++)
    {
    	j=i-1;
  		while((j>=0)&&(sv[j+1].diemTB<sv[j].diemTB))
	  	{
	  		tmp = sv[j+1];
	  	    sv[j+1]=sv[j];
	  	    sv[j] = tmp;
	  		j--;
		}
   	}
}
void sapxepnoibotmasv(){
	int i,j;
	sinhVien tmp;
	for(i=0;i<index;i++){
		for(j=index-1;j>i;j--)
		{	
			if((strcmpi(sv[j-1].maSV,sv[j].maSV)>0)) 
			{
				tmp=sv[j-1];
				sv[j-1]=sv[j];
				sv[j]=tmp;
			}
		}	
	}	
}
void sapxepnoibothoten(){
	int i,j;
	sinhVien tmp;
	for(i=0;i<index;i++){
		for(j=index-1;j>i;j--)
		{	
			if (sosanh(sv[j-1].hoTen,sv[j].hoTen) > 0)
			{
				tmp=sv[j-1];
				sv[j-1]=sv[j];
				sv[j]=tmp;
			}
		}
	}	
}
void sapxepnoibotngaysinh(){
	int i,j;
	sinhVien tmp;
	for(i=0;i<index;i++){
		for(j=index-1;j>i;j--)
		{
			if(sv[j].Nam<sv[j-1].Nam)
			{
				tmp=sv[j-1];
				sv[j-1]=sv[j];
				sv[j]=tmp;
			}
			else if((sv[j-1].Nam == sv[j].Nam) && (sv[j].Thang<sv[j-1].Thang))
			{
				tmp=sv[j-1];
				sv[j-1]=sv[j];
				sv[j]=tmp;
			}
			else if((sv[j-1].Nam == sv[j].Nam) && (sv[j-1].Thang == sv[j].Thang ) && (sv[j].Ngay<sv[j-1].Ngay))
			{
				tmp=sv[j-1];
				sv[j-1]=sv[j];
				sv[j]=tmp;
			}
		}	
	}
}
void sapxepnoibotdiem(){
	int i,j;
	sinhVien tmp;
	for(i=0;i<index;i++){
		for(j=index-1;j>i;j--)
		{
			if(sv[j-1].diemTB>sv[j].diemTB)
			{
				tmp=sv[j-1];
				sv[j-1]=sv[j];
				sv[j]=tmp;
			}
		}
	}
}

void qsmaLop(sinhVien sv[MAX],int left,int right){
	int i,j;
	sinhVien tg;
	char key[50];
	strcpy(key, sv[(left+right)/2].maLop);
	i=left;j=right;
	do
	{
		while((sosanh(sv[i].maLop,key)<0)&&i<right) i++;
		while((sosanh(sv[j].maLop,key)>0)&&j>left) j--;
		if(i<=j)
		{
			tg=sv[i];
			sv[i]=sv[j];
			sv[j]=tg;
			i++;
			j--;
		}
	}while(i<=j);
	if (left<j) qsmaLop(sv,left,j);
	if (i<right) qsmaLop(sv,i,right);      
}

void qsmasv(sinhVien sv[MAX],int left,int right){
	int i,j;
	sinhVien tg;
	char key[50];
	strcpy(key, sv[(left+right)/2].maSV);
	i=left;j=right;
	do
	{
		while((sosanh(sv[i].maSV,key)<0)&&i<right) i++;
		while((sosanh(sv[j].maSV,key)>0)&&j>left) j--;
		if(i<=j)
		{
			tg=sv[i];
			sv[i]=sv[j];
			sv[j]=tg;
			i++;
			j--;
		}
	}while(i<=j);
	if (left<j) qsmasv(sv,left,j);
	if (i<right) qsmasv(sv,i,right);      
}
void qshoten(sinhVien sv[MAX],int left,int right){
	int i,j;
	sinhVien tg;
	char key[50];
	strcpy(key, sv[(left+right)/2].hoTen);
	i=left;j=right;
	do
	{
		while((sosanh(sv[i].hoTen,key)<0)&&i<right) i++;
		while((sosanh(sv[j].hoTen,key)>0)&&j>left) j--;
		if(i<=j)
		{
			tg=sv[i];
			sv[i]=sv[j];
			sv[j]=tg;
			i++;
			j--;
		}
	}while(i<=j);
	if (left<j) qshoten(sv,left,j);
	if (i<right) qshoten(sv,i,right);
}
void qsnam(sinhVien sv[MAX],int left,int right){
	int i,j;
	sinhVien tg;
	int key=sv[(left+right)/2].Nam;
	i=left;j=right;
	do
	{
		while(sv[i].Nam>key && i<right) i++;
		while(sv[j].Nam<key && j>left) j--;
		if(i<=j)
		{
			tg=sv[i];
			sv[i]=sv[j];
			sv[j]=tg;
			i++;
			j--;
		}
	}while(i<=j);
	if (left<j) qsnam(sv,left,j);
	if (i<right) qsnam(sv,i,right);
}
void qsdiemTB(sinhVien sv[MAX],int left,int right){
	int i,j;
	sinhVien tg;
	float key=sv[(left+right)/2].diemTB;
	i=left;j=right;
	do
	{
		while(sv[i].diemTB<key&& i<right) i++;
		while(sv[j].diemTB>key&& j>left) j--;
		if(i<=j)
		{
			tg=sv[i];
			sv[i]=sv[j];
			sv[j]=tg;
			i++;
			j--;
		}
	}while(i<=j);
	if (left<j) qsdiemTB(sv,left,j);
	if (i<right) qsdiemTB(sv,i,right);
}
void timkiemmalop(){
	char maLop[8];
	int found=0;
	int vitri[index-1];
	int j=0;
	int i;
	xuatSinhVien();
	
	printf("\nNhap vao ma lop can tim: ");
    fflush(stdin);
    scanf("%s",&maLop);
	
    for(i=0;i<index;i++){
        if(strcmp(sv[i].maLop,maLop)==0){
        	found++;
			vitri[j++]=i;
		}
	}
    if(found==0){
    	printf("\nKhong tim thay lop nao co ma la: %s\n",maLop);
	}         
 	else
    {
   		system("cls");
      	printf("\n|====================================* THONG TIN SINH VIEN *==============================================|\n");
		printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
		printf("\n|   STT     |    MaSV   |       HO   VA   TEN                |   Ngay sinh    | Ma lop     |   Diem TB    |");
		printf("\n+-----------+-----------+------------------------------------+----------------+---------------------------+");
		for(i=0;i<j;i++){
			if(sv[vitri[i]].diemTB==10){
				printf("\n| %-5d     | %3s  | %-20s               | %2d/%2d/%2d     | %4s   | %4.2f        |",1,sv[vitri[i]].maSV, sv[vitri[i]].hoTen,sv[vitri[i]].Ngay,sv[vitri[i]].Thang,sv[vitri[i]].Nam,sv[vitri[i]].maLop,sv[vitri[i]].diemTB);
			}
			else{
				printf("\n| %-5d     | %3s  | %-20s               | %2d/%2d/%2d     | %4s   | %4.2f         |",1,sv[vitri[i]].maSV, sv[vitri[i]].hoTen,sv[vitri[i]].Ngay,sv[vitri[i]].Thang,sv[vitri[i]].Nam,sv[vitri[i]].maLop,sv[vitri[i]].diemTB);
			}
		}
		printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
		printf("\n\n\n");
	}
}
void timkiemmasv(){
	char maSV[8];
	int found=0;
	int vitri[index-1];
	int i;
	int j=0;
	xuatSinhVien();
	
	printf("\nNhap vao ma sinh vien can tim: ");
    fflush(stdin);
    scanf("%s",&maSV);
	
    for(i=0;i<index;i++){
        if(strcmp(sv[i].maSV,maSV)==0){
        	found++;
			vitri[j++]=i;
		}
	}
    if(found==0){
    	printf("\nKhong tim thay maSV nao co ma la: %s\n",maSV);
	}               
 	else
    {
   		system("cls");
      	printf("\n|====================================* THONG TIN SINH VIEN *==============================================|\n");
		printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
		printf("\n|   STT     |    MaSV   |       HO   VA   TEN                |   Ngay sinh    | Ma lop     |   Diem TB    |");
		printf("\n+-----------+-----------+------------------------------------+----------------+---------------------------+");
		for(i=0;i<j;i++){
			if(sv[vitri[i]].diemTB==10){
				printf("\n| %-5d     | %3s  | %-20s               | %2d/%2d/%2d     | %4s   | %4.2f        |",i+1,sv[vitri[i]].maSV, sv[vitri[i]].hoTen,sv[vitri[i]].Ngay,sv[vitri[i]].Thang,sv[vitri[i]].Nam,sv[vitri[i]].maLop,sv[vitri[i]].diemTB);
			}
			else{
				printf("\n| %-5d     | %3s  | %-20s               | %2d/%2d/%2d     | %4s   | %4.2f         |",i+1,sv[vitri[i]].maSV, sv[vitri[i]].hoTen,sv[vitri[i]].Ngay,sv[vitri[i]].Thang,sv[vitri[i]].Nam,sv[vitri[i]].maLop,sv[vitri[i]].diemTB);
			}
		}
		printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
		printf("\n\n\n");
	}
}
void timkiemhoten(){
	char hoten[50];
	int found=0;
	int vitri[index-1];
	int j=0;
	int i;
	xuatSinhVien();
	
	printf("\nNhap vao ho ten can tim: ");
    fflush(stdin);
    scanf("%s",&hoten);
	
    for(i=0;i<index;i++){
        if(strstr(sv[i].hoTen,hoten)!=0){
        	found++;
			vitri[j++]=i;
		}
	}
    if(found==0){
    	printf("\nKhong tim thay ho ten nao la: %s\n",hoten);
	}         
 	else
    {
   		system("cls");
      	printf("\n|====================================* THONG TIN SINH VIEN *==============================================|\n");
		printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
		printf("\n|   STT     |    MaSV   |       HO   VA   TEN                |   Ngay sinh    | Ma lop     |   Diem TB    |");
		printf("\n+-----------+-----------+------------------------------------+----------------+---------------------------+");
		for(i=0;i<j;i++){
			if(sv[vitri[i]].diemTB==10){
				printf("\n| %-5d     | %3s  | %-20s               | %2d/%2d/%2d     | %4s   | %4.2f        |",1,sv[vitri[i]].maSV, sv[vitri[i]].hoTen,sv[vitri[i]].Ngay,sv[vitri[i]].Thang,sv[vitri[i]].Nam,sv[vitri[i]].maLop,sv[vitri[i]].diemTB);
			}
			else{
				printf("\n| %-5d     | %3s  | %-20s               | %2d/%2d/%2d     | %4s   | %4.2f         |",1,sv[vitri[i]].maSV, sv[vitri[i]].hoTen,sv[vitri[i]].Ngay,sv[vitri[i]].Thang,sv[vitri[i]].Nam,sv[vitri[i]].maLop,sv[vitri[i]].diemTB);
			}
		}
		printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
		printf("\n\n\n");
	}
}

void timkiemngaysinh(){
	int ngay,thang,nam;
	int found=0;
	int vitri[index-1];
	int i;
	int j=0;
	xuatSinhVien();
	
	printf("\nNhap vao nam can tim: ");
    fflush(stdin);
    scanf("%d",&nam);
    printf("\nNhap vao thang can tim: ");
    fflush(stdin);
    scanf("%d",&thang);
    printf("\nNhap vao ngay can tim: ");
    fflush(stdin);
    scanf("%d",&ngay);
	
    for(i=0;i<index;i++){
        if(sv[i].Nam==nam && sv[i].Thang==thang && sv[i].Ngay==ngay){
        	found++;
			vitri[j++]=i;
		}
	}
    if(found==0){
    	printf("\nKhong tim thay sinh vien  nao co ngay sinh nhu vay\n");
	}               
 	else
    {
   		system("cls");
      	printf("\n|====================================* THONG TIN SINH VIEN *==============================================|\n");
		printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
		printf("\n|   STT     |    MaSV   |       HO   VA   TEN                |   Ngay sinh    | Ma lop     |   Diem TB    |");
		printf("\n+-----------+-----------+------------------------------------+----------------+---------------------------+");
		for(i=0;i<j;i++){
			if(sv[vitri[i]].diemTB==10){
				printf("\n| %-5d     | %3s  | %-20s               | %2d/%2d/%2d     | %4s   | %4.2f        |",i+1,sv[vitri[i]].maSV, sv[vitri[i]].hoTen,sv[vitri[i]].Ngay,sv[vitri[i]].Thang,sv[vitri[i]].Nam,sv[vitri[i]].maLop,sv[vitri[i]].diemTB);
			}
			else{
				printf("\n| %-5d     | %3s  | %-20s               | %2d/%2d/%2d     | %4s   | %4.2f         |",i+1,sv[vitri[i]].maSV, sv[vitri[i]].hoTen,sv[vitri[i]].Ngay,sv[vitri[i]].Thang,sv[vitri[i]].Nam,sv[vitri[i]].maLop,sv[vitri[i]].diemTB);
			}
		}
		printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
		printf("\n\n\n");
	}
}
void timkiemdiem(){
	float diem;
	int found=0;
	int vitri[index-1];
	int j=0;
	int i;
	xuatSinhVien();
	
	printf("\nNhap vao diem trung binh can tim: ");
    fflush(stdin);
    scanf("%f",&diem);
	
    for(i=0;i<index;i++){
        if(sv[i].diemTB==diem){
        	found++;
			vitri[j++]=i;
		}
	}
    if(found==0){
    	printf("\nKhong tim thay diem trung binh nao bang: %.2f\n",diem);
	}         
 	else
    {
   		system("cls");
      	printf("\n|====================================* THONG TIN SINH VIEN *==============================================|\n");
		printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
		printf("\n|   STT     |    MaSV   |       HO   VA   TEN                |   Ngay sinh    | Ma lop     |   Diem TB    |");
		printf("\n+-----------+-----------+------------------------------------+----------------+---------------------------+");
		for(i=0;i<j;i++){
			if(sv[vitri[i]].diemTB==10){
				printf("\n| %-5d     | %3s  | %-20s               | %2d/%2d/%2d     | %4s   | %4.2f        |",1,sv[vitri[i]].maSV, sv[vitri[i]].hoTen,sv[vitri[i]].Ngay,sv[vitri[i]].Thang,sv[vitri[i]].Nam,sv[vitri[i]].maLop,sv[vitri[i]].diemTB);
			}
			else{
				printf("\n| %-5d     | %3s  | %-20s               | %2d/%2d/%2d     | %4s   | %4.2f         |",1,sv[vitri[i]].maSV, sv[vitri[i]].hoTen,sv[vitri[i]].Ngay,sv[vitri[i]].Thang,sv[vitri[i]].Nam,sv[vitri[i]].maLop,sv[vitri[i]].diemTB);
			}
		}
		printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
		printf("\n\n\n");
	}
}
void timkiemnhiphanmalop(){
	qsmaLop(sv,0,index-1);
	char maLop[8];
	int found=0;
	int vitri[index-1];
	int i=0;
	int j=index-1;
	int vt=0;
	int midPoint;
	xuatSinhVien();
	
	printf("\nNhap vao ma lop can tim: ");
    fflush(stdin);
    scanf("%s",&maLop);
    
	while(i <= j)
	{
		// uoc luong gia tri tai vi tri trung vi 
		// midPoint = (lowerBound + upperBound) / 2;
		midPoint = i + (j - i) / 2;	
		
		// tim thay du lieu
		if(strcmp(sv[midPoint].maLop,maLop)==0)
		{
			found++;
			vitri[vt] = midPoint;
			vt++;
		}
		else 
		{
			// neu du lieu la lon hon 
			if(sv[midPoint].maLop < maLop){
				// tim kiem du lieu phan lon hon
				i = midPoint + 1;
			}
			// neu du lieu la nho hon 
			else{           
				// tim kiem du lieu phan nho hon
				j = midPoint - 1;
			 }
		}               
	}
	
    if(found==0){
    	printf("\nKhong tim thay lop nao co ma la: %s\n",maLop);
	}         
 	else
    {
   		system("cls");
      	printf("\n|====================================* THONG TIN SINH VIEN *==============================================|\n");
		printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
		printf("\n|   STT     |    MaSV   |       HO   VA   TEN                |   Ngay sinh    | Ma lop     |   Diem TB    |");
		printf("\n+-----------+-----------+------------------------------------+----------------+---------------------------+");
		for(i=0;i<j;i++){
			if(sv[vitri[i]].diemTB==10){
				printf("\n| %-5d     | %3s  | %-20s               | %2d/%2d/%2d     | %4s   | %4.2f        |",1,sv[vitri[i]].maSV, sv[vitri[i]].hoTen,sv[vitri[i]].Ngay,sv[vitri[i]].Thang,sv[vitri[i]].Nam,sv[vitri[i]].maLop,sv[vitri[i]].diemTB);
			}
			else{
				printf("\n| %-5d     | %3s  | %-20s               | %2d/%2d/%2d     | %4s   | %4.2f         |",1,sv[vitri[i]].maSV, sv[vitri[i]].hoTen,sv[vitri[i]].Ngay,sv[vitri[i]].Thang,sv[vitri[i]].Nam,sv[vitri[i]].maLop,sv[vitri[i]].diemTB);
			}
		}
		printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
		printf("\n\n\n");
	}
}
void timkiemnhiphanmasv(){
	qsmasv(sv,0,index-1);
	char maSV[8];
	int found=0;
	int vitri[index-1];
	int i=0;
	int j=index-1;
	int vt=0;
	int midPoint;
	xuatSinhVien();
	
	printf("\nNhap vao ma sv can tim: ");
    fflush(stdin);
    scanf("%s",&maSV);
    
	while(i <= j)
	{
		midPoint = i + (j - i) / 2;	
		if(strcmp(sv[midPoint].maSV,maSV)==0)
		{
			found++;
			vitri[vt] = midPoint;
			vt++;
			break;
		}
		else 
		{
			if(sv[midPoint].maSV < maSV){
				i = midPoint + 1;
			} 
			else{           
				j = midPoint - 1;
			 }
		}               
	}
	
    if(found==0){
    	printf("\nKhong tim thay sinh vien nao co ma la: %s\n",maSV);
	}         
 	else
    {
   		system("cls");
      	printf("\n|====================================* THONG TIN SINH VIEN *==============================================|\n");
		printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
		printf("\n|   STT     |    MaSV   |       HO   VA   TEN                |   Ngay sinh    | Ma lop     |   Diem TB    |");
		printf("\n+-----------+-----------+------------------------------------+----------------+---------------------------+");
		for(i=0;i<vt;i++){
			if(sv[vitri[i]].diemTB==10){
				printf("\n| %-5d     | %3s  | %-20s               | %2d/%2d/%2d     | %4s   | %4.2f        |",1,sv[vitri[i]].maSV, sv[vitri[i]].hoTen,sv[vitri[i]].Ngay,sv[vitri[i]].Thang,sv[vitri[i]].Nam,sv[vitri[i]].maLop,sv[vitri[i]].diemTB);
			}
			else{
				printf("\n| %-5d     | %3s  | %-20s               | %2d/%2d/%2d     | %4s   | %4.2f         |",1,sv[vitri[i]].maSV, sv[vitri[i]].hoTen,sv[vitri[i]].Ngay,sv[vitri[i]].Thang,sv[vitri[i]].Nam,sv[vitri[i]].maLop,sv[vitri[i]].diemTB);
			}
		}
		printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
		printf("\n\n\n");
	}
}
void timkiemnhiphanhoten(){}
void timkiemnhiphanngaysinh(){}
void timkiemnhiphandiem(){
	float diem;
	int found=0;
	int vitri[index-1];
	int i=0;
	int j=index-1;
	int vt=0;
	int midPoint;
	xuatSinhVien();
	
	printf("\nNhap vao diem trung binh can tim: ");
    fflush(stdin);
    scanf("%f",&diem);
	
    while(i <= j)
	{
		midPoint = i + (j - i) / 2;	
		if(sv[midPoint].diemTB==diem)
		{
			found++;
			vitri[vt] = midPoint;
			vt++;
			break;
		}
		else 
		{
			if(sv[midPoint].diemTB < diem){
				i = midPoint + 1;
			} 
			else{           
				j = midPoint - 1;
			 }
		}               
	}
    if(found==0){
    	printf("\nKhong tim thay diem trung binh nao bang: %.2f\n",diem);
	}         
 	else
    {
   		system("cls");
      	printf("\n|====================================* THONG TIN SINH VIEN *==============================================|\n");
		printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
		printf("\n|   STT     |    MaSV   |       HO   VA   TEN                |   Ngay sinh    | Ma lop     |   Diem TB    |");
		printf("\n+-----------+-----------+------------------------------------+----------------+---------------------------+");
		for(i=0;i<j;i++){
			if(sv[vitri[i]].diemTB==10){
				printf("\n| %-5d     | %3s  | %-20s               | %2d/%2d/%2d     | %4s   | %4.2f        |",1,sv[vitri[i]].maSV, sv[vitri[i]].hoTen,sv[vitri[i]].Ngay,sv[vitri[i]].Thang,sv[vitri[i]].Nam,sv[vitri[i]].maLop,sv[vitri[i]].diemTB);
			}
			else{
				printf("\n| %-5d     | %3s  | %-20s               | %2d/%2d/%2d     | %4s   | %4.2f         |",1,sv[vitri[i]].maSV, sv[vitri[i]].hoTen,sv[vitri[i]].Ngay,sv[vitri[i]].Thang,sv[vitri[i]].Nam,sv[vitri[i]].maLop,sv[vitri[i]].diemTB);
			}
		}
		printf("\n+-----------+-----------+------------------------------------+----------------+------------+--------------+");
		printf("\n\n\n");
	}
}

void thongkesoluongsv(sinhVien sv[MAX],int index){
	char maLop[10];
	sinhVien sv1[index];
	int sum[index];
	int SUM=0;
	int i,j;
	for(i=0;i<index;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(strcmpi(sv[i].maLop,sv1[j].maLop)!=0)
			{
				sv1[j]=sv[i];
			}

		}
	}
	for(i=0;i<index;i++)
	{
		sum[i]=0;
		for(j=0;j<index;j++)
		{
			if(strcmpi(sv1[j].maLop,sv[j].maLop)==0)
			{
				sum[i]++;
			}
		}
		SUM+=sum[i];
	}
	printf("\n");
	printf("\n+--------------+-----------------------------+");
	printf("\n|   Ma Lop     |    So Sinh Vien  	     |");
	printf("\n+--------------+-----------------------------+");
	for(i=0;i<index;i++){
		printf("\n| %-5s     |       %3d        	     |",sv1[i],sum[i]);
		printf("\n+--------------+-----------------------------+");
	}
	printf("\n|   Tong       |       %3d        	     |",SUM);
	printf("\n+--------------+-----------------------------+");
	printf("\n\n\n");
}
//void thongkekqhoctap(sinhVien *sv,int index){}

void menu()
{
    int choose0=0;
    do
    {
    	ReadFile("SinhVien.Dat");
    	printf("NOTE: Chon M2 -> 1 de lay du lieu tu tep\n");
   		printf("\n\n\n                  CHUONG TRINH QUAN LY SINH VIEN \n");
    	printf(" **************************************************************");
		printf("\n ** 1/ Nhap thong tin sinh vien                              **");
		printf("\n ** 2/ Danh sach sinh vien                                   **");
		printf("\n ** 3/ Sap xep sinh vien                                     **");
	    printf("\n ** 4/ Tim kiem sinh vien                                    **");
	    printf("\n ** 5/ Thong ke so luong sinh vien theo lop                  **\n **    hoac thong ke phan loai ket qua hoc tap cua sinh vien **");
	    printf("\n ** 6/ Thoat chuong trinh                                    **");
	    printf("\n **************************************************************");
	    printf("\n\n");
	    printf("\n Moi ban lua chon yeu cau: M");
	    fflush(stdin);
    	scanf("%d",&choose0);
	    switch(choose0)
	    {
		    case 1:{
		    	int choose1=0;
		    	system("cls");
		    	textColor(YELLOW);
		    	do{
		    	system("cls");
		    	printf("Ban da chon M1 \n\n");
		    	printf("1.Bat dau nhap sinh vien.\n2.Sua\n3.Xoa\n4.Thoat\n");
		    	printf("Moi ban chon: ");
		    	fflush(stdin);
		    	scanf("%d",&choose1);
		    	switch(choose1)
		    	{
		    		case 1:{
		    			system("cls");
		    			textColor(GREEN);
		    			nhapThongTin();
		    			WriteFile("SinhVien.dat");
						break;
					}
					case 2:{
						system("cls");
						textColor(GREEN);
						printf("Ban chon sua thong tin sinh vien\n\n\n");
						sua();
						WriteFile("SinhVien.dat");
						break;
					}
					case 3:{
						textColor(GREEN);
						system("cls");
						printf("Ban chon xoa thong tin sinh vien\n\n\n");
						xoa();
						WriteFile("SinhVien.dat");
						break;
					}
					case 4:{
						textColor(WHITE);
						system("cls");
						menu();
						break;
					}
					default:
					{
						printf("\n**Ban chi duoc nhap so nguyen tu 1->4 **\n\n");
						system("pause");
					}
				}
				}while(true);
				break;
			}         
		    PRINTF:case 2:{	
		    	textColor(YELLOW);
		    	system("cls");
		    	do{
		    		int choose2=0;
		    		system("cls");
		    		printf("Ban chon M2\n\n");
		    		printf("\n1.In ra danh sach sinh vien\n2.Tro ve menu chinh\n");
		    		printf("Moi ban chon: ");
		    		fflush(stdin);
		    		scanf("%d",&choose2);
		    		switch(choose2)
		    		{
						case 1:{
							system("cls");
							textColor(GREEN);
							printf("In ra danh sach sinh vien\n\n");
							xuatSinhVien();
							system("pause");
							textColor(YELLOW);
							goto PRINTF;
							break;
						}
						case 2:{
							system("cls");
							textColor(WHITE);
							menu();
							break;
						}
						default:
						{
							printf("\n**Ban chi duoc nhap so nguyen tu 1->2**\n\n");
							system("pause");
						}
					}
				}while(true);
				break;
			}           
		    SAPXEP:case 3:{
		    	do{
		    	int choose3=0;
		    	system("cls");
		    	textColor(YELLOW);
		    	printf("Ban da chon M3\n\n");
		    	printf("1.Sap xep chon\n2.Sap xep chen\n3.Sap xep noi bot\n4.Sap xep nhanh\n5.Tro ve menu chinh\n\n");
		    	printf("\n\nMoi ban chon: ");
		    	fflush(stdin);
		    	scanf("%d",&choose3);
		    	switch(choose3)
		    	{
		    		case 1:{		
		    			do{
		    				int choose31=0;
		    				system("cls");
		    				textColor(GREEN);
		    				printf("Ban da chon sap xep chon\n\n");
		    				printf("1.Theo MaSV\n2.Theo Ho&Ten\n3.Theo ngay sinh\n4.Theo diem TB tich luy\n5.Tro ve\n\n");
		    				printf("\n\nMoi ban chon: ");
		    				fflush(stdin);
		    				scanf("%d",&choose31);
		    				switch(choose31)
		    				{
		    					case 1:{
		    						system("cls");
		    						textColor(RED);
		    						printf("Theo MaSV\n\n");
		    						sapxepchonmasv();
		    						WriteFile("SinhVien.dat");
		    						xuatSinhVien();
		    						system("pause");
		    						system("cls");
									break;
								}
								case 2:{
									system("cls");
									textColor(RED);
									printf("Theo Ho&Ten\n\n");
									sapxepchonten();
									WriteFile("SinhVien.dat");
									xuatSinhVien();
									system("pause");
									system("cls");
									break;
								}
								case 3:{
									system("cls");
									textColor(RED);
									printf("Theo ngay sinh\n\n");
									sapxepchonngaysinh();
									WriteFile("SinhVien.dat");
									xuatSinhVien();
									system("pause");
									system("cls");
									break;
								}
								case 4:{
									system("cls");
									textColor(RED);
									printf("Theo diem trung binh tich luy\n\n");
									sapxepchondiem();
									WriteFile("SinhVien.dat");
									xuatSinhVien();
									system("pause");
									system("cls");
									break;
								}
								case 5:{
									goto SAPXEP;
									break;
								}
								default:
								{
									printf("\n**Ban chi duoc nhap so nguyen tu 1->5 **\n\n");
									system("pause");
								}
							}
						}while(true);
						break;
					}
					case 2:{
		    			do{
		    				int choose32=0;
		    				system("cls");
							textColor(GREEN);
							printf("Ban da chon sap xep chen\n\n");
		    				printf("1.Theo MaSV\n2.Theo Ho&Ten\n3.Theo ngay sinh\n4.Theo diem TB tich luy\n5.Tro ve\n");
		    				printf("\n\nMoi ban chon: ");
		    				fflush(stdin);
		    				scanf("%d",&choose32);
		    				switch(choose32)
		    				{
		    					case 1:{
			    					system("cls");
			    					textColor(RED);
		    						printf("Theo MaSV\n\n");
		    						sapxepchenmasv();
		    						WriteFile("SinhVien.dat");
		    						xuatSinhVien();
		    						system("pause");
		    						system("cls");
									break;
								}
								case 2:{
									system("cls");
									textColor(RED);
									printf("Theo Ho&Ten\n\n");
									sapxepchenhoten();
									WriteFile("SinhVien.dat");
									xuatSinhVien();
		    						system("pause");
		    						system("cls");
									break;
								}
								case 3:{
									system("cls");
									textColor(RED);
									printf("Theo ngay sinh\n\n");
									sapxepchennamsinh();
									WriteFile("SinhVien.dat");
									xuatSinhVien();
		    						system("pause");
		    						system("cls");
									break;
								}
								case 4:{
									system("cls");
									textColor(RED);
									printf("Theo diem trung binh tich luy\n\n");
									sapxepchendiem();
									WriteFile("SinhVien.dat");
									xuatSinhVien();
		    						system("pause");
		    						system("cls");
									break;
								}
								case 5:{
									goto SAPXEP;
									break;
								}
								default:
								{
									printf("\n**Ban chi duoc nhap so nguyen tu 1->5 **\n\n");
									system("pause");
								}
							}
						}while(true);
						break;
					}
					case 3:{
		    			do{
		    				int choose33=0;
		    				system("cls");
							textColor(GREEN);
							printf("Ban da chon sap xep noi bot\n\n");
		    				printf("1.Theo MaSV\n2.Theo Ho&Ten\n3.Theo ngay sinh\n4.Theo diem TB tich luy\n5.Tro ve\n");
		    				printf("\n\nMoi ban chon: ");
		    				fflush(stdin);
		    				scanf("%d",&choose33);
		    				switch(choose33)
		    				{
		    					case 1:{
		    						system("cls");
		    						textColor(RED);
		    						printf("Theo MaSV\n\n");
		    						sapxepnoibotmasv();
		    						WriteFile("SinhVien.dat");
		    						xuatSinhVien();
		    						system("pause");
		    						system("cls");
									break;
								}
								case 2:{
									system("cls");
									textColor(RED);
									printf("Theo Ho&Ten\n\n");
									sapxepnoibothoten();
									WriteFile("SinhVien.dat");
									xuatSinhVien();
		    						system("pause");
		    						system("cls");
									break;
								}
								case 3:{
									system("cls");
									textColor(RED);
									printf("Theo ngay sinh\n\n");
									sapxepnoibotngaysinh();
									WriteFile("SinhVien.dat");
									xuatSinhVien();
		    						system("pause");
		    						system("cls");
									break;
								}
								case 4:{
									system("cls");
									textColor(RED);
									printf("Theo diem trung binh tich luy\n\n");
									sapxepnoibotdiem();
									WriteFile("SinhVien.dat");
									xuatSinhVien();
		    						system("pause");
		    						system("cls");
									break;
								}
								case 5:{
									goto SAPXEP;
									break;
								}
								default:
								{
									printf("\n**Ban chi duoc nhap so nguyen tu 1->5 **\n\n");
									system("pause");
								}
							}
						}while(true);
						break;
					}
					case 4:{		    			
		    			do{
		    				int choose34=0;
		    				system("cls");
							textColor(GREEN);
							printf("Ban da chon sap xep nhanh\n\n");
		    				printf("1.Theo MaSV\n2.Theo Ho&Ten\n3.Theo ngay sinh\n4.Theo diem TB tich luy\n5.Tro ve\n");
		    				printf("\n\nMoi ban chon: ");
		    				fflush(stdin);
		    				scanf("%d",&choose34);
		    				switch(choose34)
		    				{
		    				case 1:{
		    						system("cls");
		    						textColor(RED);
		    						printf("Theo MaSV\n\n");
		    						qsmasv(sv,0,index-1);
		    						WriteFile("SinhVien.dat");
		    						xuatSinhVien();
		    						system("pause");
		    						system("cls");
									break;
								}
								case 2:{
									system("cls");
									textColor(RED);
									printf("Theo Ho&Ten\n\n");
									qshoten(sv,0,index-1);
									WriteFile("SinhVien.dat");
									xuatSinhVien();
		    						system("pause");
		    						system("cls");
									break;
								}
								case 3:{
									system("cls");
									textColor(RED);
									printf("Theo ngay sinh\n\n");
									qsnam(sv,0,index-1);
									WriteFile("SinhVien.dat");
									xuatSinhVien();
		    						system("pause");
		    						system("cls");
									break;
								}
								case 4:{
									system("cls");
									textColor(RED);
									printf("Theo diem trung binh tich luy\n\n");
									qsdiemTB(sv,0,index-1);
									WriteFile("SinhVien.dat");
									xuatSinhVien();
		    						system("pause");
		    						system("cls");
									break;
								}
								case 5:{
									goto SAPXEP;
									break;
								}
								default:
								{
									printf("\n**Ban chi duoc nhap so nguyen tu 1->5 **\n\n");
									system("pause");
								}
							}
						}while(true);
						break;
					}
					case 5:{
						system("cls");
						textColor(WHITE);
						menu();
						break;
					}
					default:
					{
						printf("\n**Ban chi duoc nhap so nguyen tu 1->5 **\n\n");
						system("pause");
					}
				} 		
				}while(true);
				break;
			}            
		    TIMKIEM:case 4:{
		    	system("cls");
		    	textColor(YELLOW);	   	
		    	do{
		    		int choose4=0;
		    		system("cls");
		    		printf("Ban da chon M4\n\n"); 
		    		printf("1.Tim kiem tuan tu\n2.Tim kiem nhi phan\n3.Tro ve menu chinh\n");
		    		printf("Moi ban chon: ");
		    		fflush(stdin);
		    		scanf("%d",&choose4);
		    		switch(choose4)
		    		{
		    			case 1:{
			    			do{
			    				int choose41=0;
			    				system("cls");
			    				textColor(GREEN);
			    				printf("Ban da chon tim kiem tuan tu\n");
			    				printf("1.Theo ma lop\n2.Theo MaSV\n3.Theo Ho&Ten\n4.Theo ngay sinh\n5.Theo diem TB tich luy\n6.Tro ve\n");
			    				printf("\n\nMoi ban chon: ");
			    				fflush(stdin);
			    				scanf("%d",&choose41);
			    				switch(choose41)
			    				{
			    					case 1:{
			    						system("cls");
			    						textColor(RED);
			    						printf("Theo Ma Lop\n\n");
			    						timkiemmalop();
			    						system("pause");
			    						textColor(GREEN);
										break;
									}
			    					case 2:{
			    						system("cls");
			    						textColor(RED);
			    						printf("Theo MaSV\n\n");
			    						timkiemmasv();
			    						system("pause");
			    						textColor(GREEN);
										break;
									}
									case 3:{
										system("cls");
										textColor(RED);
										printf("Theo Ho&Ten\n\n");
										timkiemhoten();
										system("pause");
										textColor(GREEN);
										break;
									}
									case 4:{
										system("cls");
										textColor(RED);
										printf("Theo ngay sinh\n\n");
										timkiemngaysinh();
										system("pause");
										textColor(GREEN);
										break;
									}
									case 5:{
										system("cls");
										textColor(RED);
										printf("Theo diem trung binh tich luy\n\n");
										timkiemdiem();
										system("pause");
										textColor(GREEN);
										break;
									}
									case 6:{
										goto TIMKIEM;
										break;
									}
									default:
									{
										printf("Ban chi duoc nhap so nguyen tu 1->6 \n\n");
										system("pause");
									}
								}
							}while(true);
							break;
						}
						case 2:{
			    			do{
			    				int choose42=0;
			    				system("cls");
								textColor(GREEN);
								printf("Ban da chon tim kiem nhi phan\n");
			    				printf("1.Theo ma lop\n2.Theo MaSV\n3.Tim theo HoTen\n4.Tim theo ngay sinh\n5.Theo diem TB tich luy\n6.Tro ve\n");
			    				printf("\n\nMoi ban chon: ");
			    				fflush(stdin);
			    				scanf("%d",&choose42);
			    				switch(choose42)
			    				{
			    					case 1:{	    						
										system("cls");
										textColor(RED);
										printf("Theo diem Ma Lop\n\n");
										timkiemnhiphanmalop();
										system("pause");
										textColor(GREEN);
										break;
									}
									case 2:{
										system("cls");
			    						textColor(RED);
			    						printf("Theo MaSV\n\n");
			    						timkiemnhiphanmasv();	  
										system("pause");  
										textColor(GREEN);						
										break;
									}
									case 3:{
										system("cls");
										textColor(RED);
										printf("Theo Ho&Ten\n\n");
										timkiemnhiphanhoten();
										system("pause");
										textColor(GREEN);
										break;
									}
									case 4:{
										system("cls");
										textColor(RED);
										printf("Theo ngay sinh\n\n");
										timkiemnhiphanngaysinh();
										system("pause");
										textColor(GREEN);
										break;
									}
									case 5:{
										system("cls");
										textColor(RED);
										printf("Theo diem trung binh tich luy\n\n");
										timkiemnhiphandiem();
										system("pause");
										textColor(GREEN);
										break;
									}
									case 6:{
										goto TIMKIEM;
										break;
									}
									default:
									{
										printf("Ban chi duoc nhap so nguyen tu 1->6 \n\n");
										system("pause");
									}
								}
							}while(true);
							break;
						}
						case 3:{
							system("cls");
							textColor(WHITE);
							menu();
							break;
						}
						default:
						{
							printf("Ban chi duoc nhap so nguyen tu 1->3 \n\n");
							system("pause");
						}
					}
				}while(true);
				break;
			}               
		    case 5:{		    	
		    	system("cls");
		    	textColor(YELLOW);
		    	printf("Ban da chon M5\n\n");
		    	do{
		    		int choose5=0;
		    		printf("1.Thong ke so luong sinh vien theo lop\n2.Thong ke phan loai ket qua hoc tap cua sinh vien\n3.Tro ve menu chinh\n");
		    		printf("Moi ban chon: ");
		    		fflush(stdin);
		    		scanf("%d",&choose5); 		
		    		switch(choose5)
		    		{
		    			case 1:{
		    				system("cls");
		    				textColor(GREEN);
		    				printf("Ban da chon thong ke so luong sinh vien theo lop");
		    				thongkesoluongsv(sv,index);
							break;
						}
						case 2:{
							system("cls");
							textColor(GREEN);
							printf("Ban da chon thong ke phan loai ket qua hoc tap cua sinh vien\n\n\n");
							//thongkekqhoctap(sv,index);			
							break;
						}
						case 3:{
							system("cls");
							textColor(WHITE);
							menu();
							break;
						}
						default:
						{
							printf("\n**Ban chi duoc nhap so nguyen tu 1->3 **\n\n");
							system("pause");
						}
					}
				}while(true);
				break;
			}                  
		    case 6:{
		    	system("cls");
		    	textColor(GREEN);		    	
		    	printf("\nBan co chac chan muon thoat ko? (Chon '1' de THOAT hoac '2' de HUY)\n\n\n");
		    	do{
		    		int choose6=0;
		    		printf("Moi ban chon: ");
		    		fflush(stdin);
			    	scanf("%d",&choose6);
					switch(choose6)
					{
						case 1:{
							exit(0);
							break;
						}
						case 2:{
							system("cls");
							textColor(WHITE);
							menu();
							break;
						}
						default:
						{
							printf("\n**Ban chi duoc nhap so nguyen tu 1->2 **\n");
							system("pause");
						}
					}
				}while(true);
			} 
		    default:{
				printf("\n Ban phai lua chon cac yeu cau tuong ung voi cac so nguyen tu 1 -> 6.\n\n");
				system("pause");
				system("cls");
				break;
			}
    	}
    }while(true);
}
int main(){
	menu();
	return 0;
}
