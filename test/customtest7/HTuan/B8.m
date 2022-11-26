%bai toan nem xien
clc; clear all; close all;
disp('========Khi co ma sat=======');
des='D2x=-k*Dx/m, D2y=-k*Dy/m-g';
cds='x(0)=x0,y(0)=y0,Dx(0)=v0*cos(alpha),Dy(0)=v0*sin(alpha)';
r=dsolve(des,cds);
x=r.x, y=r.y
m=0.1; x0=0; y0=15; v0=40; alpha=pi/6; g=9.81; k=0.1;
xt=subs(x); yt=subs(y);
vxt=diff(xt); vyt=diff(yt);
%tim thoi diem cham dat
yin=inline(vectorize(yt),'t');
tcd=fsolve(yin,4)                   %t cham dat
xmax=double(subs(xt,'t',tcd))
%tim thoi diem h max
vyin=inline(vectorize(vyt),'t');
disp('Thoi diem va vi tri khi hmax');
tmax=fsolve(vyin,1.3)
ymax=yin(tmax)
x_ymax=double(subs(xt,'t',tmax))
%Khi khong co ma sat;
disp('====Khi khong co mat sat====');
des2='D2x=0, D2y=-g';
r2=dsolve(des2,cds);
x2=r2.x, y2=r2.y
xt2=subs(x2); yt2=subs(y2);
% vxt2=diff(xt2); vyt=diff(yt2);
yin2=inline(vectorize(yt2),'t');
tcd2=fsolve(yin2,4)
xmax2=double(subs(xt2,'t',tcd2))
disp('Vat di xa hon la: '); x_plus=xmax2-xmax
%ve do thi
figure(1);
subplot(221); ezplot(xt,[0 tcd]); title('xt');
subplot(222); ezplot(vxt,[0 tcd]); title('vxt');
subplot(223); ezplot(yt,[0 tcd]); title('yt');
subplot(224); ezplot(vyt,[0 tcd]); title('vyt');
figure(2); ezplot(xt,yt,[0 tcd]); 
axis([0 1.1*xmax 0 1.1*ymax]); title('do thi xt yt');
