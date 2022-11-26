#include<stdio.h>
#include<math.h>
int main()
{
	int i=3,j;
	double x, a=1, ms=1, s, ts;
	//y 1
	printf("nhap x=");
	scanf("%lf",&x);
	//y 2
	s= x;
	ts= x;
	while(fabs(a)>0.0001)
	{
		ts= ts*x*x;
		ms= ms*i*(i-1);
		j= pow((-1),(i-1)/2);
		a= j*ts/ms;
		s+= a;
		i+= 2;
	}
	
	printf("Gia tri cua sin theo cong thuc = %lf\n",s);
	//y 3
	printf("Ket qua ham sin(%lf) = %lf\n", x, sin(x));
	// y 4
	if(s == sin(x))
	{
		printf("hai cach cho ra cung ket qua");
	}
	else
	{
		printf("khong ra cung ket qua!");
	}
	return 0;
}


