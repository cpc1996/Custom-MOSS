#include<stdio.h>
#include<math.h>
main()
{ 
 float x1,x2,y1,y2,d;
  printf("nhap toa do diem A: ");
  scanf("%f%f",&x1,&x2);
  printf("nhap toa do diem B: ");
  scanf("%f%f",&y1,&y2);
  d=sqrt((x1-y1)*(x1-y1)+(x2-y2)*(x2-y2));
  printf("AB= %0.2f",d);
  return 0;
}
