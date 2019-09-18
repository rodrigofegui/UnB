%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%   Introdução a Processamento de Imagens - Turma A - ;
%%   Professor:
%                   Bruno Espinoza;
%%   Responsável:
%                   Rodrigo Guimarães - 14/0170740;
%%   Objetivo:
%                   Fixar os conceitos de realce no domínio espacial e
%                   filtragem no domínio da freqüência e de morfologia
%                   matemática.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%  Limpeza da Área de Trabalho
    %   Liberando memória previamente alocada, janelas de exibição e janela
    %   de comandos
        clear all, close all, clc


%%  Declaração das Variáveis e Constantes Iniciais
    %   'lena' armazena o nome da imagem da Lena que servirá como base do
    %   processamento
        lena = 'lena512.bmp';
    %   'marv' armazena o nome da imagem do Marv, Sin City, que servirá
    %   como base do processamento
        marv = 'marv1.bmp';
    %   'monalisa' armazena o nome da imagem da Monalisa que servirá como
    %   base do processamento
        monalisa = 'mona.bmp';
    %   'exibir' armazena a escolha sobre exibição dos resultados das
    %   operações de manipulação, sendo 1 para exibir ou outro qualquer
    %   para não exibir
        exibir = 0;
    %   'salvar' armazena a escolha sobre armazenagem dos resultados das
    %   operações de manipulação em disco, independente da escolha de
    %   'exibir', sendo analogo a 'exibir'
        salvar = 1;


%%  Criando Struct
    %   'Info' armazena as informações básicas para o projeto e inerentes
    %   as imagens
        Info = Cria_Struct;


%%  Resolução do Problema 1 - DCT e Quantização
        fprintf ('Começo das Atividades!\n\n');
        %fprintf ('Começando a Resolver o Problema 1...\n');
    %   Resolvendo para a Lena
        %[Info.Variancias(1, :,  1), Info.PSNRs(1, :, 1)] = Problema1 (Info, lena, 0, exibir, salvar);
        %fprintf ('\nFinalizou análise na Lena...\n');
    %   Resolvendo para o Marv
        %[Info.Variancias(2, :, 1), Info.PSNRs(2, :, 1)] = Problema1 (Info, marv, 1, exibir, salvar);
        %fprintf ('\nFinalizou análise no Marv...\n');
    %   Resolvendo para a Monalisa
        %[Info.Variancias(3, :, 1), Info.PSNRs(3, :, 1)] = Problema1 (Info, monalisa, 2, exibir, salvar);
        %fprintf ('\nFinalizou análise na Monalisa...\n');
	%   Gravando os resultados
        %Grava_Var_PSNR (Info, 1);


%%  Resolução do Problema 2 - DCT e Quantização, com DPCM anteriormente
        fprintf ('\nComeçando a Resolver o Problema 2...\n');
    %   Resolvendo para a Lena
        [Info.Variancias(1, :, 2), Info.PSNRs(1, :, 2)] = Problema2 (Info, lena, 3, exibir, salvar);
        fprintf ('\nFinalizou análise na Lena...\n');
    %   Resolvendo para o Marv
        [Info.Variancias(2, :, 2), Info.PSNRs(2, :, 2)] = Problema2 (Info, marv, 4, exibir, salvar);
        fprintf ('\nFinalizou análise no Marv...\n');
    %   Resolvendo para a Monalisa
        [Info.Variancias(3, :, 2), Info.PSNRs(3, :, 2)] = Problema2 (Info, monalisa, 5, exibir, salvar);
        fprintf ('\nFinalizou análise na Monalisa...\n');
    %   Gravando os resultados
        Grava_Var_PSNR (Info, 2);


        fprintf ('\nAtividades Encerradas!\n\n');