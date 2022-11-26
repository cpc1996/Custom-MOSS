#include <stdio.h>
#include <math.h>
float giatrisopi(){
	float s=0;
	float i=1;
	float k=0;
	do{
		s+=pow(-1,k)*(1/i);
		i=i+2;
		k++;
	}while((4*1/i) > 0.00001);
	return 4*s;
}	
int main(){
	float s=0;
	float i=1;
	float k=0;
	do{
		s+=pow(-1,k)*(1/i);
		i=i+2;
		k++;
	}while((4*1/i) > 0.00001);
	printf("tinh theo cong thuc: %f\n",4*s);
	printf("gia tri hang so pi trong thu vien: %f\n\n\n\n",M_PI);
	
	
	printf("tinh theo ham: %f\n",giatrisopi());
	printf("gia tri hang so pi trong thu vien: %f",M_PI);
	return 0;
}	
