clc; close all; clear all;
syms x a
f1=(x^2 - x - 2)^20/(x^3 - 12*x + 16)^10;
s1=limit(f1,x,2)
f2=(x^100 - 2*x + 1)/(x^50 - 2*x + 1);
s2=limit(f2, x, 1)
f3=(sqrt(x + sqrt(x + sqrt(x)))/(sqrt(x + 1)));
s3=limit(f3, x, inf,'left')
f4=(sqrt(x) + x^(1/3) + x^(1/4))/(sqrt(2*x + 1));
s4=limit(f4, x, inf, 'left')
f5=(sin(x) - sin(a))/(x - a);
s5=limit(f5, x, a)
f6=(cos(sqrt(x)))^(1/x);
s6=limit(f6,x,0,'right')
