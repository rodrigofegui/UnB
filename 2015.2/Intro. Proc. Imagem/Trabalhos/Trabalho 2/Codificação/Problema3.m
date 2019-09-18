function [ void ] = Problema3 ( dir_ref )
    %%  Inicialização da Execução da Função
        Limpeza ();
        
    %%  Determinação dos Parâmetros
        %   'nome_imagem_base' armazena o nome da imagem que será realizado
        %   o processamento
            nome_imagem_base = '../Referências/img_cells.jpg';
            %nome_imagem_base = 'img_cells.jpg';
        %   'nome_arquivo' armazena o nome do arquivo que conterá as
        %   informações relevantes sobre este problema
            nome_arq = '../Resultados/Problema 3/Resultados_Problema 3.txt';
        %   'limite_bin' armazena o limiar da binarização da operação de
        %   TopHat na imagem base
            limite_bin = 145;
        %   Normalização do 'limite_bin_top' para o intervalo [0, 1]
            limite_bin = limite_bin/255;
        %   'dist_tipo' armazena o tipo de distância a ser considerada
            dist_tipo = 'euclidean';
            
    %% Carregando Imagem Base e Pré-Processamento
        %   Construção final do nome da imagem
            %nome_imagem_base = strcat (dir_ref, nome_imagem_base);
        %   Carregar a imagem base, cuja identificação é 'nome_imagem_base', e
        %   armazenar em 'imagem_base'
            imagem_base = rgb2gray(imread (nome_imagem_base));
        %   Suavisando o ruído na 'imagem_base' com um filtro de média
            filtro = fspecial ('average');
            imagem_base = imfilter(imagem_base, filtro);
        %   Exibição da 'imagem_base' com o título: "Imagem Base"
            imshow(imagem_base);
            title ('Imagem Base');
        
	%%  Binarização da Imagem
        %   Binarização da imagem atráves da função 'im2bw', dado um
        %   limiar, 'limite_bin', de binarização da imagem original
            imagem_binaria = im2bw(imagem_base, limite_bin);
        %   Negativo da imagem_binaria, para deixar o fundo preto e os
        %   objetos de interesse em branco
            imagem_binaria = ~imagem_binaria (:, :, :);
        %   Exibição da imagem binarizada com o título: "Imagem
        %   Binarizada"
            figure, imshow(imagem_binaria);
            title('Imagem Binarizada');
        %   Salvando a 'imagem_binaria' com o título: "Imagem Binarizada"
            saveas (gcf, '../Resultados/Problema 3/Imagem Binarizada.jpg');
            
	%%  Preenchimento dos buracos
        %   Preenchimento da imagem binária atráves da função 'imfill'
            imagem_bin_preenchida = imfill (imagem_binaria, 'holes');
        %   Exibição da imagem binaria preenchida com o título: "Binarizada
        %   Preenchida"
            figure, imshow(imagem_bin_preenchida);
            title('Imagem Binarizada Preenchida');
        %   Salvando a 'imagem_binaria' em disco com o título: "Imagem
        %   Binarizada Preenchida"
            saveas (gcf, '../Resultados/Problema 3/Imagem Binarizada Preenchida.jpg');
        %   Exibição do negativo da imagem binaria preenchida com o título:
        %   "Negativo da Imagem Binarizada Preenchida"
            figure, imshow(~imagem_bin_preenchida);
            title('Negativo da Imagem Binarizada Preenchida');
        %   Salvando a 'imagem_binaria' em disco com o título: "Negativo da
        %   Imagem Binarizada Preenchida"
            saveas (gcf, '../Resultados/Problema 3/Negativo da Imagem Binarizada Preenchida.jpg');
            
	%%  Cálculo da Distância Interna
        %   Cálculo da Distância atráves da função 'bwdist'
            dist = bwdist (~imagem_bin_preenchida);
        %   Exibição dos contornos detectados, com o
        %   título: "Distâncias Detectadas"
            figure, hold on, imcontour(dist);
            title ('Distâncias Internas Detectadas');
        %   Salvando a 'dist', em disco com o título:
        %   "Distâncias Internas Detectadas"
            saveas (gcf, '../Resultados/Problema 3/Distâncias Internas Detectadas.jpg');
        %   Exibição da 'imagem_base', com os contornos detectados, com o
        %   título: "Imagem Base com as Distâncias Detectadas"
            figure, imshow (imagem_base);
            hold on, imcontour(dist);
            title ('Imagem Base com as Distâncias Internas');
        %   Salvando a 'imagem_base', com a 'dist', em disco com o título:
        %   "Imagem Base com as Distâncias Internas"
            saveas (gcf, '../Resultados/Problema 3/Imagem Base com as Distâncias Internas.jpg');
        %   Exibição da 'dist' com o título: Células Pretas e Fundo
        %   Branco"
            %figure, imshow (dist1);
            %title ('Células Pretas e Fundo Branco');
        %   Salvando 'dist' em disco com o título: "Células Pretas e Fundo
        %   Branco"
            %imwrite (dist1, '../Resultados/Problema 3/Células Pretas e Fundo Branco.jpg');         
        %   Complemento da distância, e configurando os pixels que não pertencem aos objetos para -Inf.
            dist = -dist;
            dist(~imagem_bin_preenchida) = -Inf;
            
	%%  Transformada de Watershed_Distâncias Internas
        %   Cálculo da transformada watershed pela função 'watershed'
            imagem_water1 = watershed (dist);
        %   Conversão de regiões marcadas para colorido
            imagem_water1 = label2rgb (imagem_water1);
        %   Exibição da 'imagem_water2', com os contornos detectados, com o
        %   título: "Transforma Watershed_Distancias Internas"
            figure, imshow(imagem_water1);
            title('Transforma Watershed\_Distancias Internas');
        %   Salvando 'imagem_water1' em disco com o título: "Transforma
        %   Watershed_Distancias Internas"
            saveas (gcf, '../Resultados/Problema 3/Transforma Watershed_Distancias Internas.jpg');
            
	%%  Cálculo da Distância Externa
        %   Cálculo da Distância atráves da função 'bwdist'
            dist = bwdist (imagem_bin_preenchida);
        %   Exibição dos contornos detectados, com o
        %   título: "Distâncias Detectadas"
            figure, hold on, imcontour(dist);
            title ('Distâncias Externas Detectadas');
        %   Salvando a 'dist', em disco com o título:
        %   "Distâncias Externas Detectadas"
            saveas (gcf, '../Resultados/Problema 3/Distâncias Externas Detectadas.jpg');
        %   Exibição da 'imagem_base', com os contornos detectados, com o
        %   título: "Imagem Base com as Distâncias Detectadas"
            figure, imshow (imagem_base);
            hold on, imcontour(dist);
            title ('Imagem Base com as Distâncias Externas');
        %   Salvando a 'imagem_base', com a 'dist', em disco com o título:
        %   "Imagem Base com as Distâncias Externas"
            saveas (gcf, '../Resultados/Problema 3/Imagem Base com as Distâncias Externas.jpg');
        %   Exibição da 'dist' com o título: Células Pretas e Fundo
        %   Branco"
            %figure, imshow (dist1);
            %title ('Células Pretas e Fundo Branco');
        %   Salvando 'dist' em disco com o título: "Células Pretas e Fundo
        %   Branco"
            %imwrite (dist1, '../Resultados/Problema 3/Células Pretas e Fundo Branco.jpg');         
        %   Complemento da distância, e configurando os pixels que não pertencem aos objetos para -Inf.
            dist = -dist;
            dist(~imagem_bin_preenchida) = -Inf;

	%%  Transformada de Watershed_Distâncias Externas
        %   Cálculo da transformada watershed pela função 'watershed'
            imagem_water1 = watershed (dist);
        %   Conversão de regiões marcadas para colorido
            imagem_water1 = label2rgb (imagem_water1);
        %   Exibição da 'imagem_water2', com os contornos detectados, com o
        %   título: "Transforma Watershed_Distâncias Externas"
            figure, imshow(imagem_water1);
            title('Transforma Watershed\_Distâncias Externas');
        %   Salvando 'imagem_water1' em disco com o título: "Transforma
        %   Watershed_Distâncias Externas"
            saveas (gcf, '../Resultados/Problema 3/Transforma Watershed_Distâncias Externas.jpg');
                       
	Pausa ();
end
