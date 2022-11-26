#include<stdio.h>
#include<math.h>
struct point
{
	int hd ;
	int td ;
};
void toadodiem(int *x , int *y )
{
	printf("\nhoanh do = ");
	scanf("%d",x);
	printf("\ntung do = ");
	scanf("%d",y);
}
void dodai(int m , int n , int p , int q    )
{
	float d ;
	d = sqrt((m-p)*(m-p)+(n-q)*(n-q));
	
	printf("\nChieu dai = %f ",d);
	
}
main()
{
	struct point a , b  ;
	printf("Nhap thong tin diem A ") ;
	toadodiem(&a.hd,&a.td);
	printf("\nNhap thong tin diem B ");
	toadodiem(&b.hd,&b.td);
	
