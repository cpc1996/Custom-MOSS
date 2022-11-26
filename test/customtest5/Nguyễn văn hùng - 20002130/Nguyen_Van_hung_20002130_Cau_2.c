#include <stdio.h>
#include <math.h>
#include <stdlib.h>

main()
{
	float i=1, ms=1, ps=0;
	while(fabs(4/ms)>0.00001)  //fabs la tri tuyet doi 
	{
		ps = ps + (4*i)/ms;
		i = i*(-1);
	    ms = ms+2;	
	}
	printf("gia tri cua pi = %f", ps);
	printf("\ngia tri cua hang so M_PI=%f", M_PI);
}

