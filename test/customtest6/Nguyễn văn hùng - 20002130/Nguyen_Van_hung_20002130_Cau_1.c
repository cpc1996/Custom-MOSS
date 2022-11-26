#include<stdio.h>

main()
{
    float x,y;
    printf("nhap gia tri cua x: ");
    scanf("%f",&x);
    y = (x>0)?x*x:x+1;
    printf("ket qua la: y = %.4f",y);
}
