#include<stdio.h>
#include<math.h>

int main()
{
	float AC,AB;
	float BC,AH;
	printf("nhap gia tri cua AC:");
	scanf("%f",&AC);
	printf("nhap gia tri cua AB:");
	scanf("%f",&AB);
	if(AC > 0 && AB > 0)
	{
		printf("BC = %.3f\n",sqrt(AC*AC+AB*AB));
		BC = sqrt(AC*AC+AB*AB);
		if(AC < AB + BC && AB < AC+BC && BC < AC+AB)
		{
			printf("AH = %.3f",AB*AC/BC);
		}
		else
		{
			printf("tam giac khong ton tai");
		}
	}
	else
	{
		printf("nhap lai cac canh!");
	}
	return 0;
}
