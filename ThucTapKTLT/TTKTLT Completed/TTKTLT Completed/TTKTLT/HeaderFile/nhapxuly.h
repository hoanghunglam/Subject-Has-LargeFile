#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define Sosinhvien 200
typedef struct 
{ 
    unsigned int ngay; 
    unsigned int thang; 
    unsigned int nam; 
} KieuNgayThang;
typedef struct 
{ 
    char ngay[10];
    char thang[10];
    char nam[10];
} KieuNgayThang1; 
typedef struct 
{ 
    char malop[20];
    char masv[10];
    char hoten[20];
    KieuNgayThang ns;
    KieuNgayThang1 nsc;
    char diemc[10];
    int diem;
} KieuSinhVien; 


void Laysosv(int &demsosv)
{
	FILE *f2;
	f2=fopen("ResourceFile/demsosv.txt","rt");
	if(f2!=NULL)
	{
		fscanf(f2,"%d\n",&demsosv);
		fclose(f2);
	}
}

void Input(KieuSinhVien *s)
{
	FILE *f2;
	f2=fopen("ResourceFile/output.txt","at");
	if(f2!=NULL)
	{
		fprintf(f2,"\n%s\n",s->malop);
		fprintf(f2,"%s\n",s->masv);
		fprintf(f2,"%s\n",s->hoten);
		if(s->ns.ngay>=1 && s->ns.ngay<=9)
		{
			fprintf(f2,"0%d\n",s->ns.ngay);
		}
		else
		{
			fprintf(f2,"%d\n",s->ns.ngay);	
		}
		if(s->ns.thang>=1 && s->ns.thang<=9)
		{
			fprintf(f2,"0%d\n",s->ns.thang);	
		}
		else
		{
			fprintf(f2,"0%d\n",s->ns.thang);	
		}
		fprintf(f2,"%d\n",s->ns.nam);
		fprintf(f2,"%s\n",s->diemc);
		fclose(f2);
	}
}
void Input2(KieuSinhVien s[],int v)
{
	int a;
	Laysosv(a);
	FILE *f2;
	f2=fopen("ResourceFile/output.txt","wt");
	if(f2!=NULL)
	{
		for(int i=1;i<=a;i++)
		{
			if(i!=v)
			{
			fprintf(f2,"\n");
			fprintf(f2,"%s",s[i].malop);
			fprintf(f2,"%s",s[i].masv);
			fprintf(f2,"%s",s[i].hoten);
			fprintf(f2,"%s",s[i].nsc.ngay);	
			fprintf(f2,"%s",s[i].nsc.thang);	
			fprintf(f2,"%s",s[i].nsc.nam);
			fprintf(f2,"%s",s[i].diemc);
			}
		}
		fclose(f2);
	}
}
void Input3(KieuSinhVien s[],int X,int q)
{
	int a;
	Laysosv(a);
	FILE *f2;
	f2=fopen("ResourceFile/output.txt","wt");
	if(f2!=NULL)
	{
		for(int i=1;i<=a;i++)
		{
			fprintf(f2,"\n");
			fprintf(f2,"%s",s[i].malop);
			if(X==7 && i==q)
			{
				fprintf(f2,"\n");
			}
			fprintf(f2,"%s",s[i].masv);
			if(X==20 && i==q)
			{
				fprintf(f2,"\n");
			}
			fprintf(f2,"%s",s[i].hoten);
			if(X==31 && i==q)
			{
				fprintf(f2,"\n");
			}
			fprintf(f2,"%s",s[i].nsc.ngay);	
			if(X==71 && i==q)
			{
				fprintf(f2,"\n");
			}
			fprintf(f2,"%s",s[i].nsc.thang);
			if(X==71 && i==q)
			{
				fprintf(f2,"\n");
			}	
			fprintf(f2,"%s",s[i].nsc.nam);
			if(X==71 && i==q)
			{
				fprintf(f2,"\n");
			}
			fprintf(f2,"%s",s[i].diemc);
			if(X==82 && i==q)
			{
				fprintf(f2,"\n");
			}		
		}
		fclose(f2);
	}
}
void Ghisosv(int demsosv)
{
	FILE *f1;
	f1=fopen("ResourceFile/demsosv.txt","wt");
	if(f1!=NULL)
	{
		fprintf(f1,"%d",demsosv);
		fclose(f1);
	}
}
void DLSxep(KieuSinhVien s[],int a)
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
		}
		fclose(f);
	}
}
void DLSua(KieuSinhVien *s,int a)
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
		}
		fclose(f);
	}
}
void MKTSxepw(int a)
{
	FILE *f;
	f=fopen("ResourceFile/ktrsx.txt","wt");
	if(f!=NULL)
	{
		fprintf(f,"%d",a);
		fclose(f);
	}
}
void MKTSxepr(int &a)
{
	FILE *f;
	f=fopen("ResourceFile/ktrsx.txt","rt");
	if(f!=NULL)
	{
		fscanf(f,"%d",&a);
		fclose(f);
	}
}
//..............................................Xu ly Sap Xep Chon.................................................//
int SosanhD(char a[], char b[])
{
	int n = 0;
	do
	{
		if (a[n] > b[n])
			return 1;
		else if (a[n] < b[n])
			return -1;
		n++;
	} while (n!=strlen(a));
	return 0;
}
void TronDiem(char *s)
{
	if(strlen(s)==1)
	{
		s[1]=s[0];
		s[0]=48;
		for(int u=strlen(s);u>=3;u--)
		{
			s[strlen(s)-1]= '\0';
		}
	}
}
void LayTen(char a[],int &k)
{
	for(k=strlen(a)-2;k>=0;k--)
	{
		if(a[k-1]==32)
		{
			break;
		}
	}
}
int SosanhTen(char a[], char b[])
{
	int k,l;
	LayTen(a,k);
	LayTen(b,l);
	do
	{
		if (a[k] > b[l])
			return 1;
		else if (a[k] < b[l])
			return -1;
		k++;l++;
	} while (a[k] != '\0' || b[l] != '\0');	
	return 0;
}
int SosanhTen1(char a[], char b[])
{
	int k=0,l;
	LayTen(b,l);
	do
	{
		if (a[k] > b[l])
			return 1;
		else if (a[k] < b[l])
			return -1;
		k++;l++;
	} while (k!=strlen(a));	
	return 0;
}
int SosanhHo(char a[], char b[])
{
	int k=0,l=0;
	do
	{
		if (a[k] > b[l])
			return 1;
		else if (a[k] < b[l])
			return -1;
		k++;l++;
	} while (a[k] ==32 || b[l] ==32);
	
	return 0;
}
void Hoanvi(KieuSinhVien &d,KieuSinhVien &f)
{
	KieuSinhVien temp;
	temp=d;
	d=f;
	f=temp;
}
void Hoanvi1(int &d, int &f)
{
	int temp;
	temp = d;
	d = f;
	f = temp;
}
void XetNamSinh(int temp[],KieuSinhVien s[],int demsosv)
{
	for (int i = 1; i <= demsosv; i++)
	{
		s[i].ns.nam = atoi(s[i].nsc.nam);
		s[i].ns.thang = atoi(s[i].nsc.thang);
		s[i].ns.ngay = atoi(s[i].nsc.ngay);
		temp[i] = s[i].ns.nam * 10000 + s[i].ns.thang * 100 + s[i].ns.ngay;
	}
}
void SapxepCDG(KieuSinhVien s[],int l)
{
	int i,j,u;
	for(i=1;i<=l-1;i++)
	{		
		for(j=i+1;j<=l;j++)
		{
			if(strcmp(s[i].diemc, s[j].diemc)==-1)
			{
				Hoanvi(s[i],s[j]);
			}	
		}
	}
}
void SapxepCDT(KieuSinhVien s[],int l)
{
	int i,j,u,b=l;
	for(i=1;i<=l-1;i++)
	{		
		for(j=i+1;j<=l;j++)
		{
			if(strcmp(s[i].diemc, s[j].diemc)==1)
			{
				Hoanvi(s[i],s[j]);
			}		
		}
	}
}
void SapxepCMLT(KieuSinhVien s[],int l)
{
	int i,j,u,b=l;
	for(i=1;i<=l-1;i++)
	{		
		for(j=i+1;j<=l;j++)
		{
			if(strcmp(s[i].malop, s[j].malop)==1)
			{
				Hoanvi(s[i],s[j]);
			}		
		}
	}
}
void SapxepCMLG(KieuSinhVien s[],int l)
{
	int i,j,u,b=l;
	for(i=1;i<=l-1;i++)
	{		
		for(j=i+1;j<=l;j++)
		{
			if(strcmp(s[i].malop, s[j].malop)==-1)
			{
				Hoanvi(s[i],s[j]);
			}	
		}
	}
}
void SapxepCMST(KieuSinhVien s[],int l)
{
	int i,j;
	for(i=1;i<=l-1;i++)
	{	
		for(j=i+1;j<=l;j++)
		{
			if(strcmp(s[i].masv, s[j].masv)==1)
			{
				Hoanvi(s[i],s[j]);
			}
		}
	}
}
void SapxepCMSG(KieuSinhVien s[],int l)
{
	int i,j;
	for(i=1;i<=l-1;i++)
	{	
		for(j=i+1;j<=l;j++)
		{
			if(strcmp(s[i].masv, s[j].masv)==-1)
			{
				Hoanvi(s[i],s[j]);
			}
		}
	}
}

void SapxepCNSG(KieuSinhVien s[],int l)
{
	int i,j,a[l+1];
	XetNamSinh(a,s,l);
	for(i=1;i<=l-1;i++)
	{	
		for(j=i+1;j<=l;j++)
		{
			if(a[i]>a[j])
			{
				Hoanvi(s[i],s[j]);
				Hoanvi1(a[i],a[j]);
			}
		}
	}
}

void SapxepCNST(KieuSinhVien s[],int l)
{
	int i,j,a[l+1];
	XetNamSinh(a,s,l);
	for(i=1;i<=l-1;i++)
	{	
		for(j=i+1;j<=l;j++)
		{
			if(a[i]<a[j])
			{
				Hoanvi(s[i],s[j]);
				Hoanvi1(a[i],a[j]);
			}
		}
	}
}
void SapxepCHTT(KieuSinhVien s[],int l)
{
	int k,o,m;
	for(int i=1;i<=l-1;i++)
	{	
		for(int j=i+1;j<=l;j++)
		{
			if(SosanhTen(s[i].hoten, s[j].hoten)==1)
			{
				Hoanvi(s[i],s[j]);
			}	
			else if(SosanhTen(s[i].hoten, s[j].hoten)==0)
			{
				if(SosanhHo(s[i].hoten, s[j].hoten)==1)
				{
					Hoanvi(s[i],s[j]);
				}
			}
		}	
	}
}
void SapxepCHTG(KieuSinhVien s[],int l)
{
	int k,o,m;
	for(int i=1;i<=l-1;i++)
	{	
		for(int j=i+1;j<=l;j++)
		{
			if(SosanhTen(s[i].hoten, s[j].hoten)==-1)
			{
				Hoanvi(s[i],s[j]);
			}
			else if(SosanhTen(s[i].hoten, s[j].hoten)==0)
			{
				if(SosanhHo(s[i].hoten, s[j].hoten)==-1)
				{
					Hoanvi(s[i],s[j]);
				}
			}
		}	
	}
}
//......................................Sap xep noi bot..............................//
void SapxepBDT(KieuSinhVien s[],int l)
{
	int i,j,u;
	for (i=0; i<l; i++) 
	{
      	for (int j=l; j>i+1; j--)
      	{
			if(strcmp(s[j-1].diemc, s[j].diemc)==1)
			{
				Hoanvi(s[j],s[j-1]);
			}	
		}
	}
}
void SapxepBDG(KieuSinhVien s[],int l)
{
	int i,j,u;
	for (i=0; i<l; i++) 
	{
      	for (int j=l; j>i+1; j--)
      	{
			if(strcmp(s[j-1].diemc, s[j].diemc)==-1)
			{
				Hoanvi(s[j],s[j-1]);
			}	
		}
	}
}
void SapxepBMLG(KieuSinhVien s[],int l)
{
	int i,j,u;
	for (i=0; i<l; i++) 
	{
      	for (int j=l; j>i+1; j--)
      	{
			if(strcmp(s[j-1].malop, s[j].malop)==-1)
			{
				Hoanvi(s[j],s[j-1]);
			}	
		}
	}
}
void SapxepBMLT(KieuSinhVien s[],int l)
{
	int i,j,u;
	for (i=0; i<l; i++) 
	{
      	for (int j=l; j>i+1; j--)
      	{
			if(strcmp(s[j-1].malop, s[j].malop)==1)
			{
				Hoanvi(s[j],s[j-1]);
			}	
		}
	}
}
void SapxepBMST(KieuSinhVien s[],int l)
{
	int i,j;
	for (i=0; i<l; i++) 
	{
      	for (int j=l; j>i+1; j--)
      	{
			if(strcmp(s[j-1].masv, s[j].masv)==1)
			{
				Hoanvi(s[j],s[j-1]);
			}
		}
	}
}
void SapxepBMSG(KieuSinhVien s[],int l)
{
	int i,j;
	for (i=0; i<l; i++) 
	{
      	for (int j=l; j>i+1; j--)
      	{
			if(strcmp(s[j-1].masv, s[j].masv)==-1)
			{
				Hoanvi(s[j],s[j-1]);
			}
		}
	}
}

void SapxepBNST(KieuSinhVien s[],int l)
{
	int i,j,a[l+1];
	XetNamSinh(a,s,l);
	for (i=0; i<l; i++) 
	{
      	for (int j=l; j>i+1; j--)
      	{
			if(a[j-1]<a[j])
			{
				Hoanvi(s[j],s[j-1]);
				Hoanvi1(a[j],a[j-1]);
			}
		}
	}
}
void SapxepBNSG(KieuSinhVien s[],int l)
{
	int i,j,a[l+1];
	XetNamSinh(a,s,l);
	for (i=0; i<l; i++) 
	{
      	for (int j=l; j>i+1; j--)
      	{
			if(a[j-1]>a[j])
			{
				Hoanvi(s[j],s[j-1]);
				Hoanvi1(a[j],a[j-1]);
			}
		}
	}
}
void SapxepBHTT(KieuSinhVien s[],int l)
{
	int k,o;
	for (int i=0; i<l; i++) 
	{
      	for (int j=l; j>i+1; j--)
      	{
			if(SosanhTen(s[j-1].hoten, s[j].hoten)==1)
			{
				Hoanvi(s[j-1],s[j]);
			}
			else if(SosanhTen(s[j-1].hoten, s[j].hoten)==0)
			{
				if(SosanhHo(s[j-1].hoten, s[j].hoten)==1)
				{
					Hoanvi(s[j-1],s[j]);
				}
			}	
		}	
	}
}
void SapxepBHTG(KieuSinhVien s[],int l)
{
	int k,o;
	for (int i=0; i<l; i++) 
	{
      	for (int j=l; j>i+1; j--)
      	{
			if(SosanhTen(s[j-1].hoten, s[j].hoten)==-1)
			{
				Hoanvi(s[j-1],s[j]);
			}	
			else if(SosanhTen(s[j-1].hoten, s[j].hoten)==0)
			{
				if(SosanhHo(s[j-1].hoten, s[j].hoten)==-1)
				{
					Hoanvi(s[j-1],s[j]);
				}
			}
		}	
	}
}
//.......................................Sap xep Chen......................//
void SapxepEMST(KieuSinhVien s[],int l)
{
   int j,x;
   KieuSinhVien temp;
   for(int i=2;i<=l;i++)
   {
	   j=i-1;
	   temp=s[i];
	   while(strcmp(temp.masv, s[j].masv)==-1 && j>0)
	   {
		   s[j+1]=s[j];
		   j--;
	   }
	   s[j+1]=temp;
	}
}
void SapxepEMSG(KieuSinhVien s[],int l)
{
   int j,x;
   KieuSinhVien temp;
   for(int i=2;i<=l;i++)
   {
	   j=i-1;
	   temp=s[i];
	   while(strcmp(temp.masv, s[j].masv)==1 && j>0)
	   {
		   s[j+1]=s[j];
		   j--;
	   }
	   s[j+1]=temp;
	}
}

void SapxepEDT(KieuSinhVien s[],int l)
{
   int j,x;
   KieuSinhVien temp;
   for(int i=2;i<=l;i++)
   {
	   j=i-1;
	   temp=s[i];
	   while(strcmp(temp.diemc, s[j].diemc)==-1 && j>0)
	   {
		   s[j+1]=s[j];
		   j--;
	   }
	   s[j+1]=temp;
	}
}
void SapxepEDG(KieuSinhVien s[],int l)
{
   int j,x;
   KieuSinhVien temp;
   for(int i=2;i<=l;i++)
   {
	   j=i-1;
	   temp=s[i];
	   while(strcmp(temp.diemc, s[j].diemc)==1 && j>0)
	   {
		   s[j+1]=s[j];
		   j--;
	   }
	   s[j+1]=temp;
	}
}
void SapxepEMLG(KieuSinhVien s[],int l)
{
   int j,x;
   KieuSinhVien temp;
   for(int i=2;i<=l;i++)
   {
	   j=i-1;
	   temp=s[i];
	   while(strcmp(temp.malop, s[j].malop)==1 && j>0)
	   {
		   s[j+1]=s[j];
		   j--;
	   }
	   s[j+1]=temp;
	}
}
void SapxepEMLT(KieuSinhVien s[],int l)
{
   int j,x;
   KieuSinhVien temp;
   for(int i=2;i<=l;i++)
   {
	   j=i-1;
	   temp=s[i];
	   while(strcmp(temp.malop, s[j].malop)==-1 && j>0)
	   {
		   s[j+1]=s[j];
		   j--;
	   }
	   s[j+1]=temp;
	}
}
void SapxepEHTT(KieuSinhVien s[],int l)
{
   int j,x;
   KieuSinhVien temp;
   for(int i=2;i<=l;i++)
   {
	   j=i-1;
	   temp=s[i];
	   if(SosanhTen(temp.hoten, s[j].hoten)!=0)
	   {
		   while(SosanhTen(temp.hoten, s[j].hoten)==-1 && j>0)
		   {
		   		s[j+1]=s[j];
		   		j--;
	   		}
	   	}
	   	else
	   	{
	   		while(SosanhHo(temp.hoten, s[j].hoten)==-1 && SosanhTen(temp.hoten, s[j].hoten)==0)
			{
		   		s[j+1]=s[j];
		   		j--;
			}
		}
	   s[j+1]=temp;
	}
}
void SapxepEHTG(KieuSinhVien s[],int l)
{
   int j,x;
   KieuSinhVien temp;
   for(int k=0;k<3;k++){
   for(int i=2;i<=l;i++)
   {
	   j=i-1;
	   temp=s[i];
	   if(SosanhTen(temp.hoten, s[j].hoten)!=0)
	   {
		   while(SosanhTen(temp.hoten, s[j].hoten)==1 && j>0)
		   {
		   		s[j+1]=s[j];
		   		j--;
	   		}
	   	}
	   	else
	   	{
	   		while(SosanhHo(temp.hoten, s[j].hoten)==1 && SosanhTen(temp.hoten, s[j].hoten)==0)
			{
		   		s[j+1]=s[j];
		   		j--;
			}
		}
	   s[j+1]=temp;
	}}
}
void SapxepENST(KieuSinhVien s[],int l)
{
	int j,x;
   KieuSinhVien temp;
   for(int k=0;k<3;k++){
   for(int i=2;i<=l;i++)
   {
	   j=i-1;
	   temp=s[i];
	   if(strcmp(temp.nsc.nam, s[j].nsc.nam)==0)
	   {
		   if(strcmp(temp.nsc.thang, s[j].nsc.thang)==1)
		   {
			   while(strcmp(temp.nsc.thang, s[j].nsc.thang)==1 && strcmp(temp.nsc.nam, s[j].nsc.nam)==0)
			   {
			   s[j+1]=s[j];
			   j--;
			   }
		   }
		   else if(strcmp(temp.nsc.thang, s[j].nsc.thang)==0)
		   {
			   while(strcmp(temp.nsc.ngay, s[j].nsc.ngay)==1 && strcmp(temp.nsc.thang, s[j].nsc.thang)==0)
			   {
			   s[j+1]=s[j];
			   j--;
			   }
		   }
	   }
	   else
	   {
		   while(strcmp(temp.nsc.nam, s[j].nsc.nam)==1 && j>0)
		   {
			   s[j+1]=s[j];
			   j--;
		   }
		   
	   }
	   s[j+1]=temp;
   }}
}
void SapxepENSG(KieuSinhVien s[],int l)
{
	int j,x;
   KieuSinhVien temp;
   for(int k=0;k<3;k++){
   for(int i=2;i<=l;i++)
   {
	   j=i-1;
	   temp=s[i];
	   if(strcmp(temp.nsc.nam, s[j].nsc.nam)==0)
	   {
		   if(strcmp(temp.nsc.thang, s[j].nsc.thang)==-1)
		   {
			   while(strcmp(temp.nsc.thang, s[j].nsc.thang)==-1 && strcmp(temp.nsc.nam, s[j].nsc.nam)==0)
			   {
			   s[j+1]=s[j];
			   j--;
			   }
		   }
		   else if(strcmp(temp.nsc.thang, s[j].nsc.thang)==0)
		   {
			   while(strcmp(temp.nsc.ngay, s[j].nsc.ngay)==-1 && strcmp(temp.nsc.thang, s[j].nsc.thang)==0)
			   {
			   s[j+1]=s[j];
			   j--;
			   }
		   }
	   }
	   else
	   {
		   while(strcmp(temp.nsc.nam, s[j].nsc.nam)==-1 && j>0)
		   {
			   s[j+1]=s[j];
			   j--;
		   }
		   
	   }
	   s[j+1]=temp;
   }}
}
//................................Sap xep QuickSort....................
void SapxepQDT(KieuSinhVien s[],int left,int right)
{
    int    i, j;
    KieuSinhVien temp;
    temp = s[(left+right)/2];     
    i = left;    
    j = right;
    do{
        while (strcmp(temp.diemc, s[i].diemc)==1) i++;   
        while (strcmp(temp.diemc, s[j].diemc)==-1) j--;    
        if ( i <= j)      
        {
            Hoanvi(s[i], s[j]);
            i++;        
            j--;        
        }
    } while (i<j);
    if (left < j)    
        SapxepQDT(s, left, j);
    if (right > i)    
        SapxepQDT(s, i, right);
}
void SapxepQDG(KieuSinhVien s[],int left,int right)
{
    int    i, j;
    KieuSinhVien temp;
    temp = s[(left+right)/2];     
    i = left;    
    j = right;
    do{
        while (strcmp(temp.diemc, s[i].diemc)==-1) i++;   
        while (strcmp(temp.diemc, s[j].diemc)==1) j--;    
        if ( i <= j)      
        {
            Hoanvi(s[i], s[j]);
            i++;        
            j--;        
        }
    } while (i<j);
    if (left < j)    
        SapxepQDG(s, left, j);
    if (right > i)    
        SapxepQDG(s, i, right);
}
void SapxepQMSG(KieuSinhVien s[],int left,int right)
{
    int    i, j;
    KieuSinhVien temp;
    temp = s[(left+right)/2];     
    i = left;    
    j = right;
    do{
        while (strcmp(temp.masv, s[i].masv)==-1) i++;   
        while (strcmp(temp.masv, s[j].masv)==1) j--;    
        if ( i <= j)      
        {
            Hoanvi(s[i], s[j]);
            i++;        
            j--;        
        }
    } while (i<j);
    if (left < j)    
        SapxepQMSG(s, left, j);
    if (right > i)    
        SapxepQMSG(s, i, right);
}
void SapxepQMST(KieuSinhVien s[],int left,int right)
{
    int    i, j;
    KieuSinhVien temp;
    temp = s[(left+right)/2];     
    i = left;    
    j = right;
    do{
        while (strcmp(temp.masv, s[i].masv)==1) i++;   
        while (strcmp(temp.masv, s[j].masv)==-1) j--;    
        if ( i <= j)      
        {
            Hoanvi(s[i], s[j]);
            i++;        
            j--;        
        }
    } while (i<j);
    if (left < j)    
        SapxepQMST(s, left, j);
    if (right > i)    
        SapxepQMST(s, i, right);
}
void SapxepQMLG(KieuSinhVien s[],int left,int right)
{
    int    i, j;
    KieuSinhVien temp;
    temp = s[(left+right)/2];     
    i = left;    
    j = right;
    do{
        while (strcmp(temp.malop, s[i].malop)==-1) i++;   
        while (strcmp(temp.malop, s[j].malop)==1) j--;    
        if ( i <= j)      
        {
            Hoanvi(s[i], s[j]);
            i++;        
            j--;        
        }
    } while (i<j);
    if (left < j)    
        SapxepQMLG(s, left, j);
    if (right > i)    
        SapxepQMLG(s, i, right);
}
void SapxepQMLT(KieuSinhVien s[],int left,int right)
{
    int    i, j;
    KieuSinhVien temp;
    temp = s[(left+right)/2];     
    i = left;    
    j = right;
    do{
        while (strcmp(temp.malop, s[i].malop)==1) i++;   
        while (strcmp(temp.malop, s[j].malop)==-1) j--;    
        if ( i <= j)      
        {
            Hoanvi(s[i], s[j]);
            i++;        
            j--;        
        }
    } while (i<j);
    if (left < j)    
        SapxepQMLT(s, left, j);
    if (right > i)    
        SapxepQMLT(s, i, right);
}
void SapxepQHTT(KieuSinhVien s[],int left,int right)
{
    int    i, j;
    KieuSinhVien temp;
    temp = s[(left+right)/2];     
    i = left;    
    j = right;
    do{
        while (SosanhTen(temp.hoten, s[i].hoten)==1) i++;   
        while (SosanhTen(temp.hoten, s[j].hoten)==-1) j--;    
        if ( i <= j)      
        {
            Hoanvi(s[i], s[j]);
            i++;        
            j--;        
        }
    } while (i<j);
    if (left < j)    
        SapxepQHTT(s, left, j);
    if (right > i)    
        SapxepQHTT(s, i, right);
}
void SapxepQHTG(KieuSinhVien s[],int left,int right)
{
    int    i, j;
    KieuSinhVien temp;
    temp = s[(left+right)/2];     
    i = left;    
    j = right;
    do{
        while (SosanhTen(temp.hoten, s[i].hoten)==-1) i++;   
        while (SosanhTen(temp.hoten, s[j].hoten)==1) j--;    
        if ( i <= j)      
        {
            Hoanvi(s[i], s[j]);
            i++;        
            j--;        
        }
    } while (i<j);
    if (left < j)    
        SapxepQHTG(s, left, j);
    if (right > i)    
        SapxepQHTG(s, i, right);
}
void SapxepQNSG(KieuSinhVien s[], int left, int right)
{
	int a[Sosinhvien];
	XetNamSinh(a, s, right);
	int    i, j;
	int temp;
	temp = a[(left + right) / 2];
	i = left;
	j = right;
	do {
		while (temp > a[i])
		{
			i++;
		}
		while (temp < a[j])
		{
			j--;
		}
		if (i <= j)
		{
			Hoanvi1(a[i], a[j]);
			Hoanvi(s[i], s[j]);
			i++;
			j--;
		}
	} while (i<j);
	if (left < j)
		SapxepQNSG(s, left, j);
	if (right > i)
		SapxepQNSG(s, i, right);
}
void SapxepQNST(KieuSinhVien s[], int left, int right)
{
	int a[Sosinhvien];
	XetNamSinh(a, s, right);
	int    i, j;
	int temp;
	temp = a[(left + right) / 2];
	i = left;
	j = right;
	do {
		while (temp < a[i])
		{
			i++;
		}
		while (temp > a[j])
		{
			j--;
		}
		if (i <= j)
		{
			Hoanvi1(a[i], a[j]);
			Hoanvi(s[i], s[j]);
			i++;
			j--;
		}
	} while (i<j);
	if (left < j)
		SapxepQNST(s, left, j);
	if (right > i)
		SapxepQNST(s, i, right);
}
//........................TIM KIEM TUAN TU.......................
void TKTTMasv(char x[], KieuSinhVien a[],int n,char dem[],int &l){
	l=0;
for(int i=1;i<=n;i++)
{
	int k=0,o=0;
	while(k<=strlen(x)-1 && int(a[i].masv[o])==int(x[k]) && o<strlen(a[i].masv)-1)
	{
		if(k==strlen(x)-1)
		{
			dem[l]=i;
			l++;
		}
		k++;
		o++;
	}
}
}
void TKTTMalop(char x[], KieuSinhVien a[],int n,char dem[],int &l){
	l=0;
for(int i=1;i<=n;i++)
{
	int k=0,o=0;
	while(k<=strlen(x)-1 && int(a[i].malop[o])==int(x[k]) && o<strlen(a[i].malop)-1)
	{
		if(k==strlen(x)-1)
		{
			dem[l]=i;
			l++;
		}
		k++;
		o++;
	}
}
}
void TKTTDiem(char x[], KieuSinhVien a[],int n,char dem[],int &l){
int k=0,o;l=0;
for(int i=1;i<=n;i++)
{
	for(int u=0;u<strlen(a[i].diemc);u++)
	{
		int k=0;o=u;
			while(k<=strlen(x)-1 && int(a[i].diemc[o])==int(x[k]) && o<strlen(a[i].diemc)-1)
			{
				if(k==strlen(x)-1)
				{
					dem[l]=i;
					l++;
				}
				k++;
				o++;
			}
		if(dem[l-1]==i) break;
	}
}
}
void TKTTNS(char x[], KieuSinhVien a[],int n,char dem[],int &l){
l=0;
for(int i=1;i<=n;i++)
{
	int k=2,o=0;
	while(k<=strlen(x)-1 && int(a[i].nsc.ngay[o])==int(x[k]) && o<strlen(a[i].nsc.ngay)-1)
	{
		if(k==strlen(x)-1)
		{
			dem[l]=i;
			l++;
		}
		k++;
		o++;
	}
}
}
void TKTTTS(char x[], KieuSinhVien a[],int n,char dem[],int &l){
l=0;
for(int i=1;i<=n;i++)
{
	int k=2,o=0;
	while(k<=strlen(x)-1 && int(a[i].nsc.thang[o])==int(x[k]) && o<strlen(a[i].nsc.thang)-1)
	{
		if(k==strlen(x)-1)
		{
			dem[l]=i;
			l++;
		}
		k++;
		o++;
	}
}
}
void TKTTN(char x[], KieuSinhVien a[],int n,char dem[],int &l){
l=0;
for(int i=1;i<=n;i++)
{
	int k=2,o=0;
	while(k<=strlen(x)-1 && int(a[i].nsc.nam[o])==int(x[k]) && o<strlen(a[i].nsc.nam)-1)
	{
		if(k==strlen(x)-1)
		{
			dem[l]=i;
			l++;
		}
		k++;
		o++;
	}
}
}
void TKTTHT(char x[], KieuSinhVien a[],int n,char dem[],int &l){
	KieuSinhVien temp[Sosinhvien];
	strlwr(x);
	int k=0,o;l=0;
	for(int i=1;i<=n;i++)
	{
		temp[i]=a[i];
		strlwr(temp[i].hoten);
		for(int u=0;u<strlen(temp[i].hoten);u++)
		{
			int k=0;o=u;
				while(k<=strlen(x)-1 && int(temp[i].hoten[o])==int(x[k])&& o<strlen(temp[i].hoten)-1)
				{
					if(k==strlen(x)-1)
					{
						dem[l]=i;
						l++;
					}
					k++;
					o++;
				}
			if(dem[l-1]==i) break;
		}
	}
}
//......................TIM KIEM NHI PHAN.................................//
void TKNPDT(char x[],KieuSinhVien s[], int n,char dem[], int &deml)
 { 
  	int left = 1;
  	int right = n,mid;
  	deml=0;
  	while (left <= right) {
  		mid = (left + right) / 2;
		if(SosanhD(x , s[mid].diemc)==-1)
		{
 			right = mid - 1;
		}
 		else if(SosanhD(x , s[mid].diemc)==1) 
		{
 			left = mid + 1;
		}
		else if(SosanhD(x,s[mid].diemc)==0) 
		{
			for(int i=mid;i>=left;i--)
			{
				if(strcmp(s[i].diemc , s[mid].diemc)==0)
				{
					dem[deml]=i;
					deml++;
				}
				else break;
			}
			for(int i=mid+1;i<=right;i++)
			{
				if(strcmp(s[i].diemc , s[mid].diemc)==0)
				{
					dem[deml]=i;
					deml++;
				}
				else break;
			}
			break;
		}
 	} 
}
void TKNPDG(char x[],KieuSinhVien s[], int n,char dem[], int &deml)
 { 
  	int left = 1;
  	int right = n,mid;
  	deml=0;
  	while (left <= right) {
  		mid = (left + right) / 2;
		if(SosanhD(x , s[mid].diemc)==1)
		{
 			right = mid - 1;
		}
 		else if(SosanhD(x , s[mid].diemc)==-1) 
		{
 			left = mid + 1;
		}
		else if(SosanhD(x,s[mid].diemc)==0) 
		{
			for(int i=mid;i>=left;i--)
			{
				if(SosanhD(x , s[i].diemc)==0)
				{
					dem[deml]=i;
					deml++;
				}
				else break;
			}
			for(int i=mid+1;i<=right;i++)
			{
				if(SosanhD(x , s[i].diemc)==0)
				{
					dem[deml]=i;
					deml++;
				}
				else break;
			}
			break;
		}
 	} 
}
void TKNPMSVT(char x[],KieuSinhVien s[], int n,char dem[], int &deml)
 {
  int left = 1;
  	int right = n,mid;
  	deml=0;
  	while (left <= right) {
  		mid = (left + right) / 2;
		if(SosanhD(x , s[mid].masv)==-1)
		{
 			right = mid - 1;
		}
 		else if(SosanhD(x , s[mid].masv)==1) 
		{
 			left = mid + 1;
		}
		else if(SosanhD(x,s[mid].masv)==0) 
		{
			for(int i=mid;i>=left;i--)
			{
				if(SosanhD(x,s[i].masv)==0)
				{
					dem[deml]=i;
					deml++;
				}
				else break;
			}
			for(int i=mid+1;i<=right;i++)
			{
				if(SosanhD(x,s[i].masv)==0)
				{
					dem[deml]=i;
					deml++;
				}
				else break;
			}
			break;
		}
 	}
}
void TKNPMSVG(char x[],KieuSinhVien s[], int n,char dem[], int &deml)
 {
  	int left = 1;
  	int right = n,mid;
  	deml=0;
  	while (left <= right) {
  		mid = (left + right) / 2;
		if(SosanhD(x , s[mid].masv)==1)
		{
 			right = mid - 1;
		}
 		else if(SosanhD(x , s[mid].masv)==-1) 
		{
 			left = mid + 1;
		}
		else if(SosanhD(x,s[mid].masv)==0) 
		{
			for(int i=mid;i>=left;i--)
			{
				if(SosanhD(x,s[i].masv)==0)
				{
					dem[deml]=i;
					deml++;
				}
				else break;
			}
			for(int i=mid+1;i<=right;i++)
			{
				if(SosanhD(x,s[i].masv)==0)
				{
					dem[deml]=i;
					deml++;
				}
				else break;
			}
			break;
		}
 	}
}
void TKNPMLG(char x[],KieuSinhVien s[], int n,char dem[], int &deml)
 {
  	int left = 1;
  	int right = n,mid;
  	deml=0;
  	while (left <= right) {
  		mid = (left + right) / 2;
		if(SosanhD(x , s[mid].malop)==1)
		{
 			right = mid - 1;
		}
 		else if(SosanhD(x , s[mid].malop)==-1) 
		{
 			left = mid + 1;
		}
		else if(SosanhD(x,s[mid].malop)==0) 
		{
			for(int i=mid;i>=left;i--)
			{
				if(SosanhD(x,s[i].malop)==0)
				{
					dem[deml]=i;
					deml++;
				}
				else break;
			}
			for(int i=mid+1;i<=right;i++)
			{
				if(SosanhD(x,s[i].malop)==0)
				{
					dem[deml]=i;
					deml++;
				}
				else break;
			}
			break;
		}
 	}
}
void TKNPMLT(char x[],KieuSinhVien s[], int n,char dem[], int &deml)
 {
  	int left = 1;
  	int right = n,mid;
  	deml=0;
  	while (left <= right) {
  		mid = (left + right) / 2;
		if(SosanhD(x , s[mid].malop)==-1)
		{
 			right = mid - 1;
		}
 		else if(SosanhD(x , s[mid].malop)==1) 
		{
 			left = mid + 1;
		}
		else if(SosanhD(x,s[mid].malop)==0) 
		{
			for(int i=mid;i>=left;i--)
			{
				if(SosanhD(x,s[i].malop)==0)
				{
					dem[deml]=i;
					deml++;
				}
				else break;
			}
			for(int i=mid+1;i<=right;i++)
			{
				if(SosanhD(x,s[i].malop)==0)
				{
					dem[deml]=i;
					deml++;
				}
				else break;
			}
			break;
		}
 	}
}
void TKNPHTT(char x[],KieuSinhVien s[], int n,char dem[], int &deml)
 {
	 KieuSinhVien temp[Sosinhvien];
	 strlwr(x);
  		int left = 1;
  	int right = n,mid;
  	deml=0;
  	while (left <= right) {
  		mid = (left + right) / 2;
		temp[mid]=s[mid];
		strlwr(temp[mid].hoten);
		if(SosanhTen1(x , temp[mid].hoten)==-1)
		{
 			right = mid - 1;
		}
 		else if(SosanhTen1(x , temp[mid].hoten)==1) 
		{
 			left = mid + 1;
		}
		else if(SosanhTen1(x,temp[mid].hoten)==0) 
		{
			for(int i=mid;i>=left;i--)
			{
				temp[i]=s[i];
				strlwr(temp[i].hoten);
				if(SosanhTen1(x,temp[i].hoten)==0)
				{
					dem[deml]=i;
					deml++;
				}
				else break;
			}
			for(int i=mid+1;i<=right;i++)
			{
				temp[i]=s[i];
				strlwr(temp[i].hoten);
				if(SosanhTen1(x,temp[i].hoten)==0)
				{
					dem[deml]=i;
					deml++;
				}
				else break;
			}
			break;
		}
 	}
}
void TKNPHTG(char x[],KieuSinhVien s[], int n,char dem[], int &deml)
 {
	 KieuSinhVien temp[Sosinhvien];
	 strlwr(x);
  		int left = 1;
  	int right = n,mid;
  	deml=0;
  	while (left <= right) {
  		mid = (left + right) / 2;
		temp[mid]=s[mid];
		strlwr(temp[mid].hoten);
		if(SosanhTen1(x , temp[mid].hoten)==1)
		{
 			right = mid - 1;
		}
 		else if(SosanhTen1(x , temp[mid].hoten)==-1) 
		{
 			left = mid + 1;
		}
		else if(SosanhTen1(x,temp[mid].hoten)==0) 
		{
			for(int i=mid;i>=left;i--)
			{
				temp[i]=s[i];
				strlwr(temp[i].hoten);
				if(SosanhTen1(x,temp[i].hoten)==0)
				{
					dem[deml]=i;
					deml++;
				}
				else break;
			}
			for(int i=mid+1;i<=right;i++)
			{
				temp[i]=s[i];
				strlwr(temp[i].hoten);
				if(SosanhTen1(x,temp[i].hoten)==0)
				{
					dem[deml]=i;
					deml++;
				}
				else break;
			}
			break;
		}
 	}
}
void TKNPNST(char x[],KieuSinhVien s[], int n,char dem[], int &deml)
 {
  	int left = 1;
  	int right = n,mid;
  	deml=0;
  	while (left <= right) {
  		mid = (left + right) / 2;
		if(SosanhD(x , s[mid].nsc.nam)==-1)
		{
 			right = mid - 1;
		}
 		else if(SosanhD(x , s[mid].nsc.nam)==1) 
		{
 			left = mid + 1;
		}
		else if(SosanhD(x,s[mid].nsc.nam)==0) 
		{
			for(int i=mid;i>=left;i--)
			{
				if(SosanhD(x,s[i].nsc.nam)==0)
				{
					dem[deml]=i;
					deml++;
				}
				else break;
			}
			for(int i=mid+1;i<=right;i++)
			{
				if(SosanhD(x,s[i].nsc.nam)==0)
				{
					dem[deml]=i;
					deml++;
				}
				else break;
			}
			break;
		}
 	}
}
void TKNPNSG(char x[],KieuSinhVien s[], int n,char dem[], int &deml)
 {
  	int left = 1;
  	int right = n,mid;
  	deml=0;
  	while (left <= right) {
  		mid = (left + right) / 2;
		if(SosanhD(x , s[mid].nsc.nam)==1)
		{
 			right = mid - 1;
		}
 		else if(SosanhD(x , s[mid].nsc.nam)==-1) 
		{
 			left = mid + 1;
		}
		else if(SosanhD(x,s[mid].nsc.nam)==0) 
		{
			for(int i=mid;i>=left;i--)
			{
				if(SosanhD(x,s[i].nsc.nam)==0)
				{
					dem[deml]=i;
					deml++;
				}
				else break;
			}
			for(int i=mid+1;i<=right;i++)
			{
				if(SosanhD(x,s[i].nsc.nam)==0)
				{
					dem[deml]=i;
					deml++;
				}
				else break;
			}
			break;
		}
 	}
}
//....................................XU LY THONG KE..............................
void Thongke(KieuSinhVien s[],char *dem,int &l,int a,int demsosv)
{
	l=0;
	SapxepCMLT(s,demsosv);
	for(int i=a;i<=demsosv;i++)
	{
		if(strcmp(s[i].malop,s[i+1].malop)==0)
		{
			*(dem+l)=i;
			l++;
		}
		else
		{
			*(dem+l)=i;
			l++;
			break;
		}
	}
}
