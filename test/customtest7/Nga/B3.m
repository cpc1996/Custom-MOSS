% Nguyen THi Nga - 19020733
clc; clear all; close all;
des='m*D2x = -k1*Dx, m*D2y= -g*m - k1*Dy';
cds='x(0)=x0,y(0)=y0,Dx(0)=v0*cos(alpha),Dy(0)=v0*sin(alpha)';
r=dsolve(des,cds);
x=r.x; y=r.y;
m = 0.15, h = 15, v0 = 25, alpha = 30*pi/180, k1 = 0.05, g = 9.8
x0 = 0, y0 = 15;
% Phan a
xt = subs(x), yt = subs(y), vxt = diff(xt), vyt = diff(yt)
ds = solve(xt == 20)
disp('Thoi diem bong cham tuong')
t1 = double (ds)
disp('Do cao qua bong khi cham tuong')
h1 = double(subs(yt,t1))
% Phan b: Tinh va ve do thi x,y, vx, vy theo thoi gian va quy dao cua qua bong tu kkhi nem den khi cham dat
% sau khi cham tuong
xt1= -subs(x)+40;
vxt1=diff(xt);
disp('Thoi diem qua bong cham dat')
t2 = double(solve(yt == 0))
x2=double(subs(xt,t2));
disp('Qua bong cham dat cach tuong 1 khoang: ')
x2 - 20,
figure(1);
subplot(221);ezplot(xt,[0 t1]);hold on; ezplot(xt1,[t1 t2]);hold off;
subplot(222);ezplot(yt,[0 t2]);
subplot(223);ezplot(vxt,[0 t1]); hold on; ezplot(vxt1,[t1 t2]);hold off;
subplot(224);ezplot(vyt,[0 t2]);
figure(2)
ezplot(xt,yt,[0 t1]);hold on;
ezplot(xt1,yt,[t1 t2]);hold on;
% Phan c
