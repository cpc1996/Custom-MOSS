% a.Phuong trinh ten lua
clc; clear all; close all;
syms m vz F1 t dm dvz dt Dz D2z Dm
syms ve m0 m1 g k1 c
p0 = m*vz; 
p1 = (m+dm)*(vz+dvz)-dm*(vz-ve);
dp = simplify(p1-p0);
pt1 = dp/dt - F1;
dvz = D2z*dt; dm = Dm*dt; F1 = -m*g-k1*Dz;
pt1 = simplify(subs(pt1));
pt2 = limit(pt1,dt,0)
m = dsolve('Dm = -c','m(0) = m0 + m1','t')
Dm = diff(m,t);
pt3 = subs(pt2)
tf = solve(m-m1,t)
z = dsolve(char(pt3),'z(0) = 0,Dz(0) = 0','t')
z = simplify(z)
vz = diff(z,t); vz = simplify(vz)
% Thay so lieu vao pt
%dlg = {m0,m1,g,c,k1,ve}; gt = {105,95,9.8,5,0.0001,1000};
m0=105;
m1=95;
g=9.8;
c=5;
k1=0.0001;
ve=1000;
tf1 = subs(tf) %thoi gian chay het nhien lieu
z1 = subs(z) %toa do
vz1 = subs(vz) %van toc
figure(1);
ezplot(z1,[0 18]);title('Do thi z(t)'); grid on; 
figure(2); ezplot(vz1,[0 18]); title('Do thi Vz(t)'); 
grid on;
% Phan a
disp('Do cao ten lua khi chay het nhien lieu:')
H = double(subs(z1,t,tf1))
disp('Van toc ten lua dat duoc:')
V =double(subs(vz1,t,tf1))
% Phan b
% Luc nay ten lua chuyen dong voi khoi luong m1, van toc V, alpha 
disp ('Do cao max ten lua dat duoc:')
hmax = H + (V^2)/(9.8*2)
disp('Thoi diem ten lua cham dat:')
tg = double(tf1 + V/9.8 + sqrt(2*hmax/9.8))
