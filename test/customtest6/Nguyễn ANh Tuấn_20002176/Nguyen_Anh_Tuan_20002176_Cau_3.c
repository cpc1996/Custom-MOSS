#include<stdio.h>
#include<string.h>
#include<conio.h>
void chuanhoa(char s[])
{
	int i;
	while (s[0]==' ') strcpy(&s[0], &s[1]);
	for (i=0;i<strlen(s);i++)
	if(s[i]==' '&&s[i+1]==' ')
	{
	strcpy(&s[i], &s[i+1]);
	i--;}
	while (s[strlen(s)-1]==' ') strcpy(&s[strlen(s)-1], &s[strlen(s)]);
	
}
main()
{
	char s[200],k[200],x,c;
	printf("nhap chuoi s ");
	gets(s);
	printf("nhap chuoi k ");
	gets(k);
	chuanhoa(s);
	chuanhoa(k);
	printf("/%s/",s);
		printf("\n/%s/",k);
		printf("Nhap tu can chon: ");
	scanf("%c",&x);
	int i;
	for(i =0 ; i< strlen(s);i++){
		if(s[i] == x ){
			c = i;
			if(s[i] + 32 == tolower(x)){
				printf("Khong can viet hoa");
				break;
			}
			else{
				s[i] = s[i] - 32;
			}
		}
	}
	printf("\nChuoi sau khi xu li la :");
	puts(s);

}

