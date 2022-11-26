#include <stdio.h>
#include <math.h>

typedef struct
{
    float x, y;
} Point;

void NhapToaDo(Point *x)
{
    printf("\nNhap hoanh do: ");
    scanf("%f", &x->x);
    printf("Nhap tung do: ");
    scanf("%f", &x->y);
}

void XuatToaDo(Point *x)
{
    printf("(%f, %f)", x->x, x->y);
}

float TinhDoDai(Point *x, Point *y)
{
    return (float)sqrt(pow((y->x - x->x), 2) + pow((y->y - x->y), 2));
}
int main(int argc, char const *argv[])
{
    Point A, B;
    printf("Nhap toa do diem A: ");
    NhapToaDo(&A);
    printf("Nhap toa do diem B:");
    NhapToaDo(&B);

    float ab = TinhDoDai(&A, &B);

   printf("Do dai AB = %.2f",ab);
    return 0;
}

