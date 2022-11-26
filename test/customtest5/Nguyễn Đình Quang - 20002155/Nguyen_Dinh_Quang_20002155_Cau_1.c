// Cau 1 
#include<stdio.h>

main()
{
	float x ;
	int n , i  ;
	printf("Nhap vao x = ");
	scanf("%f",&x);
	while( n <= 0 )
	{
		printf("\nNhap vao n > 0  = ");
		scanf("%d",&n);
	}
	float p = 1  ;
	for( i = 1; i <= n; i++) 
	{
        p = p*x;
    } 
    printf("\nKet qua x mu n = %0.4f",p);
}

