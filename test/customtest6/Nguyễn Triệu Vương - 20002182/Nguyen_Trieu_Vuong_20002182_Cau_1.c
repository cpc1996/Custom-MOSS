#include <stdio.h>
#include <math.h>
typedef struct{
	float x;
	float y;
}toado ;
int main(){
	toado A, B ;
	float d;
// a)
	printf(" Nhap vao toa do cua A: \n");
	scanf("%f", &A.x);
	scanf("%f", &A.y);
	printf(" Nhap vao toa do cua B: \n");
	scanf("%f", &B.x);
	scanf("%f", &B.y);
// In ra toa do
	printf("Toa do diem A la: A(%.2f,%.2f)", A.x, A.y);
	printf("Toa do diem A la: B(%.2f,%.2f)", B.x, B.y);
// b)
	d=sqrt ((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
	printf("\nKhoang cach cua AB la: %.2f\n", d);	
}
