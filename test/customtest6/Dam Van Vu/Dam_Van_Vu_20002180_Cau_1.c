#include<stdio.h>
#include<math.h>

int main() {
	float x1, y1, x2, y2, a;
//nhapToaDoDiem	
	printf("Nhap tao do diem A:");
	scanf("%f%f", &x1, &x2);	
	printf("Nhap tao do diem B:");
	scanf("%f%f", &y1, &y2);
//xuLyBaiToan
	a = sqrt((x1-y1)*(x2-y2)+(x2-y2)*(x2-y2));
	printf("Do dai doan thang AB = %0.2f", a);	
}
