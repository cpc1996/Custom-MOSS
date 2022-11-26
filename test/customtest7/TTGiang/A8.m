clc; clear all; close all;
A1 = [1 2 3; 4 5 6; 7 8 9];
A2 = [1 1 3; 4 5 6; 7 8 9];
A3 = [0.9999 2 3; 4 5 6; 7 8 9];
b1 = [1;1;3];
b2 = [1;2;3];

d1 = det(A1),d2 = det(A2), d3 = det(A3)
%Phan a: nghiem duy nhat A2*x=b1, A2*x=b2, A3*x=b1, A3*x=b2
disp('Nghiem cua cac pt co duy nhat mot nghiem la: ');
x21 =inv(A2)*b1, nrm21 = norm(A2*x21 - b1)
x22 =inv(A2)*b2, nrm22 = norm(A2*x22 - b2)
x31 =inv(A3)*b1, nrm31 = norm(A3*x31 - b1)
x32 =inv(A3)*b2, nrm32 = norm(A3*x32 - b2)

%Phan b: Phuong trinh vo nghiem : A1*x=b1
disp('Tua nghiem cua pt vo nghiem la: ');
x0b = null(A1)
xc1 = pinv(A1)*b1
c1 = randn; x11 = xc1+c1*x0b(:,1)
nrm11= norm(A1*xc1-b1)

%Phan c: Phuong trinh vo dinh: A1*x=b2
disp('Cac pt vo dinh: ');
x0c = null(A1)
xc2 = pinv(A1)*b2
c2 = randn; x12 = xc2+c2*x0c(:,1)
nrm12= norm(A1*xc2-b1)

%Phan d: Phuong trinh khong on dinh nghiem 
disp('Phuong trinh co nghiem khong on dinh: A1*x=b1,A3*x=b1,A1*x=b2, A3*x=b2 ')
disp ('Voi A1*x=b1,     A3*x=b1')
X11=pinv(A1)*b1
X31=pinv(A3)*b1
disp('Nghiem cua 2 phuong trinh nay la khac nhau, mac du A1 gan giong A3')
disp('Voi A1*x=b2, A3*x=b2')
x12=pinv(A1)*b2
X32=pinv(A3)*b2
disp('Nghiem cua 2 phuong trinh nay la khac nhau, mac du A1 gan giong A3')
