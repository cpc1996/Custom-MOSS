clc; clear all; close all;
% phan b bai toan nem xien
ptvp = 'D2x=-k*Dx/m, D2y=-k*Dy/m-g';
dkbd = 'x(0)=x0,y(0)=y0, Dx(0)=v0*cos(alpha),Dy(0)=v0*sin(alpha)';
r=dsolve(ptvp,dkbd); x=r.x; y=r.y;
% thay gia tri
m=0.15; x0=0; y0=15; v0=25; alpha=30*pi/180; k=0.05;
g=9.8;
xt=subs(x); yt=subs(y); vxt=diff(xt); vyt=diff(yt);
% thoi diem cham dat
yin=inline(vectorize(yt),'t');
tcd = fsolve(yin,3.05);
xmax=double(subs(xt,'t',tcd))
% ve do thi (cua phan b not nay)
