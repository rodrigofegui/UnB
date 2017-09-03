#ifndef GENERO_LITERARIO_TST_H
    #define GENERO_LITERARIO_TST_H

    /**
     *  @file   GeneroLiterario_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */

    #include "../Dominio/GeneroLiterario.hpp"
    #include "../TesteClasse.hpp"

    /**
     *  @class GeneroLiterarioTst
     *  Responsável por testar diversos cenários da classe
     *  Gênero Literário, a fim de garantir um correto funcionamento
     */
    class GeneroLiterarioTst : public TesteClasse{
        private:
            /*  Corpo de teste */
            GeneroLiterario *genLit;

            /*  Etapas do teste */
            void inicializar() override;
            void validar() override;
            void finalizar() override;

            /*  Validações unitárias */
            void validarCampoOk (string campo);
            void validarCampoNOk (string campo);

            /*  Constantes de teste */
            const string VALIDO_REG[5] = {"EPOPEIA",
                                          "NOVELA",
                                          "CONTO",
                                          "ENSAIO",
                                          "ROMANCE"};
            const string INVALIDO[4] = { "AVENTURA",
                                         "FICCAO",
                                         "FICÇÃO",
                                         "DRAMA"};
    };
#endif // GENERO_LITERARIO_H
