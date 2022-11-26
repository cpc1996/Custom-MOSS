close all; clc; clear all;
x0=1.2; y0=0; vx0=0; vy0=6; u0=[x0,vx0,y0,vy0];
%Thiet lap he phuong trinh vi phan voi GM=4*pi^2
stdu1=['[u(2);-4*pi^2*u(1)/(u(1)^2+u(3)^2)^(3/2);'];
stdu2=['u(4);-4*pi^2*u(3)/(u(1)^2+u(3)^2)^(3/2)]'];
stdu=[stdu1,stdu2]; du=inline(stdu,'t','u');
%Giai phuong trinh vi phan
opt=odeset('reltol',1e-6,'abstol',1e-9); tn=30;
[t,u]=ode45(du,0:.01:tn,u0,opt);
x=u(:,1); vx=u(:,2); y=u(:,3); vy=u(:,4);
%ban kinh quy dao
r=sqrt(x.^2+y.^2);
v= sqrt(vx.^2+vy.^2);
%xet tai t=0
%ban kinh quy dao
R=sqrt(x0^2+y0^2);
V=sqrt(vx0^2+vy0^2);
%chu ki quy dao
T=2*pi*R/V
figure(1); plot(x,y)
%Tu hinh ve ta thay duoc quy dao cua hanh tinh la hinh elip( 1 kepler)
