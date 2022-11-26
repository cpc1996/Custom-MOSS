#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i,*a,s=0;
    
    printf("nhap vao so phan tu cua mang: ");
    scanf("%d",&n);

    a=(int*)malloc(n*sizeof(int));

    if(a==NULL){
        exit(0);
    }

    for(i=0;i<n;i++){
        *(a+i)=i*i+2;
    }

    for(i=0;i<n;i++){
        if(*(a+i)%3==0){
            s+=*(a+i);
        }
    }

    printf("cac phan tu cua mang la:");
    for(i=0;i<n;i++){
        printf("%d  ",*(a+i));
    }

    printf("\ntong la: %d ",s);

}