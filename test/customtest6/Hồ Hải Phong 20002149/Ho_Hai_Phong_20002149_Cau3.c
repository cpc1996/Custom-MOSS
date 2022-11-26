#include<stdio.h>
#include<math.h>
int main()
{
	int i=3,j;
	double x, ps=1, ms=1, sum, ts;
	
	//cau a
	printf("nhap x=\n");
	scanf("%lf",&x);
	
	//cau b
	sum= x;
	ts= x;
	while(fabs(ps)>0.0001)
	{
		ts= ts*x*x;
		ms= ms*i*(i-1);
		j= pow((-1),(i-1)/2);
		a= j*ts/ms;
		sum+= a;
		i+= 2;
	}
	printf("Gia tri cua sin theo cong thuc = %lf\n",sum);
	
	//cau c
	printf("Ket qua ham sin(%lf) = %lf\n", x, sin(x));
}
