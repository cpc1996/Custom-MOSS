%Phan a
function sopi = sopihitormiss(N)
        x=rand(1,N); 
        y=rand(1,N);
        n=0;
        for k=1:N
                    if (x(k).^2+y(k).^2<1)n=n+1;
                    end
        end
        sopi=4*n/N;

%phan b
clc; close all; clear all;
A=[];
i=1;
Tong=0;
M=200;
for k=1:M
    N=10^4; x=rand(1,N); y=rand(1,N);
    n=0;

    for k=1:N
        if(x(k).^2+y(k).^2<1)
            n=n+1;
        end
    end
    sopi=4*n/N;
    A(i)=sopi;
    i=i+1;
    Tong=Tong+sopi;
    pi_tb=Tong/(i-1);
end
pi_tb
j=0;
for k=1:M
    j=(A(k)-pi_tb)^2+j;
end
dolechchuan=sqrt(j/(i-2))
