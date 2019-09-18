function [Info] = Cria_Struct()
    %%  Declara��o das Vari�veis e Constantes Iniciais
        %   'dir_ref' armazena o nome do diret�rio que cont�m as imagens de
        %   interesse
            dir_ref = '../Refer�ncias/';
        %   'dir_result' armazena o diret�rio refer�ncia para grava��o
        %   dos resultados
            %dir_result = '../Resultados/';
            dir_result = '../Resul/';
        %   'tam_bloco' armazena o tamanho do bloco, ao qual a imagem ser�
        %   dividida
            tam_bloco = 8;
        %   'quantizacao' armazena os passos de quantiza��o a serem
        %   aplicados na imagem
            quantiza = [1 10 20 50 100];
        %   'var_med' armazena a variancia das imagens
            var_med = zeros (3, size(quantiza, 2), 2);
        %   'PSNRs' armazena o PSNR das imagens
            PSNRs = zeros (3, size(quantiza, 2), 2);
            
    %%  Configurando struct
        %   Declarando e definindo os campos da struct 'Informacoes'
            campo1 = 'Dir_ref';
            campo2 = 'Dir_result';
            campo3 = 'Tam_bloco';
            campo4 = 'Quantizacao';
            campo5 = 'Variancias';
            campo6 = 'PSNRs';

        %   Cria��o da struct 'Informacoes'
            Info = struct (campo1, dir_ref, campo2, dir_result, campo3, tam_bloco, campo4, quantiza, campo5, var_med, campo6, PSNRs);
  
end

