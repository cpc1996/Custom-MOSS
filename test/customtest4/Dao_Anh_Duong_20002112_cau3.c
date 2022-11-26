#include<stdio.h>
typedef struct {
	char name[50];
	int W; //win
	int D; //draw
	int L;  //lost
	int P;  //point
}football;
int main (){
    football a[100];
    int i,j;
	FILE *f;
	fflush(stdin);
	for( i = 0; i < 4;i++){
		printf("Nhap ten CLB: ");
		gets(a[i].name);
		printf("Nhap so tran thang: ");
		scanf("%d",&a[i].W);
		printf("Nhap so tran hoa: ");
		scanf("%d",&a[i].D);
		printf("Nhap so tran thua: ");
		scanf("%d%*c",&a[i].L);
		a[i].P = a[i].W * 3 + a[i].D * 1 + a[i].L * 0;
	}
	for(i = 0; i< 4;i++){
		printf("------------------------\n");
		printf("%s %d %d %d %d\n",a[i].name,a[i].W,a[i].D,a[i].L,a[i].P);
	}
		f = fopen("football.txt","w");
	if(f == NULL){
		return 0;
	}
	for(i = 0; i < 4;i++){
		fprintf(f,"------------------------\n");
		fprintf(f,"%s %d %d %d %d\n",a[i].name,a[i].W,a[i].D,a[i].L,a[i].P);
	}
	fclose(f);
}
