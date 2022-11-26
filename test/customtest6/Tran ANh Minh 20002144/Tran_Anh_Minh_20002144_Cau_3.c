#include<stdio.h>
#include<stdlib.h>
int main(){
	int *a, n, i, j;
	int m;
	do{
    	printf("Nhap so phan tu cua mang: ");
    	scanf("%d", &n);
    	if (n <= 0){
        printf("\nn phai la so nguyen duong, Xin nhap lai!\n");
    	}
	} while (n <= 0);
    a = (int *)malloc(n * sizeof(int));
    if (a == NULL)
    {
        printf("\nKhong the cap phat bo nho");
        exit(0);
    }

    printf("\nNhap mang: \n");
    for (i = 0; i < n; i++){
        printf("a[%d] = ", i);
        scanf("%d", a+i);
    }
    for (i=0; i<n-1; i++){
        for (j=i+1; j<n; j++){
            if (a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (i=0; i<n; i++){
    	printf("%d\t", a[i]);
	}
    
}

