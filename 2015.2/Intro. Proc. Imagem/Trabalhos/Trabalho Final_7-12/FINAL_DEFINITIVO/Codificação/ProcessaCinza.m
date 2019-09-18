function [final, cont] = ProcessaCinza (dir_ref, back, mao, reg2, ID, cont, exibe, salva)
    %%  Obtendo a Escala de Gray das Imagens
        %   'back_gray' armazena o background em escala de Gray
            back_gray = rgb2gray (back);
        %   'mao_gray' armazena a mão em escala de Gray
            mao_gray = rgb2gray (mao);


    %%  Diferença em Escala de Gray
        %   Calculando a diferença entre as imagens, em escala de Gray,
        %   centralizando o resultado no nível 128
            dif_gray = (mao_gray - back_gray) + 128;

        %   Exibição e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (dir_ref, ID, dif_gray, 'Diferença em Escala de Gray', cont, exibe, salva);


     %%  Binarizando as Diferenças
        %   'bin' armazena o resultado da binarização sobre 'dif_gray'
            bin = im2bw (dif_gray, graythresh(dif_gray));

        %   Exibição e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (dir_ref, ID, bin, 'Binaria sobre a Diferença em Escala de Gray', cont, exibe, salva);


    %%  Preenchimento das Binárias
        %   'bin_preen' armazena o resultado do preenchimento de pequenos
        %   buracos da 'bin'
            bin_preen = imfill (bin, 'holes');
        %   'ES' armazena o elemento estruturante para a erosão
            ES = strel ('disk', 2);
        %   Operação morfológica de Erosão em ambas as binárias preenchidas
            bin_preen = imerode (bin_preen, ES);

        %   Exibição e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (dir_ref, ID, bin_preen, 'Binaria Preenchida sobre a Diferença em Escala de Gray', cont, exibe, salva);


    %%  Reconhecimento de Regiões
        %   São consideradas as conectivadades entre 8 vizinhos
        %   'reg1'  armazena as regiões detectadas para a 'bin_preen'
            reg1 = bwlabel (bin_preen, 8);

        %   Exibição e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (dir_ref, ID, label2rgb(reg1), 'Regiões Detectadas sobre a Diferença em Escala de Gray', cont, exibe, salva);


    %%  Tratamento das Regiões
        %   Extração das informações das regiões detectadas em 'reg1'
            reg1 = TrataRegioes (reg1);

        %   Exibição e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (dir_ref, ID, reg1, 'Binaria Preenchida Refinada sobre a Diferença em Escala de Gray', cont, exibe, salva);


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

        %   Binarização da imagem, garantindo que seja lógica
            %uniao = im2bw (uniao, graythresh(uniao));

        %   Exibição e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (dir_ref, ID, final, 'União das Mãos Detectadas', cont, exibe, salva);


    %%  Selecionando a imagem de retorno
        %   Extração das informações das regiões detectadas em 'reg2'
            status = regionprops (reg1, 'Area');
        %   Avaliando a porcentagem da área ocupada pela "mao" segmentada
            percent = 0;
            for k = 1:size(status)
                percent = percent + status(k).Area; 
            end
            percent = (percent / (size(back, 1) * size(back, 2))) * 100;
        %   Estando abaixo de 5% a imagem "original" é utilizada
            if (percent < 5)
                final = reg1;
            end
        %   Binarização da imagem, garantindo que seja lógica
            final = im2bw (final, graythresh(final));
end

