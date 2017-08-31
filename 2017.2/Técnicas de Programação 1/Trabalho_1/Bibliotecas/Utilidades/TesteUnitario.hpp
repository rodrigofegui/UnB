#ifndef TESTE_UNITARIO_HPP
    #define TESTE_UNITARIO_HPP

    /**
     *  @file   TesteUnitario.hpp
     *  @author Rodrigo F. Guimarães
     */

    #include <stdio.h>
    #include <iostream>
    using namespace std;

    /**
     *  Conversão de Booleano para String
     */
    #define bool2str(x) (x ? "true" : "false")

    /**
     *  @class  TesteUnitario
     *  Responsável por implementar testes unitários para
     *  alguns tipos básicos:
     *      - Booleano;
     *      - Caracter;
     *      - Inteiro;
     *      - Double;
     *      - String.
     */
    class TesteUnitario {
        private:
            /**
             *  Gerenciamento para os testes unitários para cada tipo
             *  de dados manipulados pela classe
             */
            static void expect (bool avaliar, bool cond);
            static void expect (char val1, char val2, string cmp);
            static void expect (int val1, int val2, string cmp);
            static void expect (double val1, double val2, string cmp);
            static void expect (string val1, string val2, string cmp);

            /**
             *  Mensagens padrões para sucesso e falha na operação
             *  dos testes
             */
            static void msgSucesso (){cout << "\tPassou!" << endl << endl;}
            static void msgFalha (){cout << "\tFalhou!" << endl;}

            /**
             *  Tratamento de falha para cada tipo de dado manipulado
             *  pela classe
             */
            static void tratarFalha (int falhaCode, char val1, char val2);
            static void tratarFalha (int falhaCode, double val1, double val2);
            static void tratarFalha (int falhaCode, string val1, string val2);

            /**
             *  Códigos de falha possíveis
             */
            enum falha {FALHA_EQ, FALHA_NE, FALHA_LT, FALHA_LE, FALHA_GT, FALHA_GE};

        public:
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
             *  Validação da classe, realizando todos os testes
             *  possíveis
             */
            static void validar ();
            /**
             *  Validação dos testes relativos ao expect_True
             */
            static void validarTrue ();
            /**
             *  Validação dos testes relativos ao expect_False
             */
            static void validarFalse();
            /**
             *  Validação dos testes relativos ao expect_EQ
             */
            static void validarEQ();
            /**
             *  Validação dos testes relativos ao expect_NE
             */
            static void validarNE();
            /**
             *  Validação dos testes relativos ao expect_LT
             */
            static void validarLT();
            /**
             *  Validação dos testes relativos ao expect_LE
             */
            static void validarLE();
            /**
             *  Validação dos testes relativos ao expect_GT
             */
            static void validarGT();
            /**
             *  Validação dos testes relativos ao expect_GE
             */
            static void validarGE();

            /**
             *  Teste unitário para cond == True
             *  @param cond Valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_True (bool cond);
            /**
             *  Teste unitário para cond == False
             *  @param cond Valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_False (bool cond);

            /**
             *  Teste unitário para val1 == val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_EQ (char val1, char val2);
            /**
             *  Teste unitário para val1 != val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_NE (char val1, char val2);
            /**
             *  Teste unitário para val1 < val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_LT (char val1, char val2);
            /**
             *  Teste unitário para val1 <= val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_LE (char val1, char val2);
            /**
             *  Teste unitário para val1 > val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_GT (char val1, char val2);
            /**
             *  Teste unitário para val1 => val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_GE (char val1, char val2);

            /**
             *  Teste unitário para val1 == val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_EQ (int val1, int val2);
            /**
             *  Teste unitário para val1 != val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_NE (int val1, int val2);
            /**
             *  Teste unitário para val1 < val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_LT (int val1, int val2);
            /**
             *  Teste unitário para val1 <= val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_LE (int val1, int val2);
            /**
             *  Teste unitário para val1 > val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_GT (int val1, int val2);
            /**
             *  Teste unitário para val1 == val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_GE (int val1, int val2);

            /**
             *  Teste unitário para val1 == val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_EQ (double val1, double val2);
            /**
             *  Teste unitário para val1 != val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_NE (double val1, double val2);
            /**
             *  Teste unitário para val1 < val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_LT (double val1, double val2);
            /**
             *  Teste unitário para val1 <= val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_LE (double val1, double val2);
            /**
             *  Teste unitário para val1 > val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_GT (double val1, double val2);
            /**
             *  Teste unitário para val1 => val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_GE (double val1, double val2);

            /**
             *  Teste unitário para val1 == val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_EQ (string val1, string val2);
            /**
             *  Teste unitário para val1 != val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_NE (string val1, string val2);
            /**
             *  Teste unitário para val1 == val2, sem sensibilidade
             *  de maiúsculo/minúsculo
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_CEQ (string val1, string val2);
            /**
             *  Teste unitário para val1 != val2, sem sensibilidade
             *  de maiúsculo/minúsculo
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return Resultado do teste: positivo ou negativo,
             *  com tratamento de exceção
             */
            static void expect_CNE (string val1, string val2);
    };
#endif // TESTE_UNITARIO
