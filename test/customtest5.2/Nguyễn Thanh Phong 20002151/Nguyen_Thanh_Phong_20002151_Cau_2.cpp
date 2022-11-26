#include <stdio.h>
#include <math.h>
int main ()
{
	int M, N, max, min;
	printf("M=");
	scanf ("%d", &M);
	printf("N=");
	scanf("%d", &N);
 	int a [100] [100];
	int i,j;
 	for (i = 0; i <M; i ++)
 	   {
 	    for (j = 0; j <N; j ++)
 	     {  printf("a[i][j]=");
 	        scanf("%d", &a[i][j]);
 	     }
 	   }
 	for (i = 0; i <M; i ++)
 	   {
 	     for (j = 0; j <N; j ++)
	     {
		  max = a [0] [0];
		  if(max <a [i] [j]) 
		   {
			max = a [i] [j];
		   }
		 }	
	   }
	for ( i = 0; i <M; i ++)
 	 {
 	  for ( j = 0; j <N; j ++)
	    {
		if (a[i][j] == max)
			printf("%d, a[%d][%d] \n", max,i,j);
		}
	  }
	for (int i = 0; i <M; i ++)
 	  {
 	  	for (int j = 0; j <N; j ++)
	    {
		min = a[0][0];
		if (min > a[i][j])
	      min = a[i][j];
	    }
	  }
	for (int i = 0; i <M; i ++)
 	  {
 	  	for (int j = 0; j <N; j ++)
	    {
		if (a[i][j] == min)
		printf ("%d, a[%d][%d]", min, i, j);
	    }
	  }
}
