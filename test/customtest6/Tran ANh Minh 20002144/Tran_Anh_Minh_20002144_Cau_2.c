#include<stdio.h>
int main()
{
	int m,n,i,j;
	printf("Nhap m,n: "); scanf("%d%d",&m,&n);
	int a[m][n],min,max;
	for(i=0;i<m;i++){
	 	for(j=0;j<n;j++){ 
	 		printf("a[%d][%d]= ",i,j);
	    	scanf("%d",&a[i][j]);
	  	}
	}
	max=a[0][0];
	for(i=0;i<m;i++){
	 	for(j=0;j<n;j++){
	  		if(a[i][j]>max) 
	 			max=a[i][j];
	 		}
	 	}
	printf("Max = %d, tai ",max);
	for(i=0;i<m;i++){
	 	for(j=0;j<n;j++){
	  		if(a[i][j]==max) printf("a[%d][%d] ",i,j);
		}
	}
    min=a[0][0];
	for(i=0; i<m; i++){
	 	for(j=0; j<n; j++){
	  		if(a[i][j]<min) 
	 			min=a[i][j];
	 		}
	 	}
	printf("\nMin = %d, tai ",min);
	for(i=0;i<m;i++)
	 	for(j=0;j<n;j++)
	  		if(a[i][j]==min) printf("a[%d][%d] ",i,j);

	return 0;	
}

