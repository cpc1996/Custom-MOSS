clc; clear all; close all;
syms x
%a.
figure(1)
xi=[-2 -1.5 -1 1 1.5];
yi=[166 38.0313 0 -14 -42.0313];
plot(xi,yi,'+r');hold on;
xx = linspace(-20,20,500);
%da thuc bac 3
P3 =[xi(1)^3 xi(1)^2 xi(1)^1 1;
 xi(2)^3 xi(2)^2 xi(2)^1 1;
 xi(3)^3 xi(3)^2 xi(3)^1 1;
 xi(4)^3 xi(4)^2 xi(4)^1 1;
 xi(5)^3 xi(5)^2 xi(5)^1 1];
Y3='yi';
a3i=pinv(P3)*Y3;
y3 =subs(poly2sym(a3i),x,xx);
plot(xx,y3,'m'); 
%da thuc bac 4
P4=[xi(1)^4 xi(1)^3 xi(1)^2 xi(1) 1;
 xi(2)^4 xi(2)^3 xi(2)^2 xi(2) 1;
 xi(3)^4 xi(3)^3 xi(3)^2 xi(3) 1;
 xi(4)^4 xi(4)^3 xi(4)^2 xi(4) 1;
 xi(5)^4 xi(5)^3 xi(5)^2 xi(5) 1];
Y4='yi';
a4i=pinv(P4)*Y4;
y4 =subs(poly2sym(a4i),x,xx);
plot(xx,y4,'k')
%da thuc bac 5
P5=[xi(1)^5 xi(1)^4 xi(1)^3 xi(1)^2 xi(1) 1;
 xi(2)^5 xi(2)^4 xi(2)^3 xi(2)^2 xi(2) 1;
 xi(3)^5 xi(3)^4 xi(3)^3 xi(3)^2 xi(3) 1;
 xi(4)^5 xi(4)^4 xi(4)^3 xi(4)^2 xi(4) 1;
 xi(5)^5 xi(5)^4 xi(5)^3 xi(5)^2 xi(5) 1];
Y5='yi';
a5i=pinv(P5)*Y5;
y5 = subs(poly2sym(a5i),x,xx);
plot(xx,y5,'b');
legend('du lieu','Bac 3', 'Bac 4', 'Bac 5');
%b.
figure(2)
pp3=polyfit(xi,yi,3);
pp4=polyfit(xi,yi,4);
pp5=polyfit(xi,yi,5);
plot(xi,yi,'+r'); hold on;
yi3=polyval(pp3,xx);
yi4=polyval(pp4,xx);
yi5=polyval(pp5,xx);
plot(xx,yi3,'m',xx,yi4,'k',xx,yi5,'b'); hold off;
legend('du lieu','Bac 3', 'Bac 4', 'Bac 5');
