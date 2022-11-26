#include<stdio.h>
#include<stdlib.h>
int main(){
	int *a, N, i,S=0;
	printf("Nhap so luong phan tu: ");
	scanf("%d",&N);
	a=(int*)malloc(N*sizeof(int));
	for(i=0;i<N;i++){
		*(a+i)=i*i+2;
		if(*(a+i)%3==0){
			S=S+*(a+i);
		}
	}
	printf("Mang da nhap la: \n");
	for(i=0;i<N;i++){
		printf("%d\t",*(a+i));
	}
	printf("\nTong cac so chia het cho 3 la: %d",S);
}
