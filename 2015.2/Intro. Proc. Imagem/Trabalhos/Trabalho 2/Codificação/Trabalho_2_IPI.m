%%  Limpeza das vari�vel, das janelas e da Command Window
    clear all, close all, clc

%%  Determina��o do Par�metro Global
    %   'dir_ref' armazena o nome do diret�rio que armazena a imagem de
    %   interesse
        dir_ref = '../Refer�ncias/';

%%  Resolu��o do Problema 1 - PCB
    %   Execu��o do script armazenado no arquivo Problema1.m
        Problema1 (dir_ref);

%%  Resolu��o do Problema 2 - Monalisa + Texto
    %   Execu��o do script armazenado no arquivo Problema2.m
        Problema2 (dir_ref);

%%  Resolu��o do Problema 3 - C�lulas
    %   Execu��o do script armazenado no arquivo Problema3.m
        Problema3 (dir_ref);
          