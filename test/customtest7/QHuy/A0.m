clc; clear all; close all;
syms t
x1=20*cos(2*pi*t/3+pi/2);
v1=diff(x1);
a1=diff(v1);
x1t=char(x1);
v1t=char(diff(x1));
a1t=char(diff(x1,2));
figure(1);
fplot(x1t,[0 20]); hold on;
fplot(v1t,[0 20]); hold on;
fplot(a1t,[0 20]);
legend('x1(t)','v1(t)','a1(t)');
title('Do thi dao dong dieu hoa');
ylabel('x1 , v , a ');
xlabel('t');
figure(2);
ezplot(x1t,v1t,[0 20]);
title('Bieu dien khong gian pha');
xlabel('t');
ylabel('Pha');
disp('NHAN XET VE Nang Luong CUA VAT DAO DONG DIEU HOA')
disp('Tai vi tri can bang vat co van toc lon nhat nen co dong nang cuc dai')
disp('khi do dong nang chinh bang nang lýõng con lac')
%x=a*exp(-lamda*t)*cos(w*t+alpha);
% a=30; lamda=0.2; w=pi/3; alpha=pi/2; t=[0 20]
t=linspace(0,20);
x2=30.*exp(-0.2.*t).*cos(-pi/3.*t+pi/2);
figure(3)
subplot(2,1,1); plot(t,x2,'r*--');
ylim([-20 25]); % gioi han truc y
title('Do thi dao dong tat dan lenh plot');
xlabel('t');
ylabel('xb');
subplot(2,1,2); ezplot('30*exp(-0.2*t)*cos(-pi/3*t+pi/2)',[0 20]);
ylim([-20 25]);
title('Do thi dao dong tat dan lenh ezplot');
xlabel('t');
ylabel('xb');
