#include<stdio.h>
#include<math.h>
int main(){
	int n,i;
	float x,ms,ts;
	float tong,heso;
	
	printf("Nhap so thuc: ");
	scanf("%f",&x);
	
	ms=1;
	ts=x;
	printf("nhap n:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		ts=pow(x,(2*i+1));
		heso=i*2+1;
		ts= ts*heso*(heso-1);
		tong+=pow(-1,(i+1))*ts/ms;
	}
	printf("tong la %f",tong);
}
	
