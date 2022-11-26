#include<stdio.h>
#include<string.h>
main()
{
	char x[100],a;
	int i, count;
	puts("Nhap vao xau ky tu:");
	gets(x);
	printf("Xau ky tu la: |%s|\n",x);
		for (i=0;i<strlen(x);i++)
	{
		x[i]= toupper(x[i]);
	}
	
	puts("\nChuoi sau khi chuyen thanh chu HOA la:");
	puts(x);
}
