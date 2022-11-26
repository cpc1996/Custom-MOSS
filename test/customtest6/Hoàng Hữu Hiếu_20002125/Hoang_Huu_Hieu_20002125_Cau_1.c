#include<stdio.h>
# define M_PI           3.14159265358979323846
int main() 
{    
	float X,n;
	printf("Nhap goc X do: ");
	scanf("%f",&X);
	n=X*(M_PI/180);
	printf("\nGoc sau khi doi sang radian: %0.2f",n);
	

return 0;
}
