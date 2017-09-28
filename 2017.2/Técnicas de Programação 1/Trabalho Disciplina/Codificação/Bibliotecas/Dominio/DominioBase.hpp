#ifndef DOMINIO_BASE_H
    #define DOMINIO_BASE_H

    /**
     *  @file   DominioBase.hpp
     *  @author Rodrigo F. Guimarães
     */

    #include <iostream>
    #include <stdexcept>
    #include "../Utilidades/Manipulacao.hpp"
    using namespace std;

    /**
     *  @class DominioBase
     *  Modelo do tipo mínimo manipulado na estante digital,
     *  garantindo um interfaciamento amigável e padrão às demais
     */
    class DominioBase{
        private:
            /*  Tipo a ser armazenado */
            string campo;

            /*  Validação do tipo a ser armazenado */
            virtual void validar (const string &campo) throw (invalid_argument, length_error){};

        public:
            /**
             *  Atribuição do tipo do domínio, respeitando a sua
             *  integridade
             *  @param campo Tipo do domínio candidato à atribuição
             */
            void setCampo(const string &campo) throw (invalid_argument, length_error);

            /**
             *  Recuperar o valor atribuído ao tipo do domínio
             *  @return Valor armazenado ao tipo do domínio
             */
            string getCampo() const;

            /**
             *  Verificar se dois domínios são iguais
             *  @param alvo Domínio alvo de comparação
             *  @return PASSOU ou FALHOU
             */
            bool equals (const DominioBase &alvo) const;

            /**
             *  Destrutor padrão
             */
            virtual void deletar (){};
    };

    inline string DominioBase::getCampo()const {return this->campo;}
#endif // DOMINIO_BASE_H
