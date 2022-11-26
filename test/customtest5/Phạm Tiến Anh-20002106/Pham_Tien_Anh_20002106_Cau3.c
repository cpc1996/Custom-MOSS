#include<stdio.h>
main()
{
	int N1,N2;
	printf("nhap N1 va N2:");
	scanf("%d%d",&N1,&N2);
	while(N2<N1)
	{
		printf("nhap lai N1 va N2: "); 
		scanf("%d%d",&N1,&N2);
	}
}
