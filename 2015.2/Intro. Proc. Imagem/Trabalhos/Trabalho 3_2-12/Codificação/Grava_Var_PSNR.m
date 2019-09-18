function [void] = Grava_Var_PSNR(Info, Problema)
    %%  Declaração das Variáveis e Constantes Iniciais
        %   'larg' armazena a largura da linha nas plotagens
            larg = 1.5;
        %   'prob' armazena o problema a ser plotado as informacoes
            if (Problema == 1)
                prob = 'Problema 1 -';
            else
                prob = 'Problema 2 -';
            end


    %%  Plotando as Variâncias
        %   Plotando as Variâncias da Lena
            figure,
            plot (Info.Quantizacao, Info.Variancias(1, :, Problema), 'r', 'LineWidth', larg);
        %   Plotando as Variâncias do Marv
            hold on,
            plot (Info.Quantizacao, Info.Variancias(2, :, Problema), 'b', 'LineWidth', larg);
        %   Plotando as Variâncias da Monalisa
            hold on,
            plot (Info.Quantizacao, Info.Variancias(3, :, Problema), 'k', 'LineWidth', larg);
        %   Título e legenda da plotagem
            nome = strcat (prob, sprintf (' Comparativo das Variâncias Médias'));
            title (nome);
            grid on,
            xlabel ('Níveis de Quantização');
            ylabel ('Variâncias');
            legend ('Lena', 'Marv', 'Monalisa', 'Location', 'southoutside', 'Orientation','horizontal');
        %   Salvando o plot
            nome = strcat (Info.Dir_result, nome);
            nome = strcat (nome, '.jpg');
            saveas (gcf, nome);


    %%  Plotando os PSNRs
        %   Plotando os PSNRs da Lena
            figure,
            plot (Info.Quantizacao, Info.PSNRs(1, :, Problema), 'r', 'LineWidth', larg);
        %   Plotando os PSNRs do Marv
            hold on,
            plot (Info.Quantizacao, Info.PSNRs(2, :, Problema), 'b', 'LineWidth', larg);
        %   Plotando os PSNRs da Monalisa
            hold on,
            plot (Info.Quantizacao, Info.PSNRs(3, :, Problema), 'k', 'LineWidth', larg);
        %   Título e legenda da plotagem
            nome = strcat (prob, sprintf(' Comparativo dos PSNRs'));
            title (nome);
            grid on,
            xlabel ('Níveis de Quantização');
            ylabel ('PSNRs');
            legend ('Lena', 'Marv', 'Monalisa', 'Location', 'southoutside', 'Orientation','horizontal');
        %   Salvando o plot
            nome = strcat (Info.Dir_result, nome);
            nome = strcat (nome, '.jpg');
            saveas (gcf, nome);


    %%  Plotando PSNR x Variância
        %   Plotando os PSNR versus Variância, para todas as imagens
            figure
            for ind = 1 : size (Info.PSNRs, 1)
               plot (Info.Variancias(ind, :, Problema), Info.PSNRs(ind, :, Problema), 'LineWidth', larg);
               hold on,
            end        
        %   Título e legenda da plotagem
            nome = strcat (prob, sprintf (' PSNRs x Variâncias'));
            title (nome);
            grid on,
            ylabel ('PSNRs');
            xlabel ('Variâncias');
            legend ('Lena', 'Marv', 'Monalisa', 'Location', 'southoutside', 'Orientation','horizontal');
        %   Salvando o plot
            nome = strcat (Info.Dir_result, nome);
            nome = strcat (nome, '.jpg');
            saveas (gcf, nome);
            
    %%  Escrevendo os resultados em disco
        %   Construção do nome do Arquivo
            nome_arq = strcat (Info.Dir_result, prob);
            nome_arq = strcat (nome_arq, sprintf(' Resultados Finais.txt'));
        %   Abertura do arquivo lógico para escrita das informações,
        %   sobrescrevendo-as, caso já exista o arquivo
            arq = fopen (nome_arq, 'w');
        %   Escrevendo as informações das imagens no arquivo
            for arqv = 1 : size(Info.PSNRs, 1)
            %   Identificação da imagem-base da análise, no caso a Lena
                if (arqv == 1)
                    fprintf (arq, 'Imagem base: lena512.bmp\n');
            %   Identificação da imagem-base da análise, no caso o Marv
                elseif (arqv == 2)
                    fprintf (arq, 'Imagem base: marv1.bmp\n');
            %   Identificação da imagem-base da análise, no caso a
            %   Monalisa
                else
                    fprintf (arq, 'Imagem base: mona.bmp\n');
                end

            %   Escrevendo os passos de quantização
                fprintf (arq, '\tPassos:\t\t');
                for ind = 1 : size(Info.Quantizacao, 2)
                    fprintf (arq, '%d\t\t\t', Info.Quantizacao(ind));
                end
            %   Escrevendo as PSNR
                fprintf (arq, '\n\tPSNR:\t\t');
                for ind = 1 : size(Info.Quantizacao, 2)
                    fprintf (arq, '%.2f\t\t', Info.PSNRs(arqv, ind, Problema));
                end
            %   Escrevendo as Variâncias
                fprintf (arq, '\n\tVAR:\t\t');
                for ind = 1 : size(Info.Quantizacao, 2)
                    if (ind < 2)
                        if (arqv == 2)
                            fprintf (arq, '%.0f\t\t\t', Info.Variancias(arqv, ind, Problema));
                        else
                            fprintf (arq, '%.0f\t\t', Info.Variancias(arqv, ind, Problema));
                        end
                    else
                        fprintf (arq, '%.0f\t\t\t', Info.Variancias(arqv, ind, Problema));
                    end
                end
                fprintf (arq, '\n\n\n');
            end
            
        %   Fechando o arquivo lógico
            fclose (arq);
end

