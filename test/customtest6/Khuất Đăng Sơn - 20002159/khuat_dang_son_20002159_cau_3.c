#include<stdio.h>
#include<string.h>
main()
{
	char x[100],a;
	int i,count;
    
    puts("moi ban nhap vao mot xau ki tu :");
 	gets(x);
 	printf("\nxau ki tu la :|%s|",x);
 	
 	//Chuan hoa ki tu
    puts("moi ban nhap mot ki tu can viet hoa");
    scanf("%c",&a);
    for(i=0;i<strlen(x);i++)
	{	
		if(x[i]==a)
		{
			x[i]=toupper(x[i]);
		}
	}
	printf("\nxau ki tu moi la |%s|",x);
}
