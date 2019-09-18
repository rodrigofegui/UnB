%%  Limpeza das variável, das janelas e da Command Window
    clear all, close all, clc

%%  Determinação do Parâmetro Global
    %   'dir_ref' armazena o nome do diretório que armazena a imagem de
    %   interesse
        dir_ref = '../Referências/';

%%  Resolução do Problema 1 - PCB
    %   Execução do script armazenado no arquivo Problema1.m
        Problema1 (dir_ref);

%%  Resolução do Problema 2 - Monalisa + Texto
    %   Execução do script armazenado no arquivo Problema2.m
        Problema2 (dir_ref);

%%  Resolução do Problema 3 - Células
    %   Execução do script armazenado no arquivo Problema3.m
        Problema3 (dir_ref);
          