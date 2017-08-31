#ifndef TESTE_UNITARIO_HPP
    #define TESTE_UNITARIO_HPP

    /**
     *  @file   TesteUnitario.hpp
     *  @author Rodrigo F. Guimarães
     */

    #include <stdio.h>
    #include <iostream>
    #include <stdexcept>
    #include "Manipulacao.hpp"
    using namespace std;

    /**
     *  @class  TesteUnitario
     *  Responsável por implementar testes unitários para
     *  alguns tipos básicos:
     *      - Booleano;
     *      - Caracter;
     *      - Inteiro;
     *      - Double;
     *      - Ponteiro;
     *      - String.
     */
    class TesteUnitario {
        private:
            /**
             *  Gerenciamento para os testes unitários para cada tipo
             *  de dados manipulados pela classe
             */
            static bool expect (void *pt, bool cond) throw (invalid_argument);
            static bool expect (bool avaliar, bool cond) throw (invalid_argument);
            static bool expect (char val1, char val2, string cmp) throw (invalid_argument);
            static bool expect (int val1, int val2, string cmp) throw (invalid_argument);
            static bool expect (double val1, double val2, string cmp) throw (invalid_argument);
            static bool expect (string val1, string val2, string cmp) throw (invalid_argument);

            /**
             *  Mensagens padrões
             */
            static void msgTeste (int teste);
            static void msgCatch (string mensagem);
            static void msgSucesso ();

            /**
             *  Tratamento de falha para cada tipo de dado manipulado
             *  pela classe
             */
            static void tratarComp ();
            static string tratarFalha (int falhaCode);
            static string tratarFalha (int falhaCode, char val1, char val2);
            static string tratarFalha (int falhaCode, double val1, double val2);
            static string tratarFalha (int falhaCode, string val1, string val2);

            /**
             *  Códigos de falha possíveis
             */
            enum falhaComplexa  {FALHA_EQ, FALHA_NE, FALHA_LT, FALHA_LE, FALHA_GT, FALHA_GE};
            enum falhaSimples   {FALHA_NULL, FALHA_NNULL, FALHA_TRUE, FALHA_FALSE};


        public:
            /**
             *  Padronização dos códigos de retorno possíveis
             */
            enum retorno  {FALHOU, PASSOU};
            enum condicao {ERRADO, CORRETO};

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
             *  Captura de falha em funções fo protótipo:
             *  bool func (bool)
             *  @param func Função a ser captada
             *  @param cond Condição sujeita à exceção
             */
            static void capturarFalha(bool (* func) (bool), bool cond);
            /**
             *  Captura de falha em funções fo protótipo:
             *  bool func (char, char)
             *  @param func Função a ser captada
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             */
            static void capturarFalha(bool (* func) (char, char), char val1, char val2);
            /**
             *  Captura de falha em funções fo protótipo:
             *  bool func (int, int)
             *  @param func Função a ser captada
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             */
            static void capturarFalha(bool (* func) (int, int), int val1, int val2);
            /**
             *  Captura de falha em funções fo protótipo:
             *  bool func (double, double)
             *  @param func Função a ser captada
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             */
            static void capturarFalha(bool (* func) (double, double), double val1, double val2);
            /**
             *  Captura de falha em funções fo protótipo:
             *  bool func (string)
             *  @param func Função a ser captada
             *  @param val1 Primeiro valor a ser considerado
             */
            static void capturarFalha(bool (* func) (string), string val1);
            /**
             *  Captura de falha em funções fo protótipo:
             *  bool func (string, string)
             *  @param func Função a ser captada
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             */
            static void capturarFalha(bool (* func) (string, string), string val1, string val2);


            /**
             *  Teste unitário para ponteiro que deveria ser
             *  nulo
             *  @param pt Ponteiro a ser considerado
             *  @return PASSOU ou FALHOU
             */
            static bool expect_Null (void *pt) throw (invalid_argument);
            /**
             *  Teste unitário para ponteiro que deveria ser
             *  não nulo
             *  @param pt Ponteiro a ser considerado
             *  @return PASSOU ou FALHOU
             */
            static bool expect_NotNull (void *pt) throw (invalid_argument);


            /**
             *  Teste unitário para cond == True
             *  @param cond Valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_True (bool cond) throw (invalid_argument);
            /**
             *  Teste unitário para cond == False
             *  @param cond Valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_False (bool cond) throw (invalid_argument);


            /**
             *  Teste unitário para val1 == val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_EQ (char val1, char val2) throw (invalid_argument);
            /**
             *  Teste unitário para val1 != val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_NE (char val1, char val2) throw (invalid_argument);
            /**
             *  Teste unitário para val1 < val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_LT (char val1, char val2) throw (invalid_argument);
            /**
             *  Teste unitário para val1 <= val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_LE (char val1, char val2) throw (invalid_argument);
            /**
             *  Teste unitário para val1 > val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_GT (char val1, char val2) throw (invalid_argument);
            /**
             *  Teste unitário para val1 => val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_GE (char val1, char val2) throw (invalid_argument);


            /**
             *  Teste unitário para val1 == val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_EQ (int val1, int val2) throw (invalid_argument);
            /**
             *  Teste unitário para val1 != val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_NE (int val1, int val2) throw (invalid_argument);
            /**
             *  Teste unitário para val1 < val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_LT (int val1, int val2) throw (invalid_argument);
            /**
             *  Teste unitário para val1 <= val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_LE (int val1, int val2) throw (invalid_argument);
            /**
             *  Teste unitário para val1 > val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_GT (int val1, int val2) throw (invalid_argument);
            /**
             *  Teste unitário para val1 == val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_GE (int val1, int val2) throw (invalid_argument);


            /**
             *  Teste unitário para val1 == val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_EQ (double val1, double val2) throw (invalid_argument);
            /**
             *  Teste unitário para val1 != val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_NE (double val1, double val2) throw (invalid_argument);
            /**
             *  Teste unitário para val1 < val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_LT (double val1, double val2) throw (invalid_argument);
            /**
             *  Teste unitário para val1 <= val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_LE (double val1, double val2) throw (invalid_argument);
            /**
             *  Teste unitário para val1 > val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU
             *  com tratamento de exceção
             */
            static bool expect_GT (double val1, double val2) throw (invalid_argument);
            /**
             *  Teste unitário para val1 => val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_GE (double val1, double val2) throw (invalid_argument);


            /**
             *  Teste unitário para val1 == val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_EQ (string val1, string val2) throw (invalid_argument);
            /**
             *  Teste unitário para val1 != val2
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_NE (string val1, string val2) throw (invalid_argument);
            /**
             *  Teste unitário para val1 == val2, sem sensibilidade
             *  de maiúsculo/minúsculo
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_CEQ (string val1, string val2) throw (invalid_argument);
            /**
             *  Teste unitário para val1 != val2, sem sensibilidade
             *  de maiúsculo/minúsculo
             *  @param val1 Primeiro valor a ser considerado
             *  @param val2 Segundo valor a ser considerado
             *  @return PASSOU ou FALHOU,
             *  com tratamento de exceção
             */
            static bool expect_CNE (string val1, string val2) throw (invalid_argument);
    };

    inline void TesteUnitario::msgSucesso (){
        cout << "Passou!" << endl;
    }
#endif // TESTE_UNITARIO
