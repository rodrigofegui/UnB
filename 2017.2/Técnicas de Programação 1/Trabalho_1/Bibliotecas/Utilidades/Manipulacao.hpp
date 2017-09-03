#ifndef MANIPULACAO_HPP
    #define MANIPULACAO_HPP

    /**
     *  @file   Manipulacao.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include <iostream>
    #include "TesteUnitario.hpp"

    using namespace std;

    /**
     *  @class  Manipulacao
     *  Responsável por implementar manipulações referentes
     *  aos tipos listados, seja manipulacao direta ou verificacoes:
     *      - String.
     */
    class Manipulacao{
        public:
            /**
             *  Conversão de Booleano para String
             */
            #define bool2str(x) (x ? "true" : "false")

            /**
             *  Converter string para uma string de letras
             *  maiúsculas, apenas, A-Z
             *  @param src String a ser manipulada
             *  @return String em maiusculo
             */
            static string maiuscula (string src);
            /**
             *  Converter string para uma string de letras
             *  minúsculas, apenas, a-z
             *  @param src String a ser manipulada
             *  @return String em minusculo
             */
            static string minuscula (string src);

            /**
             *  Verificar se uma dada string está no limite de
             *  caracteres permitido
             *  @param src String a ser avaliada
             *  @param lim Limite superior a ser considerado
             *  @return PASSOU ou FALHOU
             */
            static bool noLimite (string src, int lim);

            /**
             *  Verificar se há a existência de pelo menos
             *  um caracter numérico numa dada string
             *  @param src String a ser avaliada
             *  @return PASSOU ou FALHOU
             */
            static bool haNum (string src);

            /**
             *  Verificar se todos os caracteres são alfabeticos
             *  numa dada string
             *  @param src String a ser avaliada
             *  @return PASSOU ou FALHOU
             */
            static bool eAlfabetico (string src);

            /**
             *  Verificar se todos os caracteres são numéricos
             *  numa dada string
             *  @param src String a ser avaliada
             *  @return PASSOU ou FALHOU
             */
            static bool eNum (string src);

            /**
             *  Verificar se uma dada string tem um tamanho
             *  definido
             *  @param src String a ser avaliada
             *  @param tam Tamanho desejável
             *  @return PASSOU ou FALHOU
             */
            static bool tam(string src, int tam);
    };

#endif // MANIPULACAO_HPP
