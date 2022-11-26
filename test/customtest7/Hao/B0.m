function sopi = sopi(N)
        x=rand(1,N); y=rand(1,N);
        n=0;
        for k=1:N
                    if (x(k).^2 +y(k).^2<1)n=n+1;
                                end
        end
        sopi=4*n/N
