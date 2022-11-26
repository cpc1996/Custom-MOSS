#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
main()
{
    char x[100];
    int i,k,h;
    int vitrixoa;

    printf("Nhap xau ki tu:");
    gets(x);
    printf("in ra chuoi ky tu: |%s|\n",x);

    k= strlen(x);
    printf("so ki tu: %d\n",k);
    
    while(x[i]==' ')
    	i++;
    strcpy(&x[0],&x[i]);

    i=0;
    while(x[strlen(x)-1] == ' ')
    x[strlen(x)-1]='\0';

    i=0;h=0;
    while(x[i]!='\0')
    {
        if(!((x[i]==' ')&&(x[i+1]==' ')))
        {
            x[h]=x[i];
            h++;
        }
        i++;
    }
    x[h]='\0';
    
    for(i=0;i<strlen(x)-1;i++){
        x[i]=tolower(x[i]);
    }
    
    x[0]=toupper(x[0]);
    printf("chuoi sau khi chuan hoa la:'%s'\n",x);
    i=1;
    while(x[strlen(x)-i]!=' ')
    {
        x[strlen(x)-i]='*';
        i++;
    }
    printf("Chon vi tri can xoa: ");
    scanf("%d",&vitrixoa);
    for( i= vitrixoa +1; i<k; i++) {
    	x[i-1]=x[i];
	}
	x[strlen(x)-1]='\0';
	printf("\nChuoi sau khi xoa 1 tu tai vi tri chi dinh: ");
	for(i=0; i<k; i++){
		printf("%s",x);
	}
}
