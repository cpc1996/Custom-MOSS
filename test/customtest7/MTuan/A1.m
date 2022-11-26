clc; clear all; close all;
syms x y 
% khai bao
[x,y] = meshgrid(-3:0.1:3, -3:0.2:3);
Z = sin(x.*x).*cos(y.*y);
figure(1)
subplot(2,2,1); surf(x,y,Z);
subplot(2,2,2); mesh(x,y,Z); grid on;
n = 30;
subplot(2,2,3); cv = contour(x,y,Z,n);
subplot(2,2,4); cv = contour(x,y,Z,n);
figure(2)
subplot(2,1,2); cv = contour(Z,n); 
subplot(2,1,1); ezsurf(Z,n);
