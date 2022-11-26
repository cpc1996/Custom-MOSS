clc, close all, clear all
% bai toan nem xien
ptvp = 'D2x=-k*Dx/m, D2y=-k*Dy/m-g';
dkbd = 'x(0)=x0,y(0)=y0, Dx(0)=v0*cos(alpha),Dy(0)=v0*sin(alpha)';
r=dsolve(ptvp,dkbd);
x=r.x; 
y=r.y;
% thay gia tri
m=0.15;
x0=0; 
y0=15; 
v0=25; 
alpha=pi/6;
g=9.8;
k=0.05;
xt=subs(x); yt=subs(y); vxt=diff(xt); vyt=diff(yt);
yin=inline(vectorize(yt),'t');
% Cau a:
% thoi diem cham tuong
xt1= -subs(x) + 40;
tct=double(solve(xt==20))
% do cao cham tuong
yct=double(subs(yt,'t',tct))
% Cau b:
% thoi diem cham dat
tcd = fsolve(yin, 3)
% tam xa
xmax = double(subs(xt,'t',tcd)); 
% do thi
figure(1);
subplot(221); ezplot(xt,[0 tcd]); 
subplot(222); ezplot(vxt,[0 tcd]); 
subplot(223); ezplot(yt,[0 tcd]); 
subplot(224); ezplot(vyt,[0 tcd]); 
figure(2)
ezplot(xt,yt,[0 tct]);hold on;
ezplot(xt1,yt,[tct tcd]);hold on;
% khoang cach no cach tuong
dx = xmax-20
% Cau c:
