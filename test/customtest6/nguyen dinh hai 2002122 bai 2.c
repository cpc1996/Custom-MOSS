#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void doAction(char *src, int pos, int len) {
	int i;
	int size = strlen(src);
	for(i = pos; i <= size - len; i++) {
		src[i] = src[i + len];
	}
}

void removeStr(char *src, char *m) {
	int i;
	int len = strlen(m);
	for(i = 0; src[i] != '\0'; i++) {
		if(strstr(&src[i], m) == &src[i]) {
			doAction(src, i, len);
			i --;
		}
	}
}

int main() 
{
    char n[1000];
    char m[100];
    
    printf("nhap chuoi:");
    fgets(n, 999, stdin);
    printf("xuat:");
	puts(n);
	
	printf("nhap tu can xoa:");
    fgets(m, 99, stdin);
    printf("xuat:");
    puts(m);
    
    int len = strlen(m);
    if(len > 0)
    {
    	m[len - 1] = '\0';
	}
	
	int size = strlen(n);
	if(n > 0)
	{
		n[size - 1] = '\0';
	}
	
    removeStr(n,m);
    puts(n);
    return 0;
}
