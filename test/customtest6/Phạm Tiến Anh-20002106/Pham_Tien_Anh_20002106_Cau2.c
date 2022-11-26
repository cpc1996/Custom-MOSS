#include<stdio.h>
#include<stdlib.h>
main()
{
	int *a,n,i,c;
	printf("nhap so n: ");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	if( a == NULL)
		{
			printf("khong cap phat duoc bo nho");
			exit(0);
		}
	printf("nhap mang: ");
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	for(i=0;i<n/2;i++)
		{
			c=*(a+i);
			*(a+i)=*(a+(n-i-1));
			*(a+(n-i-1))=c;
		}
	printf("mang moi la: ");
	for(i=0;i<n;i++)
	printf("%d ",*(a+i));
	free(a);
	}
