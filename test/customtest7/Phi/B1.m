clc; clear all; close all;
% thay gia tri
x0=1.2;vx0=0;y0=0;vy0=6;tn=30;
opt=odeset('reltol',1e-6,'abstol',1e-9);
dkbd ='u(1)=1.2,u(2)=0,u(3)=0,u(4)=6';
stdu1=['[u(2);-4*pi^2*u(1)/(u(1)^2+u(3)^2)^(3/2);'];
stdu2=['u(4);-4*pi^2*u(3)/(u(1)^2+u(3)^2)^(3/2)]'];
stdu=[stdu1,stdu2]; ptvp=inline(stdu,'t','u');
u0=[x0,vx0,y0,vy0]; 
[t,u]=ode45(ptvp,[0:0.01:tn],u0,opt);
x=u(:,1); vx=u(:,2); y=u(:,3); vy=u(:,4);
% phan a ve quy dao
G=6.67e-11; M=1.99e30;
a=(max(x)-min(x))/2
b=(max(y)-min(y))/2 
kmin=5; kmax=5;
for k=5:length(t)
        if round(u(kmin,1),0)>round(u(k,1),0)
                kmin=k;
        end
        if round(u(kmax,1),0)<round(u(k,1),0)
                kmax=k;
        end
end
T=2*abs(t(kmax)-t(kmin))
r=sqrt(x.^2+y.^2);
plot(x,y); title('quy dao hanh tinh')
% phan b L bảo toàn
L=x.*vy-y.*vx;
