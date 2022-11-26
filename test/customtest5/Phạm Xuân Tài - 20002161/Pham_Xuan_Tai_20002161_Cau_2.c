#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

main()
{
    int a[50][50];
    int i,j,n,m,p,q,max,min;

    printf("Nhap so hang so cot ma tran a: ");
    scanf("%d %d",&m,&n);

    for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++) 
		{
			printf("a[%d][%d]:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("ma tran a :\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
        	printf(" %3d ",a[i][j]);
		}
			printf("\n");
	}

    max=a[0][0];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++) 
		{
			if(max<a[i][j])
            {
                max=a[i][j];
            }
		}
	}

    for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++) 
		{
			if(max==a[i][j])
            {
                max=a[i][j];
                p=i;
                q=j;
                printf("\ncuc dai cua ma tran o hang %d cot %d la:%d",p,q,max);

            }
		}
	}
    min=a[0][0];
    for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++) 
		{
			if(min>a[i][j])
            {
                min=a[i][j];
            }
		}
	}

    for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++) 
		{
			if(min==a[i][j])
            {
                min=a[i][j];
                p=i;
                q=j;
                printf("\ncuc tieu cua ma tran o hang %d cot %d la:%d",p,q,min);

            }
		}
	}

    return(0);
}