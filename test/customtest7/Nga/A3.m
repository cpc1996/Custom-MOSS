% Nguyen Thi Nga - 19020733
clc; clear all; close all;
syms x a
% Phan a
S1 = limit((x^2 - x - 2)^20/(x^3 - 12*x + 16)^10,x,2)
% Phan b
S2 = limit((x^100 - 2*x + 1)/(x^50 - 2*x + 1),x,1)
% Phan e
S5 = limit((sin(x)-sin(a))/(x-a),x,a)
% Phan f
S6 = limit((cos(sqrt(x)))^(1/x),x,0,'right')
% Phan c
f3 = sqrt(x+ sqrt(x + sqrt(x)))/(sqrt(x+1))
S3 = limit(f3,x,inf,'right')
% Phan d
S4 = limit((sqrt(x) + x.^(1/3) + x.^(1/4))./sqrt(2.*x + 1),x,inf,'right')
