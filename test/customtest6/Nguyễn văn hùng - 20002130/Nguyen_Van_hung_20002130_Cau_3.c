#include <stdio.h>
#include <string.h>

typedef struct {
	char name[40];
	int Win;
	int Draw;
	int Lost;
	int Point;
} football;

int main()
{
    football a[100];
    int i,j;
	FILE *f;
	fflush(stdin);
	
	for(i=0; i<4; i++)
	{
		printf("Nhap ten CLB: ");
		gets(a[i].name);
		printf("Nhap so tran thang: ");
		scanf("%d", &a[i].Win);
		printf("Nhap so tran hoa: ");
		scanf("%d", &a[i].Draw);
		printf("Nhap so tran thua: ");
		scanf("%d%*c",&a[i].Lost);
		a[i].Point = a[i].Win * 3 + a[i].Draw * 1 + a[i].Lost * 0;
	}
	
	for(i = 0; i< 4;i++)
	{
		printf("\n");
		printf("%s %d %d %d %d\n",a[i].name,a[i].Win,a[i].Draw,a[i].Lost,a[i].Point);
	}
		
	f = fopen("football.txt","w");
	if(f == NULL)
	{
		return 0;
	}
	for(i = 0; i < 4; i++)
	{
		fprintf(f,"------------------------\n");
		fprintf(f,"%s %d %d %d %d\n",a[i].name,a[i].Win,a[i].Draw,a[i].Lost,a[i].Point);
	}
	fclose(f);
}
