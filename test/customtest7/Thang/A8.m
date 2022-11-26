A1=[1 2 3;4 5 6;7 8 9];
A2=[1 1 3;4 5 6;7 8 9];
A3=[0.9999 2 3;4 5 6; 7 8 9];
b1=[1;1;3];
b2=[1;2;3];
% Cau a
% Cac phuong trinh co nghiem duy nhat la: A2*x=b1, A2*x=b2, A3*x=b1,A3*x=b2
%A2*x=b1
X21=pinv(A2)*b1
n21=norm(A2*X21-b1)
%A2*x=b2
X22=pinv(A2)*b2
n22=norm(A2*X22-b2)
%A3*x=b1
X31=pinv(A3)*b1
n31=norm(A3*X31-b1)
%A3*x=b2
X32=pinv(A3)*b2
n32=norm(A3*X32-b2)
% Cau b
% Phuong trinh vo nghiem : A1*x=b1
X0b=null(A1)
X11=pinv(A1)*b1
n11=norm(A1*X11-b1)
% Cau c
%Phuong trinh vo dinh: A1*x=b2
X0c= null(A1)
X12=pinv(A1)*b2
c=randn, X = X12 + c*X0c(:,1)
n12=norm(A1*X12-b2)
% Cau d
