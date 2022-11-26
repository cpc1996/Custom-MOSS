#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	float s=1;
	int i;
	for(i=2;i<=n;i++){
		s=s+1.0/i;
	}
	printf("%.3f",s);
}
