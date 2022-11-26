#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct{
	char name[20];
	float win;
	float drawn;
	float lost;
	float point;
}bongda;

main(){
	bongda a[100];
	int i, n;
	FILE *f;
	fflush(stdin);
	
	puts("Nhap so doi bong: "); scanf("%d%*c", &n);
	for(i = 0; i<n; i++){
		printf("\nNhap bang diem doi bong thu %d: \n", i+1);
		printf("\nTen doi bong: "); 
		gets(a[i].name);
		printf("\nSo tran thang: "); 
		scanf("%f", &a[i].win);
		printf("\nSo tran hoa: "); 
		scanf("%f", &a[i].drawn);
		printf("\nSo tran thua: "); 
		scanf("%f%*c", &a[i].lost);
		
		// Tinh diem:
		a[i].point = a[i].win*3 + a[i].drawn*1 + a[i].lost*0;
	}
	
	puts("___________Thong tin cua cac doi bong___________");
	puts("Ten  \tWin\tDrawn \tLost\tPoint");
	for(i = 0; i<n; i++){
		printf("%s\t%.0f \t%.0f \t%.0f \t%.0f\n", a[i].name, a[i].win, a[i].drawn, a[i].lost, a[i].point);
	}
	
	f = fopen("fooball.txt", "w");
	if(f == NULL){
		puts("Errol");
		exit(0);
	}
	for(i = 0; i < n; i++){
		fprintf(f, "\n%s  \t%.0f \t%.0f \t%.0f \t%.0f\n", a[i].name, a[i].win, a[i].drawn, a[i].lost, a[i].point);
	}
	fclose(f);
	return 0;
}


