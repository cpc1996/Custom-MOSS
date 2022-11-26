#include<stdio.h>
#include<stdlib.h>

void daonguoc(int a[],int N){
	int dn;
	int i;
	for(i=0;i<N/2;i++){
		dn=*(a+i);
		*(a+i)=*(a+N-i-1);
		*(a-i+N-1)=dn;
	}
}

void in(int a[], int N){
	int i;
	for(i=0;i<N;i++){
		printf("%d\t",*(a+i));
	}
}

void nhap(int a[], int N){
	int i;
	for(i=0;i<N;i++){
		printf("\nNhap a[%d]=",i);
		scanf("%d",(a+i));
	}
}

main(){
	//Khai bao va nhap N
	int N;
	
	do{
	printf("\nNhap N=");
	scanf("%d",&N);
	}while(N<=0);
	//Cap phat dong
	int a[100];
	
	//Nhap gia tri mang
	nhap(a,N);
	
	//In chuoi chua dao nguoc
	printf("\nChuoi truoc khi dao nguoc la:\n");
	in(a,N);
	
	//Dao nguoc
	daonguoc(a,N);
	
	//In chuoi da dao nguoc
	printf("\nChuoi sau khi dao nguoc la:\n");
	in(a,N);
}
