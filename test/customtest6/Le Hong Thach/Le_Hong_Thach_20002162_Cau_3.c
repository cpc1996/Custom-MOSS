#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main(){
		char a[100];
	int x;
	int i,k,j,h,n;
	int count;
	printf("nhap xau ki tu: ");
	gets(a);
	printf("xau do la: |%s|", a);
	while(a[strlen(a)-1]==' ')
	a[strlen(a)-1]='\0';
	while(a[0]==' ')
	strcpy(&a[0],&a[1]);
	i=0;k=0;
	for(i=0;a[i]!='\0';i++){
	
		if( !((a[i]==' ')&&(a[i+1]==' '))  ){
			a[k]=a[i];
			k++;
		}
	}
	a[k]='\0';
	count=0;
	for(i=0;i<strlen(a);i++){
		if((a[i]!=' ')&&(a[i+1]==' ')){
			count++;
		}
	}
	printf("\nso tu trong xau: %d", count+1);
	printf("\nchon vi tri tu: ");
	scanf("%d", &x);
	j=0;
	h=1;
	n=0;
	if(x<=count){
	for(i=0;i<strlen(a);i++){
		if(a[i]!=' '&&a[i+1]==' '){
			h++;
			if(h==x){
				j=2+i;
				for(j=2+i;a[j]!=' ';j++){
					a[j]=toupper(a[j]);
					n++;
				}
			}
		}
	}
	}
	printf("|%s|",a);
}
