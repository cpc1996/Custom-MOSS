#include<stdio.h>
#include<string.h>
main()
{
    char x[100];
    int i,k,h;
	
	//cau a
    printf("Nhap xau ki tu:");
    gets(x);
    printf("in ra chuoi ky tu: |%s|\n",x);
	
	//caub
    k= strlen(x);// do dai chuoi= so ky tu
    printf("so ki tu: %d\n",k);
    
    // neu phan tu thu i cua chuoi bat dau = dau trang thi ta ghep dau trang voi phan tu thu 0 de khi xoa khoang trang o dau ta se chi con kitu chu
    while(x[i]==' ')
    	i++;
    strcpy(&x[0],&x[i]);

    // xoa dau trang o cuoi chuoi
    i=0;
    while(x[strlen(x)-1] == ' ')
    x[strlen(x)-1]='\0';

	//xoa dau trang o dau va giua chuoi
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
    
    // chuyen thanh chu hoa
    x[0]=toupper(x[0]);
    
    printf("chuoi sau khi chuan hoa la:'%s'\n",x);
    i=1;
    while(x[strlen(x)-i]!=' ')
    {
        x[strlen(x)-i]='*';
        i++;
    }
    
    
}
