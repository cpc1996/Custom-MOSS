#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
 float AC, AB;
 printf("nhap canh AC = ");
 scanf("%f",&AC);
 printf("nhap canh AB = ");
 scanf("%f",&AB);
 float BC, AH;
 BC = sqrt(pow(AC,2)+pow(AB,2)); 
 printf("canh BC= %.3f",BC);
 AH = (AC*AB)/BC;
 printf("\t canh AH = %.3f",AH);
}
