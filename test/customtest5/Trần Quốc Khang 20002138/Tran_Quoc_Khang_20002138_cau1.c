#include<stdio.h>
int main()
{
	int n;
	printf("\nMoi nhap mot so nguyen duong nho hon 10 :  ");
	do
	{
		scanf("%d",&n);
	}while( n < 0 || n >= 10);
	float tong = 0;
	int k = 1;
	int i;
	for( i = 1; i <= n; i++)
	{
		k = k * i;
		tong += k;
	}
	printf("\nTong cua 1! + 2! + 3! + ... + n! :  %.3f",tong);
 return 0;
 }
