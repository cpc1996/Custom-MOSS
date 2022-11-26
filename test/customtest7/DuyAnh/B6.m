clc; clear all; close all;
%a.
ptvp = 'D2q = -q/C1';
dkbd = 'q(0) = Q01,Dq(0) = I01';
Q1 = dsolve(ptvp,dkbd);
C1=0.2;
L1=5;
Q01=1.5;
I01=2;
w=sqrt(C1/L1);
T=2*pi/w;
Q1=subs(Q1);
I1=diff(Q1);
figure(1)
fplot(Q1,[0 20]); title('Do thi Q(t)')
%b.
ptvp = 'D2q= (-q/C2)-(R2*Dq)';
dkbd = 'q(0)=Q02, Dq(0)=I02';
Q2=dsolve(ptvp,dkbd);
C2=1.3;
L2=4;
Q02=2;
I02=0;
R2=0.2;
w=sqrt(C2/L2);
T=2/pi/w;
Q2=subs(Q2);
I2=diff(Q2);
figure(2)
fplot(Q2, [0 20]); hold on;
fplot(I2, [0 20]); hold off;
legend('Q(t)','I(t)')
