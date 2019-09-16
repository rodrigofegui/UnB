function [ void ] = Problema3 ( dir_ref )
    %%  Inicializa��o da Execu��o da Fun��o
        Limpeza ();
        
    %%  Determina��o dos Par�metros
        %   'nome_imagem_base' armazena o nome da imagem que ser� realizado
        %   o processamento
            nome_imagem_base = '../Refer�ncias/img_cells.jpg';
            %nome_imagem_base = 'img_cells.jpg';
        %   'nome_arquivo' armazena o nome do arquivo que conter� as
        %   informa��es relevantes sobre este problema
            nome_arq = '../Resultados/Problema 3/Resultados_Problema 3.txt';
        %   'limite_bin' armazena o limiar da binariza��o da opera��o de
        %   TopHat na imagem base
            limite_bin = 145;
        %   Normaliza��o do 'limite_bin_top' para o intervalo [0, 1]
            limite_bin = limite_bin/255;
        %   'dist_tipo' armazena o tipo de dist�ncia a ser considerada
            dist_tipo = 'euclidean';
            
    %% Carregando Imagem Base e Pr�-Processamento
        %   Constru��o final do nome da imagem
            %nome_imagem_base = strcat (dir_ref, nome_imagem_base);
        %   Carregar a imagem base, cuja identifica��o � 'nome_imagem_base', e
        %   armazenar em 'imagem_base'
            imagem_base = rgb2gray(imread (nome_imagem_base));
        %   Suavisando o ru�do na 'imagem_base' com um filtro de m�dia
            filtro = fspecial ('average');
            imagem_base = imfilter(imagem_base, filtro);
        %   Exibi��o da 'imagem_base' com o t�tulo: "Imagem Base"
            imshow(imagem_base);
            title ('Imagem Base');
        
	%%  Binariza��o da Imagem
        %   Binariza��o da imagem atr�ves da fun��o 'im2bw', dado um
        %   limiar, 'limite_bin', de binariza��o da imagem original
            imagem_binaria = im2bw(imagem_base, limite_bin);
        %   Negativo da imagem_binaria, para deixar o fundo preto e os
        %   objetos de interesse em branco
            imagem_binaria = ~imagem_binaria (:, :, :);
        %   Exibi��o da imagem binarizada com o t�tulo: "Imagem
        %   Binarizada"
            figure, imshow(imagem_binaria);
            title('Imagem Binarizada');
        %   Salvando a 'imagem_binaria' com o t�tulo: "Imagem Binarizada"
            saveas (gcf, '../Resultados/Problema 3/Imagem Binarizada.jpg');
            
	%%  Preenchimento dos buracos
        %   Preenchimento da imagem bin�ria atr�ves da fun��o 'imfill'
            imagem_bin_preenchida = imfill (imagem_binaria, 'holes');
        %   Exibi��o da imagem binaria preenchida com o t�tulo: "Binarizada
        %   Preenchida"
            figure, imshow(imagem_bin_preenchida);
            title('Imagem Binarizada Preenchida');
        %   Salvando a 'imagem_binaria' em disco com o t�tulo: "Imagem
        %   Binarizada Preenchida"
            saveas (gcf, '../Resultados/Problema 3/Imagem Binarizada Preenchida.jpg');
        %   Exibi��o do negativo da imagem binaria preenchida com o t�tulo:
        %   "Negativo da Imagem Binarizada Preenchida"
            figure, imshow(~imagem_bin_preenchida);
            title('Negativo da Imagem Binarizada Preenchida');
        %   Salvando a 'imagem_binaria' em disco com o t�tulo: "Negativo da
        %   Imagem Binarizada Preenchida"
            saveas (gcf, '../Resultados/Problema 3/Negativo da Imagem Binarizada Preenchida.jpg');
            
	%%  C�lculo da Dist�ncia Interna
        %   C�lculo da Dist�ncia atr�ves da fun��o 'bwdist'
            dist = bwdist (~imagem_bin_preenchida);
        %   Exibi��o dos contornos detectados, com o
        %   t�tulo: "Dist�ncias Detectadas"
            figure, hold on, imcontour(dist);
            title ('Dist�ncias Internas Detectadas');
        %   Salvando a 'dist', em disco com o t�tulo:
        %   "Dist�ncias Internas Detectadas"
            saveas (gcf, '../Resultados/Problema 3/Dist�ncias Internas Detectadas.jpg');
        %   Exibi��o da 'imagem_base', com os contornos detectados, com o
        %   t�tulo: "Imagem Base com as Dist�ncias Detectadas"
            figure, imshow (imagem_base);
            hold on, imcontour(dist);
            title ('Imagem Base com as Dist�ncias Internas');
        %   Salvando a 'imagem_base', com a 'dist', em disco com o t�tulo:
        %   "Imagem Base com as Dist�ncias Internas"
            saveas (gcf, '../Resultados/Problema 3/Imagem Base com as Dist�ncias Internas.jpg');
        %   Exibi��o da 'dist' com o t�tulo: C�lulas Pretas e Fundo
        %   Branco"
            %figure, imshow (dist1);
            %title ('C�lulas Pretas e Fundo Branco');
        %   Salvando 'dist' em disco com o t�tulo: "C�lulas Pretas e Fundo
        %   Branco"
            %imwrite (dist1, '../Resultados/Problema 3/C�lulas Pretas e Fundo Branco.jpg');         
        %   Complemento da dist�ncia, e configurando os pixels que n�o pertencem aos objetos para -Inf.
            dist = -dist;
            dist(~imagem_bin_preenchida) = -Inf;
            
	%%  Transformada de Watershed_Dist�ncias Internas
        %   C�lculo da transformada watershed pela fun��o 'watershed'
            imagem_water1 = watershed (dist);
        %   Convers�o de regi�es marcadas para colorido
            imagem_water1 = label2rgb (imagem_water1);
        %   Exibi��o da 'imagem_water2', com os contornos detectados, com o
        %   t�tulo: "Transforma Watershed_Distancias Internas"
            figure, imshow(imagem_water1);
            title('Transforma Watershed\_Distancias Internas');
        %   Salvando 'imagem_water1' em disco com o t�tulo: "Transforma
        %   Watershed_Distancias Internas"
            saveas (gcf, '../Resultados/Problema 3/Transforma Watershed_Distancias Internas.jpg');
            
	%%  C�lculo da Dist�ncia Externa
        %   C�lculo da Dist�ncia atr�ves da fun��o 'bwdist'
            dist = bwdist (imagem_bin_preenchida);
        %   Exibi��o dos contornos detectados, com o
        %   t�tulo: "Dist�ncias Detectadas"
            figure, hold on, imcontour(dist);
            title ('Dist�ncias Externas Detectadas');
        %   Salvando a 'dist', em disco com o t�tulo:
        %   "Dist�ncias Externas Detectadas"
            saveas (gcf, '../Resultados/Problema 3/Dist�ncias Externas Detectadas.jpg');
        %   Exibi��o da 'imagem_base', com os contornos detectados, com o
        %   t�tulo: "Imagem Base com as Dist�ncias Detectadas"
            figure, imshow (imagem_base);
            hold on, imcontour(dist);
            title ('Imagem Base com as Dist�ncias Externas');
        %   Salvando a 'imagem_base', com a 'dist', em disco com o t�tulo:
        %   "Imagem Base com as Dist�ncias Externas"
            saveas (gcf, '../Resultados/Problema 3/Imagem Base com as Dist�ncias Externas.jpg');
        %   Exibi��o da 'dist' com o t�tulo: C�lulas Pretas e Fundo
        %   Branco"
            %figure, imshow (dist1);
            %title ('C�lulas Pretas e Fundo Branco');
        %   Salvando 'dist' em disco com o t�tulo: "C�lulas Pretas e Fundo
        %   Branco"
            %imwrite (dist1, '../Resultados/Problema 3/C�lulas Pretas e Fundo Branco.jpg');         
        %   Complemento da dist�ncia, e configurando os pixels que n�o pertencem aos objetos para -Inf.
            dist = -dist;
            dist(~imagem_bin_preenchida) = -Inf;

	%%  Transformada de Watershed_Dist�ncias Externas
        %   C�lculo da transformada watershed pela fun��o 'watershed'
            imagem_water1 = watershed (dist);
        %   Convers�o de regi�es marcadas para colorido
            imagem_water1 = label2rgb (imagem_water1);
        %   Exibi��o da 'imagem_water2', com os contornos detectados, com o
        %   t�tulo: "Transforma Watershed_Dist�ncias Externas"
            figure, imshow(imagem_water1);
            title('Transforma Watershed\_Dist�ncias Externas');
        %   Salvando 'imagem_water1' em disco com o t�tulo: "Transforma
        %   Watershed_Dist�ncias Externas"
            saveas (gcf, '../Resultados/Problema 3/Transforma Watershed_Dist�ncias Externas.jpg');
                       
	Pausa ();
end
