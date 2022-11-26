#include<math.h>
#include<stdio.h>
#include<stdlib.h>

main()
{
	int i,j,N,tg;
	int *a;
	printf("Nhap so nguyen duong N = ");
	scanf("%d",&N);
	
	a = (int*)malloc(N*sizeof(int));
		if(a==NULL)
	{
		printf("Khong duoc cap bo nho cho mang");
		exit(0);
	}
	printf("Nhap cac phan tu cua mang : \n");
   	for(i=0 ; i < N ; i++ ) 
   	{
   		printf("a[%d]=",i);
    	scanf("%d", a+i);
   	}
	for(i=0;i<N-1;i++)
   	{
   		for(j=i+1;j<N;j++)
   		{
   			if(*(a+j)<*(a+i))
   			{
   				tg= *(a+i);
   				*(a+i)= *(a+j);
   				*(a+j)= tg;
			}
		}
	}
	printf("Mang sap xep theo chieu tang dan la: ");
	for( i=0 ; i < N ; i++ ) 
   	{
    	printf("%d\t",*(a+i));
   	}
}
