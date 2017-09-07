#ifndef LIVRO_TST_H
    #define LIVRO_TST_H

    /**
     *  @file   Livro_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../TesteClasse.hpp"
    #include "../Entidade/Livro.hpp"

    /**
     *  @class  LivroTst
     *  Responsável por testar a classe Livro,
     *  a fim de garantir um correto funcionamento
     */
    class LivroTst : public TesteClasse{
        private:
            /*  Etapas do teste */
            void inicializar () override;
            void validar () override;
            void finalizar () override;

            /*  Validações unitárias */
            void validarCodigo (const Codigo &codigo);
            void validarData (const Data &data);
            void validarGenero (const GeneroLiterario &genero);
            void validarAutor (const Nome &autor);
            void validarTitulo (const Titulo &titulo);

            /*  Corpo de teste */
            Livro *livro;

            /*  Constantes de teste */
            Codigo codigo;
            Data data;
            GeneroLiterario genero;
            Nome autor;
            Titulo titulo;
    };
#endif // LIVRO_TST_H
