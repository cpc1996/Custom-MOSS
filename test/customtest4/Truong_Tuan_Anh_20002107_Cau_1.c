#include<stdio.h>

main()
{
	int N;
	float i;
	float sum=0;
	printf("\nNhap N(N>0): ");
	scanf("%d",&N);	
	for(i=1;i<=N;i++)
	{
		sum=sum+1.0/i;
	}
	printf("Sum=%.3f",sum);
}

