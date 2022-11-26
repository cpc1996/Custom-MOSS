clc; clear all; close all;
%mach LC
des='D2q=-q/(L*C)';
cds='q(0)=Q0, Dq(0)=I0';
Q=dsolve(des,cds)
C=0.1; L=4; Q0=1.5; I0=2;   %a
qt=subs(Q); it=diff(qt);
E1m=L*it^2/2; E1e=(qt^2)/(2*C); E1t=E1m+E1e;
%mach RLC
des2='D2q=-q/(L*C)-(R/L)*Dq';
cds2='q(0)=Q0, Dq(0)=I0';
Q2=dsolve(des2,cds2)
Q0=3; R=1.2; I0=0; L=4; C=1.3;
q2t=subs(Q2); i2t=diff(q2t);
E2m=L*i2t^2/2; E2e=(q2t^2)/(2*C); E2t=E2m+E2e;
%ve do thi
figure(1);  
subplot(211); fplot(qt,[0 10]); hold on;
title('Do thi q(t) mach LC'); ylim([-4 4]);
subplot(212); h=fplot(it,[0 10]); hold off;
title('Do thi i(t) mach LC'); set(h,'color','r')
ylim([-4 4]);
figure(2);
subplot(211); fplot(q2t,[0 20]); hold on;
title('Do thi q(t) mach RLC'); ylim([-4 4]);
subplot(212); h=fplot(i2t,[0 20]); hold off;
title('Do thi i(t) mach RLC'); set(h,'color','r');
ylim([-4 4]);
figure(3);
ezplot(qt,it); title('Mach LC');
xlabel('q(t)'); ylabel('i(t)');
ylim([-4 4]);
figure(4);
ezplot(E2m,[0 20]); hold on;
ezplot(E2e,[0 20]); 
ezplot(E2t,[0 20]); hold off;
title('Mach RLC');
legend('Em','Ee','Et');
