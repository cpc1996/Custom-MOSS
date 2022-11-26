clc; clear all; close all
ezplot('sin(x)^2 + sin(y)^2-1'); hold on
h = ezplot('4*x*y+0.1*x+0.2*y-1');
set(h,'color','r');
axis ([0 2 0 2])
f = @(x) [(sin(x1)^2 + sin(x2)^2-1),(4*(x1)*(x2)+0.1*(x1)+0.2*(x2)-1)];
[x0 y0] = ginput(1);
for k=1:length(x0)
            [xy(k,:),fxy(k,:)]=fsolve(f,[x0(k),y0(k)])
end
disp('Nghiem la: ')
xyf =[xy,fxy]S
