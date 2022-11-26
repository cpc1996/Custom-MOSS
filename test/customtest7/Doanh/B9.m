clear; clc; close all;
eq1='DN1=-ld1*N1'; 
int1='N1(0)=N0';
eq2='DN2=ld1*N1-ld2*N2'; 
int2='N2(0)=0'; 
sol=dsolve( eq1,eq2,int1,int2 );
N0=10000; 
ld1=0.62; 
ld2=0.67;
N1t=subs(sol.N1); N2t=subs(sol.N2);
fplot(N1t,[0 1000],'r'); hold on;
fplot(N2t,[0 1000],'b'); hold off

N0=1e4;
% p=~1/T=ln2/T=lamda
T1=14.8; 
p1=log(2)/T1; 
t=1:15*T1;
T2=16.1; 
p2=log(2)/T2;
N1=ones(1,N0);
N2=zeros(1,N0);

for k=1:length(t)
        r1=rand(1,N0);
        N1p=N1&(r1<=p1);
        N1=N1&(r1>p1);
        n1(k)=sum(N1);
        r2=rand(1,N0);
        N2p=N2&(r2<=p2);
        N2=(N2&(r2>p2))|N1p;n2(k)=sum(N2);
end
plot([0 t],[N0 n1],'b'); hold on;
plot([0 t],[0 n2],'r'); hold off
