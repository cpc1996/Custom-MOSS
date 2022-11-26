#include<stdio.h>

int giaithua(int a)
{
	int i,b;
	b=1;
	for (i=1;i<=a;i++)
		b=b*i;
	return(b);
}

main()
{
	int i,N,S;
	printf("Nhap N=");	scanf("%d",&N);
	while ((N>=10) || (N<=0))
	{
		printf("Moi nhap lai N=");
		scanf("%d",&N);
	}
	
	S=0;
	for (i=1;i<=N;i++)
		S=S+giaithua(i);
		
	printf("Tong S=%.3d",S);
}
