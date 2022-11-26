#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
	char a[100]; 
	int i,j,vt,luui,k;
	
	puts("Moi ban nhap vao chuoi:");	gets(a);
	puts("Vi tri tu duoc chon:");		scanf("%d",&vt);
	
	while (a[0]==' ')
		for (i=0;i<strlen(a);i++)
			a[i]=a[i+1];
			
	while (a[strlen(a)-1]==' ')
		a[strlen(a)-1]='\0';
			
	i=0;k=0;
	while (a[i]!='\0')
	{
		if ( !( (a[i] == ' ') && (a[i+1] == ' ') ) )
		{
			a[k]=a[i];
			k++;
		}
		i++;
	}
	a[k]='\0';
	
	int dem=0;i=0;
	while (dem<vt-1)
	{
		if (a[i]==' ') dem++;
		i++;
	}
	
	luui=i;
	
	while(a[i]!=' ')
	{
		a[i]=toupper(a[i]);
		i++;
	}
	puts("\nChuoi moi sau khi in hoa :");
	printf("|%s|",a);
	
/*	char *x,b;
	x=(char*)malloc(sizeof(char));
	puts("Nhap vao chuoi ");
	i=0;
	while ((b=getchar())!='\n');
	{
		*(x+i)=b;
		i++;
		x=(char*)realloc(x,i+1);
	}
	x[i]="\0";*/
}
