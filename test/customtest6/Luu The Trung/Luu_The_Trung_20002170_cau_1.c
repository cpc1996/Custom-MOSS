#include<stdio.h>

int main() {
	float x, y;
	printf("Moi nhap x:\n");
	scanf("%f", &x);
	y = (x>0) ? (x*x) : (x+1);
	printf("%.4f", y);
}
