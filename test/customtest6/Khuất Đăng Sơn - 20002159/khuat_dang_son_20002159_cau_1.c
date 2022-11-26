#include<stdio.h>
int main()
{
	// cau a
	int n;
	printf("\nMoi nhap mot so nguyen duong nho hon 10 :  ");
	do
	{
		scanf("%d",&n);
	}while( n < 0 || n >= 10);
	
	// cau b
	float s = 0;
	int k = 1;
	int i;
	for( i = 1; i <= n; i++)
	{
		k = k * i;
		s = s + k;
	}
	printf("\nTong cua 1! + 2! + 3! + ... + n! :  %.3f",s);
	
 return 0;
 }

