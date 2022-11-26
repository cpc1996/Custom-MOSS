#include<stdio.h>
#include<math.h>

main(){
	float AB, AC, BC, AH;
	printf("Nhap AB, AC: "); scanf("%f%f", &AB, &AC);
	
	BC = sqrt(AB*AB + AC*AC);
	printf("\nDo dai BC: %.3f", BC);
	
	AH = sqrt( (AB*AB * AC*AC) / (AB*AB + AC*AC) );
	printf("\nDo dai AH: %.3f", AH);
	return 0;
}

