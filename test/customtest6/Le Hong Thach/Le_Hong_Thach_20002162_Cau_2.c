#include<stdio.h>
main(){
	FILE *m;
	int n;
	int a[100][100],b[100][100];
	int i,j,k,h;
	int c[100][100];
	printf("n= ");
	scanf("%d",&n);
	printf("nhap ma tran a:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("a[%d][%d]=", i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("\n");
	printf("nhap ma tran b:\n");
	for(k=0;k<n;k++){
		for(h=0;h<n;h++){
			printf("b[%d][%d]=", k,h);
			scanf("%d",&b[k][h]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			c[i][j]=0;
			for(k=0;k<n;k++){
				c[i][j] += a[i][k]*b[k][j];
			}
		}
	}
	printf("ma tran tich la:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	
}
