#include<stdio.h>
typedef struct 
{
	char name[10];
	int  win;
	int  draw;
	int  lost;
	int point;
}trandau;

int main()
{
	trandau a[100];
	int i,n;
	FILE *f;
	
	printf("nhap vao so doi bong:\n");
	scanf("%d",&n);
	
	printf("nhap thong tin cua cac doi bong:\n");
	for(i=0;i<n;i++);
	{
		printf("nhap vao ten doi bong :");
		gets(a[i].name);
		printf(" nhap so tran win : ");
		scanf("%d",&a[i].win);
		printf("nhap so tran draw");
		scanf("%d",&a[i].draw);
		printf("nhap so tran lost");
		scanf("%d",&a[i].lost);
		
		a[i].point = (a[i].win)*3 + a[i].draw*1;
	}
	puts("thong tin cua cac tran dau la :");
	for(i=0;i<n;i++)
	{
		printf(f,"%d",a[i].point);
		printf("&s.%2f.%2f.%2f.%2f\n",a[i].win,a[i].draw,a[i].lost,a[i].point);
	}
	//MO FILE DE GHI DU LIEU
	f=fopen("fooball.txt","w");
	if(f==NULL)
	{
		return 0;
	}
	for(i=0;i<n;i++)
	{
		fprintf(f,"&s.%2f.%2f.%2f.%2f\n",a[i].win,a[i].draw,a[i].lost,a[i].point);
	}
	fclose(f);
	
	
}
