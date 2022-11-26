#include<stdio.h>
main()
{	
	int f0 , f1 , fn , i , n  ;
	float x ; 
	printf("\nNhap x =");
	scanf("%f",&x);
	printf("Nhap vao gia tri n = " );
	scanf("%d",&n);
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
			fn = 2*x +  f0 - f1 ; 
			f0 = f1 ; 
			f1 = x ; 
		}
		printf("\n F%d = %d " , i , fn ) ;
	}
}
