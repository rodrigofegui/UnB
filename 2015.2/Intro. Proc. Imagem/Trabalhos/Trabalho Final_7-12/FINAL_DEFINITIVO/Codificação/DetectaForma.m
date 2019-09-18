function [formato] = DetectaForma (dir_ref, base, canny, crct, cont, ID, exibir, salvar)
    %%  Declara��o das Vari�veis e Constantes Iniciais
		%	'porcent_1' armazena a porcentagem da dist�ncia entre o
        %   centr�ide do bloco at� seu topo em que deve ser posicionada a
        %   linha de corte dos dedos
			porcent_1 = 0.70;
		%	'porcent_2' armazena a porcentagem da dist�ncia entre o
        %   centr�ide do bloco at� seu topo em que deve ser posicionada a
        %   linha de corte do dedao
			porcent_2 = 0.10;
        %	'porcent_3' armazena a porcentagem da dist�ncia entre o
        %   centr�ide do bloco at� sua base em que deve ser posicionada a
        %   linha de corte do dedao
			porcent_3 = 0.30;
		%	'formato' armazena o resultado da determina��o da forma
		    formato = '0_Desconhecido';
		%	'dedos_acima' armazena a quantidade de dedos que existem na linha de corte
		    dedos_acima = 0;
		%	'dedao'	armazena a quantidade de dedos registrados no espa�o abaixo do centr�ide
		    dedao = 0;
		%	'corte' armazena a imagem resultante a cada an�lise feita
		    corte = im2bw(zeros(size(canny)));
            
   
    if (size(crct,1) > 0)
        %%  Verificando se ficou resqu�cio de mais de uma regi�o
            %   Verifica��o, em si
                if (size (crct, 1) > 1)
                %   'max_area' armazena a maior �rea de 'crct'
                    max_area = max([crct.Area]);
                    %   'ind_max' armazena o indice de 'crct' de maior �rea
                    for ind_max = 1: size(crct, 1)
                        if (isequal([crct(ind_max).Area], max_area) == 1)
                            break;
                        end
                    end
                else
                    ind_max = 1;
                end           
            if ([crct(ind_max).Area] > 0)
            %figure, imshow (canny);
            %pause ()+
            %   Configura��o das colunas de busca, onde 'col_in' armazena a
            %   coluna inicial e 'col_fim' a coluna final
                col_in = round([crct(ind_max).BoundingBox(1)]);
                col_fim = round([crct(ind_max).BoundingBox(1)] + [crct(ind_max).BoundingBox(3)]);
            %   Garantindo arredondamento correto das 'col_in' e 'col_fim',
            %   onde caso estejam fora do limite da imagem, s�o redefinidos
            %   como os limites da imagem            
                if (col_in < 1)
                    col_in = 1;
                elseif(col_in > size(canny, 2))
                    col_in = size(canny, 2);
                end
                if (col_fim < 1)
                    col_fim = 1;
                elseif(col_fim > size(canny, 2))
                    col_fim = size(canny, 2);
                end

            %%	Determinando a quantidade de dedos levantados
                %	'lin_corte_sup' armazena a linha de corte a ser determinado o valor de 'dedos_acima'
                    lin_corte = round([crct(ind_max).Centroid(2)] + round(([crct(ind_max).BoundingBox(2)] - [crct(ind_max).Centroid(2)]) * porcent_1));
                %	Copia da imagem original
                    corte = canny;
                %	Guardando opera��o de corte na imagem
                    corte (lin_corte, col_in : col_fim) = 255;


            %%  Detec��o dos dedos levantados
                %   'cor' armazena a cor do pixel lido na linha, sendo 0 para preto
                %   e 1 para branco
                    cor = 0;
                %   'pri_col' e 'ult_col' armazenam, respectivamente, a primeira e
                %   a �ltima coluna com branco na linha de corte
                    pri_col = size(canny, 1);
                    ult_col = 0;

                %   Busca pela quantidade de dedos
                    for col =  col_in : col_fim 
                        %   Sendo branco e a coluna atual ser maior que a �ltima
                        %   coluna, sobrescreve o valor de 'ult_col'
                        if ((canny(lin_corte, col) == 1) && (col >= ult_col))
                            ult_col = col;
                        end
                        %   Sendo branco e a coluna atual ser menor que a primeira
                        %   coluna, sobrescreve o valor de 'pri_col'
                        if ((canny(lin_corte, col) == 1) && (col < pri_col))
                            pri_col = col;
                        end

                        %   Se vinha lendo preto e o pixel � branco, incrementa a
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
                %   Configura��o final do n�mero de dedos
                    dedos_acima = (dedos_acima / 2);


            %%  Detec��o do ded�o
                %   'lin_in' armazena a linha superior de busca por ded�o
                    lin_in = round([crct(ind_max).Centroid(2)] + round(([crct(ind_max).BoundingBox(2)] - [crct(ind_max).Centroid(2)]) * porcent_2));
                %   'lin_fim' armazena a linha inferior de busca por ded�o
                    lin_fim = [crct(ind_max).BoundingBox(2)] + [crct(ind_max).BoundingBox(4)];
                    lin_fim = (lin_fim - [crct(ind_max).Centroid(2)]) * porcent_3;
                    lin_fim = floor(lin_fim + [crct(ind_max).Centroid(2)]);
                %   Garantindo arredondamento correto das 'lin_in' e 'lin_fim',
                %   onde caso estejam fora do limite da imagem, s�o redefinidos
                %   como os limites da imagem            
                    if (lin_in < 1)
                        lin_in = 1;
                    elseif (lin_in > size(canny, 2))
                        lin_in = size(canny, 2);
                    end
                    if (lin_fim < 1)
                        lin_fim = 1;
                    elseif (lin_fim > size(canny, 2))
                        lin_fim = size(canny, 2);
                    end
                %   Busca pelo ded�o nas linhas permitidas, do centr�ide at� a
                %   linha limite
                    for linha = lin_in : lin_fim;
                        %	Guardando opera��o de corte na imagem
                            corte (linha, col_in : col_fim) = 255;
                        %   Inicializa��o das vari�veis de controle para uma nova
                        %   linha de busca
                            col = col_in;
                            cor = 0;
                            dedao = 0;
                        %   Enquanto n�o for encontrado dois dedos e ainda estiver
                        %   no bloco
                        while ((dedao < 4) && (col < col_fim))
                            %   Se vinha lendo preto e o pixel � branco, incrementa a
                            %   quantidade de dedos
                            if ((cor == 0) && (canny(linha, col) == 1))
                                dedao = dedao + 1;
                                cor = 1;
                            %   Se vinha branco e mudou para preto, muda-se a cor para
                            %   preto
                            elseif ((cor == 1) && (canny(linha, col) == 0))
                                cor = 0;
                            end

                            %   Ir para a pr�xima coluna
                                col = col + 1;
                        end           

                        %   Sendo encontrado ded�o na imagem, n�o precisa mais
                        %   procurar
                        if (dedao > 3)
                            break;
                        end
                    end
                %   Configura��o final do n�mero de dedos
                    dedao = (dedao / 2);
                %	Guardando opera��o de corte na imagem
                    corte (linha, col_in : col_fim) = 255;

            %%  Determina��o da forma
                %   Tendo ded�o na imagem
                    if (dedao > 1)
                    %   Al�m disso, h� mais do que 3 dedos levantados, ent�o �
                    %   PAPEL
                        if (dedos_acima >= 3)
                            formato = '2_Papel';
                    %   Ou h� exatamente 2 dedos levantados, ent�o �
                    %   SPOCK
                        elseif (dedos_acima == 2)
                            formato = '5_Spock';
                        %else
                        %    formato = '4_Lagarto';
                        end
                %   Ou n�o detectando ded�o,
                    else
                    %   E h� exatamente 2 dedos levantados, ent�o �
                    %   TESOURA
                        if (dedos_acima == 2)
                            formato = '3_Tesoura';
                    %   Caso contr�rio, faz-se mais um teste
                        elseif (dedos_acima ~= 2)
                        %   'validade_final' armazena o resultado sobre a an�lise
                        %   da dist�ncia entre 'pri_col' e 'ult_col', sobre a
                        %   largura do bloco 
                            validade_final = (ult_col - pri_col) / [crct(ind_max).BoundingBox(3)];
                        %   Tendo acima de 50% da largura, ent�o �
                        %   PEDRA
                            if(validade_final >= 0.5)
                                formato = '1_Pedra';
                        %   Sen�o �
                        %   LAGARTO
                            else
                                formato = '4_Lagarto';
                            end
                        end
                    end


            %%  Salvando a imagem resultado da an�lise
                %   'colorida' armazena a imagem dos cortes e a BoundingBox
                    colorida = zeros(size(corte,1), size(corte,2), 3);
                    for plano = 1:3
                        colorida (:, :, plano) = corte;
                    end
                %   Configura��o das linhas, onde 'lin_in' armazena a
                %   linha inicial e 'lin_fim' a finha final
                    lin_in = round([crct(ind_max).BoundingBox(2)]);
                    lin_fim = round([crct(ind_max).BoundingBox(2)] + [crct(ind_max).BoundingBox(4)]);
                %   Garantindo arredondamento correto das 'lin_in' e 'lin_fim',
                %   onde caso estejam fora do limite da imagem, s�o redefinidos
                %   como os limites da imagem            
                    if (lin_in < 1)
                        lin_in = 1;
                    elseif (lin_in > size(colorida, 1))
                        lin_in = size(coloria, 1);
                    end
                    if (lin_fim < 1)
                        lin_fim = 1;
                    elseif (lin_fim > size(colorida, 1))
                        lin_fim = size(colorida, 1);
                    end
                
                %   'esp' armazena a metade da espessura da linha a ser desenhada
                    esp = 2;
                %   Marcando a BoundingBox na imagem
                %   Garantindo arredondamento correto das 'lin_in' e 'lin_fim',
                %   onde caso estejam fora do limite da imagem, s�o redefinidos
                %   como os limites da imagem            
                    if ((lin_in - esp) < 1)
                        lin_in_arred = 1;
                    else
                        lin_in_arred = (lin_in - esp);
                    end
                    if ((lin_fim + esp) > size(colorida, 1))
                        lin_fim_arred = size(colorida, 1);
                    else
                        lin_fim_arred = (lin_fim + esp);
                    end
                    if ((col_in - esp) < 1)
                        col_in_arred = 1;
                    else
                        col_in_arred = (col_in - esp);
                    end
                    if ((col_fim + esp) > size(colorida, 2))
                        col_fim_arred = size(colorida, 2);
                    else
                        col_fim_arred = (col_fim + esp);
                    end
                
                    colorida ((lin_in_arred) : (lin_in + esp), col_in : col_fim, 1) = 1;
                    colorida ((lin_fim - esp) : lin_fim_arred, col_in : col_fim, 1) = 1;
                    colorida (lin_in : lin_fim, col_in_arred : (col_in + esp), 1) = 1;
                    colorida (lin_in : lin_fim, (col_fim - esp) : col_fim_arred, 1) = 1;
                %   Exibi��o e Armazenamento em Disco da Imagem
                    Exibe_Salva (dir_ref, ID, colorida, 'Linhas de Corte', cont, exibir, salvar);
            end
    end
end
