//Le_Sy_Van_20002178_Cau_1
#include <stdio.h>
#include <math.h>
float Rad( float *a)
{
	float s;
	s=(*a*M_PI)/180;
	return (s);
}
main()
{
	float x;
	printf("moi ban nhap do x=");
	scanf("%f",&x);
	printf("do radian la %f*pi = %.2f",Rad(&x)/M_PI,Rad(&x));
}
