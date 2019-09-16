function [Info] = Cria_Struct()
    %%  Declaração das Variáveis e Constantes Iniciais
        %   'dir_ref' armazena o nome do diretório que contém as imagens de
        %   interesse
            dir_ref = '../Referências/';
        %   'dir_result' armazena o diretório referência para gravação
        %   dos resultados
            %dir_result = '../Resultados/';
            dir_result = '../Resul/';
        %   'tam_bloco' armazena o tamanho do bloco, ao qual a imagem será
        %   dividida
            tam_bloco = 8;
        %   'quantizacao' armazena os passos de quantização a serem
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

        %   Criação da struct 'Informacoes'
            Info = struct (campo1, dir_ref, campo2, dir_result, campo3, tam_bloco, campo4, quantiza, campo5, var_med, campo6, PSNRs);
  
end

