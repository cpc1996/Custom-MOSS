clc;
A1 = [1 2 3; 4 5 6; 7 8 9];
A2 = [1 1 3; 4 5 6; 7 8 9];
A3 = [0.9999 2 3; 4 5 6; 7 8 9];
b1 = [1;1;3];
b2 = [1;2;3];
R11 = [rank(A1) rank([A1 b1])]
R12 = [rank(A1) rank([A1 b2])]
R21 = [rank(A2) rank([A2 b1])]
R22 = [rank(A2) rank([A2 b2])]
R31 = [rank(A3) rank([A3 b1])]
R32 = [rank(A3) rank([A3 b2])]
%phan a
disp('Phuong trinh co nghiem duy nhat: A2*x=b1, A2*x = b2, A3*x = b1, A3*x = b2');
disp('Nghiem cua pt A2*x=b1 la: '); x21 = inv(A2)*b1
disp('sai so: '); norm(A2*x21-b1)
disp('Nghiem cua pt A2*x=b2 la: '); x22 = inv(A2)*b2
disp('sai so: '); norm(A2*x22-b2)
disp('Nghiem cua pt A3*x=b1 la: '); x31 = inv(A3)*b1
disp('sai so: '); norm(A3*x31-b1)
disp('nghiem cua pt A3*x=b2: '); x32 = inv(A3)*b2
disp('sai so: '); norm(A3*x32-b2)
%phan b
disp('Phuong trinh vo nghiem la: A1*x=b1');
disp('Tua nghiem cua pt A1*x=b1 la: ');
x0 = null(A1);
x11 = pinv(A1)*b1
disp('Nghiem vo dinh: ');
c1 = randn;
x11vd = x11 + c1*x0(:,1)
disp('sai so: '); norm(A1*x11-b1)
%phan c
disp('Phuong trinh vo dinh la: A1*x=b2');
disp('nghiem tong quat: ');
xx0 = null(A1);
x22 = pinv(A1)*b2
disp('Mot nghiem rieng la: ');
c2 = randn;
x22r = x22 + c2*xx0(:,1)
disp('sai so: '); norm(A1*x22-b2)
%ma tran ko on dinh la A3x=b note e-10 can luu ý
