#include <stdio.h>
#include <math.h>

#define PI 3.14

int main()
{
	float n = -PI;
	while(n <= PI)
	{
		printf("%0.2f\t%f\n", n, sin(n));
		n = n + 0.01;
	}
	return 0;
}
