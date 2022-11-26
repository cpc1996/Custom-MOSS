#include<stdio.h>
#include<math.h>
#define Pi 3.14



float radian(float x){
	return x*Pi/180;
}

main(){
	float x;
	float y;
	
	printf("\nNhap so do goc x(Do): ");
	scanf("%f",&x);
	
	y=x;
	
	x=radian(x);
	printf("ket qua: %.2f do = %.2f radian",y,x);
}
