#include<stdio.h>
#include<math.h>

void nhapmang(int *a, int n){
	int i;
	for(i = 0; i<n; i++){
	scanf("%d", (a+i));
	}
}

void xuatmang(int *a, int n){
	int i;
	for(i = 0; i<n; i++){
		printf("\t%d", *(a+i));
	}
}

void daonguocmang(int *a, int n){
	int i, j, tg;
	for(i = 0; i < n/2; i++){
		j = n - 1 - i;
			if(*(a+i) != *(a+j)){
				tg = *(a+i);
				*(a+i) = *(a+j);
				*(a+j) = tg;
			}
		}
	xuatmang(a, n);
}
int main(){
	int n;
	printf("Nhap so phan tu cua mang: "); scanf("%d", &n);
	int *a;
	a = (int*)malloc(n*sizeof(int));
	nhapmang(a, n);
	puts("\nMang ban dau");
	xuatmang(a, n);
	puts("\nMang dao nguoc: ");
	daonguocmang(a, n);
	free(a);
	return 0;
}