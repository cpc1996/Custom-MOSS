clc; clear all; close all;
%dao dong tu tuyen tinh
%dao dong dieu hoa co ma sat
des='D2x=-w0^2*x-b*Dx+F0*cos(w1*t)'; %gamma=b
cds='x(0)=x0,Dx(0)=v0';
x=dsolve(des,cds);
w0=2; b=0.1; T=2*pi/w0;
x0=0;v0=0; %gt m=1;
F0=1; w1=1.9;
xt=simplify(subs(x)); vt=diff(xt);
syms t;
A=inline(vectorize(xt),'t');
tmax=fminsearch(A,10*T);
A_max=abs(A(tmax))
% ve do thi
figure(1);
fplot(xt,[0 15*T],'b'); hold on;
fplot(vt,[0 15*T],'r'); hold off;
legend('xt','vt');
figure(2);
ezplot(xt,vt,[0 15*T]); axis equal;
xlabel('x'); ylabel('y');
Ek1=vt^2/2; Ep1=w1^2*xt^2/2; E1=Ek1+Ep1;
figure(3);
fplot(Ek1,[0 15*T],'b'); hold on;
fplot(Ep1,[0 15*T],'r'); 
fplot(E1,[0 15*T],'k'); hold off;
legend('Ek','Ep','Et');
%w1=1.5:0.1:2.5
w1=1.5:0.1:2.5; w1=w1(:);
xt2=subs(x);
syms t;
for k=1:length(w1)
            A=inline(vectorize(xt2(k,1)),'t');
                tmax=fminsearch(A,10*T);
                    A_max(k)=abs(A(tmax));
end
w_biendo=[w1 A_max(:)]
figure(4)
plot(w1,A_max,'-*r');
