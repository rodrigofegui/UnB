function [final, cont] = ProcessaCinza (dir_ref, back, mao, reg2, ID, cont, exibe, salva)
    %%  Obtendo a Escala de Gray das Imagens
        %   'back_gray' armazena o background em escala de Gray
            back_gray = rgb2gray (back);
        %   'mao_gray' armazena a m�o em escala de Gray
            mao_gray = rgb2gray (mao);


    %%  Diferen�a em Escala de Gray
        %   Calculando a diferen�a entre as imagens, em escala de Gray,
        %   centralizando o resultado no n�vel 128
            dif_gray = (mao_gray - back_gray) + 128;

        %   Exibi��o e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (dir_ref, ID, dif_gray, 'Diferen�a em Escala de Gray', cont, exibe, salva);


     %%  Binarizando as Diferen�as
        %   'bin' armazena o resultado da binariza��o sobre 'dif_gray'
            bin = im2bw (dif_gray, graythresh(dif_gray));

        %   Exibi��o e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (dir_ref, ID, bin, 'Binaria sobre a Diferen�a em Escala de Gray', cont, exibe, salva);


    %%  Preenchimento das Bin�rias
        %   'bin_preen' armazena o resultado do preenchimento de pequenos
        %   buracos da 'bin'
            bin_preen = imfill (bin, 'holes');
        %   'ES' armazena o elemento estruturante para a eros�o
            ES = strel ('disk', 2);
        %   Opera��o morfol�gica de Eros�o em ambas as bin�rias preenchidas
            bin_preen = imerode (bin_preen, ES);

        %   Exibi��o e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (dir_ref, ID, bin_preen, 'Binaria Preenchida sobre a Diferen�a em Escala de Gray', cont, exibe, salva);


    %%  Reconhecimento de Regi�es
        %   S�o consideradas as conectivadades entre 8 vizinhos
        %   'reg1'  armazena as regi�es detectadas para a 'bin_preen'
            reg1 = bwlabel (bin_preen, 8);

        %   Exibi��o e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (dir_ref, ID, label2rgb(reg1), 'Regi�es Detectadas sobre a Diferen�a em Escala de Gray', cont, exibe, salva);


    %%  Tratamento das Regi�es
        %   Extra��o das informa��es das regi�es detectadas em 'reg1'
            reg1 = TrataRegioes (reg1);

        %   Exibi��o e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (dir_ref, ID, reg1, 'Binaria Preenchida Refinada sobre a Diferen�a em Escala de Gray', cont, exibe, salva);


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

        %   Binariza��o da imagem, garantindo que seja l�gica
            %uniao = im2bw (uniao, graythresh(uniao));

        %   Exibi��o e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (dir_ref, ID, final, 'Uni�o das M�os Detectadas', cont, exibe, salva);


    %%  Selecionando a imagem de retorno
        %   Extra��o das informa��es das regi�es detectadas em 'reg2'
            status = regionprops (reg1, 'Area');
        %   Avaliando a porcentagem da �rea ocupada pela "mao" segmentada
            percent = 0;
            for k = 1:size(status)
                percent = percent + status(k).Area; 
            end
            percent = (percent / (size(back, 1) * size(back, 2))) * 100;
        %   Estando abaixo de 5% a imagem "original" � utilizada
            if (percent < 5)
                final = reg1;
            end
        %   Binariza��o da imagem, garantindo que seja l�gica
            final = im2bw (final, graythresh(final));
end

