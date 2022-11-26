#include<stdio.h>
#include<math.h>
#include "stdlib.h"

typedef struct {
	char name[4];
	int win;
	int drawn;
	int lost;
	int point;
}xephang;
main()
{	xephang x[100];
	int i,n;
	FILE *f;
	printf ("nhap n=");scanf ("%d%*c",&n);
	printf ("nhap ket qua cua tung doi bong:\n");
	for (i=0;i<n;i++){
		printf ("nhap ten doi bong:\n"); gets (x[i].name);
		printf ("so tran thang:\n"); scanf ("%d",&x[i].win);
		printf ("so tran hoa:\n "); scanf ("%d",&x[i].drawn);
		printf ("so tran thua:\n"); scanf ("%d%*c",&x[i].lost);
		x[i].point=x[i].win*3  + x[i].drawn;
	} fflush(stdin); 
//xuat ra man hinh//
	printf ("bang xep hang ngoai hang anh:\n");
	for (i=0;i<n;i++){
		
		printf ("\n-------------------------------------------------------------------\n");
		printf ("%s\t	%d\t	%d\t	%d\t 	%d",x[i].name,x[i].win,x[i].drawn,x[i].lost,x[i].point);
	}
	f =fopen("fooball.txt","w");
	if (f==NULL){
		exit (0);
	}
	for (i=0;i<n;i++){
	//	fprintf (f," name	  win		drawn		lost		point");
		fprintf (f,"\n-------------------------------------------------------------------\n");
		fprintf (f,"%s|\t	%d\t	%d\t	%d\t 	%d",x[i].name,x[i].win,x[i].drawn,x[i].lost,x[i].point);
	}
	fclose(f);
}

