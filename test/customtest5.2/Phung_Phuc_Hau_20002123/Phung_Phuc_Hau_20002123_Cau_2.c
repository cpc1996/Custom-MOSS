#include <stdio.h>

int main() {
	int a[50][50];  
	int i, j, n, m, max, min;
	printf("Nhap vao so hang : "); 
	scanf("%d", &m); 
	printf("Nhap vao so cot : ");
	scanf("%d", &n);
	
	printf("Nhap phan tu cua ma tran A : \n");
	for( i = 0 ; i < m ; i++)
	{
		for( j = 0 ; j < n ; j++)
		{
		printf("a[%d][%d] = ", i, j); 
		scanf("%d", &a[i][j]); 
		}
	}
	
	printf("Cac phan tu cua ma tran A : \n");
	for( i = 0 ; i < m ; i++)
	{
		for( j = 0 ; j < n ; j++)
		{
		printf(" %d ", a[i][j]); 
		}
		printf("\n"); 
	}
	
	max = a[0][0];
	min = a[0][0];
	for( i = 0 ; i < m ; i++)
	{
		for( j = 0 ; j < n ; j++)
		{
			if	(max < a[i][j])
				 max = a[i][j];
			if	(min > a[i][j])
				 min = a[i][j];
		}
	}
	for( i = 0 ; i < m ; i++)
	{
		for( j = 0 ; j < n ; j++)
		{
		if ( max == a[i][j])
			printf("Vi tri cua phan tu lon nhat : a[%d][%d] = %d \n", i, j, max);
		if( min == a[i][j]) 
			printf("Vi tri cua phan tu nho nhat : a[%d][%d] = %d \n", i, j, min);
		}
	}
	
	return 0;
}

