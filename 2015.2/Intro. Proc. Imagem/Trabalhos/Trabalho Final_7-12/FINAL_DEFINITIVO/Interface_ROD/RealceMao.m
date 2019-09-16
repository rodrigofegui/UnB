function [final, canny, crct] = RealceMao (back_cru, mao_crua)
    %%  Declara��o das Vari�veis e Constantes Iniciais
        %   'filtro' armazena o filtro a ser aplicado nas imagens, o de m�dia
            filtro = fspecial ('average');
        %   'dif_gray' armazena a diferen�a entre o background e a imagem da
        %   m�o em escala de Gray
            dif_gray = im2uint8 (zeros (size (back_cru, 1), size (back_cru,2)));
        %   'dif_cb' armazena a diferen�a entre o background e a imagem da
        %   m�o no plano Cb, do YCbCr
            dif_cb = dif_gray;
        %   'dif_cr' armazena a diferen�a entre o background e a imagem da
        %   m�o no plano Cr, do YCbCr
            dif_cr = dif_cb;
        %   'limiar_alvo' armazena o limiar desejado como separador da
        %   opera��o sobre a escala de cinza
            limiar_alvo = 0.62;


    %%  Pr�-processamento B�sico
        %   'back' armazena o resultado da suavisa��o do ru�do na 'back_cru'
        %   com um 'filtro'
            back = imfilter (back_cru, filtro);
        %   'mao' armazena o resultado da suavisa��o do ru�do na 'mao_crua'
        %   com um 'filtro'
            mao = imfilter (mao_crua, filtro);


    %%  Obtendo os Planos YCbCr das Imagens
        %   'back_ycbcr' armazena o background no espa�o de cores YCbCr
            back_ycbcr = im2uint8(rgb2ycbcr (back));
        %   'mao_ycbcr' armazena a m�o no espa�o de cores YCbCr
            mao_ycbcr = im2uint8(rgb2ycbcr (mao));


    %%  Diferen�a em YCbCr
        %   Calculando a diferen�a entre as imagens, no plano Y,
        %   centralizando o resultado no n�vel 128
            dif_y = (mao_ycbcr(:, :, 1) - back_ycbcr(:, :, 1)) + 128;
        %   Calculando a diferen�a entre as imagens, no plano Cb
            dif_cb = (mao_ycbcr(:, :, 2) - back_ycbcr(:, :, 2));
        %   Calculando a diferen�a entre as imagens, no plano Cr
            dif_cr = (mao_ycbcr(:, :, 3) - back_ycbcr(:, :, 3));
        %   Calculando a diferen�a entre as imagens, nos dois planos,
        %   armazenando em 'dif2', centralizando o resultado no n�vel 128
            dif_ycbcr = (dif_cb + dif_cr) + 128;
        %   Configurando o limiar de luminosidade a ser binarizada
            limiar_y = graythresh (dif_y);


	%%  Binarizando as Diferen�as
        %   'bin2' armazena o resultado da binariza��o sobre 'dif_ycbcr'
            bin2 = im2bw (dif_ycbcr, graythresh (dif_ycbcr));


	%%  Preenchimento das Bin�rias
        %   'bin_preen2' armazena o resultado do preenchimento de pequenos
        %   buracos da 'bin2'
            bin_preen2 = imfill (bin2, 'holes');
        %   'ES' armazena o elemento estruturante para a eros�o
            ES = strel ('disk', 2);
        %   Opera��o morfol�gica de Eros�o em ambas as bin�rias preenchidas
            bin_preen2 = imerode (bin_preen2, ES);


	%%  Reconhecimento de Regi�es
        %   'reg2'  armazena as regi�es detectadas para a 'bin_preen2'
            reg2 = bwlabel (bin_preen2, 8);


    %%  Tratamento das Regi�es
        %   Extra��o das informa��es das regi�es detectadas em 'reg2'
            status2 = regionprops (reg2, 'basic');
        %   Refinamento sobre as regi�es encontradas, verificando cada
        %   regi�o encontrada
            for ind = 1: size(status2)
                %   Estando abaixo de 5% da �rea total da imagem
                if ((status2(ind).Area < (0.05 * (size (back_cru, 1) * size (back_cru, 2)))))
                    %  Passando pelo refinamento, elimina-se tal regi�o da
                    %  imagem
                    for lin = 1: size (reg2, 1)
                        for col = 1: size (reg2, 2)
                            if (reg2 (lin, col) == ind)
                                reg2 (lin, col) = 0;
                            end
                        end
                    end
                end
            end
        %   Nova extra��o de informa��es, considerando a imagem
        %   pr�-refinada
            status2 = regionprops (reg2, 'basic');


    %%  Verificando a necessidade de processar na Escala de Cinza
        if (limiar_y > limiar_alvo)
            %   Configura��o da imagem final
                final = ProcessaCinza (back, mao, reg2);
        else
            %   Configura��o da imagem final
                final = im2bw (reg2, graythresh(reg2));
        end
  
    %%  Verificando validade da imagem
        %   Tendo imagem diferente de totalmente preta
            compara = im2bw(zeros (size(final)));
            isequal (final, compara)
            if (isequal (final, compara) == 0)
            %%  Detec��o de Borda da imagem a ser enviada
                %   Utiliza��o do Processo Canny
                    canny = edge (final, 'Canny');

            %%   Extra��o de Caracter�sticas da Imagem
                %   'angulo' armazena o limiar da orienta��o da m�o segmentada
                    angulo = 46;
                %   Extra��o da Caracter�sticas, em si
                    crct = regionprops (final, 'Orientation', 'Centroid', 'BoundingBox', 'Area');
                %   Avaliando Orienta��o da M�o
                %   Estando na Horizontal, converte para Vertical
                    if ((crct.Orientation > -angulo) && (crct.Orientation < angulo))
                    %   Estando orientado para baixo, gire sentido anti-hor�rio
                        if ((crct.Orientation >= -angulo) && (crct.Orientation <= 0))
                            angulo_final = -90;
                    %   Caso contr�rio, gire sentido hor�rio
                        else
                            angulo_final = 90;
                        end
                    %   Rotacionando a imagem
                        back_cru = imrotate (back_cru, angulo_final);
                        mao_crua = imrotate (mao_crua, angulo_final);
                        [final, canny, crct] = RealceMao (back_cru, mao_crua);
                    end
        %   Tendo imagem nula, todos os retornos s�o nulos   
            else
                final = 0;
                canny = 0;
                crct = 0;
            end
end