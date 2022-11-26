#include <stdio.h>
#include <math.h>

int checkSNT(int n)
{
    if (n < 2)
    {
        return 0;
    }
    else
    {
        int i;
        for (i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}

int main(int argc, char const *argv[])
{
    int i, j, check = 1;
    ;
    int n1, n2;
    int n;
    // nhap n kiem tra ham SNT
    printf("Nhap n: ");
    scanf("%d", &n);
    int result = checkSNT(n);
    if (result == 1)
    {
        printf("%d la SNT\n", n);
    }
    else
    {
        printf("%d khong la SNT\n", n);
    }
    do
    {
        printf("Nhap n1, n2 (n1 < n2): ");
        scanf("%d%d", &n1, &n2);
    } while (n1 > n2 || n1 < 0 || n2 < 0);

    // goi ham in ra cac so ko la SNT
    for (i = n1; i <= n2; i++)
    {
        if (checkSNT(i) == 0)
        {
            printf("%5d", i);
        }
    }
    return 0;
}