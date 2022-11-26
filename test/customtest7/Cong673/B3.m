clc; clear all; close all;
des='m*D2x = -k1*Dx, m*D2y= -g*m - k1*Dy';
cds='x(0)=x0,y(0)=y0,Dx(0)=v0*cos(alpha),Dy(0)=v0*sin(alpha)';
r=dsolve(des,cds);
x=r.x; y=r.y;
m=0.15; 
x0=0; 
y0=15; 
v0=25; 
alpha=30*pi/180; 
g=9.8; 
k1=0.05;
xt=subs(x), yt=subs(y), vxt=diff(xt), vyt=diff(yt);

%Phan a: thoi diem va do cao khi cham tuong
disp('Thoi diem vat cham tuong')
tct=double(solve(xt==20))
disp('do cao khi vat cham tuong')
yct=double(subs(yt,tct))
disp('Van toc khi cham tuong cua vat theo truc x')
vxct=double(subs(vxt,tct))
disp('Van toc khi cham tuong cua vat theo truc y')
vyct=double(subs(vyt,tct))

%Phan b: 
%sau khi cham tuong
xt1= -subs(x)+40;
vxt1=diff(xt);
tcd=double(solve(yt==0))
xcd=double(subs(xt1,tcd))
disp('Khoang cach cua vat cach tuong sau khi cham dat')
khoangcach=20-xcd

figure(1);
subplot(221);
ezplot(xt,[0 tct]);hold on; 
ezplot(xt1,[tct tcd]);hold off;

subplot(222);
ezplot(yt,[0 tcd]);

subplot(223);
ezplot(vxt,[0 tct]); hold on; 
ezplot(vxt1,[tct tcd]);hold off;
subplot(224);ezplot(vyt,[0 tcd]);

figure(2)
ezplot(xt,yt,[0 tct]);hold on;
ezplot(xt1,yt,[tct tcd]);hold on;
axis equal;

%phan c: goc nem toi uu
%vat cach tuong xa nhat
syms t;
des1='m*D2x = -k1*Dx, m*D2y= -g*m - k1*Dy';
cds1='x(0)=x0,y(0)=y0,Dx(0)=v0*cos(alpha),Dy(0)=v0*sin(alpha)';
r1=dsolve(des1,cds1);
x1=r1.x; y1=r1.y;
m=0.15; 
x0=0; 
y0=15;
v0=25; 
%alpha=30*pi/180; 
g=9.8; 
k1=0.05;
xt1=subs(x1), yt1=subs(y1), vxt1=diff(xt1), vyt1=diff(yt1)
%sau kh dap tuong, chuyen dong tro thanh nem ngang
L=sqrt(vxt1^2+vyt1^2)*2*g*y0
Lmax=solve(max(L,t))
