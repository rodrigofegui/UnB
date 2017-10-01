#ifndef OP_RESULTADO_HPP
    #define OP_RESULTADO_HPP

    /**
     *  @file   OpResult.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "DominioBase.hpp"

    /**
     *  @class  OpResult
     *  Resultado padrão aceito na estante digital
     */
    class OpResult : public DominioBase{
        public:
            /**
             *  Construtor padrão
             */
            OpResult (){};

            /**
             *  Construtor do resultado, conhecendo-se seu código
             *  @param campo Código do resultado
             */
            OpResult (const string &campo);

            /**
             *  Destrutor padrão
             */
            void deletar() override;

            /** Avaliação de Sucesso na Operação */
            const static string SUCESSO;
            /** Avaliação de Falha na Operação */
            const static string FALHA;
            /** Avaliação para execução da funcionalidade de Autenticar */
            const static string EXE_AUTENTICAR;
            /** Avaliação para execução da funcionalidade de Usuário */
            const static string EXE_USUARIO;
            /** Avaliação para execução da funcionalidade da Estante */
            const static string EXE_ESTANTE;

    };
#endif // OP_RESULTADO_HPP
