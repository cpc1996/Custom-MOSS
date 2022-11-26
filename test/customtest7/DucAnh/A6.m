function [sin_x]= f_sin(x)
        N=input('Nhap N=  ');
        fsin=0;
        for k=0:N
                     ak=(((-1)^k).*x.^(2.*k+1))./(factorial(2.*k+1));
                          fsin = fsin + ak;
        end
        fsin
end

 
function [cosh_x]=f_cosh(x)
        N=input('Nhap N=  ');
        fcosh=1;
        for k=1:N
                    ak= (x.^(2.*k))./factorial(2.*k);
                        fcosh =fcosh + ak;
        end;
        fcosh
end
