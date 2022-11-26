function [fsin] = baatapa6(x,N)
        fsin = 0; 
        for k = 1:N
                    tong1 = ((-1)^(k)*x^(2*k+1))/factorial(2*k+1);
                        fsin = fsin + tong1;
        end
        fsin
