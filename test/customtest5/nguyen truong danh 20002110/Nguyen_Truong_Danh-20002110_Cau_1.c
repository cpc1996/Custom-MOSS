#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i;
    float x,s=1;
    
    printf("nhap vao so nguyen duong n: ");
    scanf("%d",&n);
    
    while(n<0){
        printf("moi nhap lai: ");
        scanf("%d",&n);
    }

    printf("nhap vao so x: ");
    scanf("%f",&x);

    for(i=1;i<=n;i++){
        s*=x;
    }

    printf(" ket qua cua x mu n la: %.4f",s);

}