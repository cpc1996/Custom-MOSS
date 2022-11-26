#include<stdio.h>
#include<math.h>

main()
{
	float x;
	float y;
	float n1,n2;
	float i;
	
	printf("\nNhap vao 2 nut: ");
	scanf("%f%f",&n1,&n2);
	printf("x\tsin(x)");
	for(i=n1;i<=n2;i=i+0.01)
	{
		x=i;
		y=sin(i);
		printf("%.3f\t%.3f",i,y);
		printf("\n");
	}
	
	FILE *fptr;
	fptr = fopen("data.txt","w");
	printf("x\tsin(x)");
	for(i=n1;i<=n2;i=i+0.01)
	{
		x=i;
		y=sin(i);
		printf(fptr,"%.3f\t%.3f",i,y);
		printf("\n");
	}

	fclose(fptr);

}

