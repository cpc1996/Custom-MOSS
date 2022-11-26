#include<stdio.h>
#include<math.h> 
main() 
{ 
  float x1,y1,x2,y2,L; 
  printf("nhap toa do x1");
  scanf("%f",&x1);
  printf("nhap toa do y1");
  scanf("%f",&y1);
  printf("nhap toa do x2");
  scanf("%f",&x2);
  printf("nhap toa do y2");
  scanf("%f",&y2);
  L=(((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
  printf("Do dai AB la: %0.2f",sqrt(L));
}
