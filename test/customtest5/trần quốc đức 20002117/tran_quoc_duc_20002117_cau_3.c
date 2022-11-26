#include <stdio.h>
#include <string.h>
void Xoa(char x[],int vt)
{
	int i=0;
	int cd=strlen(x);
	for(i=vt-1;i<cd;i++)
	{
		x[vt]=x[vt+1];
	}
}
int main()
{
	char x[100];
	int i,j;
	puts("Nhap xau ky tu :");
	gets(x);
	int cd=strlen(x);
	for(i=0;i<cd;i++)
	{
			if((x[i]==' ')&&(x[i+1]==' '))
			{
				for(j=i;j<cd;j++)
			    {
				x[j]=x[j+1];
				}
				cd--;
				i--;
			}
	}
	printf("Xau sau khi chuan hoa:");
	for(i=0;i<cd;i++)
	{
		printf("%c",x[i]);
	}
	printf("\nXau chuan hoa thanh chu in hoa:");
	for(i=0;i<cd;i++)
	{
		printf("%c",toupper(x[i]));
	}
	printf("\nXau sau khi xoa:");
	Xoa(x,2);
	for(i=0;i<cd;i++)
	{
		printf("%c",x[i]);
	}
}
