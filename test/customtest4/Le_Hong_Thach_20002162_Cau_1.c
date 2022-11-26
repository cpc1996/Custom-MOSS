#include<stdio.h>
#include<math.h>
typedef struct {
	float x;
	float y;
}toado;
main(){
	toado A,B;
	float x;
	printf("nhap A:");
	scanf("%f",&A.x);
	scanf("%f",&A.y);
	printf("nhap B:");
	scanf("%f", &B.x);
	scanf("%f", &B.y);
	x=sqrt((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y));
	printf("do dai AB: %.2f", x);
}
