clc; clear all; close all;
A1 = [1 2 3;4 5 6;7 8 9];
A2 = [1 1 3;4 5 6;7 8 9];
A3 = [0.999 2 3;4 5 6;7 8 9];
b1 = [1;1;3]; 
b2 = [1;2;3];
d1 = det(A1),d2 = det(A2), d3 = det(A3)
% phan a nghiem duy nhat A2*x=b1, A2*x=b2, A3*x=b1,A3*x=b2
X21 = inv(A2)*b1, X22 = inv(A2)*b2
n21=norm(A2*X21 - b1); 
n22=norm(A2*X22 - b2);
X31 = inv(A3)*b1, X32 = inv(A3)*b2
n31=norm(A3*X31 - b1); 
n32=norm(A3*X32 - b2);
%phan b Phuong trinh vo nghiem : A1*x=b1
X0b=null(A1)
X11=pinv(A1)*b1
n11=norm(A1*X11-b1)
%phan c Phuong trinh vo dinh: A1*x=b2
X0c= null(A1)
X12=pinv(A1)*b2
c2=randn, Xc = X12 + c2*X0c
n12=norm(A1*X12-b2)
%phan d ma tran ko on dinh la A3x=b
