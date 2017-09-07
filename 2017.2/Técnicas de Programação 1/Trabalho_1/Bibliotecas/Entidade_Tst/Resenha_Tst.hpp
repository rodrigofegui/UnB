#ifndef RESENHA_TST_H
    #define RESENHA_TST_H

    /**
     *  @file   Resenha_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../TesteClasse.hpp"
    #include "../Entidade/Resenha.hpp"

    /**
     *  @class  ResenhaTst
     *  Responsável por testar a classe Resenha,
     *  a fim de garantir um correto funcionamento
     */
    class ResenhaTst : public TesteClasse{
        private:
            /*  Corpo de Teste */
            Resenha *resenha;

            /*  Etapas do teste */
            void inicializar () override;
            void validar () override;
            void finalizar () override;

            /*  Validações unitárias */
            void validarTitulo ();
            void validarTexto ();

            /*  Componentes de uma resenha */
            Texto texto;
            Titulo titulo;
    };
#endif // RESENHA_TST_H
