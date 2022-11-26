#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	typedef struct {
		char name[20];
		int win, draw, lost, point;
	} solieuNHA;
	
	int i;
	solieuNHA x[4];
	FILE *p;
	p = fopen("solieu.txt", "w");
	if(p==NULL) {
		exit(0);
	}
	for(i=0;i<4;i++) {
		printf("Nhap ten doi bong:\n");
		gets(x[i].name);
		printf("Nhap so tran win:\n");
		scanf("%d%*c", &x[i].win);
		printf("Nhap so tran draw:\n");
		scanf("%d", &x[i].draw);
		printf("Nhap so tran lost:\n");
		scanf("%d%*c", &x[i].lost);
		x[i].point = 3*x[i].win + x[i].draw;
	}
	
	printf(" name   win   draw   lost   point \n");
	for(i=0;i<4;i++) {
		printf(" %-2s", x[i].name);
		fprintf(p," %-2s", x[i].name);
		printf(" %-2d", x[i].win);
		fprintf(p," %-2d", x[i].win);
		printf(" %-2d", x[i].draw);
		fprintf(p," %-2d", x[i].draw);
		printf(" %-2d", x[i].lost);
		fprintf(p," %-2d", x[i].lost);
		printf(" %-2d\n", x[i].point);
		fprintf(p," %-2d\n", x[i].point);
	}
	fclose(p);
	
}
