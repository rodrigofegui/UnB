function [final] = ProcessaCinza (back, mao, reg2)
    %%  Obtendo a Escala de Gray das Imagens
        %   'back_gray' armazena o background em escala de Gray
            back_gray = rgb2gray (back);
        %   'mao_gray' armazena a m�o em escala de Gray
            mao_gray = rgb2gray (mao);


    %%  Diferen�a em Escala de Gray
        %   Calculando a diferen�a entre as imagens, em escala de Gray,
        %   centralizando o resultado no n�vel 128
            dif_gray = (mao_gray - back_gray) + 128;


     %%  Binarizando as Diferen�as
        %   'bin' armazena o resultado da binariza��o sobre 'dif_gray'
            bin = im2bw (dif_gray, graythresh(dif_gray));


    %%  Preenchimento das Bin�rias
        %   'bin_preen' armazena o resultado do preenchimento de pequenos
        %   buracos da 'bin'
            bin_preen = imfill (bin, 'holes');
        %   'ES' armazena o elemento estruturante para a eros�o
            ES = strel ('disk', 2);
        %   Opera��o morfol�gica de Eros�o em ambas as bin�rias preenchidas
            bin_preen = imerode (bin_preen, ES);


    %%  Reconhecimento de Regi�es
        %   S�o consideradas as conectivadades entre 8 vizinhos
        %   'reg1'  armazena as regi�es detectadas para a 'bin_preen'
            reg1 = bwlabel (bin_preen, 8);


    %%  Tratamento das Regi�es
        %   Extra��o das informa��es das regi�es detectadas em 'reg1'
            status = regionprops (reg1, 'basic');
        %   Refinamento sobre as regi�es encontradas, verificando cada
        %   regi�o encontrada
            for ind = 1: size(status)
                %   Estando abaixo de 5% da �rea total da imagem
                if ((status(ind).Area < (0.05 * (size (back, 1) * size (back, 2)))))
                    %  Passando pelo refinamento, elimina-se tal regi�o da
                    %  imagem
                    for lin = 1: size (reg1, 1)
                        for col = 1: size (reg1, 2)
                            if (reg1 (lin, col) == ind)
                                reg1 (lin, col) = 0;
                            end
                        end
                    end
                end
            end
        %   Nova extra��o de informa��es, considerando a imagem
        %   pr�-refinada
            status = regionprops (reg1, 'basic');


     %%  Uni�o das Regi�es
        %   'uniao' armazena a uniao das regi�es
            final = im2uint8 (zeros (size (back, 1), size (back,2)));
        %   Realiza��o da uni�o das regi�es
            for lin = 1 : size(reg1, 1)
                for col = 1: size(reg1, 2)
                    if ((reg1(lin, col) > 0) || (reg2(lin, col) > 0))
                        final(lin, col) = 255;
                    end
                end
            end


    %%  Selecionando a imagem de retorno
        %   Extra��o das informa��es das regi�es detectadas em 'reg2'
            status = regionprops (reg1, 'Area');
            percent = 0;
            for k = 1:size(status)
                percent = percent + status(k).Area; 
            end
            percent = (percent / (size(back, 1) * size(back, 2))) * 100;

            if (percent > 5)
                final = reg1;
            end

        %   Binariza��o da imagem, garantindo que seja l�gica
            final = im2bw (final, graythresh(final));
end