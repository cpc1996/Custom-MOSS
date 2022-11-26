#include<stdio.h>
#include<math.h>

int kiemtraSNT(int a){
	int i;
	
	if(a<=1){
		return 1;
	}
	
	if(a>1){
		for(i=2;i<=sqrt(a);i++){
			if(a%i==0){
				return 1;
			}
		}
		return 0;
	}
}

main(){
	int N1,N2;
	int kt=0;
	do{
		printf("Vui long Nhap 2 so nguyen duong sao cho N2 > N1!\n");
		printf("Nhap N1: ");
		scanf("%d",&N1);
		printf("Nhap N2: ");
		scanf("%d",&N2);
	}while(N1>N2 || N1<0);
	
	int j;
	printf("Cac so khong phai so nguyen to trong [%d,%d] la:\n",N1,N2);
	for(j=N1;j<=N2;j++){
		kt=0;
		kt=kiemtraSNT(j);
		if(kt==1){
			printf("%d\t",j);
		}
	}
}
