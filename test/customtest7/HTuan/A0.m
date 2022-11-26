clc; close all; clear all;
figure(1);
syms t;
A = 20; w = 2*pi/3; phi = pi/2
x = A*cos(w*t + phi);
fplot(x,[0,20],'k');
hold on;
v = diff(x,'t');
fplot(v,[0,20],'g');
a = diff(x,2);
fplot(a,[0,20],'m');
legend('x(t)','v(t)','a(t)');
figure(2);
ezplot(x,v,[0,20]);

t = linspace(0,20);
x1 = 30.*exp(-0.2.*t).*cos(pi/3.*t + pi/2);
x2 = @(t) 30.*exp(-0.2.*t)*cos(pi/3.*t + pi/2);
aa = @(t) 30.*exp(-0.2.*t);
figure(2);
subplot(2,1,1); plot(t,x1);
xlabel('t'); ylabel('x'); title('ve bang lenh plot');
subplot(2,1,2); ezplot(x2,[0,20]);
xlabel('t'); ylabel('x'); title('ve bang lenh ezplot');
