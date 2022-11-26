clc;
A1 = [1 2 3; 4 5 6; 7 8 9];
A2 = [1 1 3; 4 5 6; 7 8 9];
A3 = [0.9999 2 3; 4 5 6; 7 8 9];
b1 = [1;1;3];
b2 = [1;2;3];
%Dinh thuc
disp('Dinh thuc')
A1d = det(A1)
A2d = det(A2)
A3d = det(A3)
%Ma tran nghich dao
disp('Ma tran nghich dao')
A1i = inv(A1)
A1i*A1 %Kiem tra
A2i = inv(A2)
A2i*A2 %Kiem tra
A3i = inv(A3)
A3i*A3 %Kiem tra
%ma tran gia nghich dao
disp('Ma tran gia nghich dao')
A1pi = pinv(A1)
A1pi*A1*A1pi %Kiem tra
A2pi = pinv(A2)
A2pi*A2*A2pi %Kiem tra
A3pi = pinv(A3)
A3pi*A3*A3pi %Kiem tra
%Hang cua ma tran mo rong
r11 = [rank(A1) rank([A1 b1])];
r12 = [rank(A1) rank([A1 b2])];
r21 = [rank(A2) rank([A2 b1])];
r22 = [rank(A3) rank([A2 b2])];
r31 = [rank(A3) rank([A3 b1])];
r32 = [rank(A3) rank([A3 b2])];
tong = [r11;r12;r21;r22;r31;r32]
