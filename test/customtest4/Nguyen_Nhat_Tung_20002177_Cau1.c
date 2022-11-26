#include<stdio.h>
#include<math.h>
main()
{
	int x1,x2,y1,y2;
	printf("Nhap toa do cua diem A: \n");
	printf("Toa do x1:\n ");
	scanf("%d",&x1);
	printf("Toa do y1:\n ");
	scanf("%d",&y1);

	printf("Nhap toa do cua diem B: \n");
	printf("Toa do x:\n ");
	scanf("%d",&x2);
	printf("Toa do y:\n ");
	scanf("%d",&y2);
	
	float kc;
	kc = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

	printf("Khoang cach giua A va B = %.2f", kc);
	return 0;
}
