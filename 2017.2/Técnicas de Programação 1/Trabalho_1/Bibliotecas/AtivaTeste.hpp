#ifndef ATIVA_TESTE_H
    #define ATIVA_TESTE_H

    /**
     *  @brief  Controle da execução, como teste ou definitivo
     */
    #define TESTE
    #define ECHO_CATCH
    #define ECHO_MSG_TST

    #include "Utilidades/Manipulacao.hpp"
    #include "TesteClasse.hpp"
    #include "Dominio_Tst/Apelido_Tst.hpp"
    #include "Dominio_Tst/Codigo_Tst.hpp"
    #include "Dominio_Tst/Data_Tst.hpp"
    #include "Dominio_Tst/GeneroLiterario_Tst.hpp"
    #include "Dominio_Tst/Nome_Tst.hpp"

    void testarDominios (TesteClasse *);


    void fullTeste(){
        //*
        TesteClasse *sobTeste;

        testarDominios (sobTeste);
    }

    void testarDominios (TesteClasse *sobTeste){
        cout << "Testando Apelido:" << endl;
        sobTeste = new ApelidoTst();
        sobTeste->executar();

        cout << "Testando Codigo:" << endl;
        sobTeste = new CodigoTst ();
        sobTeste->executar();

        cout << "Testando Data:" << endl;
        sobTeste = new DataTst ();
        sobTeste->executar();

        cout << "Testando Gênero Literário:" << endl;
        sobTeste = new GeneroLiterarioTst ();
        sobTeste->executar();

        cout << "Testando Nome:" << endl;
        sobTeste = new NomeTst ();
        sobTeste->executar();
    }

#endif // ATIVA_TESTE_H
