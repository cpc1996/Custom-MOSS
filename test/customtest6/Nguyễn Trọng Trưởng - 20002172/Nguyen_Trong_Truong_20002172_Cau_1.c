#include<stdio.h>
int main()
{
	int n;
	printf("\nNhap n ( n < 10 ) :  ");
	do
	{
		scanf("%d",&n);
	}while( n < 0 || n >= 10);
	float Tong = 0;
	int i;
	int k = 1;
	for( i = 1; i <= n; i++)
	{
		k = k * i;
		Tong += k;
	}
	printf("\nTong cua 1! + 2! + 3! + ... + n! :  %.3f",Tong);
 return 0;
 }
