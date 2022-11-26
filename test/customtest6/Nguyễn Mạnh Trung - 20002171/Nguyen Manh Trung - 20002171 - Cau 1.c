#include<stdio.h>
int main(){
	float x,S;
	unsigned int n;
	int i;
	printf("Nhap gia tri cua x: ");
	scanf("%f",&x);
	S=x;
	printf("Nhap gia tri cua n: ");
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		S=S*x;
	}
	printf("%.4f",S);
}
