#include<stdio.h>
main() {

	int M,N;
	int i,j;
	//Nhap vao M, N
	printf("Moi nhap M: ");
	scanf("%d",&M);
	printf("Moi nhap N: ");
	scanf("%d",&N);
	
	// M hang , N cot 
	int a[M][N];
	for(i = 0; i < M; i++) {
		for(j = 0; j< N; j++){
		
			printf("a[%d][%d] =  ",i,j);
			scanf("%d",&a[i][j]);
			printf("\n");
		
		}
		
	}
	//in
	for(i = 0; i < M; i++) {
		for(j = 0; j< N; j++){
		
			printf(" %d ",a[i][j]);
			
		
		}
		printf("\n");
	}
	
	
	
	printf("\n");
	// tim Min Max
	int max = a[0][0];
	int min = a[0][0];
	
	for(i = 0; i<M; i++) {
	
		for( j = 0; j < N; j++) {
		
			if( max < a[i][j]) {
				max = a[i][j];
			}
			if(min >a[i][j]) {
				min = a[i][j];
			}
		}
		
	}
	
	for(i = 0; i<M; i++) {
	
		for( j = 0; j < N; j++) {
		
			if( a[i][j] == min) {
				
				printf("min a[%d][%d] = %d\n",i, j , min);
			}
			if(a[i][j] == max) {
				
				printf("max a[%d][%d] = %d\n",i, j , max);
			}
		}
		
	}

}
