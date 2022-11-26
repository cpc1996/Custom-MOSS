#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int NT(int *a)
{
	int count = 0;
	int i;
	if(*a < 2)
	{
      	count=0;
        return 0;
    }
    for(i = 2; i <= sqrt(*a); i++)
	{
        if(*a % i == 0)
		{
            count=1;
            break;
        }
    }
	return(count);
}
main()
{
	int n1,n2,i;
	printf("moi nhap n1,n2=");
	scanf("%d %d",&n1,&n2);
	for(i=n1;i<=n2;i++)
	{
		if(NT(&i)==1)
		{
			printf("%d",i);
		}
	}
}
