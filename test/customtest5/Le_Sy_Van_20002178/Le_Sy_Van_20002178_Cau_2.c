#include <stdio.h>
#include <stdlib.h>
void inputVAL(int *a, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",(a+i));
	}
}
void RE(int *a, int n)
{
	int i=0,j=n-1,d;
	while(i<=j)
	{
		d=*(a+i);
		*(a+i)=*(a+j);
		*(a+j)=d;
		j--;
		i++;
	}
}
void outputVAL(int *a, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d	",*(a+i));	
	}
}
main()
{
	int *a,n;
	printf("moi ban nhap  so phan tu :");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	inputVAL(a, n);
	RE(a,n);
	printf("\n mang da doi chieu la :");
	outputVAL( a, n);
	
}

