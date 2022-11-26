#include <stdio.h>
#include <stdlib.h>
int TinhT(int **a,int N,int cot)
{
	int S=0;
	int i;
        for (i = 0; i < N; i++)
        {
           S=S+a[i][cot];
        }
        return S;
}
int main()
{
	int **a=NULL,N,i,j,cot;
	printf("Nhap N :");
	scanf("%d",&N);
	a=(int*)malloc(N*N*sizeof(int));
	for (i = 0; i < N; i++)
	{
        for (j = 0; j < N; j++)
        {
            printf("a[%d][%d] = ", i+1, j+1);
            scanf("%d", (a+i*N+j));
        }
    }
    printf("Ma tran sau khi nhap : \n");
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%d\t", *(a + i*N + j));
        }
        printf("\n");
    }
    printf("\n");
    int S=0;
    printf("Nhap cot muon tinh tong :");
    scanf("%d",&cot);
    for(i=0;i<N;i++)
    {
      S+=*(a+i*N+cot);
	}
	printf("Tong cot thu la : %d",S);
}
