% Tinh cac gioi han sau
clc; clear all; close all;
syms x y a
%Cau a
lim_a = limit(((x^2-x-2)^20)/((x^3-12*x+16)^10),x,2)
%Cau b
lim_b = limit(((x^100-2*x+1)/(x^50-2*x+1)),x,1)
%Cau c
lim_c = limit((((((x^1/2)+x)^1/2+x)^1/2)/((x+1)^1/2)),x,inf)
%Cau d
lim_d = limit(((x^1/2+x^1/3+x^1/4)/(2*x+1)^1/2),x,inf)
%Cau e
lim_e = limit(((sin(x)-sin(a))/(x-a)),x,a)
%Cau f
lim_f = limit(((cos(x^1/2))^(1/x)),x,0)
