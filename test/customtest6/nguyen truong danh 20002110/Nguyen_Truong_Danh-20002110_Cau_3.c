#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main(){
    int n,i,s=0;
    char a[30];

    printf("nhap vao so nguyen duong n: ");
    scanf("%d",&n);
   
   itoa(n,a,10);
    for(i=0;i<strlen(a)/2;i++){
        int h=a[i];
        a[i]=a[strlen(a)-i-1];
        a[strlen(a)-1-i]=h;
    }
    printf("so duong sau khi dao la: ");
    puts(a);

    for(i=0;i<strlen(a);i++){
        s+= (a[i]-48);

    }
    printf("tong la: %d",s);


}
