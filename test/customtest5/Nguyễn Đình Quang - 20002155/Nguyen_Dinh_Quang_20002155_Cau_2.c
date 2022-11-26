//cau 2 
#include<stdio.h>
#include<stdlib.h>

main()
{
	int *a ,i,n,s=0 ; 
	printf("Nhap vao so phan tu cua  n = ");
	scanf("%d",&n);
	a = (int*)malloc(n*sizeof(int)) ; 
	if(a == NULL ) 
	{
		printf("\nKhong the cap phat !!! ");
		exit(0); 
	}
	for ( i = 0 ; i< n ; i++ )
	{
		*(a+i) = i*i +2;
	}
	printf("\nCac phan tu cua mang : ");
	for (i = 0 ; i< n ;i++ )
	{
		printf("%d\t",*(a+i));
	}
	
	for ( i = 0 ; i< n ; i++ )
	{
		if (*(a+i) % 3 == 0 )
		{
			s += *(a+i);
		}
	}
	
	printf("\nTong cac phan tu chia het cho 3 la %d",s);
	free(a); 
	
}

