#include<stdio.h>

float Thu(int n, float x)
{
	int i;
	float a=1;
	float b=x;
	float T;
	for (i=2;i<=n;i++)
	{
		T=2*x*b-a;
		a=b;
		b=T;
	}
	return(T);
}

main()
{
	int n,i; 
	float x;
	float T[100];
	
	printf("n="); 	scanf("%d",&n);
	printf("x=");	scanf("%f",&x);
	
	T[0]=1;
	T[1]=x;
	for (i=2;i<=n;i++)
		T[i]=2*x*T[i-1]-T[i-2];
	for (i=0;i<=n;i++)
	{
		printf("%d\t %f",i,T[i]);
		printf("\n");
	}
	printf("\n");
	
	int mang[100],so,j;
	printf("So phan tu n:"); scanf("%d",&so);
	printf("\n");
	printf("Mang chua n gom cac phan tu:");
	for (j=0;j<so;j++);
		scanf("%d",&mang[j]);
	
	for (i=0;i<so;i++)
	{
		printf("%d\t %f",mang[i],Thu(mang[i],x));
		printf("\n");
	}
				
	FILE *p;
	p=fopen("C:\\Users\\congd\\Desktop\\chev.txt","w");
	
	for (i=0;i<so;i++)
	{
		fprintf(p,"%d\t %f",mang[i],Thu(mang[i],x));
		fprintf(p,"\n");
	}
	fclose(p);
}
