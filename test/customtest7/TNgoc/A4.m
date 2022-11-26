function a = Taylor_sin(x,N,an1)
        n=1; an = 1; S = 0;
        while (abs(an)>= an1) & (n <= N)
                an = (-1)^(n-1)*x^(2*n-1)/factorial(2*n-1);
                S = S + an;
                n = n +1;
        end
        a = S
