#include <stdio.h>
#include <stdlib.h>

void sapXepTang(int *a, int n)
{
	int i, j;
	int tg; 
    for( i = 0; i < n - 1; i++)
	{
        for( j = i + 1; j < n; j++)
		{
            if(*(a + i) > *(a + j))
			{
                tg = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = tg;        
            }
        }
    }
}

int main()
{
    int *a;
    int n, i, j;
    
    printf("Nhap vao N : ");
	scanf("%d", &n);
	do{
        if(n <= 0)
		{
            printf("\nNhap n > 0 ");
    	}
    }while(n <= 0);
    
    a = (int*)malloc(n*sizeof(int));
    if(a == NULL)
	{
		printf("Khong cap phat bo nho !");
		exit(0); 
	}
	
	printf("Nhap vao phan tu mang : \n");
    for( i = 0; i < n; i++)
	{
        printf("a[%d] = ",i);
        scanf("%d", (a + i));
    }
    printf("Mang vua nhap la : \n");
    for(i = 0 ; i < n ; i++)
    {
    	printf("%5d ", *(a + i));
	}
	
//    int tg; 
//    for( i = 0; i < n - 1; i++)
//	{
//        for( j = i + 1; j < n; j++)
//		{
//            if(*(a + i) > *(a + j))
//			{
//                tg = *(a + i);
//                *(a + i) = *(a + j);
//                *(a + j) = tg;        
//            }
//        }
//    }
	
    sapXepTang(a, n);
    
    printf("\nMang sap xep tang dan la: \n");
    for( i = 0; i < n; i++)
	{
        printf("%5d ", *(a + i));
    }
    
    free(a); 
}


