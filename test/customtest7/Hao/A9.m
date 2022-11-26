clc; clear all, close all;
x = [-2 -1.5 -1 1 1.5];
y = [166 38.0313 0 -14 -42.0313];
%phan a
%Noi suy bac ba
A3 = [ x(1)^3 x(1)^2 x(1) 1;...
       x(2)^3 x(2)^2 x(2) 1;...
       x(3)^3 x(3)^2 x(3) 1;...
       x(4)^3 x(4)^2 x(4) 1;...
       x(5)^3 x(5)^2 x(5) 1];
 aa3 = pinv(A3)*y(:)
 y3= @(x) aa3(1)*x^3 + aa3(2)*x^2 + aa3(3)*x + aa3(4)
%Noi suy bac 4
A4 = [ x(1)^4 x(1)^3 x(1)^2 x(1) 1;...
       x(2)^4 x(2)^3 x(2)^2 x(2) 1;...
       x(3)^4 x(3)^3 x(3)^2 x(3) 1;...
       x(4)^4 x(4)^3 x(4)^2 x(4) 1;...
       x(5)^4 x(5)^3 x(5)^2 x(5) 1];
 aa4 = pinv(A4)*y(:)
 y4= @(x) aa4(1)*x^4 + aa4(2)*x^3 + aa4(3)*x^2 + aa4(4)*x + aa4(5)
%Noi suy bac 5
A5 = [ x(1)^5 x(1)^4 x(1)^3 x(1)^2 x(1) 1;...
       x(2)^5 x(2)^4 x(2)^3 x(2)^2 x(2) 1;...
       x(3)^5 x(3)^4 x(3)^3 x(3)^2 x(3) 1;...
       x(4)^5 x(4)^4 x(4)^3 x(4)^2 x(4) 1;...
       x(5)^5 x(5)^4 x(5)^3 x(5)^2 x(5) 1];
 aa5 = pinv(A5)*y(:)
 y5= @(x) aa5(1)*x^5 + aa5(2)*x^4 + aa5(3)*x^3 + aa5(4)*x^2 + aa5(5)*x + aa5(6)
 %Ve do thi
figure (1)
x1 = linspace (-2,-1.5,100);
plot(x,y,'*r'); hold on;
ezplot (y3, [-2.5 1.5]);
h = ezplot (y4, [-2.5 1.5]); set (h,'color','g');
k = ezplot (y5, [-2.5 1.5]); set (k,'color','m'); hold off;
legend('diem gia tri','bac 3', 'bac 4','bac 5');
title ('Noi suy bang giai HPT DSTT');
 
 %phan b
xx = linspace (-2,1.5,100);
pp3 = polyfit (x,y,3); yy3 = polyval (pp3,xx);
pp4 = polyfit (x,y,4); yy4 = polyval (pp4,xx);
pp5 = polyfit (x,y,5); yy5 = polyval (pp5,xx);
figure (2)
plot (x,y,'*r'); hold on;
plot (xx,yy3,xx,yy4,'g',xx,yy5,'m'); hold off;
