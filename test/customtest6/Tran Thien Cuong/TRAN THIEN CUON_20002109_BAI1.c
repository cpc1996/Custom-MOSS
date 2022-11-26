#include <stdio.h>
#include <math.h>
main()
{
	float x,y ;
	printf ("nhap vao x =");
	scanf ("%f",&x);
	y=(x>0)?x*x:x+1;
	printf ("ket qua = %.4f",y);
}
