clc; clear all; close all;
syms x y 
f1= sin(x)^2+sin(y)^2-1;
g2=4*x*y+0.1*x+0.2*y-1;
h=ezplot('sin(x)^2+sin(y)^2-1', [0 2]);
set(h,'color', 'r'); hold on;
ezplot('4*x*y+0.1*x+0.2*y-1', [0 2]); shg
f=@(x) [sin(x(1))^2+sin((2))^2-1, 4*x(1)*x(2)+0.1*x(1)+0.2*x(2)-1];
[x0,y0]=ginput;
for k=1:length(x0)
        [xy(k,:), fxy(k,:)]=fsolve(f,[x0(k),y0(k)]);
end
disp('Nghiem cua he la: ')
xyf=[xy,fxy]
