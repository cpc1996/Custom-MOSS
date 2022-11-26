#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846
int main()
{
    float x;
    printf("Nhap goc: ");
    scanf("%f", &x);
    float xRad = (x * M_PI) / 180;
    printf("xRad = %.2f", xRad);
    return 0;
}