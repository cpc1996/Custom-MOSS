clc; clear all; close all;
% phan a bai toan nem xien
ptvp = 'D2x=-k*Dx/m, D2y=-k*Dy/m-g';
dkbd = 'x(0)=x0,y(0)=y0, Dx(0)=v0*cos(alpha),Dy(0)=v0*sin(alpha)';
r=dsolve(ptvp,dkbd); x=r.x; y=r.y;
% thay gia tri
m=0.2; x0=0; y0=25; v0=30; alpha=37*pi/180; k=0.05;g=9.8;
xt=subs(x); yt=subs(y); vxt=diff(xt); vyt=diff(yt);
% thoi diem cham dat
yin=inline(vectorize(yt),'t');
tmax = fsolve(yin,2.6);
xmax=double(subs(xt,'t',tmax))
% ve do thi cua phan a 
% ma sat 0.05: xmax là 65.9112

% khong co ma sat  : xmax là 113.9755 
L=v0^2*sin(2*alpha)/(2*g)
t0=double((-v0*sin(alpha)-sqrt((v0*sin(alpha))^2-4*y0*(-g/2)))/(2*(-g/2)));
L=v0*cos(alpha)*t0
figure(1);
subplot(221); fplot(xt,[0 tmax]); title('xt')
subplot(222); fplot(vxt,[0 tmax]); title('vxt')
subplot(223); fplot(yt,[0 tmax]); title('yt')
subplot(224); fplot(vyt,[0 tmax]); title('vyt')
figure(2);
ezplot(xt,yt,[0 tmax]);
% phan b  vat tai hmax va xhmax
% thoi diem vat dat do cao cuc dai
vyin=inline(vectorize(vyt),'t');
thmax=fsolve(vyin,1.3), ymax=yin(thmax)
xhmax=double(subs(xt,'t',thmax))
