function [void] = EscreveResult(arq, ind, esperado, determinado)
    %%  Refinando o 'esperado'
        %   Retirando o '_' do código
        esperado = esperado (1 : size(esperado, 2) - 1);


    %%  Refinando o 'determinado'
        %   Retirando o '_' do código
        determinado = determinado (3 : size(determinado, 2));


    %%  Escrita da jogada no log
        resultado = strcat (num2str(ind), '\t');
        resultado = strcat (resultado, 'Era esperado:\t');
        resultado = strcat (resultado, sprintf (esperado));
        resultado = strcat (resultado, '\tFoi detectado:\t');
        resultado = strcat (resultado, sprintf (determinado));
        if (strcmp(esperado, determinado))
            resultado = strcat (resultado, '\tACERTOU\n');
        else
            resultado = strcat (resultado, '\tERROU\n');
        end
        fprintf (arq, resultado);
end

