#include <stdio.h>
#include <stdlib.h>

void DaoNguocMang(int *a, int n)
{
    int m, i;
    m = n / 2;
    int temp;
    for (i = 0; i < m; i++)
    {
        temp = *(a + i);
        *(a + i) = *(a + (n - i - 1));
        *(a + (n - i - 1)) = temp;
    }
}

int main()
{
    int *a, n, i;
    int m;
    do
    {
        printf("Nhap so phan tru cua mang: ");
        scanf("%d", &n);
        if (n <= 0)
        {
            printf("\nn phai la so nguyen duong, Xin nhap lai:");
        }
    } while (n <= 0);
    a = (int *)malloc(n * sizeof(int));
    if (a == NULL)
    {
        printf("\nKhong the cap phat bo nho");
        exit(0);
    }

    printf("\n\tNhap mang: \n");
    for (i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", a + i);
    }

    DaoNguocMang(a, n); // goi ham dao nguoc mang
    printf("\n\tMang sau khi dao nguoc lai: ");
    for (i = 0; i < n; i++)
    {
        printf("%5d", *(a + i));
    }
    return 0;
}