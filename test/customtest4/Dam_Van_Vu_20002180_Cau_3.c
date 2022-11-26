#include<stdio.h>
#include<math.h>

int kiemTraSoNguyenTo(int n){
	int i;
	if(n<2){
		return 0;	
	} else{
		for(i=2; i<=sqrt(n); i++){
			if(n%i == 0){
				return 0;
			}
		}
		return 1;
	}
}
int main(){
	int i, j, n, N1, N2;
	int kiemTra = 1;
//nhapCoKiemTra	
	do{
		printf("Nhap N1, N2 (N1<N2): ");
		scanf("%d%d", &N1, &N2);
	} while (N1>N2 || N1<0 || N2<0);
//kiemTraSoNguyenTo	
	printf("Nhap n: ");
	scanf("%d", &n);
	int ketqua = kiemTraSoNguyenTo(n);
	if (ketqua == 1){
		printf("%d la So Nguyen To", n);
	}else{
		printf("%d la khong La So Nguyen To", n);	
	}
//inRaNhungSoKhongPhaiSNT
	printf("\nNhung so khong phai So Nguyen to la: ");
	for(i=N1; i<N2; i++){
		if(kiemTraSoNguyenTo(i) == 0){
			printf("%5d", i);	
		}
	}
	return 0;
}
