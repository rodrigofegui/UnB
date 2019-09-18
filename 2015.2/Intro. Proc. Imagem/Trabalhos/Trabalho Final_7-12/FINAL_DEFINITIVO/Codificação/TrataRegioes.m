function [reg_orig] = TrataRegioes(reg_orig)
    %%  Tratamento das Regi�es
        %   Extra��o das informa��es das regi�es detectadas em 'reg1'
            status = regionprops (reg_orig, 'Area');
        %   Refinamento sobre as regi�es encontradas, verificando cada
        %   regi�o encontrada
            for ind = 1: size(status)
                %   Estando abaixo de 5% da �rea total da imagem
                if (([status(ind).Area] < (0.06 * (size (reg_orig, 1) * size (reg_orig, 2)))))
                    %  Passando pelo refinamento, elimina-se tal regi�o da
                    %  imagem
                    for lin = 1: size (reg_orig, 1)
                        for col = 1: size (reg_orig, 2)
                            if (reg_orig (lin, col) == ind)
                                reg_orig (lin, col) = 0;
                            end
                        end
                    end
                end
            end
        %   Nova extra��o de informa��es, considerando a imagem
        %   pr�-refinada
            status = regionprops (reg_orig, 'Area');
            
    %%  Refinamento extra
        %   Tendo mais de uma regi�o detectada, � escolhida a de maior �rea
        if (size (status, 1) > 1)
        %   'maior_area' armazena a maior �rea, dentre as regi�es
            maior_area = max([status.Area]);
            %   Refinamento sobre as regi�es encontradas, verificando cada
            %   regi�o encontrada
                for ind = 1: size(status)
                    %   Estando abaixo de 5% da �rea total da imagem
                    if ([status(ind).Area] < maior_area)
                        %  Passando pelo refinamento, elimina-se tal regi�o da
                        %  imagem
                        for lin = 1: size (reg_orig, 1)
                            for col = 1: size (reg_orig, 2)
                                if (reg_orig (lin, col) == ind)
                                    reg_orig (lin, col) = 0;
                                end
                            end
                        end
                    end
                end
        %   Nova extra��o de informa��es, considerando a imagem
        %   pr�-refinada
            status = regionprops (reg_orig, 'Area');
            %figure, imshow (reg_orig);
            %whos status
            %pause ();
        end
            
end

