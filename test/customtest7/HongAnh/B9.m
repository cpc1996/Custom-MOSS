clear; clc; close all;
eq1='DN1=-ld1*N1'; int1='N1(0)=N0';
eq2='DN2=ld1*N1-ld2*N2'; int2='N2(0)=0';
eq3='DN3=ld2*N2'; int3='N3(0)=0';
sol=dsolve(eq1,eq2,eq3, int1,int2 ,int3);
N0=10000; ld1=0.01; ld2=0.005;
N1t=subs(sol.N1); N2t=subs(sol.N2); N3t=subs(sol.N3);
fplot(N1t,[0 1000],'r'); hold on;
fplot(N2t,[0 1000],'b');
fplot(N3t,[0 1000],'m'); hold off;

% Chain - decay Processes
% (1) --T1--> (2) --T2--> (3) --T3--> (4) | stable
% N0 0 0 0
N0=1e6;
% p=~1/T=ln2/T=lamda
T1=6.7; p1=log(2)/T1; t=1:15*T1;T2=12.4; p2=log(2)/T2;T3=9.44; p3=log(2)/T3;
N1=ones(1,N0);N2=zeros(1,N0);N3=N2; N4=N2;
for k=1:length(t)
r1=rand(1,N0);N1p=N1&(r1<=p1);
N1=N1&(r1>p1);n1(k)=sum(N1);
r2=rand(1,N0);N2p=N2&(r2<=p2);
N2=(N2&(r2>p2))|N1p;n2(k)=sum(N2);
r3=rand(1,N0);N3p=N3&(r3<=p3);
N3=(N3&(r3>p3))|N2p;n3(k)=sum(N3);
N4=N4|N3p;n4(k)=sum(N4);
end
plot([0 t],[N0 n1],'b'); hold on;
plot([0 t],[0 n2],'r'); plot([0 t],[0 n3],'k');plot([0 t],[0 n4],'m'); hold off
