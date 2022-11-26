#include<stdio.h>
#include<math.h>

void tinhsopi( float *s ) {
	
	float i = 1, ms = 1;
	*s = 0;
	while(fabs(4/ms)>0.00001) {
		*s = *s + (4*i)/ms;
		i = i*(-1);
		ms = ms + 2;
	}
}

int main() {
	float sum;
	tinhsopi(&sum);
	printf("Gia tri cua so pi theo cong thuc la: %f\n", sum);
	printf("Gia tri cua so pi theo thu vien la: %f\n", M_PI);
}


