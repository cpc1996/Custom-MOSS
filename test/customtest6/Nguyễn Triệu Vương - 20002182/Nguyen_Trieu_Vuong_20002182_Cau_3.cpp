#include <stdio.h>
#include <string.h>
void chuyenDoi(char x[]){
	for(int i=0; i<strlen(x); i++){
		if (i==0|| (i>0 && x[i-1]==32)){
			if(x[i]>=97 && x[i]<=122)
				x[i]=x[i]-32;	
		}else{
			if(x[i]>=65 && x[i]<=90)
				x[i]=x[i]+32;	
		}
	}
}
int main(){
	char xau1[50];
	printf("Nhap vao xau 1: ");
	fgets(xau1, sizeof(xau1), stdin);
	printf("\nXau 1 da nhap la: ");
	puts(xau1);	
	char xau2[50];
	printf("Nhap vao xau 2: ");
	fgets(xau2, sizeof(xau2), stdin);
	printf("\nXau 2 da nhap la: ");
	puts(xau2);
	chuyenDoi(xau1);
	printf("\ns = ");
	puts(xau1);
	chuyenDoi(xau2);
	printf("\ns = ");
	puts(xau2);
}

