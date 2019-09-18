%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%   Pedra, Papel, Tesoura, Spock e Lagarto
%%   Introdu��o a Processamento de Imagens - Turma A - ;
%%   Professores:
%                   Alexandre Zaghetto;
%                   Bruno Machielo;
%                   Camilo D�rea
%%   Respons�veis:
%                   Diego Brian - 14/0136371,
%                   Pedro Aur�lio - 14/0158103,
%                   Rodrigo Guimar�es - 14/0170740;
%%   Objetivo:
%                   Trabalhar com imagens de forma a detectar a forma da
%                   m�o, a fim de determinar qual a escolha no jogo:
%                   Pedra, Papel, Tesoura, Spock e Lagarto
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%  Limpeza das vari�vel, das janelas e da Command Window
    clear all, close all, clc
    
%%  Declara��o das Vari�veis e Constantes Iniciais
    %   'dir_ref' armazena o nome do diret�rio que armazena a imagem de
    %   interesse
        dir_ref = '../Imagens/Base de Dados/';
    %   'dir_result' armazena o nome do diret�rio que armazena os
    %   resultados das opera��es
        dir_result = '../Imagens/Resultados/';
    %   'nome_arq' armazena o nome do arquivo a ser gravado as informa��es
    %   necess�rias
        %nome_arq = '1_Resultados da Detec��o.txt';
        %nome_arq = '2.1_Resultados da Detec��o.txt';
        %nome_arq = '3.1_Resultados da Detec��o.txt';
        %nome_arq = '4.1_Resultados da Detec��o.txt';
        nome_arq = '5.1_Resultados da Detec��o.txt';
        nome_arq = strcat (dir_result, nome_arq);
    %   'arq' armazena o arquivo l�gico que armazena as informa��es
        arq = fopen (nome_arq, 'w');
    %   'nome_back' armazena o nome da imagem que servir� como background
        nome_back0 = 'Fundo_0.jpg';
        nome_back1 = 'Fundo_1.jpg';
    %   'cod_mao' armazena o nome da imagem que servir� como base do
    %   processamento
        %cod_mao = 'Pedra_';
        %cod_mao = 'Papel_';
        %cod_mao = 'Tesoura_';
        %cod_mao = 'Lagarto_';
        cod_mao = 'Spock_';
    %   'qnt' armazena a quantidade de imagens de um certo tipo a ser
    %   analisado
        qnt = 75;
    %   'exibir' armazena a escolha sobre exibi��o dos resultados das
    %   opera��es de manipula��o, sendo 1 para exibir ou outro qualquer
    %   para n�o exibir
        exibir = 0;
    %   'salvar' armazena a escolha sobre armazenagem dos resultados das
    %   opera��es de manipula��o em disco, independente da escolha de
    %   'exibir', sendo analogo a 'exibir'
        salvar = 1;

%%  Analisando todas as imagens
    %   Analisando todas as 'qnt' vezes
        for ind = 1:qnt
            ind
        %   Determinando a imagem do fundo
            if (ind < 51)
                nome_back = nome_back0;
            else
                nome_back = nome_back1;
            end
        %   'back' armazena a imagem do background
            back = imread (strcat(dir_ref, nome_back));
        %   'nome_mao' armazena o nome final da imagem a ser considerada
            cod_mao_2 = strcat (cod_mao, num2str (ind));
            nome_mao = strcat (cod_mao_2, '.jpg');
        %   'mao' armazena a imagem do background
            mao = imread (strcat(dir_ref, nome_mao));

        %%   Realiza o realce da m�o na imagem
            [segmentada, canny, crct, cont] = RealceMao (dir_result, back, mao, cod_mao_2, exibir, salvar, 0);

        %%  Detec��o da forma da m�o
            detectado = DetectaForma (dir_result, segmentada, canny, crct, cont, cod_mao_2, exibir, salvar);

        %%  Computando o resultado
            EscreveResult (arq, ind, cod_mao, detectado);
        end
    %   Fechando o arquivo aberto
        fclose (arq);
       