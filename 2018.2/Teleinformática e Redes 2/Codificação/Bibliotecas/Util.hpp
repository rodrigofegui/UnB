#ifndef UTIL_HPP
    #define UTIL_HPP

    /**
     *  @file   Util.hpp
     *  @author Rodrigo F. Guimarães
     *  @brief  Responsável por disponbilizar as funcionalidades básicas
     *  e pertinente a todos os demais.
     */
    #include <iostream>
    #include <stdexcept>

    /**
     *  Verificar se a quantidade de argumentos fornecidos
     *  corresponde à quantidade esperada.
     *  @param expQnt Quantidade de argumentos esperada
     *  @param argQnt Quantidade de argumentos recebida
     *  @result Surge uma excessão caso não esteja correto.
     */
    void checkArg (int expQnt, int argQnt) throw (const std::length_error&);

#endif