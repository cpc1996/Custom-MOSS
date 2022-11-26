#include <stdio.h>
#include <math.h>
int main(){
	float x1,y1;
	float x2,y2;
	float AB;
	printf(" nhap toa do diem A(x1,y1): ");
	scanf("%f %f", &x1,&y1);
	printf(" nhap toa do diem B(x2,y2): ");
	scanf("%f %f", &x2,&y2);
	
	
	AB= sqrt(pow(x2-x1,2) + pow(y2-y1,2));
	printf (" do dai doan thang AB = %.2f",AB);
}
