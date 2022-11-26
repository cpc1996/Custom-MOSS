#include<stdio.h>
#include<math.h>
main()
{
	float x,tong;
	int n;
	printf("nhap n\n");
	scanf("%d",&n);
	printf("nhap vao x\n");
	scanf("%f",&x);
	tong=0;
	tong= tong + x*x*x*x*x*x*x*x*x*x*x*x;
	printf("tong la %.4f\n",tong);
}		
	
