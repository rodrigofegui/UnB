function [variancias, PSNRs] = Problema2(Info, Nome_imagem, ID, Exibir, Salvar)
    %%  Declaração das Variáveis e Constantes Iniciais
        %   'cont' armazena a quantidade de imagens exibidas e salvas em disco
            cont = 1;
        %   'variancia' armazena as variancias sobre as imagens
            variancias = zeros (1, size(Info.Quantizacao, 2));
        %   'PSNRs' armazena os PSNR sobre as imagens
            PSNRs = zeros (1, size(Info.Quantizacao, 2));


    %%  Carregando Imagem Base
        %   Construção final do nome da imagem
            nome_imagem_base = strcat (Info.Dir_ref, Nome_imagem);
        %   Carregar a imagem base, cuja identificação é 'nome_imagem_base', e
        %   armazenar em 'imagem_base'
            imagem_base = uint8 (imread (nome_imagem_base));


	%%  Realizando o Padding
        %   'pad_lin' armazena o padding nas linhas da 'imagem_base'
            pad_lin = mod (size(imagem_base, 1), Info.Tam_bloco);
            if (pad_lin ~= 0)
                pad_lin = Info.Tam_bloco - pad_lin;
            end
        %   'pad_col' armazena o padding nas linhas da 'imagem_base'
            pad_col = mod (size(imagem_base, 2), Info.Tam_bloco);
            if (pad_col ~= 0)
                pad_col = Info.Tam_bloco - pad_col;
            end
        %   Configuração do tamanho final da imagem com padding
            pad_lin = pad_lin + size(imagem_base, 1);
            pad_col = pad_col + size(imagem_base, 2);
        %   Criando imagem com padding;
            imagem_pad = uint8(zeros (pad_lin, pad_col));
        %   Copiando imagem sobre o padding
            imagem_pad (1 : size(imagem_base, 1), 1 : size(imagem_base, 2)) = imagem_base(:, :);
        %   Exibição e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (Info.Dir_result, imagem_pad, ID, cont, 'Imagem Base após Padding', Exibir, Salvar);


	%%  Aplicando a DCT e a Quantização em cada bloco
        %   'imagem_DCT' armazena o resultado da operação de DCT sobre a
        %   'imagem_pad', enquanto que 'imagem_iDCT' armazena a DCT inversa
        %   sobre o bloco;
            imagem_DCT = zeros (size (imagem_pad));
            imagem_iDCT = zeros (size (imagem_pad));
            
        %   'imagem_var' armazena uma imagem "simbolica", pois armazena as
        %   variancias dos blocos
            imagem_var = zeros (size (imagem_pad));
            %imagem_var = zeros (pad_lin / Info.Tam_bloco, pad_col / Info.Tam_bloco);

        %   Para todos os passos de quantização:
        %   'passo' armazena o passo de quantização corrente
            for ind = 1 : size(Info.Quantizacao, 2)
            %   Configuração do passo de quantização
                passo = Info.Quantizacao(ind);

            %	Percorrendo a imagem de 'Infos.Tam_bloco' em 'Infos.Tam_bloco', tanto
            %	na linha quanto coluna
                for lin = 1 : Info.Tam_bloco : size (imagem_pad, 1)
                    for col = 1 : Info.Tam_bloco : size (imagem_pad,2)
                    %   Limpeza do 'bloco_recons' para novas predições
                        if (col == 1)
                        %   'bloco_recons' armazena o bloco após a
                        %   reconstrução, base para a DPCM do próximo
                        %   bloco, visto que é utilizada a predição:
                        %   ^p = (x, y - 1)
                            predicao = uint8(zeros (Info.Tam_bloco));
                        end

                    %   'bloco' armazena um bloco da imagem a ser
                    %   processada, a menos da predição
                        bloco_imagem = imagem_pad (lin : (lin + Info.Tam_bloco - 1), col : (col + Info.Tam_bloco - 1));
                        bloco_imagem = bloco_imagem - predicao;
                    
                    %   'Transformacao' armazena o resultado da DCT sobre o
                    %   bloco
                        Transformacao = (dct2 (bloco_imagem)) ./ passo;
                        Transformacao = floor (Transformacao);
                    %   Armazenando o resultado da DCT
                        imagem_DCT (lin : (lin + Info.Tam_bloco - 1), col : (col + Info.Tam_bloco - 1)) = Transformacao;

                    %   Calculando Variância do bloco
                        if ((lin > 1) && (col > 1))
                            %imagem_var (round(lin/Info.Tam_bloco), round(col/Info.Tam_bloco)) = mean (var (Transformacao));
                            imagem_var (round(lin/Info.Tam_bloco), round(col/Info.Tam_bloco)) = (std2 (Transformacao))^2;
                        else
                            %imagem_var (1, 1) = mean (var (Transformacao));
                            imagem_var (1, 1) = (std2 (Transformacao))^2;
                        end

                    %   'Transformacao' armazena o resultado da DCT inversa
                    %   sobre o bloco
                        Transformacao = (idct2 (Transformacao)) .* passo;
                        Transformacao = floor(Transformacao);

                    %   Armazenando o resultado da DCT
                        imagem_iDCT (lin : (lin + Info.Tam_bloco - 1), col : (col + Info.Tam_bloco - 1)) = Transformacao;

                    %   Armazenando o último bloco reconstruído
                        predicao = uint8(Transformacao);
                    end
                end

            %   Redefinindo o tamanho das imagens manipuladas
                imagem_DCT = imagem_DCT(1 : size (imagem_base, 1), 1 : size (imagem_base, 2));
                imagem_iDCT = imagem_iDCT(1 : size (imagem_base, 1), 1 : size (imagem_base, 2));

            %   Avalianda a Variância sobre todas as variâncias
                variancias(ind) = mean(mean(imagem_var));
                
            %   Avaliação do PSNR das imagens
                PSNRs(ind) = PSNR (imagem_base, imagem_iDCT);
                
            %   Construção da legenda para 'imagem_DCT'
                legenda = strcat ('Passo_', num2str(passo));
                legenda = strcat (legenda, '_DCT');
            %   Conversão necessária da imagem alvo
                imagem_DCT = uint8(imagem_DCT);
            %   Exibição e Armazenamento em Disco da Imagem
                cont = Exibe_Salva (Info.Dir_result, imagem_DCT, ID, cont, legenda, Exibir, Salvar);

            %   Construção da legenda para 'imagem_iDCT'
                legenda = strcat ('Passo_', num2str(passo));
                legenda = strcat (legenda, '_DCT inversa');
            %   Conversão necessária da imagem alvo
                imagem_iDCT = uint8(imagem_iDCT);
            %   Exibição e Armazenamento em Disco da Imagem
                cont = Exibe_Salva (Info.Dir_result, imagem_iDCT, ID, cont, legenda, Exibir, Salvar);            
            end
end