/*
*/
#include<stdio.h>
#include<stdlib.h>
/*void DaoMang(int *a,int N);
void XuatMang(int *a,int N);*/
int main()
{
	int N;
	printf("nhap N = ");
	scanf("%d",&N);
	int *a;
	a=(int*)malloc(N*sizeof(int));
	if(a==NULL)
	{
		printf("ko the cap phat bo nho:");
		exit(0);
	}
	int i;
	printf("nhap mang a:\n");
	for(i=0;i<N;i++)
	{
		printf("nhap a[%d] = ",i);
		scanf("%d",a+i);
	}
	printf("dao mang a:\n");
	for(i=0;i<N/2;i++)
	{
		int t=*(a+i);
		*(a+i)=*(a+N-i-1);
		*(a+N-i-1)=t;
	}
	for(i=0;i<N;i++){
		printf("%d  ",*(a+i));
	}

/*	//dao mang
	printf("dao mang a:\n");
	DaoMang(a+i,N);
	XuatMang(a+i,N);*/
}

/*void DaoMang(int *a,int N)
	{
		int i;
	   	for(i=0;i<N/2;i++)
		{
			int t = *(a+i);
			*(a+i)= *(a+N-i-1);
			*(a+N-i-1) = t;
   		}
	}

void XuatMang(int *a, int N)
	{
		int i;
		for(i=0;i<N;i++)
		{
			printf("%d  ",*(a+i));
		}
	}
*/


