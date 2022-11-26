#include<stdio.h>
#include<stdlib.h>
int tong_cot(int **a,int n,int cot)
{
    int tong=0;
    int i=0;
    int j=0;
    for(i;i<n;i++)
    {
        tong+=a[i][cot-1];                         
    }
    return tong;
}
int main()
{
    int n;
    do
    {
        scanf(" %d",&n);
    }
	while(n<=0);
    int **a;
    a=(int**)malloc(n*sizeof(int*));
    int i=0, j=0;
    for(i;i<n;i++)
    {
        a[i]=(int*)malloc(n*sizeof(int));
    }
    for(i;i<n;i++)
    {
        for(j;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    printf("\n");
    for(i;i<n;i++)
    {
        for(j;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    int cot;                                     
    scanf(" %d",&cot);
    int tongcot=0;
    for(i;i<n;i++)
    {
        tongcot+=a[i][cot-1];                  
    }
    printf("%d\n",tongcot);

    int c;
    scanf(" %d",&c);
    printf("%d",tong_cot(a,n,cot));
    return 0;
}
