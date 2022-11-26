#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i;
	int *a;
	printf("nhap n phan tu= ");
	scanf("%d",&n);
	a = (int *)calloc(n, sizeof(int));
	printf("nhap mang\n");
	for(i=0; i<n; i++)
	{
		printf("a[%d]= ",i);
		scanf("%d",(a+i));
	}
	printf("xuat mang\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t",*(a+i));
	}
	//dao nguoc mang.
	int temp;
	for(i=0; i<=n/2; i++)
	{
		temp=*(a+n-i-1);
		*(a+n-i-1)=*(a+i);
		*(a+i)=temp;
	}
	printf("\nmang sau khi dao nguoc\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t",*(a+i));
	}
	free(a);
	return 0;
}
