clc; clear all; close all;
% u(1)=x0=1.2, u(2)=v0x=0, u(3)=y0=0,u(4)=v0y=6;
dkbd = 'u(1)=1.2,u(2)=0,u(3)=0,u(4)=6';
ptvp = inline('[u(2);-4*pi^2*u(1)/(u(1)^2+u(3)^2)^(3/2);u(4);-4*pi^2*u(3)/(u(1)^2+u(3)^2)^(3/2)]','t','u');
[t,u]=ode45(ptvp,[0:0.1:10],[1 0 0 2.5*pi]);
% phan a ve quy dao
G=6.67e-11; M=1.99e30;
a=(max(u(:,1))-min(u(:,1)))/2;
b=(max(u(:,3))-min(u(:,3)))/2;
T=(4*(pi^2)*(a^3)/(G*M))^(1/2);
syms x y
f=(x/a)^2 + (y/b)^2 -1;
f=char(f);
x0=[]; kmin=5; kmax=5;
for k=5:length(t)
        if round(u(kmin,1),0)>round(u(k,1),0)
                kmin=k;
        end
        if round(u(kmax,1),0)<round(u(k,1),0)
                kmax=k;
        end
end
T=2*abs(t(kmax)-t(kmin))
plot(u(:,1),u(:,3)); hold on
% phan b
L=(u(:,1).*u(:,4)-u(:,3).*u(:,2));
