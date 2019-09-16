function [reg_orig] = TrataRegioes(reg_orig)
    %%  Tratamento das Regiões
        %   Extração das informações das regiões detectadas em 'reg1'
            status = regionprops (reg_orig, 'Area');
        %   Refinamento sobre as regiões encontradas, verificando cada
        %   região encontrada
            for ind = 1: size(status)
                %   Estando abaixo de 5% da área total da imagem
                if (([status(ind).Area] < (0.06 * (size (reg_orig, 1) * size (reg_orig, 2)))))
                    %  Passando pelo refinamento, elimina-se tal região da
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
        %   Nova extração de informações, considerando a imagem
        %   pré-refinada
            status = regionprops (reg_orig, 'Area');
            
    %%  Refinamento extra
        %   Tendo mais de uma região detectada, é escolhida a de maior área
        if (size (status, 1) > 1)
        %   'maior_area' armazena a maior área, dentre as regiões
            maior_area = max([status.Area]);
            %   Refinamento sobre as regiões encontradas, verificando cada
            %   região encontrada
                for ind = 1: size(status)
                    %   Estando abaixo de 5% da área total da imagem
                    if ([status(ind).Area] < maior_area)
                        %  Passando pelo refinamento, elimina-se tal região da
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
        %   Nova extração de informações, considerando a imagem
        %   pré-refinada
            status = regionprops (reg_orig, 'Area');
            %figure, imshow (reg_orig);
            %whos status
            %pause ();
        end
            
end

