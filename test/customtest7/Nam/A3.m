clc; clear all; close all;
syms x a;
s1=limit((x^2-x-2)^20/(x^3-12*x+16)^10,x,2)
s2=limit((x^100-2*x+1)/(x^50-2*x+1),x,1)
s3=limit(sqrt(x+sqrt(x+sqrt(x)))/sqrt(x+1),x,inf)
s4=limit((sqrt(x)+x^(1/3)+x^(1/4))/sqrt(2*x+1),x,inf)
s5=limit((sin(x)-sin(a))/(x-a),x,a)
s6=limit(cos(sqrt(x))^(1/x),x,0,'right')
