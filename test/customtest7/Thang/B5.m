clc;close all; clear all;
st0='-g/L*sin(u(1))-b*L^2*u(2)*abs(u(2))';
%h? t?ng quát b= k/(Lm), k he so ma sat
u0=[75*pi/180,0]; g=9.81; L=1,2; w=sqrt(g/L);T=2*pi/w;
t1=0:0.05:10*T;
%a)Không có ma sát, h? b?o toàn
b=0; sm0=subs(st0); st1=['[u(2);',char(sm0),']'];
du1=inline(st1,'t','u');
[t,u]=ode45(du1,t1,u0); th1=u(:,1); dth1=u(:,2);
gtx1=L*sin(th1);gty1=L*(1-cos(th1));
Ep1=g*L*(1-cos(th1)); Ek1=(L*dth1).^2/2;Et1=Ep1+Ek1;
%b)ma sát t? l? v?n t?c
b=0.05; sm0=subs(st0); st2=['[u(2);',char(sm0),']'];
du2=inline(st2,'t','u');
[t,u]=ode45(du2,t1,u0); th2=u(:,1);dth2=u(:,2);
gtx2=L*sin(th2);gty2=L*(1-cos(th2));
Ep2=g*L*(1-cos(th2)); Ek2=(L*dth2).^2/2; Et2=Ep2+Ek2;
% Bieu dien do thi
% - Goc, van toc goc ---------------------
figure(1);
subplot(2,1,1);plot(t1,th1,t1,dth1);
grid on;title('Dao dong bao toan'); legend('\theta(t)','\theta''(t)');
subplot(2,1,2);plot(t1,th2,t1,dth2);
title('Dao dong tat dan'); legend('\theta(t)','\theta''(t)');grid on
% - The nang,dong nang va nang luong tong --
figure(2);
subplot(2,1,1);plot(t1,Ep1,t1,Ek1,t1,Et1);
grid on;title('Dao dong bao toan'); legend('Ep(t)','Ek(t)','Et(t)');
subplot(2,1,2);plot(t1,Ep2,t1,Ek2,t1,Et2);
title('Dao dong tat dan'); legend('Ep(t)','Ek(t)','Et(t)');grid on;
% - Khong gian pha ---------------------------
figure(3);
plot(th1,dth1,th2,dth2); grid on;xlabel('\theta');ylabel('\theta''');
legend('Bao toan','Tat dan'); title('Dao dong trong khong gian pha');
