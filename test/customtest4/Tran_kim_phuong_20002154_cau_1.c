#include<stdio.h>

int main()
{
	float x,y,a,b;
	printf ( " nhap x :\n ");
	scanf ("%f",&x);
	a=x*x;
	b=x+1;
	y = (x>0)? a : b;
	printf("gia tri cua ham f(x) là %f :\n",y);	 
}
