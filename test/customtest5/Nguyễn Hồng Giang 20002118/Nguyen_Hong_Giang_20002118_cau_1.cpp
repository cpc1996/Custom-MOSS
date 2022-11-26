#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;


int main()
{
   
    float xA, yA, xB, yB, d;

   
    cout<<"Nhap vao hoanh do diem A: "; cin>>xA;
    cout<<"Nhap vao tung do diem A: "; cin>>yA;

    cout<<"Nhap vao hoanh do diem B: "; cin>>xB;
    cout<<"Nhap vao tung do diem B: "; cin>>yB;

    
    d = sqrt((xB - xA)*(xB - xA) + (yB - yA)*(yB - yA));

 
    printf("Khoang cach giua 2 diem A va B la: %0.2f", d);

    cout<<endl;
    return 0;
}
