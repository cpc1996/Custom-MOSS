clc; clear all; close all;
syms x y
[x,y]=meshgrid(-3:.2:3,-3:.2:3);
z=sin(x.^2).*cos(y.^2);
t ='sin(x.^2).*cos(y.^2)';
n_lim = [-3 3 -3 3];
figure(1); 
subplot(2,2,1); surf(x,y,z); grid on;
subplot(2,2,2); mesh(x,y,z); grid on;
n=30;
subplot(2,2,3); cv=contour(x,y,z,n); grid on;
subplot(2,2,4); cv=contour3(x,y,z,n); grid on;
%phan b
figure(2);
subplot(1,2,1); ezsurf(t, n_lim,n); grid on;
subplot(1,2,2); cv=contour(x,y,z,n); grid off;
