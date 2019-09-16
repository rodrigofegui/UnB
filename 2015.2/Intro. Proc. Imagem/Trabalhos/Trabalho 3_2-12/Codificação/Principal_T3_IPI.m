%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%   Introdu��o a Processamento de Imagens - Turma A - ;
%%   Professor:
%                   Bruno Espinoza;
%%   Respons�vel:
%                   Rodrigo Guimar�es - 14/0170740;
%%   Objetivo:
%                   Fixar os conceitos de realce no dom�nio espacial e
%                   filtragem no dom�nio da freq��ncia e de morfologia
%                   matem�tica.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%  Limpeza da �rea de Trabalho
    %   Liberando mem�ria previamente alocada, janelas de exibi��o e janela
    %   de comandos
        clear all, close all, clc


%%  Declara��o das Vari�veis e Constantes Iniciais
    %   'lena' armazena o nome da imagem da Lena que servir� como base do
    %   processamento
        lena = 'lena512.bmp';
    %   'marv' armazena o nome da imagem do Marv, Sin City, que servir�
    %   como base do processamento
        marv = 'marv1.bmp';
    %   'monalisa' armazena o nome da imagem da Monalisa que servir� como
    %   base do processamento
        monalisa = 'mona.bmp';
    %   'exibir' armazena a escolha sobre exibi��o dos resultados das
    %   opera��es de manipula��o, sendo 1 para exibir ou outro qualquer
    %   para n�o exibir
        exibir = 0;
    %   'salvar' armazena a escolha sobre armazenagem dos resultados das
    %   opera��es de manipula��o em disco, independente da escolha de
    %   'exibir', sendo analogo a 'exibir'
        salvar = 1;


%%  Criando Struct
    %   'Info' armazena as informa��es b�sicas para o projeto e inerentes
    %   as imagens
        Info = Cria_Struct;


%%  Resolu��o do Problema 1 - DCT e Quantiza��o
        fprintf ('Come�o das Atividades!\n\n');
        %fprintf ('Come�ando a Resolver o Problema 1...\n');
    %   Resolvendo para a Lena
        %[Info.Variancias(1, :,  1), Info.PSNRs(1, :, 1)] = Problema1 (Info, lena, 0, exibir, salvar);
        %fprintf ('\nFinalizou an�lise na Lena...\n');
    %   Resolvendo para o Marv
        %[Info.Variancias(2, :, 1), Info.PSNRs(2, :, 1)] = Problema1 (Info, marv, 1, exibir, salvar);
        %fprintf ('\nFinalizou an�lise no Marv...\n');
    %   Resolvendo para a Monalisa
        %[Info.Variancias(3, :, 1), Info.PSNRs(3, :, 1)] = Problema1 (Info, monalisa, 2, exibir, salvar);
        %fprintf ('\nFinalizou an�lise na Monalisa...\n');
	%   Gravando os resultados
        %Grava_Var_PSNR (Info, 1);


%%  Resolu��o do Problema 2 - DCT e Quantiza��o, com DPCM anteriormente
        fprintf ('\nCome�ando a Resolver o Problema 2...\n');
    %   Resolvendo para a Lena
        [Info.Variancias(1, :, 2), Info.PSNRs(1, :, 2)] = Problema2 (Info, lena, 3, exibir, salvar);
        fprintf ('\nFinalizou an�lise na Lena...\n');
    %   Resolvendo para o Marv
        [Info.Variancias(2, :, 2), Info.PSNRs(2, :, 2)] = Problema2 (Info, marv, 4, exibir, salvar);
        fprintf ('\nFinalizou an�lise no Marv...\n');
    %   Resolvendo para a Monalisa
        [Info.Variancias(3, :, 2), Info.PSNRs(3, :, 2)] = Problema2 (Info, monalisa, 5, exibir, salvar);
        fprintf ('\nFinalizou an�lise na Monalisa...\n');
    %   Gravando os resultados
        Grava_Var_PSNR (Info, 2);


        fprintf ('\nAtividades Encerradas!\n\n');