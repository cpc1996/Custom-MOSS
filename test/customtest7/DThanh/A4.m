clc;close all; clear all;
N=10; % So lan lap
%%khai trien taylor cho ham sin
function [sin]=taylor_sin(f,fsin,ak)
sym x
for k=0:N
ak=((-1)^k).*(x.^(2*k+1))./factorial(2*k+1);
fsin=fsin+ak;
end
fsin,sin(x);
%%khai trien taylor cho ham fsinh
function [fsinh] = taylorsinh(f,fsinh,ak)
sym x
for k=0:N
ak = (x.^(2*k-1))/factorial(2*k-1);
fsinh = fsinh + ak;
end
fsinh,sinh(x);
%%khai trien taylor cho fcosh
function [fcosh] = taylorcosh(f,fcosh,ak)
sym x
for k=0:N
ak = ((x.^(2*k))/factorial(2*k);
fcosh = fcosh + ak;
end
fcosh;
function [fln] = taylorlnx(f,fln,ak)
sym x
for k=0:N
ak = ((-1)^(k-1)).*(x^k)./factorial(k);
fln = fln + ak;
end
fln;
