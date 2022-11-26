#include<stdio.h>
main()
{
	int N,a,b,i,j;
	int c[50][50];
	// 1
	printf( " nhap N");
	scanf("%d",&N);
	// 5
	printf("nhap so hang:");
	scanf("%d",&a);
	printf("nhap so cot :");
	scanf("%d",&n);
	int matrix[a][b];
	printf("nhap cac phan tu :\n");
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
    	{ printf("matrix[%d][%d]=",i,j);
		scanf("%d",&matrix[i][j]);
		}
	}
	printf("ma tran a ca dang:\n");
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			printf("%d",matrix[i][j]);
		} 
		printf("\n");   
	}
	return 0;
	}
