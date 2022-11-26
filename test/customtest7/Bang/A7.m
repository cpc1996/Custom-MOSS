clc; clear all; close all;
A1 = [1 2 3;4 5 6;7 8 9];
A2 = [1 1 3;4 5 6;7 8 9];
A3 = [0.999 2 3;4 5 6;7 8 9];
b1 = [1;1;3]; b2 = [1;2;3];

%phan a: dinh thuc det, ma tran nghich dao inv, ma tran tua nghich dao
D1 = det(A1),A1i = inv(A1) , A1i*A1
 A1pi = pinv(A1); A1pi*A1*A1pi, A1*A1pi*A1;
 
D2 = det(A2),Ai2 = inv(A2), Ai2*A2
 A2pi = pinv(A2), A2pi*A2*A2pi, A2*A2pi*A2
 
D3 = det(A3),Ai3 = inv(A3); Ai3*A3
 A3pi = pinv(A3); A3pi*A3*A3pi; A3*A3pi*A3;
 
% phan b tinh hang cac ma tran voi ma tran mo rong
disp('ma tran mo rong [A1 bj]')
R1 = rank(A1); R11 = rank([A1 b1]);
disp('ma tran mo rong [A2 bj]')
R2 = rank(A2), R21 = rank([A2 b1]),
disp('ma tran mo rong [A3 bj]')
R3 = rank(A3), R31 = rank([A3 b1]),
