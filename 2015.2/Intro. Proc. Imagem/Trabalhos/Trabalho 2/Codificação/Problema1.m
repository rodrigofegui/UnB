%%  Problema 1 Imagem Circuito PCB

function [void] = Problema1 (dir_ref)
    %%  Inicializa��o da Execu��o da Fun��o
        Limpeza ();

    %%  Determina��o dos Par�metros
        %   'nome_imagem_base' armazena o nome da imagem que ser� realizado
        %   o processamento
            nome_imagem_base = 'pcb.jpg';
        %   'nome_arquivo' armazena o nome do arquivo que conter� as
        %   informa��es relevantes sobre este problema
            nome_arq = '../Resultados/Problema 1/Resultados_Problema 1.txt';
        %   'limite_bin' armazena o limiar da binariza��o da opera��o de
        %   TopHat na imagem base
            limite_bin = 128;
        %   Normaliza��o do 'limite_bin_top' para o intervalo [0, 1]
            limite_bin = limite_bin/255;
        %   'ES_tipo', 'ES_tam' e 'ES_ang' armazenam as configura��es do
        %   elemento estruturante: tipo, tamanho e angula��o, respec.
            ES_tipo = 'line';
            ES_tam = 17;
            ES_ang = 56;
        %   'conectividade' armazena o tipo de conectividade a ser considerada
        %   na detec��o das regioes, sendo 4 ou 8
            conectividade = 8;

    %%  Carregando Imagem Base
        %   Constru��o final do nome da imagem
            nome_imagem_base = strcat (dir_ref, nome_imagem_base);
        %   Carregar a imagem base, cuja identifica��o � 'nome_imagem_base', e
        %   armazenar em 'imagem_base'
            imagem_base = imread (nome_imagem_base);
        %   Exibi��o da 'imagem_base' com o t�tulo: "Original"
            imshow(imagem_base);
            title ('Imagem Base');

    %%  Binariza��o da Imagem Base
        %   Binariza��o da imagem atr�ves da fun��o 'im2bw', dado um
        %   limiar, 'limite_bin', de binariza��o da imagem original
            imagem_binaria = im2bw (imagem_base, limite_bin);
        %   Exibi��o da 'imagem_binaria' com o t�tulo: "Imagem Binarizada"
            imshow(imagem_base);
            title ('Imagem Binarizada');
        %   Salvando a 'imagem_binaria' com o t�tulo: "Imagem Binarizada"
            saveas(gcf, '../Resultados/Problema 1/Imagem Binarizada.jpg');

    %%  Opera��o de Fechamento - P�s-Processamento
        %   Determina��o do elemento estruturante a ser utilizado,
        %   com as configura��es de 'ES_*'
            ES = strel (ES_tipo, ES_tam, ES_ang);
        %   Opera��o morfol�gica de fechamento em si, dado em elemento
        %   estruturante e a imagem bin�ria
            imagem_binaria = imclose (imagem_binaria, ES);
        %   Exibi��o da 'imagem_binaria' com o t�tulo: "Imagem Binarizada
        %   ap�s Fechamento"
            imshow(imagem_base);
            title ('Imagem Binarizada ap�s Fechamento');
        %   Salvando a 'imagem_binaria' com o t�tulo: "Imagem Binarizada
        %   ap�s Fechamento"
            saveas(gcf, '../Resultados/Problema 1/Imagem Binarizada, ap�s Fechamento.jpg');

    %%  Negativo da Bin�ria Final
        %   Negativo da imagem binarizada, prepara��o para a detec��o
        %   das regi�es que reconhece os pixels brancos
            imagem_binaria(:, :, :) = ~imagem_binaria(:, :, :);
        %   Exibi��o da 'imagem_bin�ria' com o t�tulo: "Imagem Binarizada,
        %   negativo"
            figure, imshow (imagem_binaria);
            title ('Imagem Binarizada, negativo');
        %   Salvando a 'imagem_binaria' em disco com o nome: "Imagem Binarizada,
        %   negativo"
            saveas (gcf, '../Resultados/Problema 1/Imagem Binarizada, negativo.jpg');

    %%  Detec��o das Regi�es
        %   Determina��o das regi�es da imagem bin�ria, considerando a
        %   'conectividade'
            imagem_regioes = bwlabel (imagem_binaria, conectividade);
        %   Exibi��o da 'imagem_regioes' com as regi�es coloridas e sem
        %   refinamento, mas sem alterar a imagem das regi�es (adicionando
        %   planos a imagem), com o t�tulo: "Regi�es Detectadas"
            figure, imshow (label2rgb(imagem_regioes));
            title ('Regi�es Detectadas, Coloridas');
        %   Salvando a 'imagem_regioes' colorida em disco com o nome: "Regi�es
        %   Detectadas, Coloridas"
            saveas (gcf, '../Resultados/Problema 1/Regi�es Detectadas, Coloridas.jpg');

    %%  Tratamento das Regi�es
        %   Extra��o das informa��es das regi�es detectadas
            status = regionprops (imagem_regioes, 'basic');
        %   Refinamento sobre as regi�es encontradas
            %   Verificando cada regi�o encontrada
            for ind = 1:size(status)
                %   Estando fora do tamanho de �rea pr�-definido e tendo
                %   centr�ide acima de certa pos���o em rela��o ao eixo Ox,
                %   ambas medidas emp�ricas
                if ((status(ind).Area < 400) || (status(ind).Area > 1000) || (status(ind).Centroid(1) > 250))
                    %  Passando pelo refinamento, elimina-se tal regi�o da
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
        %   Nova extra��o de informa��es, considerando a imagem
        %   pr�-refinada
            status = regionprops (imagem_regioes, 'basic');
        %   Exibi��o da 'imagem_regioes', ap�s o refinamento, com o t�tulo:
        %   "Regi�es de Interesse Final"
            figure, imshow (imagem_regioes);
            title ('Regi�es de Interesse Final');
        %   Salvando a 'imagem_regioes' em disco com o nome: "Regi�es de
        %   Interesse Final"
            saveas (gcf, '../Resultados/Problema 1/Regi�es de Interesse Final.jpg');

    %%  Escrita das Informa��es num Arquivo
        %   Abertura do arquivo l�gico para escrita das informa��es,
        %   sobrescrevendo-as, caso j� exista o arquivo
            arq = fopen (nome_arq, 'w');
        %   Identifica��o da imagem-base da an�lise
            fprintf (arq, 'Imagem base: %s\n\n', nome_imagem_base);
        %   Relatando quantas regi�es de interesse foram encontradas
            fprintf (arq, 'Foram encontradas %d regi�es de interesse, sendo elas:\n', (size(status, 1) - 1));
        %   Escrevendo as informa��es de todas as regi�es encontradas
            for reg = 2:size(status, 1)
                fprintf (arq, '\t* Regi�o %d:\n', reg - 1);
                fprintf (arq, '\t\t- �rea = %d pixels\n', status(reg).Area);
                menor_dim = min(status(reg).BoundingBox(3:4));
                fprintf (arq, '\t\t- Di�metro m�nimo = %d pixels\n\n', menor_dim);
            end
        %   Fechando o arquivo l�gico
            fclose (arq);
            
   	Pausa ();
end     
