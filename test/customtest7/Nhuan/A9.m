clc; clear all; close all;
syms x;
xi=[-2 -1.5 -1 1 1.5];
yi=[166 38.0313 0 -14 -42.0313];
% Bac 3
F3=[xi(1)^3 xi(1)^2 xi(1)^1 1;...
    xi(2)^3 xi(2)^2 xi(2)^1 1;...
    xi(3)^3 xi(3)^2 xi(3)^1 1;...
    xi(4)^3 xi(4)^2 xi(4)^1 1;...
    xi(5)^3 xi(5)^2 xi(5)^1 1]
Y3=[166;38.0313;0;-14;-42.0313]
a3=pinv(F3)*Y3
y3=poly2sym(a3)
xx=linspace(-2,1.5,100);
yy3=subs(y3,x,xx)
plot(xx,yy3,'k*-'); hold on;
% Bac 4
F4=[xi(1)^4 xi(1)^3 xi(1)^2 xi(1) 1;...
    xi(2)^4 xi(2)^3 xi(2)^2 xi(2) 1;...
    xi(3)^4 xi(3)^3 xi(3)^2 xi(3) 1;...
    xi(4)^4 xi(4)^3 xi(4)^2 xi(4) 1;...
    xi(5)^4 xi(5)^3 xi(5)^2 xi(5) 1]
Y4=[166;38.0313;0;-14;-42.0313]
a4=pinv(F4)*Y4
y4=poly2sym(a4);
ezplot(y4,[-2 1.5]); hold on;
ezplot(x,y4,'r*-'); hold on;
% Bac 5
F5=[xi(1)^5 xi(1)^4 xi(1)^3 xi(1)^2 xi(1) 1;...
    xi(2)^5 xi(2)^4 xi(2)^3 xi(2)^2 xi(2) 1;...
     xi(3)^5 xi(3)^4 xi(3)^3 xi(3)^2 xi(3) 1;...
     xi(4)^5 xi(4)^4 xi(4)^3 xi(4)^2 xi(4) 1;...
     xi(5)^5 xi(5)^4 xi(5)^3 xi(5)^2 xi(5) 1]
Y5=[166;38.0313;0;-14;-42.0313]
a5=pinv(F5)*Y5
y5=poly2sym(a5);
yy5=subs(y5,x,xx);
plot(xx,yy5,'m--');
title('Do thi')
legend('Ham bac 3','Ham bac 4','Ham bac 5');

xi=[-2 -1.5 -1 1 1.5];
yi=[166 38.0313 0 -14 -42.0313];
pp3=polyfit(xi,yi,3)
pp4=polyfit(xi,yi,4)
pp5=polyfit(xi,yi,5)
figure(2);
plot(xi,yi,'r*-'); hold on;
xx=linspace(-2,1.5,100);
yy3=polyval(pp3,xx)
yy4=polyval(pp4,xx)
yy5=polyval(pp5,xx)
plot(xx,yy3,'g'); hold on;
plot(xx,yy4,'k',xx,yy5,'m'); hold off;
legend('So lieu','Da thuc bac 3','Da thuc bac 4','Da thuc bac 5');
