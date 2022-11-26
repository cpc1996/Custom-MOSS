clc; clear all; close all; 
% phan a syms g L b 
st0='-g/L*sin(u(1))-k*L^2*u(2)*u(2)';
u0=[75*pi/180,0]; 
g=9.8; 
L=1.2;
m=1; 
k=0; 
w=sqrt(g/L); 
T=2*pi/w; 
t1=0:0.1:2*T; 
sm0=subs(st0);
st1=['[u(2);',char(sm0),']']; 
du1=inline(st1,'t','u'); 
[t,u]=ode45(du1,t1,u0); 
th1=u(:,1);
dth1=u(:,2); 
gtx1=L*sin(th1); 
dty1=L*(1-cos(th1)); 
Ep1=g*L*(1-cos(th1)); 
Ek1=(L*dth1).^2/2;Et1=Ep1+Ek1; 
figure(1);  
plot(t1,th1,'r'); 
figure(2) 
plot(t1,Ep1,'r'); hold on; title('Ep1')
plot(t1,Ek1,'b'); title('Ek1') 
plot(t1,Et1,'k'); hold off; title('Et1') 

% phan b syms g L b 
st0='-g/L *sin(u(1))-k*L^2*u(2)*abs(u(2))'; 
u0=[75*pi/180,0]; 
g=9.8; 
L=1.2;
m=1; 
%gama=0.01; 
k=0.01;
w=sqrt(g/L); 
T=2*pi/w; 
t1=0:0.1:5*T; 
sm0=subs(st0); 
st1=['[u(2);',char(sm0),']']; 
du1=inline(st1,'t','u'); 
[t,u]=ode45(du1,t1,u0); s=u(:,1);dth1=u(:,2); 
gtx1=L*sin(s); dty1=L*(1-cos(s)); 
Ep1=g*L*(1-cos(s)); 
Ek1=(L*dth1).^2/2; Et1=Ep1+Ek1;
figure(3);  
plot(t1,s,'r'); 

figure(4) 
plot(t1,Ep1,'r'); hold on; plot(t1,Ek1,'b'); plot(t1,Et1,'k'); hold off;
