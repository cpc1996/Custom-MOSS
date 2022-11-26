des='m*D2x = -k1*Dx, m*D2y= -g*m - k1*Dy';
cds='x(0)=x0,y(0)=y0,Dx(0)=v0*cos(alpha),Dy(0)=v0*sin(alpha)';
r=dsolve(des,cds);
x=r.x; y=r.y;
m=0.15; x0=0; y0=15; v0=25; alpha=30*pi/180; g=9.8; k1=0.05;
xt=subs(x), yt=subs(y), vxt=diff(xt), vyt=diff(yt);
tct=double(solve(xt==15))
yct=double(subs(yt,tct))
vxct=double(subs(vxt,tct));
vyct=double(subs(vyt,tct));
%sau khi cham tuong
xt1= -subs(x)+30;
vxt1=-diff(xt);
tcd=double(solve(yt==0))
xcd=double(subs(xt1,tcd))
kc=15-xcd
figure(1);
subplot(221);ezplot(xt,[0 tct]);hold on; ezplot(xt1,[tct tcd]);hold off;
subplot(222);ezplot(yt,[0 tcd]);
subplot(223);ezplot(vxt,[0 tct]); hold on; ezplot(vxt1,[tct tcd]);hold off;
subplot(224);ezplot(vyt,[0 tcd]);
figure(2)
ezplot(xt,yt,[0 tct]);hold on;
ezplot(xt1,yt,[tct tcd]);hold on;
