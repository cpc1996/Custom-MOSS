clc, close all, clear all
% khai trien taylor
x = input('Nhap goc: ');
y = input('Nhap y (ln(1+y)): ');
N = input('Nhap so lan khai trien: ');

function a = Taylorsin(x,N)
        k=0, fsin=0;
        while(k:N)
                 ak = (-1)^(k-1)*x^(2*k-1)/factorial(2*k-1);
                  fsin=fsin+ak;
                   k=k+1;
        end;
