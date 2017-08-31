#ifndef ATIVA_TESTE_H
    #define ATIVA_TESTE_H

    /**
     *  @brief  Controle da execução, como teste ou definitivo
     */
    #define TESTE
    #define ECHO_CATCH
    #define ECHO_MSG_TST

    #include "Dominio_Tst/Apelido_Tst.hpp"

    void fullTeste(){
        ApelidoTst apelidoTest;

        if(apelidoTest.executar())  cout << "Apelido: APROVADO!" << endl << endl;
        else    cout << "Apelido: REPROVADO!" << endl << endl;
    }

#endif // ATIVA_TESTE_H
