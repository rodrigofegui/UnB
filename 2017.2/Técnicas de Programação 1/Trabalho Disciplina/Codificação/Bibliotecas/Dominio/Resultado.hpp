#ifndef RESULTADO_HPP
    #define RESULTADO_HPP

    /**
     *  @file   Resultado.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "DominioBase.hpp"

    /**
     *  @class  Resultado
     *  Resultado de operações aceitos na estante digital
     */
    class Resultado : public DominioBase{
        private:
            void validar (const string &campo) throw (invalid_argument) override;

        public:
            /** Sinalização do sucesso */
            const static string SUCESSO;
            /** Sinalização de falha */
            const static string FALHA;
            /** Sinalização de falha por atingir limite */
            const static string FLH_LIM;

            /** Selecionada a opção de autenticar */
            const static string ESC_AUTENTICAR;
            /** Selecionada a opção de cadastrar */
            const static string ESC_CADASTRAR;
            /** Selecionada a opção de sair */
            const static string ESC_SAIR;

            /**
             *  Construtor padrão
             */
            Resultado (){};

            /**
             *  Construtor de um Resultado, conhecendo-se
             *  o mesmo
             *  @param Resultado a ser conferido
             */
            Resultado (const string &);

            /**
             *  Destrutor padrão
             */
            void deletar() override;
    };
#endif // RESULTADO_HPP
