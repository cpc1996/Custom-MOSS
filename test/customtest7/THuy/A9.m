% Noi suy va xap xi da thuc
clc;clear all;close all;
hs=[-2 -1.5 -1 1 1.5], y=poly2sym(hs); % Ham goc
f=eval(['@(x)',vectorize(y)]);
xi=[166 38.0313 0 -14 -42.0313]; yi=f(xi); % So lieu
% Noi suy: Bac cua da thuc >= so diem du lieu - 1
pp4=polyfit(xi,yi,4); pp5=polyfit(xi,yi,5)
figure(1); ezplot(y, [-1.5 3.5]); hold on; plot(xi,yi,'r*');
xx=linspace(-1.5,3.5,100);
yy4=polyval(pp4,xx); yy5=polyval(pp5,xx);
plot(xx,yy4,'k',xx,yy5,'m');hold off;
legend('Ham goc','So lieu','Da thuc bac 4','Da thuc bac 5');
