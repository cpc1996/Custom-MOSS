/*cho tam giac ABC vuong o A co duong cao AH. Viet chuong trinh
Nhap AC,AB tu ban phim
Tinh BC,AH. In ket qua ra man hinh(giu 3 chu so phan thap phan cua ket qua)
*/
#include<stdio.h>
#include<math.h>
main()
{
	float Xa,Ya,Xb,Yb,Xc,Yc,Xh,Yh;
//nhap toa do 3 dinh cua tam giac ABC, diem H
	printf("\nnhap toa do dinh A:\n");
	scanf("%f  %f",&Xa,&Ya);
	printf("\nnhap toa do dinh B:\n");
	scanf("%f  %f",&Xb,&Yb);
	printf("\nnhap toa do dinh C:\n");
	scanf("%f  %f",&Xc,&Yc);
	printf("\nnhap toa do diem H:\n");
	scanf("%f  %f",&Xh,&Yh);
//toa do AB,AC
	printf("\ntoa do AB=(%.f,%.f)",Xb-Xa,Yb-Ya);	
	printf("\ntoa do AC=(%.f,%.f)",Xc-Xa,Yc-Ya);
//tinh BC,AH
	float AB,AC,BC;
	AB=sqrt(pow((Xb-Xa),2) + pow((Yb-Ya),2));
	AC=sqrt(pow((Xc-Xa),2) + pow((Yc-Ya),2));
	BC=sqrt(pow((Xc-Xb),2) + pow((Yc-Yb),2));
	printf("\nBC=%.3f",BC);
	printf("\nAH=%.3f",(AB*AC)/BC);

}


