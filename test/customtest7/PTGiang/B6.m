clc; clear all;
% Phan a
ptvp = 'D2q=-C*q/L';
dkbd = 'q(0)=Q0,Dq(0)=I0';
Q=dsolve(ptvp,dkbd);
C=0.1; L=4; Q0=1.5; I0=2;
w=sqrt(C/L);
T=2*pi/w;
Q=subs(Q);
I=diff(Q);
% Ve do thi
fplot(Q,[0 10]); 
title('do thi Q(t)')
% Phan b
% Dao dong tat dan
ptvp = 'D2q=-q/(L*C)-R*Dq/L';
dkbd = 'q(0)=Q0,Dq(0)=I0';
Q1=dsolve(ptvp,dkbd);
C=1.3; L=4; Q0=3; I0=0; R=1.2;
w=sqrt(C/L);
T=2*pi/w;
Q1=subs(Q1); 
I1=diff(Q1);
figure(2);
fplot(Q1,[0 20]); title('do thi Q(t)'); hold on;
fplot(I1,[0 20]); title('do thi I(t)'); hold off;
legend('Q(t)','I(t)')
% Phan C bien do giam theo ham e mu
