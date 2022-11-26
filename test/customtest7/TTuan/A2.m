%bai A2
clc; clear all; close all
ezplot('sin(x)^2 + sin(y)^2 -1'); hold on;
ezplot('4*x*y + 0.1*x +0.2*y -1');
axis([0 2 0 2]);
disp('tap nghiem :'); [x y] = ginput
