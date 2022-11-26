close all; clc; clear all;
x0=1.2; y0=0; vx0=0; vy0=6; u0=[x0,vx0,y0,vy0];
%Thiet lap he phuong trinh vi phan voi GM=4*pi^2
stdu1=['[u(2);-4*pi^2*u(1)/(u(1)^2+u(3)^2)^(3/2);'];
stdu2=['u(4);-4*pi^2*u(3)/(u(1)^2+u(3)^2)^(3/2)]'];
stdu=[stdu1,stdu2]; du=inline(stdu,'t','u');
%phan a
opt=odeset('reltol',1e-6,'abstol',1e-9); tn=30;
[t,u]=ode45(du,0:.01:tn,u0,opt);
x=u(:,1); vx=u(:,2); y=u(:,3); vy=u(:,4);
r=sqrt(x.^2+y.^2); v= sqrt(vx.^2+vy.^2);
figure(1); plot(x,y); title('Quy dao hanh tinh');
disp('Ban truc be: ')
a = (max(u(:,1))-min(u(:,1)))/2
disp('Ban truc lon: ')
b = (max(u(:,3))-min(u(:,3)))/2
G = 6.67e-11; M = 2e30
disp('Chu ki quay: ')
T = double(sqrt(4*(pi^2)*(b^3)/(G*M)))

% Phan b
disp('Ty so L/m:')
hs = u(:,1).*u(:,4)-u(:,3).*u(:,2);hs

%Bai B1 phan c
close all; clc; clear all;
%hanh tinh 1
x0=1; y0=0; vx0=0; vy0=2; u0=[x0,vx0,y0,vy0];

stdu1=['[u(2);-4*pi^2*u(1)/(u(1)^2+u(3)^2)^(3/2);'];
stdu2=['u(4);-4*pi^2*u(3)/(u(1)^2+u(3)^2)^(3/2)]'];
stdu=[stdu1,stdu2]; du=inline(stdu,'t','u');
opt=odeset('reltol',1e-6,'abstol',1e-9); tn=30;
[t,u]=ode45(du,0:.01:tn,u0,opt);
x=u(:,1); vx=u(:,2); y=u(:,3); vy=u(:,4);
r=sqrt(x.^2+y.^2); v= sqrt(vx.^2+vy.^2);
figure(1); plot(x,y); title('Quy dao hanh tinh');
disp('Ban truc be: ')
a = (max(u(:,1))-min(u(:,1)))/2
disp('Ban truc lon: ')
b = (max(u(:,3))-min(u(:,3)))/2
G = 6.67e-11; M = 2e30
disp('Chu ki quay: ')
T = double(sqrt(4*(pi^2)*(b^3)/(G*M)))
