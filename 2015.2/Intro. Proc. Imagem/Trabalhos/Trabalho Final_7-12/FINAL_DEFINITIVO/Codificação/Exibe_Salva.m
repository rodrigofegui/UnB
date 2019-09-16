function [contador] = Exibe_Salva (dir_ref, ID, imagem, legenda, cont, exibir, salvar)
    %   Exibindo a imagem 'exibir' com o título 'legenda'
            if (exibir == 1)
                figure, imshow (imagem);
                title (legenda);
            end
        %   Salvando em disco a imagem exibida
            if (salvar == 1)
                nome = strcat (dir_ref, num2str(ID));
                nome = strcat (nome, '_');
                nome = strcat (nome, num2str(cont));
                nome = strcat (nome, '_');
                nome = strcat (nome, legenda);
                nome = strcat (nome, '.jpg');
                imwrite (imagem, nome);
            %   Incremento do contador de imagens
                contador = cont + 1;
            else
                contador = cont;
            end
        
end

