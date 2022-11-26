#include<stdio.h>
#include<math.h>
int main(){
	float ampi,pi;
	scanf("%f%f",&ampi,&pi);
	float xi;
	for(xi=ampi;xi<=pi;xi+=0.01){
		printf("%f	%f\n",xi,sin(xi));
	}
	
}

