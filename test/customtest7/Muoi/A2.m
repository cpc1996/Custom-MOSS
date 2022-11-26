clc; clear all; close all;
pt1='sin(x)^2 + sin(y)^2 -1=0';
pt2='4*x*y + 0.1*x +0.2*y -1=0';
h1=ezplot(pt1,[0 2]); hold on; set(h1,'Color','k');
ezplot(pt2,[0 2]); hold off;
f=@(x) [sin(x(1))^2 + sin(x(2))^2 -1,4*x(1)*x(2) + 0.1*x(1) +0.2*x(2) -1];
[x0 y0]=ginput(1);
for k=1:length(x0)
         [xy(k,:),fxy(k,:)]=fsolve(f,[x0(k),y0(k)]);
end 
xyf=[xy, fxy]

