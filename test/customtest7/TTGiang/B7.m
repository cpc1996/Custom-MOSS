clc; clear all; close all;

%Phan a: bo qua ma sat
des='m*D2x = -k*x'; 
cds='x(0)=x0, Dx(0)=v0';
x=dsolve(des,cds);
m=0.3; k=25; x0=5; v0=10; w=sqrt(k/m);T=2*pi/w;b = 0.5;
xt=subs(x); 
vt=diff(xt);

figure(1)
fplot(xt,[0 5*T],'b'); hold on;
fplot(vt,[0 5*T],'r'); hold off;
legend('x(t)','v(t)');

figure(2); 
ezplot(xt,vt,[0 T]); 
xlabel('x'); ylabel('v');

figure(3); 
Ek=m*vt^2/2; Ep=k*xt^2/2; E=Ek+Ep;
fplot(Ek,[0 5*T],'b'); hold on;
fplot(Ep,[0 5*T],'r');
fplot(E,[0 5*T],'k'); hold off; axis([0 3.5 0 300])

%phan b
des='m*D2x = -k*x-b*Dx'; cds='x(0)=x0, Dx(0)=v0';
x=dsolve(des,cds);
m=1.5; k=15; x0=5; v0=10; b=0.5; 

%gamma
w=sqrt(k/m); T=2*pi/w; xt=subs(x); vt=diff(xt);
figure(4)
fplot(xt,[0 5*T],'b'); hold on;
fplot(vt,[0 5*T],'r'); hold off;
legend('x(t)','v(t)');
title('Do thi khong gian pha gamma khi < 1')

figure(5); 
ezplot(xt,vt,[0 5*T]); 
xlabel('x'); ylabel('v');
xlabel('x'); ylabel('v');
title('Do thi khong gian pha khi gamma > 1');

figure(6); 
Ek=m*vt^2/2; 
Ep=k*xt^2/2; 
E=Ek+Ep;
fplot(Ek,[0 5*T],'b'); hold on;
fplot(Ep,[0 5*T],'r');
fplot(E,[0 5*T],'k'); hold off; 
axis([0 11 0 300])
title('Do thi khong gian pha khi gamma > 1');

%Phan c: 
