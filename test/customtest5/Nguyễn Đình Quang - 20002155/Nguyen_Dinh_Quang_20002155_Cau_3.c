#include<stdio.h>
void daonguoc(int n )
{
	int b,tg ;
	while(n > 0)
	{
    	
        tg = n % 10;
        b = b * 10 + tg;
        n = n / 10;
    }
    printf("\n So dao nguoc cua A =  %d", b);
}
void tinhtong(int n)
{
	int s = 0;
	while(n > 0) 
	{
		s += n % 10;
		n = n / 10;
	}
	printf("\nTong cac chu so cua A: %d\n", s);
}
main()
{
	int a, tg;
	while( a <= 0)
	{
		printf("\nNhap so duong A = ");
		scanf("%d",&a);
	}
/*	int b = 0 ; 	
    while(a > 0)
	{
    	
        tg = a % 10;
        b = b * 10 + tg;
        a = a / 10;
    }
    printf("\n So dao nguoc cua A =  %d", b);
    //b)
    int s = 0;
	while(b > 0) 
	{
		s += b % 10;
		b = b / 10;
	}
	printf("\nTong cac chu so cua A: %d\n", s);
*/
	//c) 
	daonguoc(a);
	tinhtong(a);
	
}
