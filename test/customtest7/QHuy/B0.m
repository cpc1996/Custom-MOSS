function [sopi]=hisormiss(N)
        h=ezplot('x^2+y^2-1',[0 1]);
        set(h,'color','b'); 
        x=rand(1,N);y=rand(1,N);
        hold on;plot(x,y,'*r');
        n=0;
        for k=1:N
                    if(x(k).^2+y(k).^2<1)
                                    n=n+1
                                        end
        end
        sopi=1*n/N;
