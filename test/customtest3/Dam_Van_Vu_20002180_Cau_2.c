#include<stdio.h>

int i, j;
int giaTriCucDai(int x[100][100], int m, int n){
	int max = x[0][0];
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			if(max < x[i][j]){
				max = x[i][j];	
			}
		}	
	}
	return max;
}		
int giaTriCucTieu(int x[100][100], int m, int n){
	int min = x[0][0];
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			if(min > x[i][j]){
				min = x[i][j];	
			}
		}	
	}
	return min;
}		
int main() {
	int M, N;
	int a[100][100];
	printf("Nhap vao 2 so M va N: "); //M - hang. N - cot
	scanf("%d%d", &M, &N);
//nhapMang	
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			printf("a[%d][%d]=", i, j);
			scanf("%d", &a[i][j]);
		}	
	}
//xuatMang
	printf("\nMang: \n");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
//xuLyBaiToan
	printf("Max = %d\n", giaTriCucDai(a, M, N));
	printf("Min = %d", giaTriCucTieu(a, M, N));
}
