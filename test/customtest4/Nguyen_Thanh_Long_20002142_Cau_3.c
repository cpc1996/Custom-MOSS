#include<stdio.h>
#include <stdio.h>
 
 int main(int argc, char const *argv[])
 {
     int c;
     char s[100];
 
    printf("c = "); scanf("%d", &c);
    printf("s = ");
    fgets(s, 100, stdin);
    if (strlen(s) > 0) 
        if (s[strlen(s) - 1] == '\n');
            s[strlen(s) - 1] = 0;

    printf("c = %d\n", c);
    printf("s = %s\n", s);
   
    return 0;
}

