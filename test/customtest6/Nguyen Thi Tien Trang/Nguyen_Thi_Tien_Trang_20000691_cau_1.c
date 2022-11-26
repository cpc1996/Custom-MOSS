#include<stdio.h>
int main()
{ 
	int n;
	float S;
	printf(" Nhap gia tri n:");
	scanf("%d",&n);
	float i=0;
	S=0;
	for(i=1;i<=n;i++)
	S=S+1/i;
	printf(" tong = %f", S);
} 
