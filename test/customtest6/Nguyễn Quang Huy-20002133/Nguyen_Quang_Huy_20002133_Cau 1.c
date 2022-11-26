#include<stdio.h>

main()
{
	int N;
    int i;
    do
    {
    	printf("Nhap N: ");
        scanf("%d",&N);
    }
	while(N>=1);
    for( i=1;i<=N;i++)
    {
        if(i%2==0)
        {
            printf("%d ",i);
        }
    }
    return 0;
}
