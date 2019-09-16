%%  Problema 1 Imagem Circuito PCB

function [void] = Problema1 (dir_ref)
    %%  Inicialização da Execução da Função
        Limpeza ();

    %%  Determinação dos Parâmetros
        %   'nome_imagem_base' armazena o nome da imagem que será realizado
        %   o processamento
            nome_imagem_base = 'pcb.jpg';
        %   'nome_arquivo' armazena o nome do arquivo que conterá as
        %   informações relevantes sobre este problema
            nome_arq = '../Resultados/Problema 1/Resultados_Problema 1.txt';
        %   'limite_bin' armazena o limiar da binarização da operação de
        %   TopHat na imagem base
            limite_bin = 128;
        %   Normalização do 'limite_bin_top' para o intervalo [0, 1]
            limite_bin = limite_bin/255;
        %   'ES_tipo', 'ES_tam' e 'ES_ang' armazenam as configurações do
        %   elemento estruturante: tipo, tamanho e angulação, respec.
            ES_tipo = 'line';
            ES_tam = 17;
            ES_ang = 56;
        %   'conectividade' armazena o tipo de conectividade a ser considerada
        %   na detecção das regioes, sendo 4 ou 8
            conectividade = 8;

    %%  Carregando Imagem Base
        %   Construção final do nome da imagem
            nome_imagem_base = strcat (dir_ref, nome_imagem_base);
        %   Carregar a imagem base, cuja identificação é 'nome_imagem_base', e
        %   armazenar em 'imagem_base'
            imagem_base = imread (nome_imagem_base);
        %   Exibição da 'imagem_base' com o título: "Original"
            imshow(imagem_base);
            title ('Imagem Base');

    %%  Binarização da Imagem Base
        %   Binarização da imagem atráves da função 'im2bw', dado um
        %   limiar, 'limite_bin', de binarização da imagem original
            imagem_binaria = im2bw (imagem_base, limite_bin);
        %   Exibição da 'imagem_binaria' com o título: "Imagem Binarizada"
            imshow(imagem_base);
            title ('Imagem Binarizada');
        %   Salvando a 'imagem_binaria' com o título: "Imagem Binarizada"
            saveas(gcf, '../Resultados/Problema 1/Imagem Binarizada.jpg');

    %%  Operação de Fechamento - Pós-Processamento
        %   Determinação do elemento estruturante a ser utilizado,
        %   com as configurações de 'ES_*'
            ES = strel (ES_tipo, ES_tam, ES_ang);
        %   Operação morfológica de fechamento em si, dado em elemento
        %   estruturante e a imagem binária
            imagem_binaria = imclose (imagem_binaria, ES);
        %   Exibição da 'imagem_binaria' com o título: "Imagem Binarizada
        %   após Fechamento"
            imshow(imagem_base);
            title ('Imagem Binarizada após Fechamento');
        %   Salvando a 'imagem_binaria' com o título: "Imagem Binarizada
        %   após Fechamento"
            saveas(gcf, '../Resultados/Problema 1/Imagem Binarizada, após Fechamento.jpg');

    %%  Negativo da Binária Final
        %   Negativo da imagem binarizada, preparação para a detecção
        %   das regiões que reconhece os pixels brancos
            imagem_binaria(:, :, :) = ~imagem_binaria(:, :, :);
        %   Exibição da 'imagem_binária' com o título: "Imagem Binarizada,
        %   negativo"
            figure, imshow (imagem_binaria);
            title ('Imagem Binarizada, negativo');
        %   Salvando a 'imagem_binaria' em disco com o nome: "Imagem Binarizada,
        %   negativo"
            saveas (gcf, '../Resultados/Problema 1/Imagem Binarizada, negativo.jpg');

    %%  Detecção das Regiões
        %   Determinação das regiões da imagem binária, considerando a
        %   'conectividade'
            imagem_regioes = bwlabel (imagem_binaria, conectividade);
        %   Exibição da 'imagem_regioes' com as regiões coloridas e sem
        %   refinamento, mas sem alterar a imagem das regiões (adicionando
        %   planos a imagem), com o título: "Regiões Detectadas"
            figure, imshow (label2rgb(imagem_regioes));
            title ('Regiões Detectadas, Coloridas');
        %   Salvando a 'imagem_regioes' colorida em disco com o nome: "Regiões
        %   Detectadas, Coloridas"
            saveas (gcf, '../Resultados/Problema 1/Regiões Detectadas, Coloridas.jpg');

    %%  Tratamento das Regiões
        %   Extração das informações das regiões detectadas
            status = regionprops (imagem_regioes, 'basic');
        %   Refinamento sobre as regiões encontradas
            %   Verificando cada região encontrada
            for ind = 1:size(status)
                %   Estando fora do tamanho de área pré-definido e tendo
                %   centróide acima de certa posíção em relação ao eixo Ox,
                %   ambas medidas empíricas
                if ((status(ind).Area < 400) || (status(ind).Area > 1000) || (status(ind).Centroid(1) > 250))
                    %  Passando pelo refinamento, elimina-se tal região da
                    %  imagem
                    for lin = 1:size(imagem_regioes, 1)
                        for col = 1:size(imagem_regioes, 2)
                            if (imagem_regioes(lin, col) == ind)
                                imagem_regioes(lin, col) = 0;
                            end
                        end
                    end
                end
            end
        %   Nova extração de informações, considerando a imagem
        %   pré-refinada
            status = regionprops (imagem_regioes, 'basic');
        %   Exibição da 'imagem_regioes', após o refinamento, com o título:
        %   "Regiões de Interesse Final"
            figure, imshow (imagem_regioes);
            title ('Regiões de Interesse Final');
        %   Salvando a 'imagem_regioes' em disco com o nome: "Regiões de
        %   Interesse Final"
            saveas (gcf, '../Resultados/Problema 1/Regiões de Interesse Final.jpg');

    %%  Escrita das Informações num Arquivo
        %   Abertura do arquivo lógico para escrita das informações,
        %   sobrescrevendo-as, caso já exista o arquivo
            arq = fopen (nome_arq, 'w');
        %   Identificação da imagem-base da análise
            fprintf (arq, 'Imagem base: %s\n\n', nome_imagem_base);
        %   Relatando quantas regiões de interesse foram encontradas
            fprintf (arq, 'Foram encontradas %d regiões de interesse, sendo elas:\n', (size(status, 1) - 1));
        %   Escrevendo as informações de todas as regiões encontradas
            for reg = 2:size(status, 1)
                fprintf (arq, '\t* Região %d:\n', reg - 1);
                fprintf (arq, '\t\t- Área = %d pixels\n', status(reg).Area);
                menor_dim = min(status(reg).BoundingBox(3:4));
                fprintf (arq, '\t\t- Diâmetro mínimo = %d pixels\n\n', menor_dim);
            end
        %   Fechando o arquivo lógico
            fclose (arq);
            
   	Pausa ();
end     
