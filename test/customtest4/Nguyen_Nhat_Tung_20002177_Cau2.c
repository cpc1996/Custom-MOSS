#include<math.h>
#include<stdio.h>
#include<stdlib.h>
main()
{
	int i,j,max,min;
	int M,N,a[50][50];
	printf("Nhap hai so nguyen duong M va N: \n");
	scanf("%d%d",&M,&N);
	
	printf("Nhap cac phan tu cua ma tran M hang N cot:\n");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	
	max=a[0][0]; min=a[0][0];
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			if(max<=a[i][j])
			{
				max=a[i][j];
			}
		}
	}
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			if(a[i][j]=max)
			{
				return i;
				return j;
			}
		}
	}
	printf("phan tu lon nhat la:%d \n",max);
	printf("vi tri cua phan tu la a[%d][%d]\n",i,j);
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			if(min>a[i][j])
			{
				min=a[i][j];
			}
		}
	}
	printf("phan tu nho nhat la:%d ",min);
	printf("Vi tri phan tu nho nhat la a[%d][%d]:");
}
