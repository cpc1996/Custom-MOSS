clc; clear all; close all;
figure(1);
hold on;
h1 = ezplot('(sin(x))^2 + (sin(y))^2 - 1',[0 2 0 2]);
set(h1, 'color','r');
h1 = ezplot('4*x*y + 0.1*x + 0.2*y - 1',[0 2 0 2]);
%Gan dung
[x0,y0] = ginput
%Chinh xac
f = @(x) [((sin(x(1))).^2 + (sin(x(2))).^2 -1), (4.*x(1).*x(2) + 0.1.*x(1) + 
        0.2.*x(2) -1)]
for k = 1: length(x0)
         [xy(k,:),fxy(k,:)] = fsolve(f,[x0(k),y0(k)]);
end
disp('Nghiem'); xyr = [xy, fxy]
