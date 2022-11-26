clc; clear all; close all;
% phan a 
ptvp = 'D2x=-k*Dx/m, D2y=-k*Dy/m-g';
dkbd = 'x(0)=x0,y(0)=y0, Dx(0)=v0*cos(alpha),Dy(0)=v0*sin(alpha)';
r=dsolve(ptvp,dkbd); x=r.x; y=r.y;
% thay gia tri
m=0.2; x0=0; y0=25; v0=30; alpha=37*pi/180; k=0.05;
g=9.81;
xt=subs(x); yt=subs(y); vxt=diff(xt); vyt=diff(yt);
% thoi diem cham dat
yin=inline(vectorize(yt),'t');
tcd = fsolve(yin,3.6);
xmax=double(subs(xt,'t',tcd))
% ve do thi (cua phan a not nay)
% ma sat 0.1: xmax là 34.2709
% ma sat 0 : xmax là 163.8162 ct
L=v0^2*sin(2*alpha)/(2*g)
t0=double((-v0*sin(alpha)-sqrt((v0*sin(alpha))^2-4*y0*(-g/2)))/(2*(-g/2)));
L=v0*cos(alpha)*t0
figure(1);
subplot(221); ezplot(xt,[0 tcd]); title('xt')
subplot(222); ezplot(vxt,[0 tcd]); title('vxt')
subplot(223); ezplot(yt,[0 tcd]); title('yt')
subplot(224); ezplot(vyt,[0 tcd]); title('vyt')
figure(2);
ezplot(xt,yt,[0 tcd]);

% phan b thoi diem vat lien cao nhat
vyin=inline(vectorize(vyt),'t');
thmax=fsolve(vyin,1.3), ymax=yin(thmax)
xhmax=double(subs(xt,'t',thmax))
