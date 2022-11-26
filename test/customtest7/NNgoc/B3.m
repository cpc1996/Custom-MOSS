clc; clear all; close all;

%%thiet lap phuong trinh
%phuong trinh tong quat 
des='m*D2x = -k1*Dx, m*D2y= -g*m - k1*Dy';
cds='x(0)=x0,y(0)=y0,Dx(0)=v0*cos(alpha),Dy(0)=v0*sin(alpha)';
r=dsolve(des,cds);
x=r.x; y=r.y;

%thong so
m = 0.15; 
x0 = 0; 
y0 = 15; 
v0 = 25; 
alpha = 30*pi/180; 
g = 9.8; 
k1 = 0.05;

%phuong trinh chuyen dong & van toc cua bong 
xt = subs(x), yt=subs(y), vxt=diff(xt), vyt=diff(yt);

%%cau a
disp('Thoi diem bong cham tuong la: ')
tct=double(solve(xt==20))
disp('Do cao khi bong cham tuong la: ')
yct=double(subs(yt,tct))
disp('Van toc khi cham tuong cua bong theo truc x la: ')
vxct=double(subs(vxt,tct))
disp('Van toc khi cham tuong cua bong theo truc y la: ')
vyct=double(subs(vyt,tct))

%Cau b: 
%Chia chuyen dong cua bong ra lam 2 giai doan: Truoc khi cham tuong va Sau
%khi cham tuong nay ra toi khi cham dat 

%Sau khi cham tuong
xt1= -subs(x)+40;
vxt1 = diff(xt);
tcd=double(solve(yt==0))
xcd=double(subs(xt1,tcd))
disp('Khoang cach cua bong cach tuong sau khi cham dat')
kc = 20-xcd

%%Cau c: Tam xa max

%tam xa L = ((v0^2)*sin(2*alpha))/g
%L max khi alpha = 45 do
alphatxmax  = 45 


figure(1);
subplot(221);
ezplot(xt,[0 tct]);hold on; 
ezplot(xt1,[tct tcd]);
title('Do thi x theo thoi gian'); hold off;

subplot(222);
ezplot(yt,[0 tcd]); title('Do thi y theo thoi gian');

subplot(223);
ezplot(vxt,[0 tct]); hold on; 
ezplot(vxt1,[tct tcd]); 
title('Do thi vx theo thoi gian'); hold off;

subplot(224); ezplot(vyt,[0 tcd]);
title('Do thi vy theo thoi gian'); hold off;

figure(2)
ezplot(xt,yt,[0 tct]);hold on;
ezplot(xt1,yt,[tct tcd]);
title('Quy dao cua bong tu khi nem toi khi cham dat');
hold off;
axis equal;
