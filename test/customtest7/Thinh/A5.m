% 1 . Tinh dao ham rieng cua cac ham so sau
clc; clear all; close all;
syms x y u v
% a
f1_a=(x^3+y^3)/(x^2+y^2);
df_1ax=diff(f1_a,x)
df_ay=diff(f1_a,y)
% b
f1_b=log(((x^2+y^2)^1/2-x)/((x^2+y^2)^1/2)+x);
df1_bx=diff(f1_b,x)
df1_by=diff(f1_b,y)
% c
f1_c=exp(x*y)*cos(x)*sin(y);
df1_cx=diff(f1_c,x)
df1_cy=diff(f1_c,y)
% 2. Tinh dao ham cua ham hop
% a
f2_a=exp(u^2-2*v^2);
df2_au=diff(f2_a,u);
df2_av=diff(f2_a,v);
u_a=cos(x);
du_ax=diff(u_a,x);
du_ay=diff(u_a,y);
v_a=(x^2+y^2)^1/2;
dv_ax=diff(v_a,x);
dv_ay=diff(v_a,y);
df2_ax=(df2_au)*(du_ax)+(df2_av)*(dv_ax)
df2_ay=(df2_au)*(du_ay)+(df2_av)*(dv_ay)
% b
f2_b=log(u^2+v^2);
df2_bu=diff(f2_b,u);
df2_bv=diff(f2_b,v);
u_b=x*y;
du_bx=diff(u_b,x);
du_by=diff(u_b,y);
v_b=x/y;
dv_bx=diff(v_b,x);
dv_by=diff(v_b,y);
df2_bx=df2_bu*du_bx+df2_bv*dv_bx
df2_by=df2_bu*du_by+df2_bv*dv_by
