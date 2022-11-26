#include <stdio.h>

int main() {
	double c;
	printf("Nhap do chinh xac c: ");
	scanf("%lf", &c);
	
	int k = 0;
	double m = 0;
	int cs = -1;
	double tg = 1.0 / (2 * k + 1);
	while(tg >= c) 
	{
		tg = 1.0 / (2 * k + 1);
		m += -1 * cs * tg;
		cs *= -1;
		k++;	
	}
	double PI = 4 * m;
	printf("PI = %0.7lf", PI);
	
	return 0;
}
