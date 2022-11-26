clc; clear all; close all;
ptvp='D2x=-w0^2*x-gama*Dx+cos(w1*t)';
dkbd='x(0)=x0,Dx(0)=v0';
x=dsolve(ptvp,dkbd);
% Phan a
% thay gia tri
w0=1.5; gama=0.2; w1=1.9; T=2*pi/w0; x0=0; v0=0;
x1=subs(x);
%fplot(x1,[0*T 20*T]); hold on;
% tim bien do thi dd on dinh
% thoi gian dd on dinh bat dau tu 40s
tt=[40:20*T];
A=max(double(subs(x1,'t',tt)))
% phan b
figure(2)
A1=[];
for k=1.2:0.1:1.8
         w0=1.5; gama=0.2; w1=k; T=2*pi/w0; x0=0; v0=0;
          x2=subs(x);
           tt=[30*T:50*T];
            A=max(double(subs(x2,'t',tt)));
             A1=[A1;k A];
end
A1
plot(A1(:,1),A1(:,2),'*r'); hold on;
plot(A1(:,1),A1(:,2),'b'); hold off;
title('su phu thuoc cua A vao w1 khi on dinh');
xlabel('w1'); ylabel('A')
