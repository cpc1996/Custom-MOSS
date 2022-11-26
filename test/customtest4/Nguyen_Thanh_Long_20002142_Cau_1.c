#include<stdio.h>
#include<math.h>
  int main()
	struct DIEM
{
	int x;
	int y;
};

void NhapToaDo 

	cout<<"Nhap y: "; cin>> d.x;
	cout<<"Nhap x: "; cin>> d.y;


void XuatToaDo(DIEM d)
{
	cout<<"("<<d.y<<","<<d.x<<")";
}

double KhoangCach(DIEM d1, DIEM d2)
{
	double kc;
	kc=sqrt(double(d1.y-d2.y)*(d1.y-d2.y)+(d1.x-d2.x)*(d1.x-d2.x));
	return kc;
}

void main()
{
	DIEM Diem1, Diem2;
	double KhoangCach;
	cout<<"Diem A:\n";
	NhapToaDo(Diem1);

	cout<<"\nDiem B: \n";
	NhapToaDo(Diem2);

	cout<<"\nToa do A la: ";
	XuatToaDo(Diem1);

	cout<<"\nToa do  B la: ";
	XuatToaDo(Diem2);

	KhoangCach=KhoangCach(Diem1,Diem2);
	cout<<"\nKhoang cach giua diem A va diem B la: "<<KhoangCach;
	
	cout<<endl;
}
	return 0;
	
		
	
		
	
