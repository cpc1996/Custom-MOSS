clc; clear all; close all;

A1 = [1 2 3; 4 5 6; 7 8 9];
A2 = [1 1 3; 4 5 6; 7 8 9];
A3 = [0.9999 2 3; 4 5 6; 7 8 9];
b1 = [1; 1; 3];
b2 = [1; 2; 3];

%%cau a
%Ma tran A1
disp('Dinh thuc ma tran A1 la: ')
dt1 = det(A1)
disp('Ma tran nghich dao cua ma tran A1 la: ')
nd1 = inv(A1)
disp('Kiem tra ket qua: ')
nd1*A1
disp('Ma tran tua nghich dao cua ma tran A1 la: ')
tnd1 = pinv(A1)
disp('Kiem tra ket qua: ')
tnd1*A1*tnd1
A1*tnd1*A1

%Ma tran A2
disp('Dinh thuc ma tran A2 la: ')
dt2 = det(A2)
disp('Ma tran nghich dao cua ma tran A2 la: ')
nd2 = inv(A2)
disp('Kiem tra ket qua: ')
nd2*A2
disp('Ma tran tua nghich dao cua ma tran A2 la: ')
tnd2 = pinv(A2)
disp('Kiem tra ket qua: ')
tnd2*A2*tnd2
A2*tnd2*A2

%Ma tran A3
disp('Dinh thuc ma tran A3 la: ')
dt3 = det(A3)
disp('Ma tran nghich dao cua ma tran A3 la: ')
nd3 = inv(A3)
disp('Kiem tra ket qua: ')
nd3*A3
disp('Ma tran tua nghich dao cua ma tran A3 la: ')
tnd3 = pinv(A3)
disp('Kiem tra ket qua: ')
tnd3*A3*tnd3
A3*tnd3*A3

%%cau b
%Ma tran A1 bj
disp('Ma tran mo rong [A1 bj]')
disp('Hang ma tran A1 la: ')
rankA1 = rank(A1)
disp('Hang ma tran mo rong [A1 bj] lan luot la: ')
rankA1b1 = rank([A1 b1]), rankA1b2 = rank([A1 b2])

%Ma tran A2 bj
disp('Ma tran mo rong [A2 bj]')
disp('Hang ma tran A2 la: ')
rankA2 = rank(A2)
disp('Hang ma tran mo rong [A2 bj] lan luot la: ')
rankA2b1 = rank([A2 b1]), rankA2b2 = rank([A2 b2])

%Ma tran A3 bj
disp('Ma tran mo rong [A3 bj]')
disp('Hang ma tran A3 la: ')
rankA3 = rank(A3)
disp('Hang ma tran mo rong [A3 bj] lan luot la: ')
rankA3b1 = rank([A3 b1]), rankA3b2 = rank([A3 b2])
