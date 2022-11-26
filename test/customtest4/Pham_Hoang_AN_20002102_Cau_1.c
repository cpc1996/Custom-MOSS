#include<stdio.h>
#include<math.h>
main()
{
	float AB, AC;
	float BC, AH;
	
	printf("\nCho tam giac ABC vuong tai A\n");
	printf("Nhap do dai AB= ");
	scanf("%f",&AB);
	printf("\nNhap do dai AC= ");
	scanf("%f",&AC);
	
	BC= sqrt(AB*AB + AC*AC);
	printf("\nDo dai doan BC= %.3f", BC);
	
	AH= sqrt((AB*AB*AC*AC)/(AB*AB+AC*AC));
	printf("\nDo dai doan AH= %.3f", AH);	
}
