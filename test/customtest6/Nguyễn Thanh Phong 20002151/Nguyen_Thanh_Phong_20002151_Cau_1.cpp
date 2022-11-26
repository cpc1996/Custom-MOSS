#include <stdio.h>
#include <math.h>
int main()
{
	float x1, x2, y1, y2;
	printf(" Moi ban nhap toa do diem A \n");
	printf("x1 = ");
	scanf("%f", &x1);
    printf("y1 = ");
	scanf("%f", &y1);
    printf(" Moi ban nhap toa do diem B \n");
	printf("x2 = ");
	scanf("%f", &x2);
    printf("y2 = ");
	scanf("%f", &y2);
    float D;
    D = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    printf("\n Do dai doan thang AB la %.2f", D);
    return 0;
}
