#include<stdio.h>
#include<stdlib.h>
main()
{
	int *a,m,n,i,j,min,max,k=1,t=1,p=1,q=1;
	printf("nhap so hang: ");
	scanf("%d",&m);
	printf("nhap so cot: ");
	scanf("%d",&n);
	a=(int*)malloc(m*n*sizeof(int));
	if(a==NULL)
	{
		printf("khong cap phat duoc bo nho");
		exit(0);
	}
	else
	{
		for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		scanf("%d",a+i*n+j);
		min=*(a+n+1);
		max=*(a+n+1);
			for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if(min>*(a+i*n+j))
			{
				min=*(a+i*n+j);
				p=i;
				q=j;

			}
			if(max<*(a+i*n+j))
			{
				max=*(a+i*n+j);
				k=i;
				t=j;
			}
		}
		printf("phan tu lon nhat co vi tri [%d][%d]: %d",k,t,max);
		printf("\nphan tu nho nhat co vi tri [%d][%d]: %d",p,q,min);
	}
}

