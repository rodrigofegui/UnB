function [formato] = DetectaForma (canny, crct)
	%%  Declaração das Variáveis e Constantes Iniciais    
		%	'porcent_1' armazena a porcentagem da distância entre o
        %   centróide do bloco até seu topo em que deve ser posicionada a
        %   linha de corte dos dedos
			porcent_1 = 0.70;
		%	'porcent_2' armazena a porcentagem da distância entre o
        %   centróide do bloco até seu topo em que deve ser posicionada a
        %   linha de corte do dedao
			porcent_2 = 0.10;
        %	'porcent_3' armazena a porcentagem da distância entre o
        %   centróide do bloco até sua base em que deve ser posicionada a
        %   linha de corte do dedao
			porcent_3 = 0.30;
		%	'formato' armazena o resultado da determinação da forma
		    formato = 'desconhecido';
		%	'dedos_acima' armazena a quantidade de dedos que existem na linha de corte
		    dedos_acima = 0;
		%	'dedao'	armazena a quantidade de dedos registrados no espaço abaixo do centróide
		    dedao = 0;
		%	'corte' armazena a imagem resultante a cada análise feita
		    corte = im2bw(zeros(size(canny)));
        %   Configuração das colunas de busca, onde 'col_in' armazena a
        %   coluna inicial e 'col_fim' a coluna final
            col_in = round(crct.BoundingBox(1));
            col_fim = round(crct.BoundingBox(1) + crct.BoundingBox(3));

	%%	Determinando a quantidade de dedos levantados
		%	'lin_corte_sup' armazena a linha de corte a ser determinado o valor de 'dedos_acima'
			lin_corte = round(crct.Centroid(2) + round((crct.BoundingBox(2) - crct.Centroid(2)) * porcent_1));
        %	Copia da imagem original
		    corte = canny;
		%	Guardando operação de corte na imagem
			corte (lin_corte, col_in : col_fim) = 255;
        %   Salvando a imagem
            figure, imshow (corte);
            hold on;
            rectangle('Position',[crct.BoundingBox(1),crct.BoundingBox(2),crct.BoundingBox(3),crct.BoundingBox(4)],'EdgeColor','r','LineWidth',2 );
            saveas (gcf, '../Imagens/0_Linha Superior mais Bloco.jpg');
    
	%%  Detecção dos dedos levantados
        %   'cor' armazena a cor do pixel lido na linha, sendo 0 para preto
        %   e 1 para branco
            cor = 0;
        %   'pri_col' e 'ult_col' armazenam, respectivamente, a primeira e
        %   a última coluna com branco na linha de corte
            pri_col = size(canny, 1);
            ult_col = 0;

        %   Busca pela quantidade de dedos
            for col =  col_in : col_fim 
                %   Sendo branco e a coluna atual ser maior que a última
                %   coluna, sobrescreve o valor de 'ult_col'
                if ((canny(lin_corte, col) == 1) && (col >= ult_col))
                    ult_col = col;
                end
                %   Sendo branco e a coluna atual ser menor que a primeira
                %   coluna, sobrescreve o valor de 'pri_col'
                if ((canny(lin_corte, col) == 1) && (col < pri_col))
                    pri_col = col;
                end

                %   Se vinha lendo preto e o pixel é branco, incrementa a
                %   quantidade de dedos
                if (cor == 0 && canny(lin_corte, col) == 1)
                    dedos_acima = dedos_acima + 1;
                    cor = 1;
                %   Se vinha branco e mudou para preto, muda-se a cor para
                %   preto
                elseif (cor == 1 && canny(lin_corte, col) == 0)
                    cor = 0;
                end
            end
        %   Configuração final do número de dedos
            dedos_acima = (dedos_acima / 2);
            
    %%  Detecção do dedão
        %   'lin_in' armazena a linha superior de busca por dedão
            lin_in = round(crct.Centroid(2) + round((crct.BoundingBox(2) - crct.Centroid(2)) * porcent_2));
        %   'lin_fim' armazena a linha inferior de busca por dedão
            lin_fim = crct.BoundingBox(2) + crct.BoundingBox(4);
            lin_fim = (lin_fim - crct.Centroid(2)) * porcent_3;
            lin_fim = floor(lin_fim + crct.Centroid(2));
        %   Busca pelo dedão nas linhas permitidas, do centróide até a
        %   linha limite
            for linha = lin_in : lin_fim;
                %   Inicialização das variáveis de controle para uma nova
                %   linha de busca
                    col = col_in;
                    cor = 0;
                    dedao = 0;
                %   Enquanto não for encontrado dois dedos e ainda estiver
                %   no bloco
                while ((dedao < 4) && (col < col_fim))
                    %   Se vinha lendo preto e o pixel é branco, incrementa a
                    %   quantidade de dedos
                    if ((cor == 0) && (canny(linha, col) == 1))
                        dedao = dedao + 1;
                        cor = 1;
                    %   Se vinha branco e mudou para preto, muda-se a cor para
                    %   preto
                    elseif ((cor == 1) && (canny(linha, col) == 0))
                        cor = 0;
                    end
                    
                    %   Ir para a próxima coluna
                        col = col + 1;
                end           
                
                %   Sendo encontrado dedão na imagem, não precisa mais
                %   procurar
                if (dedao > 3)
                    break;
                end
            end
        %   Configuração final do número de dedos
            dedao = (dedao / 2);
        %	Guardando operação de corte na imagem
			corte (linha, col_in : col_fim) = 255;
        %   Salvando a imagem
            figure, imshow (corte);
            hold on;
            rectangle('Position',[crct.BoundingBox(1), crct.BoundingBox(2), crct.BoundingBox(3), crct.BoundingBox(4)],'EdgeColor','r','LineWidth',2 );
            saveas (gcf, '../Imagens/0_Linha Dedão mais Bloco.jpg');

    %%  Determinação da forma
        %   Tendo dedão na imagem
            if (dedao > 1)
            %   Além disso, há mais do que 3 dedos levantados, então é
            %   PAPEL
                if (dedos_acima >= 3)
                    formato = 'papel'
            %   Ou há exatamente 2 dedos levantados, então é
            %   SPOCK
                elseif (dedos_acima == 2)
                    formato = 'spock'
                end
        %   Ou não detectando dedão,
            else
            %   E há exatamente 2 dedos levantados, então é
            %   TESOURA
                if (dedos_acima == 2)
                    formato = 'tesoura'
            %   Caso contrário, faz-se mais um teste
                else
                %   'validade_final' armazena o resultado sobre a análise
                %   da distância entre 'pri_col' e 'ult_col', sobre a
                %   largura do bloco 
                    validade_final = (ult_col - pri_col) / crct.BoundingBox(3);
                %   Tendo acima de 50% da largura, então é
                %   PEDRA
                    if(validade_final >= 0.5)
                        formato = 'pedra'
                %   Senão é
                %   LAGARTO
                    else
                        formato = 'lagarto'
                    end
                end
            end
end