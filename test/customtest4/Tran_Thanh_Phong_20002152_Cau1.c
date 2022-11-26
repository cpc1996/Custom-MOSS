#include<stdio.h>
#include<math.h>
main()
{ 
 float n,s=0,i;
 
  printf("nhap n: ");
  scanf("%f",&n);
  for(i=1;i<=n;i++)
  s=s+1/i;
  printf("%.3f",s);
}
