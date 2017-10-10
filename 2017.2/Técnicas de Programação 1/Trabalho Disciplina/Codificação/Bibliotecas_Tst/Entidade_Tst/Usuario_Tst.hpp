#ifndef USUARIO_TST_H
    #define USUARIO_TST_H

    /**
     *  @file   Usuario_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../TesteClasse.hpp"
    #include "../../Bibliotecas/Entidade/Usuario.hpp"

    /**
     *  @class UsuarioTst
     *  Responsável por testar a classe Usuario,
     *  a fim de garantir um correto funcionamento
     */
    class UsuarioTst : public TesteClasse{
        private:
            /*  Corpo de Teste */
            Usuario *usuario;

            /*  Etapas do teste */
            void inicializar () override;
            void validar () override;
            void finalizar () override;

            /*  Validações unitárias */
            void validarNome ();
            void validarApelido ();
            void validarTelefone ();
            void validarSenha ();

            /*  Componentes de um usuário */
            Nome nome;
            Apelido apelido;
            Telefone telefone;
            Senha senha;
    };
#endif // USUARIO_TST_H
