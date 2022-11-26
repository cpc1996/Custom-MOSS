#include <stdio.h>
#include <math.h>

typedef struct
{
	float x1;
	float x2;
	float y1;
	float y2;
}toado;

main()
{
	toado A, B;
	float d;
	
	printf("Nhap toa do diem A:\n");
	scanf("%f", &A.x1);
	scanf("%f", &A.y1);
	printf("Nhap toa do diem B:\n");
	scanf("%f", &B.x2);
	scanf("%f", &B.y2);
	
	d=sqrt((A.x1-B.x2)*(A.x1-B.x2) + (A.y1-B.y2)*(A.y1-B.y2));
	printf("Do dai doan thang AB = %.2f \n", d);
}

