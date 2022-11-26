%Ham sin(x)
function a = Taylor_cos(x,N,an1)
n = 1; an = 1; S = an;
while (abs(an)>= an1) & (n <= N)
    an = (-1)^n*x^(2*n)/factorial(2*n);
    S = S + an;
    n = n+1;
end
a = S

