#include<stdio.h>
main()
{	
	int G0 , G1 , GN , i , N  ;
	float X ; 
	printf("\nNhap x =");
	scanf("%f",&X);
	printf("Nhap vao gia tri n = " );
	scanf("%d",&N);
	G0 = 0 ; 
	G1 = X ;
	for ( i = 0 ; i < N ; i ++  )
	{
		if ( i < 1 )
		{
			GN = i+1 ;  
		}
		else 
		{
			GN = 2*X +  G0 - G1 ; 
			G0 = G1 ; 
			G1 = X ; 
		}
		printf("\n F%d = %d " , i , GN ) ;
	}
}
