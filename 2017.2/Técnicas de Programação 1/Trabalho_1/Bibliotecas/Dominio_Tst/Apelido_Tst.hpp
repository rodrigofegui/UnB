#ifndef APELIDO_TST_HPP
    #define APELIDO_TST_HPP

    /**
     *  @file   Apelido_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */

    #include "../Dominio/Apelido.hpp"
    #include "../Utilidades/TesteUnitario.hpp"

    /**
     *  @class ApelidoTst
     *  Responsável por testar diversos cenários da classe Apelido,
     *  a fim de garantir um correto funcionamento
     */
    class ApelidoTst{
        private:
            /**
             *  Corpo de teste
             */
            Apelido *apelido;

            /**
             *  Controle de Estado do teste
             */
            bool status;

            /**
             *  Validações unitárias
             */
            void inicializar ();
            void finalizar ();
            void validar ();
            void validarCampo(string campo, bool cond);
            void validarCampoOk (string campo);
            void validarCampoNOk (string campo);

        public:
            /**
             *  Validação da classe Apelido, com a realização
             *  de testes unitários
             *  @return PASSOU ou FALHOU, conforme os teste
             */
            bool executar();
    };
#endif // APELIDO_TST_HPP
