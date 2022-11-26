#include<stdio.h>
#include<string.h>
main()
{
	char xau[100],a;
	int i,count;	
    puts("Nhap vao mot xau ki tu :");
 	gets(xau);
 	printf("\nXau ki tu la :|%s|",xau);
 	printf("\nTong so ki tu co trong chuoi x la : %d\n",strlen(xau));
    puts("Nhap mot ki tu can viet hoa");
    scanf("%c",&a);
    for(i=0;i<strlen(xau);i++)
	{	
		if(xau[i]==a)
		{
			xau[i]=toupper(xau[i]);
		}
	}
	printf("\nxau ki tu moi la |%s|",xau);
}
