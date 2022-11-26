clc; clear all; close all;
des='m*D2x = -k*x'; cds='x(0)=x0, Dx(0)=v0';
x=dsolve(des,cds);
m=0.3; k=25; x0=5; v0=10; w=sqrt(k/m);T=2*pi/w;
xt=subs(x); vt=diff(xt);
figure(1)
fplot(xt,[0 5*T],'b'); hold on;
fplot(vt,[0 5*T],'r'); hold off;
legend('x(t)','v(t)');
figure(2); ezplot(xt,vt,[0 T]); xlabel('x'); ylabel('v');
figure(3); Ek=m*vt^2/2; Ep=k*xt^2/2; E=Ek+Ep;
fplot(Ek,[0 5*T],'b'); hold on;
fplot(Ep,[0 5*T],'r');
fplot(E,[0 5*T],'k'); hold off; axis([0 11 0 300])
