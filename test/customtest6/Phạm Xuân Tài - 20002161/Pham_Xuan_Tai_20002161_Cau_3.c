#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

snt(int x)
{
    int i;
    int dem;

    if(x<2)
    {
        printf("%d khong phai la so nguyen to!",x);
    }
    else
    {   
        dem=0;
        for(i=1;i<=x;i++)
        {
            if(x%i==0)
            dem++;
        }
        if(dem==2)
        {
            printf("%d la so nguyen to",x);
        }
        else
        {
            printf("%d khong phai la so nguyen to!",x);    
        }
    }
}
snt1(int x,int y)
{
    int i,j;
    int dem;
    
    
    for(i=x;i<=y;i++)
    {
        dem=0;
        for(j=1;j<=i;j++)
        {
            if(i%j==0)
            dem++;
        }
        if(dem>2)
        {
            printf("%d ",i);
        }
    }
  
}
    
main()
{
    int N1,N2;
    int x;
    do
    {
        printf("nhap lan luot hai so N1 va N2 (N2>N1):");
        scanf("%d",&N1);
        scanf("%d",&N2);
    }
    while(N1>N2);
    printf("kiem tra so nguyen to:\n");
    printf("nhap so can kiem tra:");
    scanf("%d",&x);
    snt(x);
    printf("\nin ra day khong la so nguyen to:\n");
    snt1(N1,N2);
    return(0);

}