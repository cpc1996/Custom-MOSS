#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
	int N;
	printf("nhap N:");
	scanf("%d",&N);
	int a[N];
	int i ;
	for(i=0 ;i<N;i++){
		scanf("%d",&a[i]);
	}
// y 3
	for(i =N-1 ; i>=0 ;i--){
	   printf("%d\t",a[i]);
	}
	// y 4
	printf("\n");
   for( i=0;i<N/2;i++) {
    int t=a[i];
   a[i]=a[N-1-i];
   a[N-1-i]=t; 
 }
 for(i = 0;i<N;i++){
   printf("%d\t",a[i]);
 }
}
