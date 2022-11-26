#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void space(char *a)
{
	int i=0,j=0,n,k;
	n=strlen(a);
	for(i=0;i<n;i++)
	{
		if(a[i]==' ')
		{
		j=i+1;	
			while(a[i]==a[j])
			{
				
				for(k=i;k<n;k++)
				{
					a[k]=a[k+1];
				}
				n--;
				
			}
		}
	}
	if(a[0]==' ')
	{
		for(k=0;k<n;k++)
		{
			a[k]=a[k+1];
		}
		n--;
	}
/*	if(a[strlen(a)+1]=' ')
	{
		a[strlen(a)+1]='\0';
	}*/	
}
void XOA(char *a, int n)
{
	int v=strlen(a)+1;
	a[v]=' ';
	int s=1,i,j,k;
	for(i=0;i<v;i++)
	{
		if(s==n)
		{
			j=i;
			while(a[j]!=' ')
			{
				for(k=j;k<v;k++)
				{
					a[k]=a[k+1];						
				}
			}
		}
		if(a[i]==' ')
		{
			s++;
		}
		
	}
}
void HOA(char *a, int n)
{
	int v=strlen(a);
	a[v+1]=' ';
	int s=1,i,j;
	for(i=0;i<v;i++)
	{
		if(s==n)
		{
			j=i;
			while(a[j]!=' ')
			{
				a[j] = toupper(a[j]);
				j++;
			}
		}
		if(a[i]==' ')
		{
			s++;
		}
		
	}
}
main()
{
	char a[100];
	gets(a);
	space(a);
	puts(a);
	int n,i,s,j,k;
	printf("\nmoi nhap tu so:");
	scanf("%d%*c",&n);
	HOA(a,n);
	puts(a);
	printf("\nmoi nhap tu can xoa:");
	scanf("%d%*c",&s);
	XOA(a,s);
	space(a);
	printf("\n");
	puts(a);
}

















