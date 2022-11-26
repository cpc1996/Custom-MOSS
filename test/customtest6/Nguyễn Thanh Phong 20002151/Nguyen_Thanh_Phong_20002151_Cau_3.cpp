#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
 

void bubbleSort(int b[], int n)
{
    int i, j;
    bool haveSwap = false;
    for (i = 0; i < n-1; i++){
    
        haveSwap = false;
        for (j = 0; j < n-i-1; j++){
            if (b[j] > b[j+1]){
                swap(b[j], b[j+1]);
                haveSwap = true; 
            }
        }
       
        if(haveSwap == false){
            break;
        }
    }
}
void XuatMang(int b[], int n){
    for(int i = 0; i < n; i++){
        printf("%5d", b[i]);
    }
}

int main()
{
	
  	int n,i;
  	scanf("%d",&n);
  	int *a = new int;
  	a = (int*) malloc(n * sizeof(int));
	for (i=0;i<n;i++)	
		scanf("%d",(a+i));
	int tg;
    for(int i = 0; i < n - 1; i++)
	{
        for(int j = i + 1; j < n; j++)
		{
            if(a[i] < a[j]){
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;        
            }
        }
    }
     printf("\nMang da sap xep theo chieu giam dan la: ");
    for(int i = 0; i < n; i++)
	{
        printf("%5d", a[i]);
	}
	 bubbleSort(a, n);;
    printf("\nMang sap xep tang dan la: ");
    XuatMang(a, n);
}




