#ifndef ATIVA_TESTE_H
    #define ATIVA_TESTE_H

    /**
     *  @brief  Controle da execução, como teste ou definitivo
     */
    #define TESTE
    #define ECHO_CATCH
    #define ECHO_MSG_TST

    #include "TesteClasse.hpp"
    #include "Dominio_Tst/Apelido_Tst.hpp"
    #include "Dominio_Tst/Codigo_Tst.hpp"

    void fullTeste(){
        TesteClasse *testar;

        cout << "Testando Apelido:" << endl;
        testar = new ApelidoTst();
        testar->executar();
        delete testar;

        cout << "Testando Codigo:" << endl;
        testar = new CodigoTst ();
        testar->executar();
        delete testar;
    }

#endif // ATIVA_TESTE_H
