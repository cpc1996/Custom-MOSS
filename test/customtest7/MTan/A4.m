function
        clc, close all, clear all
        % khai trien taylor
        x = input('Nhap goc: ');
        y = input('Nhap y (ln(1+y)): ');
        N = input('Nhap so lan khai trien: ');

        % sinx
        fsin = 0; 
        for k = 1:N
                    tong1 = ((-1)^(k)*x^(2*k+1))/factorial(2*k+1);
                        fsin = fsin + tong1;
        end
