clc; clear all;
% phan a
ptvp = 'D2q=-C*q/L';
dkbd = 'q(0)=Q0,Dq(0)=I0';
Q=dsolve(ptvp,dkbd);
C=0.2; L=5; Q0=1.5; I0=2;
w=sqrt(C/L); T=2*pi/w;
Q=subs(Q);
I=diff(Q);
% ve do thi
fplot(Q,[0 20]); title('do thi Q(t)')
% phan b
% dao dong tat dan
ptvp = 'D2q=-q/(L*C)-R*Dq/L';
dkbd = 'q(0)=Q0,Dq(0)=I0';
Q1=dsolve(ptvp,dkbd);
C=1.3; L=4; Q0=2; I0=0; R=0.2;
w=sqrt(C/L); T=2*pi/w;
Q1=subs(Q1); I1=diff(Q1);
figure(2);
fplot(Q1,[0 20]); title('do thi Q(t)'); hold on;
fplot(I1,[0 20]); title('do thi I(t)'); hold off;
legend('Q(t)','I(t)')
Function
[q1,q2,dq2]=Bai_B6(C1,L1,Q01,I01,C2,L2,Q02,I02,R2)
% phan a
ptvp = 'D2q=-C1*q/L1';
dkbd = 'q(0)=Q01,Dq(0)=I01';
Q1=dsolve(ptvp,dkbd);
% C1=0.2; L1=5; Q01=1.5; I01=2;C2=1.3; L2=4; Q02=2;I02=0; R2=0.2;
w=sqrt(C1/L1); T=2*pi/w;
Q1=subs(Q1); q1=simplify(Q1);
I1=diff(Q1);
% ve do thi
fplot(Q1,[0 20]); title('do thi Q(t)')
% phan b
% dao dong tat dan
ptvp = 'D2q=-q/(L2*C2)-R2*Dq/L2';
dkbd = 'q(0)=Q02,Dq(0)=I02';
Q2=dsolve(ptvp,dkbd);
w=sqrt(C2/L2); T2=2*pi/w;
Q2=subs(Q2); I2=diff(Q2);
q2=simplify(Q2);dq2=simplify(I2);
figure(2);
fplot(Q2,[0 20]); title('do thi Q(t)'); hold on;
fplot(I2,[0 20]); title('do thi I(t)'); hold off;
legend('Q(t)','I(t)')

