clc; clear all; close all;
function [xy,fxy]=baiA2(pt1,pt2)
        pt1='sin(x)^2+sin(y)^2=0';
        pt2='4*x*y+0.1*x+0.2*y-1=0';
        h1=ezplot(pt1,[-3 3]); hold on; set(h1,'Color','k');
        ezplot(pt2,[-3 3]); hold off;
        f=@(x) [(sin(x(1))^2+sin(x(2))^2=0),(4*x(1)*x(2)+0.1*x(1)+0.2*x(2)-1)];
        [x0,y0]=ginput;
        for k=1:length(x0)
                    X0=[x0(k),y0(k)];
                        [xy(k,:),fxy(k,:)]=fsolve(f,X0);
        end
        xyf=[xy, fxy]
