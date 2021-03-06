function [variancias, PSNRs] = Problema1 (Info, Nome_imagem, ID, Exibir, Salvar)
    %%  Declara��o das Vari�veis e Constantes Iniciais
        %   'cont' armazena a quantidade de imagens exibidas e salvas em disco
            cont = 1;
        %   'variancia' armazena as variancias sobre as imagens
            variancias = zeros (1, size(Info.Quantizacao, 2));
        %   'PSNRs' armazena os PSNR sobre as imagens
            PSNRs = zeros (1, size(Info.Quantizacao, 2));


    %%  Carregando Imagem Base
        %   Constru��o final do nome da imagem
            nome_imagem_base = strcat (Info.Dir_ref, Nome_imagem);
        %   Carregar a imagem base, cuja identifica��o � 'nome_imagem_base', e
        %   armazenar em 'imagem_base'
            imagem_base = uint8 (imread (nome_imagem_base));
        %   Exibi��o e Armazenamento em Disco da Imagem
            %cont = Exibe_Salva (Info.Dir_result, imagem_base, ID, cont, 'Imagem Base', Exibir, Salvar);


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
        %   Configura��o do tamanho final da imagem com padding
            pad_lin = pad_lin + size(imagem_base, 1);
            pad_col = pad_col + size(imagem_base, 2);
        %   Criando imagem com padding;
            imagem_pad = uint8(zeros (pad_lin, pad_col));
        %   Copiando imagem sobre o padding
            imagem_pad (1 : size(imagem_base, 1), 1 : size(imagem_base, 2)) = imagem_base(:, :);
        %   Exibi��o e Armazenamento em Disco da Imagem
            cont = Exibe_Salva (Info.Dir_result, imagem_pad, ID, cont, 'Imagem Base ap�s Padding', Exibir, Salvar);


	%%  Aplicando a DCT e a Quantiza��o em cada bloco
        %   'imagem_DCT' armazena o resultado da opera��o de DCT sobre a
        %   'imagem_pad', enquanto que 'imagem_iDCT' armazena a DCT inversa
        %   sobre o bloco;
            imagem_DCT = zeros (size (imagem_pad));
            imagem_iDCT = zeros (size (imagem_pad));
            
        %   'imagem_var' armazena uma imagem "simbolica", pois armazena as
        %   variancias dos blocos
            imagem_var = zeros (pad_lin / Info.Tam_bloco, pad_col / Info.Tam_bloco);
            
        %   Para todos os passos de quantiza��o:
        %   'passo' armazena o passo de quantiza��o corrente
            for ind = 1 : size(Info.Quantizacao, 2)
            %   Configura��o do passo de quantiza��o
                passo = Info.Quantizacao(ind);
            %	Percorrendo a imagem de 'Infos.Tam_bloco' em 'Infos.Tam_bloco', tanto
            %	na linha quanto coluna
                for lin = 1 : Info.Tam_bloco : size (imagem_pad, 1)
                    for col = 1 : Info.Tam_bloco : size (imagem_pad,2)
                    %   'bloco' armazena um bloco da imagem a ser
                    %   processada
                        bloco = imagem_pad (lin : (lin + Info.Tam_bloco - 1), col : (col + Info.Tam_bloco - 1));
                    
                    %   'Transformacao' armazena o resultado da DCT sobre o
                    %   bloco
                        Transformacao = (dct2 (bloco)) ./ passo;
                        Transformacao = floor (Transformacao);
                    %   Armazenando o resultado da DCT
                        imagem_DCT (lin : (lin + Info.Tam_bloco - 1), col : (col + Info.Tam_bloco - 1)) = Transformacao;

                    %   Calculando Vari�ncia do bloco
                        if ((lin > 1) && (col > 1))
                            %imagem_var (floor(lin/Info.Tam_bloco), floor(col/Info.Tam_bloco)) = mean (var (Transformacao));
                            imagem_var (floor(lin/Info.Tam_bloco), floor(col/Info.Tam_bloco)) = (std2 (Transformacao))^2;
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
                    end
                end

            %   Redefinindo o tamanho das imagens manipuladas
                imagem_DCT = imagem_DCT(1 : size (imagem_base, 1), 1 : size (imagem_base, 2));
                imagem_iDCT = imagem_iDCT(1 : size (imagem_base, 1), 1 : size (imagem_base, 2));

            %   Avalianda a Vari�ncia sobre todas as vari�ncias
                variancias(ind) = mean(mean(imagem_var));
                
            %   Avalia��o do PSNR das imagens
                PSNRs(ind) = PSNR (imagem_base, imagem_iDCT);
                
            %   Constru��o da legenda para 'imagem_DCT'
                legenda = strcat ('Passo_', num2str(passo));
                legenda = strcat (legenda, '_DCT');
            %   Convers�o necess�ria da imagem alvo
                imagem_DCT = uint8(imagem_DCT);
            %   Exibi��o e Armazenamento em Disco da Imagem
                cont = Exibe_Salva (Info.Dir_result, imagem_DCT, ID, cont, legenda, Exibir, Salvar);

            %   Constru��o da legenda para 'imagem_iDCT'
                legenda = strcat ('Passo_', num2str(passo));
                legenda = strcat (legenda, '_DCT inversa');
            %   Convers�o necess�ria da imagem alvo
                imagem_iDCT = uint8(imagem_iDCT);
            %   Exibi��o e Armazenamento em Disco da Imagem
                cont = Exibe_Salva (Info.Dir_result, imagem_iDCT, ID, cont, legenda, Exibir, Salvar);            
            end
end
