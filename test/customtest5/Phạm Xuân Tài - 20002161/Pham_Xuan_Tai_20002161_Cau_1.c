#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

main()
{
    float x1,y1,x2,y2;
    float s;
    printf("nhap hoanh do diem A:");
    scanf("%f",&x1);
    printf("nhap tung do diem A:");
    scanf("%f",&y1);
    printf("nhap hoanh do diem B:");
    scanf("%f",&x2);
    printf("nhap tung do diem B:");
    scanf("%f",&y2);
    s= (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
    s=sqrt(s);
    printf("Do dai doan thang AB la:%.2f",s);
    return(0);


}