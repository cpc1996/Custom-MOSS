#include<stdio.h>
const float PI=3.14;
int main()
{
	float X,Y;
	printf("Nhap goc X:"); 
	scanf("%f",&X);
	Y=(X/180)*PI;
	printf("Goc X doi ra radian la:%.2f",Y);
	return 0;
}
