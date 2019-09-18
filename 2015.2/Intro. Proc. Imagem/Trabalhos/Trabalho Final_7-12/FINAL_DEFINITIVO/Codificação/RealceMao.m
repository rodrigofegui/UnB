function [final, canny, crct, cont] = RealceMao (dir_ref, back_cru, mao_crua, ID, exibe, salva, reexecucao)
    %%  Declara��o das Vari�veis e Constantes Iniciais
        %   'cont' armazena a quantidade de imagens exibidas e salvas em disco
            cont = 1;
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
            limiar_y = graythresh(dif_y);
            
        %   Exibi��o e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (dir_ref, ID, dif_y, 'Diferen�a no Plano Y', cont, exibe, salva);
          
        %   Exibi��o e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (dir_ref, ID, dif_cb, 'Diferen�a no Plano Cb', cont, exibe, salva);
        
        %   Exibi��o e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (dir_ref, ID, dif_cr, 'Diferen�a no Plano Cr', cont, exibe, salva);
        
        %   Exibi��o e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (dir_ref, ID, dif_ycbcr, 'Diferen�a no Espa�o YCbCr, centralizado em 128', cont, exibe, salva);


	%%  Binarizando as Diferen�as
        %   'bin2' armazena o resultado da binariza��o sobre 'dif_ycbcr'
            bin2 = im2bw (dif_ycbcr, graythresh(dif_ycbcr));

        %   Exibi��o e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (dir_ref, ID, bin2, 'Binaria sobre a Diferen�a no Espa�o YCbCr', cont, exibe, salva);


	%%  Preenchimento das Bin�rias
            ES = strel ('disk', 6);
            bin2 = imdilate (bin2, ES);
        %   'bin_preen2' armazena o resultado do preenchimento de pequenos
        %   buracos da 'bin2'
            bin_preen2 = imfill (bin2, 'holes');
        %   'ES' armazena o elemento estruturante para a eros�o
            ES = strel ('disk', 4);
        %   Opera��o morfol�gica de Eros�o em ambas as bin�rias preenchidas
            bin_preen2 = imerode (bin_preen2, ES);
            
            

        %   Exibi��o e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (dir_ref, ID, bin_preen2, 'Binaria Preenchida sobre a Diferen�a no Espa�o YCbCr', cont, exibe, salva);


	%%  Reconhecimento de Regi�es
        %   'reg2'  armazena as regi�es detectadas para a 'bin_preen2'
            reg2 = bwlabel (bin_preen2, 8);
        
        %   Exibi��o e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (dir_ref, ID, label2rgb(reg2), 'Regi�es Detectadas sobre a Diferen�a no Espa�o YCbCr', cont, exibe, salva);


    %%  Tratamento das Regi�es
        %   Extra��o das informa��es das regi�es detectadas em 'reg2'
            reg2 = TrataRegioes (reg2);
        
        %   Exibi��o e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (dir_ref, ID, reg2, 'Binaria Preenchida Refinada sobre a Diferen�a no Espa�o YCbCr', cont, exibe, salva);

    %%  Verificando a necessidade de processar na Escala de Cinza
        %   Tendo ao teor de luz, ent�o avalia-se na escala de cinza
        if (limiar_y > limiar_alvo)
            %   Configura��o da imagem final
                [final, cont] = ProcessaCinza (dir_ref, back, mao, reg2, ID, cont, exibe, salva);
        else
            %   Configura��o da imagem final
                final = im2bw (reg2, graythresh(reg2));
        end

        cont = Exibe_Salva (dir_ref, ID, final, 'A Extrair Caracter�sticas', cont, exibe, salva);
    %%  Verificando validade da imagem
        %   'nula' armazena uma imagem totalmente preta
            nula = im2bw(zeros (size(final)));
        %   Verificando se h� algo na imagem
            if (~isequal(nula, final) && (reexecucao < 2))
            %%  Detec��o de Borda da imagem a ser enviada
                %   Utiliza��o do Processo Canny
                    canny = edge (final, 'Canny');
                %   Exibi��o e Armazenamento em Disco da Imagem
                    cont = Exibe_Salva (dir_ref, ID, canny, 'Bordas Detectadas', cont, exibe, salva);

            %%   Extra��o de Caracter�sticas da Imagem
                %   'angulo' armazena o limiar da orienta��o da m�o segmentada
                    angulo = 46;
                %   Extra��o da Caracter�sticas, em si
                    crct = regionprops (final, 'Orientation', 'Centroid', 'BoundingBox', 'Area');
                    %   Avaliando Orienta��o da M�o
                    %   Estando na Horizontal, converte para Vertical
                        if (and([crct.Orientation] > -angulo, [crct.Orientation] < angulo))
                        %   Estando orientado para baixo, gire sentido anti-hor�rio
                            if (([crct.Orientation] >= -angulo) && ([crct.Orientation] <= 0))
                                angulo_final = -90;
                        %   Caso contr�rio, gire sentido hor�rio
                            else
                                angulo_final = 90;
                            end
                        %   Rotacionando a imagem
                            back_cru = imrotate (back_cru, angulo_final);
                            mao_crua = imrotate (mao_crua, angulo_final);
                            [final, canny, crct] = RealceMao (dir_ref, back_cru, mao_crua, ID, exibe, salva, reexecucao + 1);
                        end
                    %end
        %   Tendo imagem nula, todos os retornos s�o nulos   
            else
                final = 0;
                canny = 0;
                crct = regionprops (nula, 'Area');
            end
end
