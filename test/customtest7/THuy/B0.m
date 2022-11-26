function [sopi]=piHitorMiss(N)
h=ezplot('x^2+y^2-1',[0 1]);
set(h,'color','b'); axis square; shg;
x=rand(1,N); y=rand(1,N);
hold on; plot(x,y,'*r');
%n: hit %N-n: miss % 4*n/N=4*C/S=pi
n=0;
for k=1:N
 if (x(k).^2+y(k).^2<1)
 n=n+1;
 end
end
sopi=4*n/N;
phan b
clc;clear all; close all;
M=200;
for h=1:M
 x=0;y=0;n=0;
 N=1e4; x=rand(1,N); y=rand(1,N);
 for k=1:N
 if (x(k).^2+y(k).^2<1)
 n=n+1;
 end
 end
 sopi=4*n/N;
 tong(h)=sopi;
end
tb=sum(tong)/M
for h=1:M
 tong1(h)=(tong(h)-tb)^2;
end
dlc=sqrt(sum(tong1)/M)
phan c
13
clc;clear all; close all;
tb1=[]; dlc1=[];
for M=200:200:2000
 for h=1:M
 x=0;y=0;n=0;
 N=1e4; x=rand(1,N); y=rand(1,N);
 for k=1:N
 if (x(k).^2+y(k).^2<1)
 n=n+1;
 end
 end
 sopi=4*n/N;
 tong(h)=sopi;
 end
 tb=sum(tong)/M;
 tb1=[tb1 tb];
 for h=1:M
 tong1(h)=(tong(h)-tb)^2;
 end
 dlc=sqrt(sum(tong1)/M);
 dlc1=[dlc1 dlc];
end
Ph?n d
clc;clear all; close all;
M=200; tb1=[]; dlc1=[];
N1=[1e1,1e2,1e3,1e4,1e5];
for td=1:length(N1)
 N=N1(td);
 for h=1:M
 x=0;y=0;n=0;
 x=rand(1,N); y=rand(1,N);
 for k=1:N
 if (x(k).^2+y(k).^2<1)
 n=n+1;
 end
 end
 sopi=4*n/N;
 tong(h)=sopi;
 end
 tb=sum(tong)/M; tb1=[tb1 tb];
 for h=1:M
 tong1(h)=(tong(h)-tb)^2;
 end
 dlc=sqrt(sum(tong1)/M);dlc1=[dlc1 dlc];
end
