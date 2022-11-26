#include<stdio.h>
#include<stdlib.h>
main()
{
	int *b,M,N,i,j,min,max,k=1,t=1,p=1,q=1;
	printf("nhap so hang M: ");
	scanf("%d",&M);
	printf("nhap so cot N: ");
	scanf("%d",&N);
	b=(int*)malloc(M*N*sizeof(int));
	if(b==NULL)
	{
		printf("khong cap phat duoc bo nho");
		exit(0);
	}
	else
	{
		for(i=1;i<=M;i++)
		for(j=1;j<=N;j++)
		scanf("%d",b+i*N+j);
		min=*(b+N+1);
		max=*(b+N+1);
			for(i=1;i<=M;i++)
		for(j=1;j<=N;j++)
		{
			if(min>*(b+i*N+j))
			{
				min=*(b+i*N+j);
				p=i;
				q=j;

			}
			if(max<*(b+i*N+j))
			{
				max=*(b+i*N+j);
				k=i;
				t=j;
			}
		}
		printf("phan tu lon nhat co vi tri [%d][%d]: %d",k,t,max);
		printf("\nphan tu nho nhat co vi tri [%d][%d]: %d",p,q,min);
	}
}
