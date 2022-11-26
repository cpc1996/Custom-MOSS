#include<stdio.h>
void DaoNguoc(int A){
	int b,c;
	while(A>0){
		b=A%10;
		c=c*10+b;
		A=A/10;
 	}
 	printf("So sau khi dao nguoc la: %d",c);
}
void TinhTong(int A){
	int b,Tong=0;
	while(A>0){
		b=A%10;
		A=A/10;
		Tong=Tong+b;
 	}
 	printf("\nTong cua cac chu so la: %d",Tong);
}
int main(){
	int A,b,c,Tong=0;
	printf("Nhap so nguyen duong A: ");
	scanf("%d",&A);
/*	while(A>0){
		b=A%10;
		c=c*10+b;
		A=A/10;
		Tong=Tong+b;
 	}
	printf("So sau khi dao nguoc la: %d\n",c);
	printf("Tong cua cac chu so la: %d",Tong);*/
	///////////////////////////////////////////////
	DaoNguoc(A);
	TinhTong(A);
	
}
