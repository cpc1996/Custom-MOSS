#include<stdio.h>
main()
{
	int n,i;
	do
	{
		printf("nhap n:");
		scanf("%d",&n);
	}
	while(n<=1);
	printf("danh sach so chan :");
	for(i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			printf(" %d",i);
		}
	}
}
