function [] = Taylorcosh (x, N)
        syms x, N
        % cosh(x)
        fcosh = 0; tong = 1;
        for k = 1:10
                    fcosh = fcosh + tong;
                        tong = x^(2*k)/factorial(2*k);
        end
        fcosh
