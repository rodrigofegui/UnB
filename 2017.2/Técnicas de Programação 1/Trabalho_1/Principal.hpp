#ifndef PRINCIPAL.HPP
    #define PRINCIPAL.HPP

    /**
     *  @file   Principal.hpp
     *  @author Rodrigo F. Guimarães
     *  @brief Arquivo responsável por adicionar todas as
     *  bibliotecas importantes e necessárias para
     *  o desenvolvimento desejável da aplicação
     */

    /**
     *  @brief  Classes dos domínios de dados a serem
     *  manipulados na aplicação
     */
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
     */
    #include "Declaracao/Entidades/Livro.hpp"
    #include "Declaracao/Entidades/Resenha.hpp"
    #include "Declaracao/Entidades/Usuario.hpp"

#endif // PRINCIPAL
