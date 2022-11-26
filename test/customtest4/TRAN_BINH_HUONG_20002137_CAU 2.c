#include<stdio.h>
#include<stdlib.h>
main()
{
	int *a,n,i,tg,tong,dem;
	printf("nhap n\n");
	scanf("%d",&n);
	a=(int*)calloc(n, sizeof(int));
	printf("nhap gia tri cua mang\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	printf("in gia tri cua mang\n");
	for(i=0;i<n;i++)
	{
		printf("%d \n",*(a+i));
	}		
	for(i=0;i<n;i++)
	{
		tg=0;
		tg= tg+ i*i+2;
	}
	printf("gia tri cac phan tu trong mang:%d\n",tg);
	tong=0;
	dem=0;
	for(i=0;i<n;i++)
	{
		if(*(a+i)%3==0)
		{
			tong = tong + *(a+i);
			dem++;
		}
	}
	if(dem==0)
	return 0;
	printf("tong gia tri cac phan tu chia het cho 3 la:%d\n",tong);
}			
	
		
