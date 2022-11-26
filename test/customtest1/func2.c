#include<stdio.h>
int main()
{
	// cau a ( 0,5 diem )
	int n;
	float x;
	
	printf("\nMoi ban nhap so nguyen duong n :  ");	
	do
	{
		scanf("%d",&n);
	}while( n < 1);
	
	printf("\nMoi ban nhap so thuc x :  ");	scanf("%f",&x);
	// cau b ( 1,5 diem )
	int f0 , i   ;
	float fn, f1;
	f0 = 0 ; 
	f1 = x ;
	for ( i = 0 ; i < n ; i ++  )
	{
		if ( i < 1 )
		{
			fn = i+1 ;  
		}
		else 
		{
			fn = 2*x*f0 - f1 ; 
			f0 = f1 ; 
			f1 = x ; 
		}
		printf("\n F%d = %.3f " , i , fn ) ;
	}
	// cau c
	return 0;
}
	
	
	
 
