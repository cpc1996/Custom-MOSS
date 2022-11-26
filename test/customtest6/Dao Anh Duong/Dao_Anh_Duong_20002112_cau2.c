#include<stdio.h>
void nhap(int a[],  int n){
	int i;
	printf("Nhap cac gia tri cua mang:\n ");
	for(i = 0; i < n;i++){
		printf("a[%d] ",i);
		scanf("%d", &a[i]);
	}
}
void xuat(int a[], int n){
	int i;
	for(i = 0;i < n;i++){
		printf("%d ", a[i]);
	}
}
void daonguoc(int a[], int n){
	int i;
	for(i = 0; i < n/2; i++){
			int c;
		    c = a[i];
			a[i] = a[n - 1 -i];
			a[n - 1 - i] = c ;
	}
}
int main (){
	int a[100],n,i,c;
	printf("Moi ban nhap so nguyen duong: ");
	scanf("%d",&n);
	nhap(a,n);
	printf("\nMang sau khi nhap la:\n ");
	xuat(a,n);
	daonguoc(a,n);
	printf("\nMang sau khi dao nguoc la: ");
	xuat(a,n);
	return 0;
}
