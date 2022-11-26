#include<stdio.h>
#include<math.h>
int SNT(int n)
{
	int i;
	for(i=2; i<=sqrt(n); i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
void NOT_SNT(int N1, int N2)
{
	int num,i;
	for(num=N1; num<N2; num++)
	{
		int count=0;
		for(i=2; i<=sqrt(num); i++)
		{
			if(num%i==0)
			{
				count++;
			}
		}
			if(count>0)
			{
			printf("%d\t",num);
			}	
		}
}
int main()
{
	int N1,N2;
	do{
		printf("nhap N1= ");scanf("%d",&N1);
		printf("nhap N2= ");scanf("%d",&N2);
	}while(N2<=N1);
	int n;
	do{
		printf("nhap n= ");
		scanf("%d",&n);
	}while(n<=1);
	int kt = SNT(n);
	if(kt==1)
	{
		printf("%d la so nguyen to\n",n);
	}
	else
	{
		printf("%d ko la so nguyen to\n",n);
	}
	NOT_SNT(N1,N2);
	return 0;
}
