#ifndef LIVRO_TST_H
    #define LIVRO_TST_H

    /**
     *  @file   Livro_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../TesteClasse.hpp"
    #include "../../Bibliotecas/Entidade/Livro.hpp"

    /**
     *  @class  LivroTst
     *  Responsável por testar a classe Livro,
     *  a fim de garantir um correto funcionamento
     */
    class LivroTst : public TesteClasse{
        private:
            /*  Corpo de teste */
            Livro *livro;

            /*  Etapas do teste */
            void inicializar () override;
            void validar () override;
            void finalizar () override;

            /*  Validações unitárias */
            void validarCodigo ();
            void validarData ();
            void validarGenero ();
            void validarAutor ();
            void validarTitulo ();

            /*  Constantes de teste */
            Codigo codigo;
            Data data;
            GeneroLiterario genero;
            Nome autor;
            Titulo titulo;
    };
#endif // LIVRO_TST_H
