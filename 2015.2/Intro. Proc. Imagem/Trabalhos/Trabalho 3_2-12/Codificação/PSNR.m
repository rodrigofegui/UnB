function [result] = PSNR (original, modificada)
    %   Conversão das imagens para o formato double
        original = double(original);
        modificada = double(modificada);
        
    %   Determinando o valor máximo possível
        maximo = 255;
        
    %   Cálculo do MSE entre as imagens
        MSE = 0;
        for lin = 1:size(original, 1)
            for col = 1:size(original, 2)
                MSE = MSE + (original(lin, col) - modificada(lin, col))^2;
            end
        end
        MSE = MSE / (size (original, 1) * size (original, 2));
        
    %   Cálculo Final da PSNR
        result = 20 * (log10 (maximo / sqrt(MSE)));
end

