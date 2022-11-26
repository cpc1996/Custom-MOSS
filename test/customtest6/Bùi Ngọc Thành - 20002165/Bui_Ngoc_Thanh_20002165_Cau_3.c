#include <stdio.h>
#include <stdlib.h>

void DaoNguocMang(int*a,int n)
{
    int m, i;
    m=n/2;
    int temp;
    for (i=0;i<m;i++)
    {
        temp = *(a + i);
        *(a+i) = *(a+(n-i-1));
        *(a+(n-i-1))=temp;
    }
}
void SapXepTang(int*a,int n)
{
    int i, j;
    for (i = 0;i<n -1;i++)
    {
        for (j=i + 1; j<n;j++)
        {
            if(a[i]>a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

