clc, clear all, close all
% phan a
syms t
A=20; w=2*pi/3; anpha=pi/2;
x = A*cos(w.*t+anpha);
v = diff(x);
a = diff(v);

figure (1);
fplot (x, [0 20]); hold on;
fplot (v, [0 20]);
fplot (a, [0 20]); hold off;
legend ('Ly do x(t))', 'Van toc v(t)', 'Gia toc a(t)');

figure (2);
fplot (x, v, [0 20]);

% phan b
figure(3)
syms t
a=30; w=pi/3; 
anpha= pi/2; 
lamda=0.2; 


subplot(2,1,2);
x=a.*exp(-lamda.*t).*cos(w.*t+anpha);
ezplot(x,[0 20]); hold on;
A1=a.*exp(-lamda.*t);
A2=-a.*exp(-lamda.*t);
h1=ezplot(A1,[0 20]);
h2=ezplot(A2,[0 20]); hold off 
set(h1,'Color','b'); set(h2,'Color','r');
ylim([-30 30]);
title(' Dao dong tat dan ezplot'); 
xlabel('Truc t'); ylabel('Truc ly do'); 


subplot(2,1,1);
t=[0:0.1:20]; 
x=a.*exp(-lamda.*t).*cos(w.*t+anpha);
plot(t,x); hold on; 
A1=a.*exp(-lamda.*t); 
A2=-a.*exp(-lamda.*t); 
plot(t,A1,'b',t,A2,'r'); hold off; 
title('Dao dong tat dan plot'); 
xlabel('Truc t'); ylabel('Truc ly do');
