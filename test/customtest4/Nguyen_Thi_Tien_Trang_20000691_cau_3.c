#include<stdio.h>
float f(float a);
int main()
{	
	float a,b;
	int n;
	printf("a=");
	scanf("%f",&a);
	printf("b=");
	scanf("%f",&b);
	printf("n=");
	printf("a^2=%f",f(a));
	return 0;
}
float f(float a)
{
	return a*a;
}
