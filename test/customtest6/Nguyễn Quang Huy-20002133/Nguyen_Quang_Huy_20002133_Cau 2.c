#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void tinhTongMotCot(int **a, int n)
{
    int i,m, sum = 0;
    printf("Chon mot cot de tinh tong: ");
    scanf("%d", &m);
    for(i = 0; i < n; i++)
    {
        sum += a[i][m-1];
    }
    printf("Tong cua cot %d la: %d", m, sum);
}
int main()
{
    int i,j,n, m, sum = 0;
    printf("Nhap 1 so nguyen duong: ");
    scanf("%d", &n);
    int **a = NULL;
    a = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
    }
    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < n; j++)
        {
            printf("a[%d][%d]= ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }
    printf("Chon mot cot de tinh tong: ");
    scanf("%d", &m);
    for(i = 0; i < n; i++)
    {
        sum += a[i][m-1];
    }
    printf("Tong cua cot %d la: %d\n", m, sum);
    tinhTongMotCot(a, n);
}
