#include<stdio.h>
#include<math.h>
int main (){
    float AC,AB,BC,AH;
	printf("Nhap AC: ");
	scanf("%f",&AC);
	printf("\nNhap AB: ");
	scanf("%f",&AB);
	AH = (AC*AB)/(sqrt(AC*AC + AB*AB));
	printf("Gia tri cua AH la: %.3f ",AH);
	BC = (AB*AC)/AH;
	printf("\nGia tri cua BC la: %.3f", BC);
	return 0;
}
