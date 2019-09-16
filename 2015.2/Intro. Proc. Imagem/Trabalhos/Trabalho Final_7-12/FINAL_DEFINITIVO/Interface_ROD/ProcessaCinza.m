function [final] = ProcessaCinza (back, mao, reg2)
    %%  Obtendo a Escala de Gray das Imagens
        %   'back_gray' armazena o background em escala de Gray
            back_gray = rgb2gray (back);
        %   'mao_gray' armazena a mão em escala de Gray
            mao_gray = rgb2gray (mao);


    %%  Diferença em Escala de Gray
        %   Calculando a diferença entre as imagens, em escala de Gray,
        %   centralizando o resultado no nível 128
            dif_gray = (mao_gray - back_gray) + 128;


     %%  Binarizando as Diferenças
        %   'bin' armazena o resultado da binarização sobre 'dif_gray'
            bin = im2bw (dif_gray, graythresh(dif_gray));


    %%  Preenchimento das Binárias
        %   'bin_preen' armazena o resultado do preenchimento de pequenos
        %   buracos da 'bin'
            bin_preen = imfill (bin, 'holes');
        %   'ES' armazena o elemento estruturante para a erosão
            ES = strel ('disk', 2);
        %   Operação morfológica de Erosão em ambas as binárias preenchidas
            bin_preen = imerode (bin_preen, ES);


    %%  Reconhecimento de Regiões
        %   São consideradas as conectivadades entre 8 vizinhos
        %   'reg1'  armazena as regiões detectadas para a 'bin_preen'
            reg1 = bwlabel (bin_preen, 8);


    %%  Tratamento das Regiões
        %   Extração das informações das regiões detectadas em 'reg1'
            status = regionprops (reg1, 'basic');
        %   Refinamento sobre as regiões encontradas, verificando cada
        %   região encontrada
            for ind = 1: size(status)
                %   Estando abaixo de 5% da área total da imagem
                if ((status(ind).Area < (0.05 * (size (back, 1) * size (back, 2)))))
                    %  Passando pelo refinamento, elimina-se tal região da
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
        %   Nova extração de informações, considerando a imagem
        %   pré-refinada
            status = regionprops (reg1, 'basic');


     %%  União das Regiões
        %   'uniao' armazena a uniao das regiões
            final = im2uint8 (zeros (size (back, 1), size (back,2)));
        %   Realização da união das regiões
            for lin = 1 : size(reg1, 1)
                for col = 1: size(reg1, 2)
                    if ((reg1(lin, col) > 0) || (reg2(lin, col) > 0))
                        final(lin, col) = 255;
                    end
                end
            end


    %%  Selecionando a imagem de retorno
        %   Extração das informações das regiões detectadas em 'reg2'
            status = regionprops (reg1, 'Area');
            percent = 0;
            for k = 1:size(status)
                percent = percent + status(k).Area; 
            end
            percent = (percent / (size(back, 1) * size(back, 2))) * 100;

            if (percent > 5)
                final = reg1;
            end

        %   Binarização da imagem, garantindo que seja lógica
            final = im2bw (final, graythresh(final));
end