clc; clear all;
syms t A w alpha ;
x=A*cos(w*t+alpha); A=20;w=(2*pi)/3;
alpha=pi/2;
x=subs(x); xt=char(x); 
vt=char(diff(x,1)); at=char(diff(x,2));
%a
t=[0 20];
figure(1);
fplot(xt,t,'r' ); hold on; fplot(vt,t, 'b'); fplot(at,t,'g'); hold off;
legend('x(t)','v(t)','a(t)');
figure(2); ezplot(xt,vt); axis equal;
%b
syms lambda A w alpha t;
x=A*exp(-lambda*t)*cos(w*t+alpha);
k=abs(A*exp(-lambda*t));
A=20;w=(2*pi)/3;alpha=pi/2; lambda=0.2;
x=subs(x); k=subs(k);
t=linspace(0, 20);
xt=subs(x); kt=subs(k);
%plot
figure(3);
subplot(211); 
plot(t, xt); hold on;
plot(t, -kt,'r'); plot(t, kt,'r'); hold off;
ylim([-22 22]); xlabel('t'); ylabel('A');
title('ve bang plot');
%ezplot
subplot(212); 
ezplot(x, [0 20]); hold on; l=ezplot(-k, [0 20]);
h=ezplot(k, [0 20]); hold off;
set(h,'color','r'); set(l,'color','r');
ylim([-22 22]); xlabel('t'); ylabel('A');
title('ve bang ezplot')
