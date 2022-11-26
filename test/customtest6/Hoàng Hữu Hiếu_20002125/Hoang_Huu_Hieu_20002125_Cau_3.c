#include<stdio.h>

int snto(int n) 
{
    
    if (n < 2) {
        return 0;
    }
    
    int k =  sqrt(n);
    int i;
    for (i = 2; i <= k; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() 
{
	 int N1, N2,i;
	Ab: printf(" Nhap 2 so nguyen duong N1, N2(N2 >N1):\n");
	    scanf(" %d %d", &N1,&N2);
	    if ( N1 <=0 || N2 <= 0 || N1> N2 ) goto Ab;
	    printf( " Khoang can xet la: [%d ; %d] !\n ", N1, N2);
	
    printf("Cac so khong la so nguyen to trong khoang [%d ; %d ] la: \n", N1, N2);
    for (i = N1; i <=N2; i++) {
        if (snto(i)==0) {
            printf(" %d ", i);
        }
    }
}