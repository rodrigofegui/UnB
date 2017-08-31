#ifndef PRINCIPAL.HPP
    #define PRINCIPAL.HPP

    /**
     *  @file   Principal.hpp
     *  @author Rodrigo F. Guimarães
     *  @brief  Responsável por adicionar todas as
     *  bibliotecas importantes e necessárias para
     *  o desenvolvimento desejável da aplicação
     */

    /**
     *  @brief  Inclusão das bibliotecas necessárias para
     *  a aplicação
     */
    #include <stdlib.h>
    #include <iostream>
    #include <string>

    /**
     *  @brief  Bibliotecas necessárias para a realização
     *  dos testes unitários
     */
    #ifdef TESTE
        #include "Bibliotecas/Utilidades/TesteUnitario.hpp"
    #endif // TESTE


    /*
     *  @brief  Classes dos domínios de dados a serem
     *  manipulados na aplicação
     *
    #include "Declaracao/Dominio/Apelido.hpp"
    #include "Declaracao/Dominio/Codigo.hpp"
    #include "Declaracao/Dominio/Data.hpp"
    #include "Declaracao/Dominio/GeneroLiterario.hpp"
    #include "Declaracao/Dominio/Nome.hpp"
    #include "Declaracao/Dominio/Senha.hpp"
    #include "Declaracao/Dominio/Telefone.hpp"
    #include "Declaracao/Dominio/Texto.hpp"
    #include "Declaracao/Dominio/Titulo.hpp"

    /**
     *  @brief Classes das entidades a serem
     *  manipuladas na aplicação
     *
    #include "Declaracao/Entidades/Livro.hpp"
    #include "Declaracao/Entidades/Resenha.hpp"
    #include "Declaracao/Entidades/Usuario.hpp"



    #ifdef TESTE
        /**
         *  @brief  Classes dos domínios de dados a serem
         *  manipulados na aplicação
         *
        #include "Declaracao/Dominio_Tst/Apelido_Tst.hpp"
        #include "Declaracao/Dominio_Tst/Codigo_Tst.hpp"
        #include "Declaracao/Dominio_Tst/Data_Tst.hpp"
        #include "Declaracao/Dominio_Tst/GeneroLiterario_Tst.hpp"
        #include "Declaracao/Dominio_Tst/Nome_Tst.hpp"
        #include "Declaracao/Dominio_Tst/Senha_Tst.hpp"
        #include "Declaracao/Dominio_Tst/Telefone_Tst.hpp"
        #include "Declaracao/Dominio_Tst/Texto_Tst.hpp"
        #include "Declaracao/Dominio_Tst/Titulo_Tst.hpp"

        /**
         *  @brief Classes das entidades a serem
         *  manipuladas na aplicação
         *
        #include "Declaracao/Entidades/Livro.hpp"
        #include "Declaracao/Entidades/Resenha.hpp"
        #include "Declaracao/Entidades/Usuario.hpp"
    #endif // TESTE
    //*/

#endif // PRINCIPAL
