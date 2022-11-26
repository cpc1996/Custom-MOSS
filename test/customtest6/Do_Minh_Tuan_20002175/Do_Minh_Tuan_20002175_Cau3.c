#include<stdio.h>
#include<math.h>
 NguyenTo(int n) {
	
	int i;
	if(n <2) {
	
		printf("\n%d khong phai so nguyen to",n);
		return 0;
	
	}
	int count = 0;
	for(i = 2; i<= sqrt(n); i++) {
	
		if(n % i ==0) {
			count++;
		}
		
	}
//	if(count == 0) {
//		
//		printf("\n%d la so nguyen to",n);
//	}
	if(count >0) {
		printf("\n%d khong la so nguyen to",n);
	}
	return 0;
}

void main() {

	int N1,N2;
	int i;
	int a;
	do {
		printf("\nNhap N1: ");
		scanf("%d",&N1);
		
		printf("\nNhap N2: ");
		scanf("%d",&N2);
	}while(N1>N2);
	
	printf("\n moi nhap so can kiem tra: ");
	scanf("%d",&a);
	
	NguyenTo(a);
	
	for(i = N1; i<=N2; i++) {
	
		NguyenTo(i);
	
	}
}
