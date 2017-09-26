#ifndef ATIVA_TESTE_H
    #define ATIVA_TESTE_H

    /**
     *  @brief  Controle da execução, como teste ou definitivo
     */
    #define TESTE
    #define ECHO_CATCH
    #define ECHO_MSG_TST

    #include "../Bibliotecas/Utilidades/Manipulacao.hpp"
    #include "TesteClasse.hpp"
    #include "Dominio_Tst/Apelido_Tst.hpp"
    #include "Dominio_Tst/Codigo_Tst.hpp"
    #include "Dominio_Tst/Data_Tst.hpp"
    #include "Dominio_Tst/GeneroLiterario_Tst.hpp"
    #include "Dominio_Tst/Nome_Tst.hpp"
    #include "Dominio_Tst/Senha_Tst.hpp"
    #include "Dominio_Tst/Telefone_Tst.hpp"
    #include "Dominio_Tst/Texto_Tst.hpp"
    #include "Dominio_Tst/Titulo_Tst.hpp"
    #include "Entidade_Tst/Livro_Tst.hpp"
    #include "Entidade_Tst/Resenha_Tst.hpp"
    #include "Entidade_Tst/Usuario_Tst.hpp"

    void testarDominios (TesteClasse *);
    void testarEntidades (TesteClasse *);


    void fullTeste(){
        TesteClasse *sobTeste;

        testarDominios (sobTeste);

        testarEntidades (sobTeste);
    }

    void testarDominios (TesteClasse *sobTeste){
        sobTeste = new ApelidoTst();
        sobTeste->executar();

        sobTeste = new CodigoTst ();
        sobTeste->executar();

        sobTeste = new DataTst ();
        sobTeste->executar();

        sobTeste = new GeneroLiterarioTst ();
        sobTeste->executar();

        sobTeste = new NomeTst ();
        sobTeste->executar();

        sobTeste = new SenhaTst ();
        sobTeste->executar();

        sobTeste = new TelefoneTst ();
        sobTeste->executar();

        sobTeste = new TextoTst ();
        sobTeste->executar();

        sobTeste = new TituloTst ();
        sobTeste->executar();
    }

    void testarEntidades (TesteClasse *sobTeste){
        sobTeste = new LivroTst ();
        sobTeste->executar();

        sobTeste = new ResenhaTst ();
        sobTeste->executar();

        sobTeste = new UsuarioTst ();
        sobTeste->executar();
    }
#endif // ATIVA_TESTE_H
