#include<stdio.h>
int main()
{	// nhap ma tran
	int i,j,m,n,min,max,imin,imax,jmin,jmax;
	printf("Nhap so m,n=");	scanf("%d%d",&m,&n);
	int a[100][100];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("x[%d][%d]=", i+1, j+1);
			scanf("%d",&a[i][j]);
		}
	}		
	min=a[0][0]; imin=0; jmin=0;
	max=a[0][0]; imax=0; jmax=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(min>a[i][j]){
				imin=i;
				jmin=j;
				min=a[i][j];
			}
			if(max<a[i][j]){
				imax=i;
				jmax=j;
				max=a[i][j];
			}
		}
	}	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[i][j]<min){
				min = a[i][j];
			}
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[i][j]>max){
				max = a[i][j];
			}
		}
	}
	printf("ma tran la : \n");
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
			printf("%d  ",a[i][j]);
		printf("\n");
	}	
	printf("\nPhan tu lon nhat la %d",max);
	printf("\nPhan tu nho nhat la %d",min);
	printf("\nVi tri phan tu min a[%d][%d]",imin+1,jmin+1);
	printf("\nVi tri phan tu max a[%d][%d]",imax+1,jmax+1);
}

