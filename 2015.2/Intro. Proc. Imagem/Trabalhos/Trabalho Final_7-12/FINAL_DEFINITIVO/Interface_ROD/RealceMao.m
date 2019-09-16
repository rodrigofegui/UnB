function [final, canny, crct] = RealceMao (back_cru, mao_crua)
    %%  Declaração das Variáveis e Constantes Iniciais
        %   'filtro' armazena o filtro a ser aplicado nas imagens, o de média
            filtro = fspecial ('average');
        %   'dif_gray' armazena a diferença entre o background e a imagem da
        %   mão em escala de Gray
            dif_gray = im2uint8 (zeros (size (back_cru, 1), size (back_cru,2)));
        %   'dif_cb' armazena a diferença entre o background e a imagem da
        %   mão no plano Cb, do YCbCr
            dif_cb = dif_gray;
        %   'dif_cr' armazena a diferença entre o background e a imagem da
        %   mão no plano Cr, do YCbCr
            dif_cr = dif_cb;
        %   'limiar_alvo' armazena o limiar desejado como separador da
        %   operação sobre a escala de cinza
            limiar_alvo = 0.62;


    %%  Pré-processamento Básico
        %   'back' armazena o resultado da suavisação do ruído na 'back_cru'
        %   com um 'filtro'
            back = imfilter (back_cru, filtro);
        %   'mao' armazena o resultado da suavisação do ruído na 'mao_crua'
        %   com um 'filtro'
            mao = imfilter (mao_crua, filtro);


    %%  Obtendo os Planos YCbCr das Imagens
        %   'back_ycbcr' armazena o background no espaço de cores YCbCr
            back_ycbcr = im2uint8(rgb2ycbcr (back));
        %   'mao_ycbcr' armazena a mão no espaço de cores YCbCr
            mao_ycbcr = im2uint8(rgb2ycbcr (mao));


    %%  Diferença em YCbCr
        %   Calculando a diferença entre as imagens, no plano Y,
        %   centralizando o resultado no nível 128
            dif_y = (mao_ycbcr(:, :, 1) - back_ycbcr(:, :, 1)) + 128;
        %   Calculando a diferença entre as imagens, no plano Cb
            dif_cb = (mao_ycbcr(:, :, 2) - back_ycbcr(:, :, 2));
        %   Calculando a diferença entre as imagens, no plano Cr
            dif_cr = (mao_ycbcr(:, :, 3) - back_ycbcr(:, :, 3));
        %   Calculando a diferença entre as imagens, nos dois planos,
        %   armazenando em 'dif2', centralizando o resultado no nível 128
            dif_ycbcr = (dif_cb + dif_cr) + 128;
        %   Configurando o limiar de luminosidade a ser binarizada
            limiar_y = graythresh (dif_y);


	%%  Binarizando as Diferenças
        %   'bin2' armazena o resultado da binarização sobre 'dif_ycbcr'
            bin2 = im2bw (dif_ycbcr, graythresh (dif_ycbcr));


	%%  Preenchimento das Binárias
        %   'bin_preen2' armazena o resultado do preenchimento de pequenos
        %   buracos da 'bin2'
            bin_preen2 = imfill (bin2, 'holes');
        %   'ES' armazena o elemento estruturante para a erosão
            ES = strel ('disk', 2);
        %   Operação morfológica de Erosão em ambas as binárias preenchidas
            bin_preen2 = imerode (bin_preen2, ES);


	%%  Reconhecimento de Regiões
        %   'reg2'  armazena as regiões detectadas para a 'bin_preen2'
            reg2 = bwlabel (bin_preen2, 8);


    %%  Tratamento das Regiões
        %   Extração das informações das regiões detectadas em 'reg2'
            status2 = regionprops (reg2, 'basic');
        %   Refinamento sobre as regiões encontradas, verificando cada
        %   região encontrada
            for ind = 1: size(status2)
                %   Estando abaixo de 5% da área total da imagem
                if ((status2(ind).Area < (0.05 * (size (back_cru, 1) * size (back_cru, 2)))))
                    %  Passando pelo refinamento, elimina-se tal região da
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
        %   Nova extração de informações, considerando a imagem
        %   pré-refinada
            status2 = regionprops (reg2, 'basic');


    %%  Verificando a necessidade de processar na Escala de Cinza
        if (limiar_y > limiar_alvo)
            %   Configuração da imagem final
                final = ProcessaCinza (back, mao, reg2);
        else
            %   Configuração da imagem final
                final = im2bw (reg2, graythresh(reg2));
        end
  
    %%  Verificando validade da imagem
        %   Tendo imagem diferente de totalmente preta
            compara = im2bw(zeros (size(final)));
            isequal (final, compara)
            if (isequal (final, compara) == 0)
            %%  Detecção de Borda da imagem a ser enviada
                %   Utilização do Processo Canny
                    canny = edge (final, 'Canny');

            %%   Extração de Características da Imagem
                %   'angulo' armazena o limiar da orientação da mão segmentada
                    angulo = 46;
                %   Extração da Características, em si
                    crct = regionprops (final, 'Orientation', 'Centroid', 'BoundingBox', 'Area');
                %   Avaliando Orientação da Mão
                %   Estando na Horizontal, converte para Vertical
                    if ((crct.Orientation > -angulo) && (crct.Orientation < angulo))
                    %   Estando orientado para baixo, gire sentido anti-horário
                        if ((crct.Orientation >= -angulo) && (crct.Orientation <= 0))
                            angulo_final = -90;
                    %   Caso contrário, gire sentido horário
                        else
                            angulo_final = 90;
                        end
                    %   Rotacionando a imagem
                        back_cru = imrotate (back_cru, angulo_final);
                        mao_crua = imrotate (mao_crua, angulo_final);
                        [final, canny, crct] = RealceMao (back_cru, mao_crua);
                    end
        %   Tendo imagem nula, todos os retornos são nulos   
            else
                final = 0;
                canny = 0;
                crct = 0;
            end
end