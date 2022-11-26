#include<stdio.h>
main()
{
	int A,sodngA,th;
	printf("nhap vao so A\n");
	scanf("%d",&A);
	sodngA=0;
	while(A>0)
	{
		th= A % 10;
		A=A/10;
		sodngA=sodngA*10 +th;
	}
	printf("%d",sodngA);
}		
