#ifndef TESTE_CLASSE_H
    #define TESTE_CLASSE_H

    /**
     *  @file   TesteClasse.hpp
     *  @author Rodrigo F. Guimarães
     */

    #include <iostream>
    #include "Utilidades/TesteUnitario.hpp"
    using namespace std;

    /**
     *  @class  TesteClasse
     *  Responsável por implantar o protocolo de teste
     *  a ser utilizado como modelo
     */
    class TesteClasse{
        private:
            /*  Validações unitárias */
            virtual void inicializar (){};
            virtual void finalizar (){};
            virtual void validar (){};

        protected:
            /**  Controle de Estado do teste */
            bool status;

        public:
            /**
             *  Executar os testes unitários cadastrados para
             *  uma dada classe
             *  @return PASSOU ou FALHOU, conforme os teste
             */
            bool executar();
    };
#endif // TESTE_CLASSE_H
