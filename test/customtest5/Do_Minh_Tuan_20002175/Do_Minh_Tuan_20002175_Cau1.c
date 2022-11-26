#include <stdio.h>
#include <math.h>
main() {

	float x1,y1,x2,y2;
	float result;
	//diem A
	printf("nhap toa do diem A: \n");
	printf("x1: ");
	scanf("%f",&x1);
	printf("\ny1: ");
	scanf("%f",&y1);
	
	//diem B
	printf("nhap toa do diem B: \n");
	printf("x2: ");
	scanf("%f",&x2);
	printf("\ny2: ");
	scanf("%f",&y2);
	
	//Tinh do dai doan AB
	result = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	
	//in ket qua
	printf("\n Do dai doan AB : %0.2f",result);
	
}
