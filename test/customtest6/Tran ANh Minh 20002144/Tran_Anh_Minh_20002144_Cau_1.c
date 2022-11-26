#include<stdio.h>
#include<math.h>
int main(){
	float x1, y1, x2, y2;
	printf("Nhap x1: ");
	scanf("%f", &x1);
	printf("Nhap y1: ");
	scanf("%f", &y1);
	printf("Nhap x2: ");
	scanf("%f", &x2);
	printf("Nhap y2: ");
	scanf("%f", &y2);
	
	float kc;
	kc = sqrt((x2-x1) * (x2-x1) + (y2-y1)*(y2-y1));
	printf("Khoang cach 2 diem AB la: %.2f", kc);
	
}
