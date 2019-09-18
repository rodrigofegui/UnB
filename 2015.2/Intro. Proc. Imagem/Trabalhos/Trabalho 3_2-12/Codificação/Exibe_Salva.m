function [contador] = Exibe_Salva (dir_ref, imagem, ID, cont, legenda, exibir, salvar)
    contador = cont;
    %%  Exibindo a imagem
        if (exibir == 1)
            figure, imshow (imagem);
            title (legenda);
        end
    %%   Salvando em disco
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
        end
end

